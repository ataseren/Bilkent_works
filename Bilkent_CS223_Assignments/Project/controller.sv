module controller(input logic clk,
                input logic [15:0] instruction,
                input logic [7:0] regToMem, memToReg, aluResult,
                output logic writeDataEnable, writeRegEnable, aluControl, branch, stop,
                output logic [3:0] writeRegAddress, writeDataAddress, readDataAddress, readRegAddress, readRegAddress2,
                output logic [4:0] romAddress,
                output logic [7:0] writeData, writeReg); 
           
always_comb
        case(instruction[15:13])
            3'b000: begin 
                writeDataEnable = 1;
                writeRegEnable = 0;
                if(instruction[12]) begin
                    writeDataAddress = instruction[11:8];
                    writeData = instruction[7:0];
                    end
                else begin
                    writeDataAddress = instruction[7:4];
                    readRegAddress2 = instruction[3:0];
                    writeData = regToMem;
                    end
            end
            3'b001:   
            begin
                writeDataEnable = 0;
                writeRegEnable = 1;
                if(instruction[12]) begin              
                    writeRegAddress = instruction[11:8];
                    writeReg = instruction[7:0];
                    end
                else begin
                    writeRegAddress = instruction[7:4];
                    readDataAddress = instruction[3:0];
                    writeReg = memToReg;
                    end  
            end
            
            
            3'b010:
            begin
                aluControl = 0;
                writeDataEnable = 0;
                writeRegAddress = instruction[11:8]; 
                readRegAddress = instruction[7:4];
                readRegAddress2 = instruction[3:0];  
                writeReg = aluResult;
                writeRegEnable = 1;
               // nextState <= gate;  
            end
            
            3'b101:
            begin
                aluControl = 1;
                branch = 1;
                readRegAddress = instruction[7:4];
                readRegAddress2 = instruction[3:0];
                romAddress = instruction[12:8]; 
                //nextState <= gate;  
            end
            
            3'b111:
            begin
                stop = 1;
            end
            
            default:
            begin
                stop = 0;
                branch = 0;
                aluControl = 0;
                writeDataEnable = 0;
                writeRegEnable = 0;
            end
         endcase
                
//    typedef enum logic [6:0]{init, gate, store, load, add, branch, stop} states;
//    states [1:0] state, nextState;
//    always @(posedge clk)
//        state <= nextState;
        
//    always_ff @(posedge clk)  
//        case( state)
//            init:
//                nextState <= gate;     
//            gate:
//            begin
//                writeDataEnable <= 0;
//                writeRegEnable <= 0;
//                case(instruction[15:13])
//                3'b000: nextState <= store;
//                3'b001: nextState <= load;
//                3'b010: nextState <= add;
//                3'b101: nextState <= branch;
//                3'b111 : nextState <= stop;
//                default: nextState <= gate;
//                endcase
//            end
            
//            store:
//            begin
//                writeDataEnable <= 0;
//                writeRegEnable <= 0;
//                if(instruction[12] == 1) begin
//                    writeDataEnable <= 1;
//                    writeDataAddress <= instruction[11:8];
//                    writeData <= instruction[7:0];
//                    nextState <= gate;  
//                    end
//                else begin
//                    writeDataEnable <= 1;
//                    writeDataAddress <= instruction[7:4];
//                    readRegAddress2 <= instruction[3:0];
//                    writeData <= regToMem;
//                    nextState <= gate;  
//                    end                    
//            end
            
//            load:
//            begin
//                writeDataEnable <= 0;
//                writeRegEnable <= 0;
//                if(instruction[12] == 1) begin
//                    writeRegEnable <= 1;                   
//                    writeRegAddress <= instruction[11:8];
//                    writeReg <= instruction[7:0];
//                    nextState <= gate;  
//                    end
//                else begin
//                    writeRegEnable <= 1;
//                    writeRegAddress <= instruction[7:4];
//                    readDataAddress <= instruction[3:0];
//                    writeReg <= memToReg;
//                    nextState <= gate;  
//                    end  
//            end
            
//            add:
//            begin
//                writeDataEnable <= 0;
//                writeRegEnable <= 0;
//                aluControl <= 0;
//                writeRegAddress <= instruction[11:8];
//                readRegAddress <= instruction[7:4];
//                readRegAddress2 <= instruction[3:0];
//                writeReg <= aluResult;
//                writeRegEnable <= 1; 
//                nextState <= gate;  
//            end
            
//            branch:
//            begin
//                writeDataEnable <= 0;
//                writeRegEnable <= 0;
//                romAddress = instruction[12:8];
//                readRegAddress <= instruction[7:4];
//                readRegAddress2 <= instruction[3:0]; 
//                nextState <= gate;  
//            end
            
//            stop:
//            begin
                
//            end
//            default: nextState <= init;
//         endcase

endmodule

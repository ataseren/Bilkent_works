module top( input logic clk, 
            input logic [15:0] swIns,
            logic [4:0] debouncer,
            output logic [15:0]insLed, 
            output logic [6:0]seg, 
            output logic dp, 
            output logic[3:0] an);

                logic [15:0] instruction;
                logic [15:0] romIns;
                logic aluControl;
                logic [3:0] readDataAddress1, readDataAddress2, 
                writeRegAddress, writeDataAddress, readDataAddress, readRegAddress, readRegAddress2;
                logic [4:0] romAddress = 5'b00000, romAddressBranch;
                logic [7:0] ramReadData1, ramReadData2, regReadData, regReadData2, writeData, writeReg, aluResult;
                logic left, right, center, down, up, branch;
                logic [3:0] memAddress;
                logic writeDataEnable, writeRegEnable, branchEnable;
                logic stop;
                
    debouncer leftButton( clk, debouncer[4], left);
    debouncer rightButton( clk, debouncer[3], right);
    debouncer upButton( clk, debouncer[2], up);
    debouncer centerButton( clk, debouncer[1], center);
    debouncer downButton( clk, debouncer[0], down);
    
    always_ff @(posedge clk) 
    begin
    if(up) begin
        romAddress <= 5'b00000;
        end
    else begin
        if(!stop) begin
            instruction <= 16'b1000000000000000;
            
            if (left)
                if (memAddress == 4'b0000)
                   memAddress <= 4'b1111;
                else
                   memAddress <= memAddress - 1;
                   
             else if (right)
                 if (memAddress == 4'b1111)
                     memAddress <= 4'b0000;
                 else
                     memAddress <= memAddress + 1;
                     
             else if (center)
                instruction <= swIns;
             
             else if((branchEnable & branch) == 1)
                    romAddress <= romAddressBranch;  
                       
             else if (down)begin
                instruction <= romIns;  
                if (romAddress == 5'b11111)
                   romAddress <= 5'b00000;
                else
                   romAddress <= romAddress + 1; 
                   end
                 
             
             end             
    end
    end
    controller control(clk, instruction, regReadData2, ramReadData2, aluResult, writeDataEnable, writeRegEnable, aluControl, branch, stop, writeRegAddress, writeDataAddress, readDataAddress, readRegAddress, readRegAddress2, romAddressBranch, writeData, writeReg);

    
    instructionMemory ins(romAddress, romIns, insLed);
    dataMemory ram(clk, up, writeDataEnable, writeDataAddress, writeData, memAddress, readDataAddress, ramReadData1, ramReadData2 );
    regFile register(clk, up, writeRegEnable, writeRegAddress, writeReg, readRegAddress, readRegAddress2, regReadData, regReadData2);
    alu cUnit(regReadData, regReadData2, aluControl, aluResult, branchEnable);  
    sevSeg7 sevSeg(clk, memAddress, 1, ramReadData1[7:4], ramReadData1[3:0], seg, dp, an);
 
    
    
endmodule

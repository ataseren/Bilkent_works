module ReduceSum(input logic clk,
                input logic writeEnable,
                input logic [7:0]readData2, 
                output logic [3:0]readAddress2, 
                output logic [11:0] total); //max digit of sum is 12
                
    typedef enum logic [3:0]{start, init, add, finish} states;
    states [1:0] state, nextState;
    logic [11:0] sum = 12'b0;
    logic [4:0] addressCounter = 5'b0;
    localparam limit = 5'b10000;
    
    //initialize clock
    always @(posedge clk)
        state <= nextState;
        
    //state transitions and additions
    always_ff @(posedge clk)  
        case( state)
            start:
            begin
                if(writeEnable)
                    nextState <= init;
                else
                    nextState <= start;
            end
            init:
            begin
                sum <= 12'b0;;
                addressCounter <= 4'b0;
                nextState <= add;
            end
            add:
            begin
            if(addressCounter != limit) begin
                sum <= sum + readData2;
                addressCounter <= addressCounter + 1;
                nextState <= add;
                end
            else 
                nextState <= finish;              
            end
            finish:
            begin
                total <= sum;
                nextState <= start;
            end
            default: nextState <= start;
         endcase
         
        assign readAddress2 = addressCounter;
endmodule

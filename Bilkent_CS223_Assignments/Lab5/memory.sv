module memory( 
input logic clk,
input logic writeEnable,
input logic [3:0] writeAddress,
input logic [7:0] writeData,
input logic [3:0] readAddress1,
input logic [3:0] readAddress2,
output logic [7:0] readData1,
output logic [7:0] readData2);
logic [7:0] mem [15:0];
always_ff @(posedge clk)
    begin
        if (writeEnable)
        mem[writeAddress] <= writeData;         
    end
    
    assign readData1 = mem[readAddress1];
    assign readData2 = mem[readAddress2]; 
    
 
endmodule
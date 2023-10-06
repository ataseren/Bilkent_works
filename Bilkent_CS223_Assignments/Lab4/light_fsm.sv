`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 23.11.2020 00:11:26
// Design Name: 
// Module Name: light_fsm
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module light_fsm(
    input logic clk,
    input logic reset,
    input logic sa,
    input logic sb,
    output logic la1,
    output logic la0,
    output logic lb1,
    output logic lb0
    );
typedef enum logic [2:0] {S0, S1, S2, S3, S4, S5, S6, S7} statetype;
statetype [2:0] state, nextstate;

always_ff @ (posedge clk, posedge reset)
if (reset) state <= S0;
else state <= nextstate;

always_comb
case (state)
S0: if (sa) nextstate = S0;
else nextstate = S1;
S1: nextstate = S2;
S2: nextstate = S3;
S3: nextstate = S4;
S4: if (sb) nextstate = S4;
else nextstate = S5;
S5: nextstate = S6;
S6: nextstate = S7;
S7: nextstate = S0;
default: nextstate = S0;
endcase

assign la1= (state == S2 | state == S3 | state == S4 | state == S5 | state == S6);
assign la0= (state == S1 | state == S7);
assign lb1= (state == S0 | state == S1 | state == S2 | state == S6 | state == S7);
assign lb0= (state == S3 | state == S5);
endmodule

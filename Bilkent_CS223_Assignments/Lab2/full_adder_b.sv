`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11.10.2020 14:26:25
// Design Name: 
// Module Name: full_adder_b
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


module full_adder_b(
    input logic A,
    input logic B,
    input logic Cin,
    output logic S,
    output logic Cout
    );
    assign S = (A ^ B) ^ Cin;
	assign Cout = A & B | (A ^ B) & Cin;
endmodule

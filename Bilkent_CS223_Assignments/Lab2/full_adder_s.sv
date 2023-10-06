`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11.10.2020 14:29:32
// Design Name: 
// Module Name: full_adder_s
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


module full_adder_s(
		input logic A,B,Cin,
		output logic S,Cout );
   logic s1,c1,c2;
   xor(s1,A,B);
   xor(S,Cin,s1);
   and(c1,A,B);
   and(c2,s1,Cin);
   or(Cout,c1,c2);
endmodule
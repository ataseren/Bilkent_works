`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11.10.2020 15:32:04
// Design Name: 
// Module Name: two_bit_adder_s
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


module two_bit_adder_s( input logic A0, B0, C0in, A1, B1, output logic S0, S1, C1out);
    logic C0out;
	
	full_adder_b fab1( A0, B0, C0in, S0, C0out);
    full_adder_b fab2( A1, B1, C0out, S1, C1out);

endmodule
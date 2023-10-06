`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11.10.2020 15:05:35
// Design Name: 
// Module Name: full_subtractor_s
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


module full_subtractor_s(
    input logic X,
    input logic Y,
    input logic Bin,
    output logic D,
    output logic Bout
    );
    logic d1,b1,b2;
        xor( d1, X, Y);
        and( b1, ~X, Y);
        xor( D, d1, Bin);
        and( b2, ~d1, Bin);
        or( Bout, b2, b1);
endmodule

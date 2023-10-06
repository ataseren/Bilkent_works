`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 23.11.2020 01:48:10
// Design Name: 
// Module Name: top
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


module top(
    input logic clk,
    input logic reset,
    input logic sa,
    input logic sb,
    output logic ledA2,
    output logic ledA1,
    output logic ledA0,  
    output logic ledB2,
    output logic ledB1,
    output logic ledB0      
    );
    
    logic clk_div;
    logic la1, la0, lb1, lb0;
    
    clock_divider(clk, reset, clk_div);
    light_fsm(clk_div, reset, sa, sb, la1, la0, lb1, lb0);

    assign ledA2 =  (la1&~la0);
    assign ledA1 =  (la1&~la0)|(~la1&~la0);
    assign ledA0 =  (~la1&~la0)|(~la1&la0)|(la1&~la0);
    assign ledB2 =  (lb1&~lb0);
    assign ledB1 =  (lb1&~lb0)|(~lb1&~lb0);
    assign ledB0 =  (~lb1&~lb0)|(~lb1&lb0)|(lb1&~lb0);
    
    
    
endmodule

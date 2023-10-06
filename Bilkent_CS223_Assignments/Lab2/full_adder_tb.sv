`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 11.10.2020 14:33:14
// Design Name:
// Module Name: full_adder_tb
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


module full_adder_tb();
  logic A, B, Cin, S, Cout;
 
      full_adder_s test(A, B, Cin, S, Cout);
     
      initial begin
          #100; // wait
           
          A=0; B=0; Cin=0; #100;
          A=0; B=0; Cin=1; #100;
          A=0; B=1; Cin=0; #100;
          A=0; B=1; Cin=1; #100;
          A=1; B=0; Cin=0; #100;
          A=1; B=0; Cin=1; #100;
          A=1; B=1; Cin=0; #100;
          A=1; B=1; Cin=1; #100;

          end
     initial
          $monitor($time,"A=%d, B=%d, Cin=%d, S=%d, Cout=%d", A, B, Cin, S, Cout);
   endmodule
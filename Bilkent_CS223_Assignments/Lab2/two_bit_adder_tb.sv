`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 11.10.2020 15:37:29
// Design Name:
// Module Name: two_bit_adder_tb
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


module two_bit_adder_tb();
  logic A0, B0, C0in, A1, B1, S0, S1, C1out;
 
      two_bit_adder_s test(A0, B0, C0in, A1, B1, S0, S1, C1out);
     
      initial begin
          #100; // wait
           
          A0=0; B0=0; C0in=0; A1=0; B1=0; #100;
          A0=0; B0=0; C0in=0; A1=0; B1=1; #100;
          A0=0; B0=0; C0in=0; A1=1; B1=0; #100;
          A0=0; B0=0; C0in=0; A1=1; B1=1; #100;
          A0=0; B0=0; C0in=1; A1=0; B1=0; #100;
          A0=0; B0=0; C0in=1; A1=0; B1=1; #100;
          A0=0; B0=0; C0in=1; A1=1; B1=0; #100;
          A0=0; B0=0; C0in=1; A1=1; B1=1; #100;
          A0=0; B0=1; C0in=0; A1=0; B1=0; #100;
          A0=0; B0=1; C0in=0; A1=0; B1=1; #100;
          A0=0; B0=1; C0in=0; A1=1; B1=0; #100;
          A0=0; B0=1; C0in=0; A1=1; B1=1; #100;
          A0=0; B0=1; C0in=1; A1=0; B1=0; #100;
          A0=0; B0=1; C0in=1; A1=0; B1=1; #100;
          A0=0; B0=1; C0in=1; A1=1; B1=0; #100;
          A0=0; B0=1; C0in=1; A1=1; B1=1; #100;
          A0=1; B0=0; C0in=0; A1=0; B1=0; #100;
          A0=1; B0=0; C0in=0; A1=0; B1=1; #100;
          A0=1; B0=0; C0in=0; A1=1; B1=0; #100;
          A0=1; B0=0; C0in=0; A1=1; B1=1; #100;
          A0=1; B0=0; C0in=1; A1=0; B1=0; #100;
          A0=1; B0=0; C0in=1; A1=0; B1=1; #100;
          A0=1; B0=0; C0in=1; A1=1; B1=0; #100;
          A0=1; B0=0; C0in=1; A1=1; B1=1; #100;
          A0=1; B0=1; C0in=0; A1=0; B1=0; #100;
          A0=1; B0=1; C0in=0; A1=0; B1=1; #100;
          A0=1; B0=1; C0in=0; A1=1; B1=0; #100;
          A0=1; B0=1; C0in=0; A1=1; B1=1; #100;
          A0=1; B0=1; C0in=1; A1=0; B1=0; #100;
          A0=1; B0=1; C0in=1; A1=0; B1=1; #100;
          A0=1; B0=1; C0in=1; A1=1; B1=0; #100;
          A0=1; B0=1; C0in=1; A1=1; B1=1; #100;
          

          end
     initial
          $monitor($time,"A0=%d, B0=%d, C0in=%d, A1=%d, B1=%d, S0=%d, S1=%d, C1out=%d", A0, B0, C0in, A1, B1, S0, S1, C1out);
   endmodule
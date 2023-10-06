`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 11.10.2020 15:24:32
// Design Name:
// Module Name: full_subtractor_tb
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


module full_subtractor_tb();
  logic X, Y, Bin, D, Bout;
 
  // instantiate the adder module object
      full_subtractor_s test(X, Y, Bin, D, Bout);
     
      initial begin
          #100; // wait
           
          X=0; Y=0; Bin=0; #100;
          X=0; Y=0; Bin=1; #100;
          X=0; Y=1; Bin=0; #100;
          X=0; Y=1; Bin=1; #100;
          X=1; Y=0; Bin=0; #100;
          X=1; Y=0; Bin=1; #100;
          X=1; Y=1; Bin=0; #100;
          X=1; Y=1; Bin=1; #100;

          end
     initial
          $monitor($time,"X=%d, Y=%d, Bin=%d, D=%d, Bout=%d", X, Y, Bin, D, Bout);
   endmodule
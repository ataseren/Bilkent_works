`timescale 1ns / 1ps
module light_tb();
logic clk, reset, sa, sb, la1, la0, lb1, lb0;
light_fsm dut(.clk(clk), .reset(reset), .sa(sa), .sb(sb), .la1(la1), .la0(la0), .lb1(lb1), .lb0(lb0));

initial
    begin
        reset <= 1; #100;
        reset <= 0; sa <= 1; #100;
        sa <= 0; #100;
        #100;
        #100;
        #100;
        sb <= 1; #100;
        sb <= 0; #100;
        #100;
        #100;
        #100;
        
        
             
    end
always
    begin
        clk <= 1; #50;
        clk <= 0; #50;
    end
endmodule

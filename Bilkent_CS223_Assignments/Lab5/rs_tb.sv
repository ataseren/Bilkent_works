`timescale 1ns / 1ps
module rs_tb();

    logic clk, writeEnableRS, writeEnableMem;
    logic [3:0] writeAddress, readAddress1, readAddress2; 
    logic [7:0] writeData, readData1, readData2;
    logic [11:0] total;

    // instantiate reduceSum
	ReduceSum dut( clk, writeEnableRS, readData2, readAddress2, total);
	memory ram( clk, writeEnableMem, writeAddress, writeData, readAddress1, readAddress2,  readData1, readData2);
	
	always
        begin
        clk <= 1; #10;
        clk <= 0; #10;
    end
    
	initial 
	   begin
        writeEnableMem = 1;
        writeAddress = 0; writeData = 8'b00000001; #20;
        writeAddress = 1; writeData = 8'b00000010; #20;
        writeAddress = 2; writeData = 8'b00000011; #20;
        writeAddress = 3; writeData = 8'b00000100; #20;
        writeAddress = 4; writeData = 8'b00000101; #20;
        writeAddress = 5; writeData = 8'b00000110; #20;
        writeAddress = 6; writeData = 8'b00000111; #20;
        writeAddress = 7; writeData = 8'b00001000; #20;
        writeAddress = 8; writeData = 8'b00001001; #20;
        writeAddress = 9; writeData = 8'b00001010; #20;
        writeAddress = 10; writeData = 8'b00001011; #20;
        writeAddress = 11; writeData = 8'b00001100; #20;
        writeAddress = 12; writeData = 8'b00001101; #20;
        writeAddress = 13; writeData = 8'b00001110; #20;
        writeAddress = 14; writeData = 8'b00001111; #20;
        writeAddress = 15; writeData = 8'b00010000; #20;
        
        writeEnableMem = 0; writeEnableRS = 1; #20;       
    end
	
endmodule


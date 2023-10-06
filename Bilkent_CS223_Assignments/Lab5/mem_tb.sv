module mem_tb();

    logic clk, writeEnable;
    logic [3:0] writeAddress;  
    logic [7:0] writeData;
    logic [3:0] readAddress1, readAddress2;
    logic [7:0] readData1, readData2;
    
   memory dut (clk, writeEnable, writeAddress, writeData, readAddress1, readAddress2, readData1, readData2);
 
   initial
    begin
    writeEnable = 1;
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
        
        writeEnable = 0;
        
        readAddress1 = 0; readAddress2 = 0; #20;
        readAddress1 = 1; readAddress2 = 1; #20;
        readAddress1 = 2; readAddress2 = 2; #20;
        readAddress1 = 3; readAddress2 = 3; #20;
        readAddress1 = 4; readAddress2 = 4; #20;
        readAddress1 = 5; readAddress2 = 5; #20;
        readAddress1 = 6; readAddress2 = 6; #20;
        readAddress1 = 7; readAddress2 = 7; #20;
        readAddress1 = 8; readAddress2 = 8; #20;
        readAddress1 = 9; readAddress2 = 9; #20;
        readAddress1 = 10; readAddress2 = 10; #20;
        readAddress1 = 11; readAddress2 = 11; #20;
        readAddress1 = 12; readAddress2 = 12; #20;   
        readAddress1 = 13; readAddress2 = 13; #20;
        readAddress1 = 14; readAddress2 = 14; #20;
        readAddress1 = 15; readAddress2 = 15; #20;
     end
     
      always
        begin
            clk <= 1; #10;
            clk <= 0; #10;
        end
endmodule
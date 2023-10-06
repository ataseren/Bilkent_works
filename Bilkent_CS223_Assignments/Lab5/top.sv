module top( input logic clk, 
            input logic [3:0] writeAddress, 
            logic [3:0] debouncer, 
            logic [7:0] writeData,
            output logic [11:0] sum, 
            output logic [6:0]seg, 
            output logic dp, 
            output logic[3:0] an);
    
    logic [3:0] addressCnt;
    logic [3:0] sumAddress;
    logic displayP, displayN, enter, displayRS;
    logic [7:0] readData1;
    logic [7:0] readData2;
    
    debounce prevButton( clk, debouncer[3], displayP);
    debounce nextButton( clk, debouncer[2], displayN);
    debounce upButton( clk, debouncer[1], enter);
    debounce sumButton( clk, debouncer[0], displayRS);
    
    always @(posedge clk) 
    begin
        if (displayP)
            if (addressCnt == 4'b0000)
               addressCnt = 4'b1111;
            else
               addressCnt = addressCnt - 1;
               
         else if (displayN)
             if (addressCnt == 4'b1111)
                 addressCnt = 4'b0000;
             else
                 addressCnt = addressCnt + 1;
    end
    
    memory ram(clk, enter, writeAddress, writeData, addressCnt, sumAddress, readData1, readData2);
    SevSeg_4digit SevSeg1(clk, addressCnt, 0, readData1[7:4], readData1[3:0], seg, dp, an);
    ReduceSum total( clk, displayRS, readData2, sumAddress, sum);    
    
endmodule

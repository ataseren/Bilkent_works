module alu( 
input logic [7:0] a, 
input logic [7:0] b,
input logic alu_control,     
output logic [7:0] result1,
output logic result2);  

 always_comb
 begin 
      case(alu_control)  
      1'b0: result1 <= a + b; 
      1'b1: result2 <= (a == b); 
      endcase  
 end  

 endmodule  
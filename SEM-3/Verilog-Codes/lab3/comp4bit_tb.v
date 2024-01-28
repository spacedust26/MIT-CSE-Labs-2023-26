`timescale 1ns/1ns
`include "comp4bit.v"
module comp4bit_tb;
reg [3:0]a,b;
wire gt,eq,lt;
comp4bit uut(a,b,gt,eq,lt);
initial begin
  $dumpfile("comp4bit_tb.vcd");
  $dumpvars(0,comp4bit_tb);
  a=4'b0000; b=4'b1111; #20
  a=4'b0001; b=4'b1101; #20
  a=4'b0010; b=4'b0111; #20
  a=4'b0011; b=4'b1001; #20
  a=4'b1001; b=4'b0000; #20
  $display("Test complete");
end
endmodule
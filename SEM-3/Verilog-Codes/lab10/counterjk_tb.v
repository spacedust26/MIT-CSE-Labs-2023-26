`timescale 1ns/1ns
`include "counterjk.v"
module counterjk_tb;
reg clk,reset;
wire [2:0]w;
counterjk uut(clk,reset,w);
initial begin
  $dumpfile("counterjk_tb.vcd");
  $dumpvars(0,counterjk_tb);
  clk=0;
  forever #10 clk=~clk;
end
initial begin
  reset=1; #20;
  reset=0; #160;
  $display("Test complete");
  $finish;
end
endmodule

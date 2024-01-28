`timescale 1ns/1ns
`include "async.v"
module async_tb;
reg clk,reset;
wire [3:0]w;
async uut(clk,reset,w);
initial begin
  $dumpfile("async_tb.vcd");
  $dumpvars(0,async_tb);
  clk=0;
  forever #10 clk=~clk;
end
initial begin
  reset=1; #20
  reset=0; #160
  $display("Test complete");
  $finish;
end
endmodule
`timescale 1ns/1ns
`include "ring.v"
module ring_tb;
reg clk,reset;
wire [3:0]q;
ring uut(clk,reset,q);
initial begin
  $dumpfile("ring_tb.vcd");
  $dumpvars(0,ring_tb);
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
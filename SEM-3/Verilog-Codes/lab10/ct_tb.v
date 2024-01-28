`timescale 1ns/1ns
`include "ct.v"
module ct_tb;
reg clk,reset;
wire [3:0]w;
ct uut(clk,reset,w);
initial begin
  $dumpfile("ct_tb.vcd");
  $dumpvars(0,ct_tb);
  clk=0;
  forever #10 clk=~clk;
end
initial begin
  reset=1; #20;
  reset=0; #240;
  $display("Test complete");
  $finish;
end
endmodule

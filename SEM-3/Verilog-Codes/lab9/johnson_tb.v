`timescale 1ns/1ns
`include "johnson.v"
module johnson_tb;
reg clk,reset;
wire [3:0]w;
johnson uut(clk,reset,w);
initial begin
  $dumpfile("johnson_tb.vcd");
  $dumpvars(0,johnson_tb);
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
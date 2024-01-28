`timescale 1ns/1ns
`include "bcd.v"
module bcd_tb;
reg clk,reset;
wire [7:0]w;
bcd uut(clk,reset,w);
initial begin
  $dumpfile("bcd_tb.vcd");
  $dumpvars(0,bcd_tb);
  clk=1'b0;
  forever #10 clk=~clk;
end
initial begin
  reset=1'b1; #20
  reset=1'b0; #400
  $display("Test complete");
  $finish;
end
endmodule
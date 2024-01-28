`timescale 1ns/1ns
`include "l8a1.v"
module l8a1_tb;
reg e,x,clk,reset;
wire [1:0]w;
l8a1 uut(e,x,clk,reset,w);
initial begin
  $dumpfile("l8a1_tb.vcd");
  $dumpvars(0,l8a1_tb);
  clk=0;
  forever #10 clk=~clk;
end
initial begin
  e=0; x=0; reset=1; #20
  e=0; x=0; reset=0; #20
  e=0; x=1; reset=0; #20
  e=1; x=1; reset=0; #20
  e=1; x=1; reset=0; #20
  e=0; x=0; reset=0; #20
  e=0; x=1; reset=0; #20
  $display("Test complete");
  $finish;
end
endmodule
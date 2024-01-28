`timescale 1ns/1ns
`include "last.v"
module last_tb;
reg x,clk,reset;
wire [2:0]w;
last uut(x,clk,reset,w);
initial begin
  $dumpfile("last_tb.vcd");
  $dumpvars(0,last_tb);
  clk=0;
  forever #10 clk=~clk;
end
initial begin
  x=0; reset=1; #20;
  x=1; reset=0; #20;
  x=0; reset=0; #20;
  x=1; reset=0; #20;
  x=0; reset=0; #20;
  x=1; reset=0; #20;
  x=0; reset=0; #20;
  $display("Test complete");
  $finish;
end
endmodule

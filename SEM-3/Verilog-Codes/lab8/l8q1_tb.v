`timescale 1ns/1ns
`include "l8q1.v"
module l8q1_tb;
reg x,clk,reset;
wire y;
wire [3:1]a;
l8q1 uut(x,clk,reset,y,a);
initial begin
  $dumpfile("l8q1_tb.vcd");
  $dumpvars(0,l8q1_tb);
  clk=1'b0;
  forever #10 clk=~clk;
end
initial begin
  x=1'b1; reset=1'b1; #20;
  x=1'b0; reset=1'b0; #20;
  x=1'b1; #20;
  x=1'b0; #20;
  x=1'b1; #20;
  x=1'b0; #20;
  x=1'b1; #20;
  $display("Test complete");
  $finish;
end
endmodule
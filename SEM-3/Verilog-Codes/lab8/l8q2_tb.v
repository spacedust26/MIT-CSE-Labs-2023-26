`timescale 1ns/1ns
`include "l8q2.v"
module l8q2_tb;
reg x,clk,reset;
wire [1:0]a;
l8q2 uut(x,clk,reset,a);
initial begin
  $dumpfile("l8q2_tb.vcd");
  $dumpvars(0,l8q2_tb);
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
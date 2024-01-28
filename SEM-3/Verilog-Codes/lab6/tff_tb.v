`timescale 1ns/1ns
`include "tff.v"
module tff_tb;
reg t,clk,reset;
wire q;
tff uut(t,clk,reset,q);
initial begin
  $dumpfile("tff_tb.vcd");
  $dumpvars(0,tff_tb);
  clk=1'b0;
  forever #20 clk=~clk;
end
initial begin
  t=1'b1; reset=0; #20
  t=1'b0; reset=1; #20
  t=1'b1; reset=1; #20
  t=1'b0; reset=1; #20
  $display("Test complete");
  $finish;
end
endmodule
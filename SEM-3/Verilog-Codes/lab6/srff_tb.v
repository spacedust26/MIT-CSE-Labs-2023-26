`timescale 1ns/1ns
`include "srff.v"
module srff_tb;
reg s,r,clk,reset;
wire q;
srff uut(s,r,clk,reset,q);
initial begin
  $dumpfile("srff_tb.vcd");
  $dumpvars(0,srff_tb);
  clk=1'b0;
  forever #10 clk=~clk;
end
initial begin
  s=1'b1; r=1'b0; reset=0; #10;
  s=1'b0; r=1'b1; reset=1; #10;
  s=1'b0; r=1'b0; reset=1; #10;
  s=1'b1; r=1'b0; reset=1; #10;
  s=1'b1; r=1'b0; reset=1; #10;
  $display("Test complete");
  $finish;
end
endmodule
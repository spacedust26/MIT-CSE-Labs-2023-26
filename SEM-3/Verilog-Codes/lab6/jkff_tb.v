`timescale 1ns/1ns
`include "jkff.v"
module jkff_tb;
reg j,k,clk,reset;
wire q;
jkff uut(j,k,clk,reset,q);
initial begin
  $dumpfile("jkff_tb.vcd");
  $dumpvars(0,jkff_tb);
  clk=1'b0;
  forever #10 clk=~clk;
end
initial begin
  j=1'b0; k=1'b1; reset=0; #10;
  j=1'b1; k=1'b0; reset=0; #10;
  j=1'b0; k=1'b0; reset=0; #10;
  j=1'b1; k=1'b0; reset=0; #10;
  j=1'b1; k=1'b1; reset=0; #10;
  $display("Test complete");
  $finish;
end
endmodule
`timescale 1ns/1ns
`include "dff.v"
module dff_tb;
reg d,clk,reset;
wire q;
dff uut(d,clk,reset,q);
initial begin
  $dumpfile("dff_tb.vcd");
  $dumpvars(0,dff_tb);
  clk=1'b0;
  forever #20 clk=~clk;
  end
initial begin
  d=1'b1; reset=1; #20
  d=1'b1; reset=0; #20
  d=1'b0; reset=0; #20
  d=1'b0; reset=1; #20
  $display("Test complete");
  $finish;
end
endmodule
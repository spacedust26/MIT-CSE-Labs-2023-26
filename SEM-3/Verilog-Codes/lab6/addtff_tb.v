`timescale 1ns/1ns
`include "addtff.v"
module addtff_tb;
reg t,clk,reset;
wire q;
addtff uut(t,clk,reset,q);
initial begin
  $dumpfile("addtff_tb.vcd");
  $dumpvars(0,addtff_tb);
  clk=0;
  forever #10 clk=~clk;
end
initial begin
  t=0; reset =1; #20;
  t=1; reset =0; #20;
  t=1; reset =0; #20;
  t=0; reset =0; #20;
  t=1; reset =0; #20;
  $display("Test complete");
  $finish;
end
endmodule
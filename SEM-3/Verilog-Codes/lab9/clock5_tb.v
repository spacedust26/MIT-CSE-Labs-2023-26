`timescale 1ns/1ns
`include "clock5.v"
module clock5_tb;
reg clk,reset;
wire y;
wire [2:0]a;
clock5 uut(clk,reset,a,y);
initial begin
  $dumpfile("clock5_tb.vcd");
  $dumpvars(0,clock5_tb);
  clk=0;
  forever #20 clk=~clk;
end
initial begin
  reset=1; #20;
  reset=0; #200;
  $display("Test complete");
  $finish;
end
endmodule
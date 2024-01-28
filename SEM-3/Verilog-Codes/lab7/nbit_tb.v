`timescale 1ns/1ns
`include "nbit.v"
module nbit_tb;
reg [3:0]i;
reg clk;
wire [3:0]o;
nbit uut(i,clk,o);
initial begin
  $dumpfile("nbit_tb.vcd");
  $dumpvars(0,nbit_tb);
  clk=1'b0;
  forever #10 clk=~clk;
end
initial begin
  i=4'b1000; #20;
  i=4'b0111; #20;
  i=4'b1101; #20;
  i=4'b0101; #20;
  $display("Test complete");
  $finish;
end
endmodule
`timescale 1ns/1ns
`include "jkff.v"
module jkff_tb;
reg clk,j,k,reset;
wire q;
jkff j1(j,k,clk,q,reset);
initial begin
$dumpfile("jkff_tb.vcd");
$dumpvars(0,jkff_tb);
clk=1'b0;
forever #20 clk=~clk;
end
initial begin
j=1'b0;k=1'b0;reset=1'b1;#20;
j=1'b1;k=1'b0;reset=1'b0;#20;
j=1'b1;k=1'b0;reset=1'b0;#20;
j=1'b0;k=1'b1;reset=1'b0;#20;
j=1'b1;k=1'b1;reset=1'b0;#20;
$display("Test Complete");
$finish;
end
endmodule
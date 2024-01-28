`timescale 1ns/1ns
`include "ft1.v"
module ft1_tb;
reg [3:0]i;
reg [1:0]s;
reg si,clk;
wire [3:0]a;
ft1 uut(i,s,si,clk,a);
initial begin
  $dumpfile("ft1_tb.vcd");
  $dumpvars(0,ft1_tb);
  clk=1'b0;
  forever #10 clk=~clk;
end
initial begin
  i=4'b1010; s=2'b01; si=1'b1; #20
  i=4'b1010; s=2'b00; si=1'b1; #20
  i=4'b1010; s=2'b01; si=1'b1; #20
  i=4'b1010; s=2'b10; si=1'b1; #20
  i=4'b1010; s=2'b11; si=1'b1; #20
  $display("Test complete");
  $finish;
end
endmodule
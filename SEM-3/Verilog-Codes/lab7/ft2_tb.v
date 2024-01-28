`timescale 1ns/1ns
`include "ft2.v"
module ft2_tb;
reg [3:0]i;
reg [1:0]s;
reg si,clk;
wire [3:0]a;
ft2 uut(i,si,s,clk,a);
initial begin
  $dumpfile("ft2_tb.vcd");
  $dumpvars(0, ft2_tb);
  clk=1'b0;
  forever #10 clk =~clk;
end
initial begin
  i=4'b1010; si=1'b0; s= 2'b01; #20
  i=4'b1010; si=1'b0; s= 2'b00; #20
  i=4'b1010; si=1'b0; s= 2'b10; #20
  i=4'b1010; si=1'b0; s= 2'b11; #20
  $display("Test complete");
  $finish;
end
endmodule

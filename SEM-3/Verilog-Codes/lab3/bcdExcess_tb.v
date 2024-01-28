`timescale 1ns/1ns
`include "bcdExcess.v"
module bcdExcess_tb;
reg [3:0]a;
wire [3:0]b;
bcdExcess uut(a,b);
initial begin
  $dumpfile("bcdExcess_tb.vcd");
  $dumpvars(0,bcdExcess_tb);
  a=4'b0000; #20
  a=4'b0001; #20
  a=4'b0010; #20
  a=4'b0011; #20
  a=4'b1001; #20
  $display("Test complete");
end
endmodule
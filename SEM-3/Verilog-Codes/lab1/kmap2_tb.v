`timescale 1ns/1ns
`include "kmap2.v"
module kmap2_tb;
reg a,b,c,d;
wire f;
kmap2 uut(a,b,c,d,f);
initial begin
  $dumpfile("kmap2_tb.vcd");
  $dumpvars(0,kmap2_tb);
  a=0; b=0; c=0; d=0; #20
  a=0; b=0; c=0; d=1; #20
  a=0; b=0; c=1; d=0; #20
  a=0; b=0; c=1; d=1; #20
  a=0; b=1; c=0; d=0; #20
  a=0; b=1; c=0; d=1; #20
  a=0; b=1; c=1; d=0; #20
  a=0; b=1; c=1; d=1; #20
  a=1; b=0; c=0; d=0; #20
  a=1; b=0; c=0; d=1; #20
  a=1; b=0; c=1; d=0; #20
  a=1; b=0; c=1; d=1; #20
  a=1; b=1; c=0; d=0; #20
  a=1; b=1; c=0; d=1; #20
  a=1; b=1; c=1; d=0; #20
  a=1; b=1; c=1; d=1; #20
  $display("Test complete");
end
endmodule


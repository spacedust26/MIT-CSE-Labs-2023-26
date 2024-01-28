`timescale 1ns/1ns
`include "f2.v"
module f2_tb;
reg a,b,c;
wire f;
f2 uut(a,b,c,f);
initial begin
  $dumpfile("f2_tb.vcd");
  $dumpvars(0,f2_tb);
  a=0; b=0; c=0; #20
  a=0; b=0; c=1; #20
  a=0; b=1; c=0; #20
  a=0; b=1; c=1; #20
  a=1; b=0; c=0; #20
  a=1; b=0; c=1; #20
  a=1; b=1; c=0; #20
  a=1; b=1; c=1; #20
  $display("Test complete");
end
endmodule


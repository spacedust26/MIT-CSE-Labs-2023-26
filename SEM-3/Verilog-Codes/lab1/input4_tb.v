`timescale 1ns/1ns
`include "input4.v"
module input4_tb;
reg x1,x2,x3,x4;
wire f;
input4 uut(x1,x2,x3,x4,f);
initial begin
  $dumpfile("input4_tb.vcd");
  $dumpvars(0,input4_tb);
  x1=0; x2=0; x3=0; x4=0; #20
  x1=0; x2=0; x3=0; x4=1; #20
  x1=0; x2=0; x3=1; x4=0; #20
  x1=0; x2=0; x3=1; x4=1; #20
  x1=0; x2=1; x3=0; x4=0; #20
  x1=0; x2=1; x3=0; x4=1; #20
  x1=0; x2=1; x3=1; x4=0; #20
  x1=0; x2=1; x3=1; x4=1; #20
  x1=1; x2=0; x3=0; x4=0; #20
  x1=1; x2=0; x3=0; x4=1; #20
  x1=1; x2=0; x3=1; x4=0; #20
  x1=1; x2=0; x3=1; x4=1; #20
  x1=1; x2=1; x3=0; x4=0; #20
  x1=1; x2=1; x3=0; x4=1; #20
  x1=1; x2=1; x3=1; x4=0; #20
  x1=1; x2=1; x3=1; x4=1; #20
  $display("Test complete");
end
endmodule

`timescale 1ns/1ns
`include "faop.v"
module faop_tb;
reg a,b;
wire andGate,nandGate,orGate,norGate,xorGate,xnorGate;
faop uut(a,b,andGate,nandGate,orGate,norGate,xorGate,xnorGate);
initial begin
  $dumpfile("faop_tb.vcd");
  $dumpvars(0,faop_tb);
  a=1'b0; b=1'b0; #20
  a=1'b0; b=1'b1; #20
  a=1'b1; b=1'b0; #20
  a=1'b1; b=1'b1; #20
  $display("Test complete");
end
endmodule
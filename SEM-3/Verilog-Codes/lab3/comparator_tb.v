`timescale 1ns/1ns
`include "comparator.v"
module comparator_tb;
reg [2:0]a,b;
wire l,e,g;
comparator uut(a,b,l,e,g);
initial begin
  $dumpfile("comparator_tb.vcd");
  $dumpvars(0,comparator_tb);
  a=3'b100; b=3'b001; #20;
  a=3'b100; b=3'b111; #20;
  a=3'b100; b=3'b100; #20;
  $display("Test complete");
end
endmodule
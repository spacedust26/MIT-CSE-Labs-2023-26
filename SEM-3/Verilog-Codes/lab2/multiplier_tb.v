`timescale 1ns/1ns
`include "multiplier.v"
module multiplier_tb;
reg [2:0]m,q;
wire [5:0]p;
multiplier uut(m,q,p);
initial begin
  $dumpfile("multiplier_tb.vcd");
  $dumpvars(0,multiplier_tb);
  m=3'b101; q=3'b011; #20
  m=3'b111; q=3'b111; #20
  m=3'b110; q=3'b001; #20
  m=3'b101; q=3'b000; #20
  $display("Test complete");
end
endmodule
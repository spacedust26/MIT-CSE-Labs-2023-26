`timescale 1ns/1ns
`include "gtob.v"
module gtob_tb;
reg [3:0]g;
wire [3:0]b;
gtob uut(g,b);
initial begin
  $dumpfile("gtob_tb.vcd");
  $dumpvars(0,gtob_tb);
  g=4'b1010; #20
  g=4'b0011; #20
  g=4'b1111; #20
  g=4'b0110; #20
  $display("Test complete");
end
endmodule
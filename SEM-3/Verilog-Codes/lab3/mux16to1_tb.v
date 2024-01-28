`timescale 1ns/1ns
`include "mux16to1.v"
module mux16to1_tb;
reg [15:0]w;
reg [3:0]s;
wire y;
mux16to1 uut(w,s,y);
initial begin
  $dumpfile("mux16to1_tb.vcd");
  $dumpvars(0, mux16to1_tb);
  w=16'b0101011101110100; s=4'b0011; #20;
  w=16'b0111010011010111; s=4'b0100; #20;
  w=16'b1101011111010111; s=4'b1011; #20;
  w=16'b0100011111010111; s=4'b1111; #20;
  $display("Test complete");
end
endmodule
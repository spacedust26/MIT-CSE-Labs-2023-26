`timescale 1ns/1ns
`include "mux4to1.v"
module mux4to1_tb;
reg [3:0]w;
reg [1:0]s;
wire y;
mux4to1 uut(w,s,y);
initial begin
  $dumpfile("mux4to1_tb.vcd");
  $dumpvars(0, mux4to1_tb);
  w=4'b0101; s=2'b00; #20;
  w=4'b0111; s=2'b01; #20;
  w=4'b1101; s=2'b10; #20;
  w=4'b0100; s=2'b11; #20;
  $display("Test complete");
end
endmodule
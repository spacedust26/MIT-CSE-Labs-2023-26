`timescale 1ns/1ns
`include "priority16to4.v"
module priority16to4_tb;
reg [15:0]w;
wire [3:0]y;
wire z;
priority16to4 uut(w,y,z);
initial begin
  $dumpfile("priority16to4_tb.vcd");
  $dumpvars(0,priority16to4_tb);
  w=16'b000011111010; #20
  w=16'b001000001111; #20
  w=16'b011010101101; #20
  w=16'b110001010110; #20
  w=16'b000000000001; #20
  $display("Test complete");
end
endmodule
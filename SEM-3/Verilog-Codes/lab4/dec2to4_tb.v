`timescale 1ns/1ns
`include "dec2to4.v"
module dec2to4_tb;
reg en;
reg [1:0]w;
wire [0:3]y;
dec2to4 uut(en,w,y);
initial begin
  $dumpfile("dec2to4_tb.vcd");
  $dumpvars(0,dec2to4_tb);
  en=1; w=2'b00; #20
  en=1; w=2'b01; #20
  en=1; w=2'b10; #20
  en=1; w=2'b11; #20
  en=0; w=2'b00; #20
  $display("Test complete");
end
endmodule
`timescale 1ns/1ns
`include "dec16.v"
module dec16_tb;
reg en;
reg [3:0]w;
wire [0:15]y;
dec16 uut(en,w,y);
initial begin
  $dumpfile("dec16_tb.vcd");
  $dumpvars(0,dec16_tb);
  en=0; w=4'b0010; #20
  en=0; w=4'b0111; #20
  en=0; w=4'b1000; #20
  en=0; w=4'b1110; #20
  en=1; w=4'b0010; #20
  $display("Test complete");
end
endmodule
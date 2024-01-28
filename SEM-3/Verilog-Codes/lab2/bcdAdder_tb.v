`timescale 1ns/1ns
`include "bcdAdder.v"
module bcdAdder_tb;
reg [3:0]x,y;
reg cin;
wire [3:0]s;
wire cout;
bcdAdder uut(cin,x,y,cout,s);
initial begin
  $dumpfile("bcdAdder_tb.vcd");
  $dumpvars(0,bcdAdder_tb);
  cin=0; x=4'b0100; y=4'b0011; #20
  cin=0; x=4'b0111; y=4'b0101; #20
  cin=0; x=4'b0110; y=4'b1001; #20
  cin=0; x=4'b1000; y=4'b0111; #20
  $display("Test complete");
end
endmodule
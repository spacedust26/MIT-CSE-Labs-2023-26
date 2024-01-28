`timescale 1ns/1ns
`include "addSub4bit.v"
module addSub4bit_tb;
reg cin;
reg [3:0]x,y;
wire cout;
wire [3:0]s;
addSub4bit uut(cin,x,y,cout,s);
initial begin
  $dumpfile("addSub4bit_tb.vcd");
  $dumpvars(0,addSub4bit_tb);
  cin=0; x=4'b0101; y=4'b0010; #20
  cin=0; x=4'b1111; y=4'b0011; #20
  cin=1; x=4'b0101; y=4'b0010; #20
  cin=1; x=4'b1111; y=4'b0011; #20
  $display("Test complete");
end
endmodule
`timescale 1ns/1ns
`include "fullAdder.v"
module fullAdder_tb;
reg cin,x,y;
wire cout,s;
fullAdder uut(cin,x,y,cout,s);
initial begin
  $dumpfile("fullAdder_tb.vcd");
  $dumpvars(0,fullAdder_tb);
  cin=0; x=0; y=0; #20;
  cin=0; x=0; y=1; #20;
  cin=0; x=1; y=0; #20;
  cin=0; x=1; y=1; #20;
  cin=1; x=0; y=0; #20;
  cin=1; x=0; y=1; #20;
  cin=1; x=1; y=0; #20;
  cin=1; x=1; y=1; #20;
  $display("Test complete");
end
endmodule
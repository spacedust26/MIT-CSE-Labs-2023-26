`timescale 1ns/1ns
`include "nbitShift.v"
module nbitShift_tb;
parameter n =6;
reg si,clk;
wire [n-1:0]so;
nbitShift uut(si,clk,so);
initial begin
  $dumpfile("nbitShift_tb.vcd");
  $dumpvars(0,nbitShift_tb);
  clk=1'b0;
  forever #10 clk=~clk;
end
initial begin
  si=1'b1; #20;
  si=1'b0; #20;
  si=1'b1; #20;
  si=1'b0; #20;
  si=1'b1; #20;
  si=1'b0; #20;
  si=1'bx; #120;
  $display("Test complete");
  $finish;
end
endmodule
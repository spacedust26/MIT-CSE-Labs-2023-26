`timescale 1ns/1ns
`include "shift.v"
module shift_tb;
reg si,clk;
wire [5:0]s;
wire so;
shift uut(si,clk,s,so);
initial begin
  $dumpfile("shift_tb.vcd");
  $dumpvars(0,shift_tb);
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
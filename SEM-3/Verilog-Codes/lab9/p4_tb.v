`timescale 1ns/1ns
`include "p4.v"
module p4_tb;
reg clk,reset;
wire [7:0]Q;
p4 uut(clk, reset, Q);
initial begin
    clk = 0;
    forever begin
        #10 clk = ~clk;
    end
end
initial begin
    $dumpfile("p4_tb.vcd");
    $dumpvars(0, p4_tb);
    reset = 0;#20
    reset = 1;#1000

    $display("Test Complete");
    $finish;
end
endmodule
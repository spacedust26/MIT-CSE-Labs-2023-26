`timescale 1ns/1ns
`include "mux4to1.v"
module mux4to1_tb;
reg [3:0]w;
wire f;
mux4to1 uut(w,f);
initial begin
    $dumpfile("mux4to1_tb.vcd");
    $dumpvars(0,mux4to1_tb);
    w=4'b0000; #20
    w=4'b0110; #20
    w=4'b1111; #20
    w=4'b0010; #20
    $display("Test complete");
end
endmodule
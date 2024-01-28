module nbit(i,clk,o);
parameter n = 4;
input [n-1:0]i;
input clk;
output reg [n-1:0]o;
always @(posedge clk)
begin
  o<=i;
end
endmodule

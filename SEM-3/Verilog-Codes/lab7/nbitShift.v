module nbitShift(si,clk,so);
parameter n = 6;
input si,clk;
output reg [n-1:0]so;
integer i;
always @(posedge clk)
begin
so[n-1]<=si;
for(i=n-2;i>=0;i=i-1)
begin
  so[i]<=so[i+1];
end
end
endmodule


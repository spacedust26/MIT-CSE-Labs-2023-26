module jkff(j,k,clk,q,reset);
input j,k,reset,clk;
output reg q;
always @(posedge clk)
begin
if(reset)
q<=0;
else
q<=((j&~q)|(~k&q));
end
endmodule
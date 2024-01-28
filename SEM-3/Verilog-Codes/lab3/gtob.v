module gtob(g,b);
parameter n=4;
input [(n-1):0]g;
output reg [(n-1):0]b;
integer i=0;
always @(g)
begin
b[n-1]=g[n-1];
for(i=n-2;i>=0;i=i-1)
begin
  b[i] = (g[i] ^ b[i+1]);
end
end
endmodule
 


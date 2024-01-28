module tff(t,clk,reset,q);
input t,clk,reset;
output reg q;
always @(posedge clk or posedge reset)
begin
if(reset) q<=1'b0;
else begin
  if(t==1'b0) q<=q;
  else q<=~q;
end
end
endmodule

module l8q2(x,clk,reset,a);
input x,clk,reset;
output [1:0]a;
tff stg0(((a[0]&~x)|(~a[1]&a[0])),clk,reset,a[1]);
tff stg1(((a[1]&~x)|(~a[0]&~x)|(~a[1]&a[0]&x)),clk,reset,a[0]);
endmodule
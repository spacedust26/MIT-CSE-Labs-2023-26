module dff(d,clk,reset,q);
input d,clk,reset;
output reg q;
always @(posedge clk or posedge reset)
begin
if(reset) q<=1'b0;
else q<=d;
end
endmodule

module l8q1(x,clk,reset,y,a);
input x,clk,reset;
output y;
output [3:1]a;
dff stg0(((a[3]&~x)|(a[2]&~a[1]&~x)),clk,reset,a[3]);
dff stg1(((a[3]&x)|(~a[3]&~a[2]&~x)|(a[1]&~x)),clk,reset,a[2]);
dff stg2(((a[2]&a[1])|(~a[3]&~a[2]&~a[1])),clk,reset,a[1]);
assign y = (a[2]&~x)|(a[3]&x)|(a[2]&a[1]);
endmodule
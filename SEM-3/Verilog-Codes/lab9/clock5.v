module dff(d,clk,reset,q);
input d,clk,reset;
output reg q;
always @(posedge clk or posedge reset)
begin
  if(reset) q<=0;
  else q<=d;
end
endmodule 

module clock5(clk,reset,a,y);
input clk,reset;
output y;
output [2:0]a;
dff stg0(((a[2]&~a[0])|(a[2]&~a[1])|(~a[2]&a[1]&a[0])),clk,reset,a[2]);
dff stg1((a[1]^a[0]),clk,reset,a[1]);
dff stg2((~a[0]),clk,reset,a[0]);
assign y = a[2]&~a[1]&~a[0];
endmodule
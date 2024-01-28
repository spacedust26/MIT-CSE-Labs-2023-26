module dff(d,clk,reset,q);
input d,clk,reset;
output reg q;
always @(posedge clk or posedge reset)
begin
  if(reset) q<=0;
  else q<=d;
end
endmodule

module johnson(clk,reset,w);
input clk,reset;
output [3:0]w;
dff stg0(~w[0],clk,reset,w[3]);
dff stg1(w[3],clk,reset,w[2]);
dff stg2(w[2],clk,reset,w[1]);
dff stg3(w[1],clk,reset,w[0]);
endmodule

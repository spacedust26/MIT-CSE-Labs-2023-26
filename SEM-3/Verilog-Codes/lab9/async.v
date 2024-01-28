module tff(t,clk,reset,q);
input t,clk,reset;
output reg q;
always @(negedge clk or posedge reset)
begin
  if(reset) q<=1'b0;
  else
    begin
      if(t==1'b0) q<=q;
      else q<=~q;
    end
end
endmodule

module async(clk,reset,w);
input clk,reset;
output [3:0]w;
tff stg0(1'b1,clk,reset,w[3]);
tff stg1(1'b1,w[3],reset,w[2]);
tff stg2(1'b1,w[2],reset,w[1]);
tff stg3(1'b1,w[1],reset,w[0]);
endmodule
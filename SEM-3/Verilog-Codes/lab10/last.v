module tff(t,clk,reset,q);
input t,clk,reset;
output reg q;
always @(posedge clk or posedge reset)
begin
  if(reset) q<=0;
  else
    begin
      if(t==0) q<=q;
      else q<=~q;
    end
end
endmodule

module last(x,clk,reset,w);
input x,clk,reset;
output [2:0]w;
tff stg0(((w[0]&~x)|(~w[1]&x)|(w[2]&w[1]&~x)),clk,reset,w[2]);
tff stg1(((w[0]&~x)|(~w[0]&x)|(w[2])|(~w[1])),clk,reset,w[1]);
tff stg2(((w[0])|(w[2]&~w[1]&x)|(~w[2]&w[1]&~x)),clk,reset,w[0]);
endmodule 
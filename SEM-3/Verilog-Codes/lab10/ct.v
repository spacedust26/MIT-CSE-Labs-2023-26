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

module ct(clk,reset,w);
input clk,reset;
output [3:0]w;
tff stg0((w[2]&w[1]),clk,reset,w[3]);
tff stg1((w[1]|(w[3]&~w[2]&w[0])|(w[3]&w[2]&~w[0])),clk,reset,w[2]);
tff stg2((w[1]|(w[3]&w[2])|(w[2]&~w[0])|(~w[3]&~w[2]&w[0])),clk,reset,w[1]);
tff stg3(((w[3]&~w[0])|(w[2]&w[1])|(~w[2]&~w[1])|(~w[3]&~w[2])|(~w[3]&~w[1]&w[0])),clk,reset,w[0]);
endmodule
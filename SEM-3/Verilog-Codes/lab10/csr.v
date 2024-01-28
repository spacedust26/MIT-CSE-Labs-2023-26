module srff(s,r,clk,reset,q);
input s,r,clk,reset;
output reg q;
always @(posedge clk or posedge reset)
begin
  if(reset) q<=0;
  else
    begin
      if(s==0 && r==0) q<=q;
      else if(s==0 && r==1) q<=0;
      else if (s==1 && r==0) q<=1;
    end
end
endmodule

module csr(clk,reset,w);
input clk,reset;
output [2:0]w;
srff stg0((~w[1]&~w[0]),(w[2]&~w[1]),clk,reset,w[2]);
srff stg1((~w[2]&~w[1]),((w[2]&~w[0])|(~w[2]&w[1]&w[0])),clk,reset,w[1]);
srff stg2(~w[0],((~w[2]&w[0])|(w[1]&w[0])),clk,reset,w[0]);
endmodule
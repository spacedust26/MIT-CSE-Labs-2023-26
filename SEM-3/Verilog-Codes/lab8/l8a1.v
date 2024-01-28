module jkff(j,k,clk,reset,q);
input j,k,clk,reset;
output reg q;
always @(posedge clk or posedge reset)
begin
  if(reset) q<=0;
  else begin
    if(j==0 && k==0) q<=q;
    else if(j==0 && k==1) q<=0;
    else if (j==1 && k==0) q<=1;
    else if (j==1 && k==1) q<=~q;
  end
end
endmodule

module l8a1(e,x,clk,reset,w);
input e,x,clk,reset;
output [1:0]w;
jkff stg0(((w[0]&e&x)|(~w[0]&e&~x)),((w[0]&e&x)|(~w[0]&e&~x)),clk,reset,w[1]);
jkff stg1(e,e,clk,reset,w[0]);
endmodule
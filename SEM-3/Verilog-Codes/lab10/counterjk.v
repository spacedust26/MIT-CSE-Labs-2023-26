module jkff(j,k,clk,reset,q);
input j,k,clk,reset;
output reg q;
always @(posedge clk or posedge reset)
  begin
    if(reset)q<=0;
    else
      begin
        if(j==0 && k==0) q<=q;
        else if (j==0 && k==1) q<=0;
        else if (j==1 && k==0) q<=1;
        else if (j==1 && k==1) q<=~q;
      end
  end
endmodule

module counterjk(clk,reset,w);
input clk,reset;
output [2:0]w;
jkff stg0(w[1],(w[1]&w[0]),clk,reset,w[2]); 
jkff stg1(w[0],(w[0]|~w[2]),clk,reset,w[1]); 
jkff stg2((w[2]|~w[1]),1'b1,clk,reset,w[0]);
endmodule 
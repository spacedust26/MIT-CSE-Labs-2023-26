module dff(d,clk,q);
input d,clk;
output reg q;
always @(posedge clk)
q<=d;
endmodule

module shift(si,clk,s,so);
input si,clk;
output [5:0]s;
output so;
dff stg0(si,clk,s[5]);
dff stg1(s[5],clk,s[4]);
dff stg2(s[4],clk,s[3]);
dff stg3(s[3],clk,s[2]);
dff stg4(s[2],clk,s[1]);
dff stg5(s[1],clk,s[0]);
assign so=s[0];
endmodule



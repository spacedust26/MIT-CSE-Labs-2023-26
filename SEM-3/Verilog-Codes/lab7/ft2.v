module mux4to1(w,s,f);
input [3:0]w;
input [1:0]s;
output reg f;
always @(w or s)
case(s)
0: f= w[0];
1: f= w[1];
2: f= w[2];
3: f= w[3];
endcase
endmodule 

module dff(d,clk,q);
input d,clk;
output reg q;
always @(posedge clk)
q<=d;
endmodule

module ft2(i,si,s,clk,a);
input [3:0]i;
input [1:0]s;
input si,clk;
output [3:0]a;
wire [3:0]m3,m2,m1,m0,d;
assign m3={a[3],~a[3],i[3],a[2]};
assign m2={a[2],~a[2],i[2],a[1]};
assign m1={a[1],~a[1],i[1],a[0]};
assign m0={a[0],~a[0],i[0],si};
mux4to1 stg0(m3,s,d[3]);
mux4to1 stg1(m2,s,d[2]);
mux4to1 stg2(m1,s,d[1]);
mux4to1 stg3(m0,s,d[0]);
dff stg4(d[3],clk,a[3]);
dff stg5(d[2],clk,a[2]);
dff stg6(d[1],clk,a[1]);
dff stg7(d[0],clk,a[0]);
endmodule 
module mux41(w,s,f);
input [3:0]w;
input [1:0]s;
output reg f;
always @(w,s)
case(s)
0: f= w[0];
1: f= w[1];
2: f= w[2];
3: f= w[3];
endcase
endmodule

module mux4to1(w,f);
input [3:0]w;
output f;
wire [3:0]n;
assign n[0] = ~(w[1]&w[0]);
assign n[1] = ~w[0];
assign n[2] = ~w[1] & w[0];
assign n[3] = ~w[0];
mux41 stg0(n,{w[3],w[2]},f);
endmodule
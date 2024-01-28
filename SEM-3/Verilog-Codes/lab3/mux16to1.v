module mux8to1(w,s,y);
input [7:0]w;
input [2:0]s;
output reg y;
always @(w,s)
 case(s)
  0: y=w[0];
  1: y=w[1];
  2: y=w[2];
  3: y=w[3];
  4: y=w[4];
  5: y=w[5];
  6: y=w[6];
  7: y=w[7];
 endcase
endmodule

module mux2to1(w,s,y);
input [1:0]w;
input s;
output reg y;
always @(w,s)
begin
  if(s==0) y=w[0];
  else y=w[1];
end
endmodule

module mux16to1(w,s,y);
input [15:0]w;
input [3:0]s;
wire [1:0]m;
output y;
mux8to1 stg0(w[7:0],s[2:0],m[0]);
mux8to1 stg1(w[15:8],s[2:0],m[1]);
mux2to1 stg2(m,s[3],y);
endmodule
module fd(a,b,c,d,f);
input a,b,c,d;
output f;
assign g = c^d;
assign f = (a&g) | (b&~g);
endmodule
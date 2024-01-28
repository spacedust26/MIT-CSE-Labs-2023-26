module comparator(a,b,l,e,g);
input [2:0]a,b;
wire [2:0]i;
output l,e,g;
assign i[2] = ~(a[2]^b[2]);
assign i[1] = ~(a[1]^b[1]);
assign i[0] = ~(a[0]^b[0]);
assign g = (a[2]&~b[2]) | (i[2]&a[1]&~b[1]) | (i[2]&i[1]&a[0]&~b[0]);
assign e = (i[2]&i[1]&i[0]);
assign l = ~(g | e);
endmodule

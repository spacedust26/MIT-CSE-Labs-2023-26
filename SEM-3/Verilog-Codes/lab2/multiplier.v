module fullAdder(cin,x,y,cout,s);
input cin,x,y;
output cout,s;
assign cout = (x&y)|(y&cin)|(x&cin);
assign s = x^y^cin;
endmodule

module multiplier(m,q,p);
input [2:0]m,q;
output [5:0]p;
wire [1:0]s;
wire [2:0]c1;
wire[0:1]c2;
assign p[0] = (m[0]&q[0]);
fullAdder stg0(1'b0, (m[1]&q[0]),(m[0]&q[1]),c1[0],p[1]);
fullAdder stg1(c1[0], (m[2]&q[0]),(m[1]&q[1]),c1[1],s[0]);
fullAdder stg2(c1[1],1'b0,(m[2]&q[1]),c1[2],s[1]);
fullAdder stg3(1'b0,s[0],(m[0]&q[2]),c2[0],p[2]);
fullAdder stg4(c2[0],s[1],(m[1]&q[2]),c2[1],p[3]);
fullAdder stg5(c2[1],c1[2],(m[2]&q[2]),p[5],p[4]);
endmodule

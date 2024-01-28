module fullAdder(cin,x,y,cout,s);
input cin,x,y;
output cout,s;
assign cout = (x&y)|(y&cin)|(x&cin);
assign s = x^y^cin;
endmodule

module addSub4bit(cin,x,y,cout,s);
input [3:0]x,y;
input cin;
output [3:0]s;
output cout;
wire [2:0]c;
fullAdder stg0(cin,x[0],(y[0]^cin),c[0],s[0]);
fullAdder stg1(c[0],x[1],(y[1]^cin),c[1],s[1]);
fullAdder stg2(c[1],x[2],(y[2]^cin),c[2],s[2]);
fullAdder stg3(c[2],x[3],(y[3]^cin),cout,s[3]);
endmodule
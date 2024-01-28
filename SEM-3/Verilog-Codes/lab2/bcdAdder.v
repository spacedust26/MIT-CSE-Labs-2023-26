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

module bcdAdder(cin,x,y,cout,s);
input [3:0]x,y;
input cin;
output [3:0]s;
wire c;
output cout;
wire [3:0]z;
addSub4bit stg0(cin,x,y,k,z);
assign c = (k | (z[3]&z[2]) | (z[3]&z[1]));
addSub4bit stg1(cin,{1'b0,c,c,1'b0},z[3:0],cout,s[3:0]);
endmodule

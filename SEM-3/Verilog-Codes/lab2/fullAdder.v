module fullAdder(cin,x,y,cout,s);
input cin,x,y;
output cout,s;
assign cout = (x&y)|(y&cin)|(x&cin);
assign s = x^y^cin;
endmodule
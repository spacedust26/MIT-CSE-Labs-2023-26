module fullAdder(cin,x,y,cout,s);
input cin,x,y;
output cout,s;
assign cout = (x&y)|(y&cin)|(x&cin);
assign s = x^y^cin;
endmodule

module faop(a,b,andGate,nandGate,orGate,norGate,xorGate,xnorGate);
input a,b;
output andGate,nandGate,orGate,norGate,xorGate,xnorGate;
wire c1,s1,c2,s2,c3,s3;
fullAdder stg0(1'b0,a,b,c2,s1);
assign xorGate=s1;
assign xnorGate=~s1;
fullAdder stg1(a,b,c1,c2,s2);
assign orGate=s2;
assign norGate=~s2;
fullAdder stg2(b,c1,s1,c3,s3);
assign andGate=s3;
assign nandGate=~s3;
endmodule
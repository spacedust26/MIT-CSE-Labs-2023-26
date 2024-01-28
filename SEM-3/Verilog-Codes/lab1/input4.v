module input4(x1,x2,x3,x4,f);
input x1,x2,x3,x4;
output f;
assign f = (~x1&x2&x3&x4)|(x1&~x2&x3&x4)|(x1&x2&~x3&x4)|(x1&x2&x3&~x4)|(x1&x2&x3&x4);
endmodule
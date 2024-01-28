module comp2bit(a,b,gt,eq,lt);
input [1:0]a,b;
output gt,eq,lt;
wire [1:0]i;
assign i[1] = ~(a[1]^b[1]);
assign i[0] = ~(a[0]^b[0]);
assign gt = (a[1]&~b[1]) | (i[1]&a[0]&~b[0]);
assign eq = i[1]&i[0];
assign lt = ~(gt | eq);
endmodule

module comp4bit(a,b,gt,eq,lt);
input [3:0]a,b;
wire gt1,eq1,lt1;
wire gt2,eq2,lt2;
output gt,eq,lt;
comp2bit stg0(a[1:0], b[1:0], gt1,eq1,lt1);
comp2bit stg1(a[3:2],b[3:2], gt2,eq2,lt2);
assign gt = gt2 + (eq2& gt1);
assign eq = eq1&eq2;
assign lt = ~(gt | eq);
endmodule
module dec2to4(en,w,y);
input en;
input [1:0]w;
output reg [0:3]y;
always @(en,w)
begin
  if(en==1)
  begin
    case(w)
    0: y = 4'b1000;
    1: y = 4'b0100;
    2: y = 4'b0010;
    3: y = 4'b0001;
    endcase
  end
  else if(en==0) y = 4'b0000;
end
endmodule

module dec16(en,w,y);
input en;
input [3:0]w;
output [0:15]y;
wire [0:3]m;
dec2to4 stg0(~en,w[3:2],m);
dec2to4 stg1(m[0],w[1:0],y[0:3]);
dec2to4 stg2(m[1],w[1:0],y[4:7]);
dec2to4 stg3(m[2],w[1:0],y[8:11]);
dec2to4 stg4(m[3],w[1:0],y[12:15]);
endmodule
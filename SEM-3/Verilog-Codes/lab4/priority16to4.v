module priority16to4(w,y,z);
input [15:0]w;
output reg [3:0]y;
output reg z;
integer i;
always @(w)
begin
  y=4'bx;
  z=0;
for(i=0;i<16;i=i+1)
begin
  if(w[i])
  begin
  y=i;
  z=1;
  end
end
end
endmodule

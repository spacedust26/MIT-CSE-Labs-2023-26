module mux4to1(w,s,y);
input [3:0]w;
input [1:0]s;
output reg y;
always @(w,s)
begin
  if(s==0) y=w[0];
  else if(s==1) y=w[1];
  else if(s==2) y=w[2];
  else if(s==3) y=w[3];
end
endmodule
module dec2to4(en,w,y);
input en;
input [1:0]w;
output reg [0:3]y;
always @(en,w)
begin
  if(en==1)
    begin
      if(w==0) y = 4'b1000;
      else if(w==1) y = 4'b0100;
      else if(w==2) y = 4'b0010;
      else if(w==3) y = 4'b0001;
    end
  else y= 4'b0000;
end
endmodule
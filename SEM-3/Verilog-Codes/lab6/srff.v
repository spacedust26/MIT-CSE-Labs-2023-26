module srff(s,r,clk,reset,q);
input s,r,clk,reset;
output reg q;
always @(negedge clk)
begin
  if(!reset) q<=1'b0;
  else
    begin
      if(s==1'b0)
      begin
        if(r==1'b0) q<=q;
        else q<=1'b0;
      end
      else if(s==1'b1)
        begin
          if(r==1'b0) q<=1;
        end
    end 
end
endmodule
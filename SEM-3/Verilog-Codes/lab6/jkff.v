module jkff(j,k,clk,reset,q);
input j,k,clk,reset;
output reg q;
always @(posedge clk)
begin
  if(reset) q<=1'b0;
  else
    begin
      if(j==1'b0)
      begin
        if(k==1'b0) q<=q;
        else q<=1'b0;
      end
      if(j==1'b1)
        begin
          if(k==1'b0) q<=1'b1;
          else q<=~q;
        end
    end
end
endmodule

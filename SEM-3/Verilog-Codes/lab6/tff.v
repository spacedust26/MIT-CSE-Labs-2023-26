module tff(t,clk,reset,q);
input t,clk,reset;
output reg q;
always @(negedge clk or negedge reset)
begin
  if(!reset) q<=1'b0;
  else
    begin
      if(t==1'b0) q<=q;
      else q<=~q;
    end
end
endmodule

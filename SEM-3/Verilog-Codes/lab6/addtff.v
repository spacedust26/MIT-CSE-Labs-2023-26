module addtff(t,clk,reset,q);
input t,clk,reset;
output reg q;
always @(negedge clk)
begin 
  if(reset) q<=0;
  else begin
    if(t==0) q<=q;
    else q<=~q;
    end
end
endmodule
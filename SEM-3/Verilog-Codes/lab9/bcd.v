module bcd(clk,reset,w);
input clk,reset;
output reg [7:0]w;
reg [3:0]first;
reg [3:0]second;
always @(posedge clk or posedge reset)
begin
  if(reset) begin
    first<=0;
    second<=0;
  end
  else
    begin
      if(first==4'b1001)begin
        first<=0;
        if(second==4'b1001)begin
          second<=0;
        end
        else begin
          second=second+1;
        end
      end
      else begin
        first=first+1;
      end
    end
end
always @* begin
  w = {second,first};
end
endmodule
module counter(clk,rst,count);
  input clk,rst;
  output reg [3:0]count;
  always@(negedge clk) begin
    if(rst == 0 || count == 9)
      count <= 0;
    else
      count <= count + 1;
  end
endmodule

module p4(clk,reset,op);
input clk,reset;
output [7:0] op;
wire s;
counter st0(clk,reset,op[3:0]);
assign s = op[3]|op[2]|op[1]|op[0];
counter st1(s,reset,op[7:4]);
endmodule
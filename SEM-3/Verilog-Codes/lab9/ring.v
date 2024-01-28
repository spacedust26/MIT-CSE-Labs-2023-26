module dff(inp,d,clk,reset,q);
input inp,d,clk,reset;
output reg q;
always @(posedge clk or posedge reset)
begin
  if(reset) q<=inp;
  else q<=d;
end
endmodule

module ring(clk,reset,q);
input clk,reset;
output [3:0]q;
dff stg0(1'b1,q[0],clk,reset,q[3]);
dff stg1(1'b0,q[3],clk,reset,q[2]);
dff stg2(1'b0,q[2],clk,reset,q[1]);
dff stg3(1'b0,q[1],clk,reset,q[0]);
endmodule

//BEHAVIOURAL CODE
// module ring(clk,reset,q);
// input clk,reset;
// output reg [3:0]q;
// always @(posedge clk or posedge reset)
// begin if(reset)q<=4'b1000;
//   else q<={q[0],q[3:1]};
// end
// endmodule

//2 BIT COUNTER AND DECODER
// module tff(t,clk,reset,q);
// input t,clk,reset;
// output reg q;
// always @(posedge clk or posedge reset)
// begin
//   if(reset) q<=1'b0;
//   else
//     begin
//       if(t==1'b0) q<=q;
//       else q<=~q;
//     end
// end
// endmodule


// module dec2to4(en,w,y);
// input en;
// input [1:0]w;
// output reg [0:3]y;
// always @(en,w)
// begin
//   if(en==1)
//     begin
//       if(w==0) y = 4'b1000;
//       else if(w==1) y = 4'b0100;
//       else if(w==2) y = 4'b0010;
//       else if(w==3) y = 4'b0001;
//     end
//   else y= 4'b0000;
// end
// endmodule

// module ring(clk,reset,q);
// input clk,reset;
// output [3:0]q;
// wire [1:0]a;
// tff stg0(a[0],clk,reset,a[1]);
// tff stg1(1'b1,clk,reset,a[0]);
// dec2to4 stg2(1'b1,a,q);
// endmodule
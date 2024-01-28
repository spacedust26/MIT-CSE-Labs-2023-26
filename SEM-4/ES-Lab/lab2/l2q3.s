;Write an ARM assembly language program to transfer a 32 bit numbers from code memory to data memory when the source and destination blocks are non overlapping
	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =SRC;
	LDR R1, =DST;
	MOV R2, #10;
UP  LDR R3, [R0], #4;
	STR	R3, [R1], #4;
	SUBS R2,#1;
	BNE UP
STOP B STOP
SRC DCD 0x12345678, 0xA1B2C3D4, 0xFEDCBA98, 0x87654321, 0xABCDEF01, 0x13579BDF, 0xDEADBEEF, 0x1F2E3D4C, 0xC0FFEE00, 0x5A5A5A5A
  	AREA mydata, DATA, READWRITE
DST DCD 0
	END
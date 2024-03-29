;Write an ARM aseembly language program to transfer block of ten 32 bit numbers from code memory to data memory when the source and destination blocks are non overlapping.
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
	LDR R0, =SRC
	LDR R1, =DST
	MOV R2, #10
UP	LDR R4, [R0], #4
	STR R4, [R1], #4
	SUBS R2, #1
	BNE UP
STOP B STOP
SRC DCD 0X2, 0X3, 0X4, 0X5, 0X6, 0X7, 0X8, 0X9, 0X10, 0XAA
	AREA mydata, DATA, READWRITE
DST DCD 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	END
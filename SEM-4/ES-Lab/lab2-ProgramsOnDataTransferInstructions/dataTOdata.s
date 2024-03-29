;Write an ARM assembly language program to transfer a 32 bit number from one location in the data memory to another location int the data memory
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
	LDR R1, [R0]
	LDR R2, =DST
	STR R1, [R2]
STOP B STOP
	AREA mydata1, DATA, READONLY
SRC DCD 0X12345678
	AREA mydata2, DATA, READWRITE
DST DCD 0
	END
		
;Find the sum of 'n' natural numbers using MLA instruction
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
	LDR R1, =SRC
	LDR R2, =DST
	LDR R3, [R1]
	MLA R3, R3, R3, R3
	LSR R3, #1
	STR R3, [R2]
STOP B STOP
SRC DCD 5
	AREA mydata, DATA, READWRITE
DST DCD 0
	END
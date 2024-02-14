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
	LDR R0, =N
	LDR R1, =SUM
	LDR R2, [R0]
	MLA R2,R2,R2,R2
	LSR R2, #1
	STR R2, [R1]
STOP B STOP
N DCD 4
	AREA mydata, DATA, READWRITE
SUM DCD 0
	END
	
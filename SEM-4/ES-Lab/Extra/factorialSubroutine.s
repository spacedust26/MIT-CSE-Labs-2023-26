;To find the factorial of a number using subroutine
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
	MOV R3, #1
	BL FACT
	STR R3, [R2]
STOP B STOP
FACT MUL R3, R3, R1
	SUBS R1, #1
	CMP R1, #0
	BNE FACT
	BX LR
SRC DCD 4
	AREA mydata, DATA, READWRITE
DST DCD 0
	END
	
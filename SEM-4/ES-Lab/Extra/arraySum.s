;To find the sum of natural numbers for each number in an array and store it
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
	LDR R2, =DST
	MOV R3, #5
UP	LDR R1, [R0], #4
	BL SUM
	STR R1, [R2], #4
	SUBS R3, #1
	CMP R3, #0
	BEQ STOP
	B UP	
SUM MLA R1, R1, R1, R1
	LSR R1, #1
	BX LR
STOP B STOP
SRC DCD 0X5, 0X6, 0X7, 0X8, 0X9
	AREA mydata, DATA, READWRITE
DST DCD 0, 0, 0, 0, 0
	END
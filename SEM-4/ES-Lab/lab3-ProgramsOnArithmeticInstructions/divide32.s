;Write an aseembly language program to implement division using repetitive subtraction
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
	LDR R0, =N1
	LDR R1, =N2
	LDR R6, =RESULT
	LDR R2, [R0]
	LDR R3, [R1]
	MOV R5, #0
UP	CMP R2, R3
	BCC STORE
	SUBS R2, R3
	ADD R5, #1
	B UP
STORE STR R5, [R6], #4
	STR R2, [R6]
STOP B STOP
N1 DCD 0X15
N2 DCD 0X5
	AREA mydata, DATA , READWRITE
RESULT DCD 0
	END
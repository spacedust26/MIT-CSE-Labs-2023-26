;Write an assembly langauge program to implement division by repetitive subtraction
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
	LDR R2, =RESULT
	MOV R3, #00
	LDR R4, [R0]
	LDR R5, [R1]
UP	CMP R4, R5
	BCC STORE
	SUB R4, R5
	ADD R3, #01
	B UP
STORE STR R3, [R2], #4
	STR R4, [R2]
STOP B STOP
N1 DCD 0X6
N2 DCD 0X2
	AREA mydata, DATA, READWRITE
RESULT DCD 0, 0
	END
	
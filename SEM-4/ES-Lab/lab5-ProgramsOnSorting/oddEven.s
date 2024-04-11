;Write an ARM assembly language program that contains a list of numbers and makes a count of even and odd numbers
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
	MOV R7, #8
	LDR R0, =SRC
	LDR R2, =EVEN
	LDR R3, =ODD
	MOV R4, #0 ;EVEN COUNT
	MOV R5, #0 ;ODD COUNT
UP	CMP R7, #0
	BEQ STOP
	LDR R1, [R0], #4
	SUBS R7, #1
	AND R1, #1
	CMP R1, #0
	BNE L1
	ADD R4, #1
	STR R4, [R2]
	B UP
L1	ADD R5, #1
	STR R5, [R3]
	B UP
STOP B STOP
SRC DCD 0X2, 0X3, 0X4, 0X5, 0X6, 0X7, 0X9, 0X11
	AREA mydata, DATA, READWRITE
EVEN DCD 0
ODD DCD 0
	END
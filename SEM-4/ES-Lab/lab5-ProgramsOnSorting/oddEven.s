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
		
		
		LDR R1, =DST
	MOV R3, #10
UP	LDR R2, [R0], #4
	STR R2, [R1], #4
	SUB R3, #1
	BNE UP
	LDR R0, =DST
	MOV R3, #9
	MOV R9, #9
OUTERLOOP MOV R5, R0
	MOV R4, R3
INNERLOOP LDR R6, [R5], #4
	LDR R7, [R5]
	CMP R7, R6
	STRLS R6, [R5]
	STRLS R7, [R5,#-4]
	SUBS R4, #1
	BNE INNERLOOP
	SUBS R3, #1
	SUBS R9, #1
	BNE OUTERLOOP
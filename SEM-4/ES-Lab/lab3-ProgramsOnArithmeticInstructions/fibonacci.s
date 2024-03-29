;Write an assembly language program to generate fibonacci series
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
	LDR R5, [R0]
	LDR R2, [R0]
	MOV R3, #0
	MOV R4, #1
	STR R3, [R1], #1
	STR R4, [R1], #1
	SUBS R5, #1
UP	ADD R7, R3, R4
	STR R7, [R1], #1
	MOV R3, R4
	MOV R4, R7
	SUBS R5, #1
	BNE UP
STOP B STOP
SRC DCD 6
	AREA mydata, DATA, READWRITE
DST DCD 0, 0, 0, 0, 0, 0
	END
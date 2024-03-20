;Write an ARM assembly language program to sort a list using bubble sort
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
	;copy content to destination
	LDR R0, =SRC
	LDR R1, =DST
	MOV R3, #10
UP	LDR R2, [R0], #4
	STR R2, [R1], #4
	SUBS R3, #1
	BNE UP
	
	;sorting
	LDR R0, =DST
	MOV R1, #10
UP2	SUB R1, #1
	CMP R1, #-1
	BEQ STOP
	MOV R2, R1
	MOV R3, R0
	LDR R4, [R3, #4]
UP3	CMP R2, #0
	BEQ UP2
	LDR R5, [R3]
	LDR R6, [R4]
	SUBS R2, #1
	CMP R5, R6
	BCS SWAP
UP1	ADD R3, #4
	ADD R4, #4
	B UP3
SWAP STR R5, [R4]
	STR R6, [R3]
	B UP1	
STOP B STOP
SRC DCD 0X3, 0X4, 0X1, 0X8, 0X7, 0X9, 0X0, 0X2, 0X6, 0X5
	AREA mydata, DATA, READWRITE
DST DCD 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	END
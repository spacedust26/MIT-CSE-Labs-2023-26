;Write an assembly program to sort an array using selection sort
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
	MOV R3, #10
UP	LDR R2, [R0], #4
	STR R2, [R1], #4
	SUB R3, #1
	BNE UP 
	LDR R0, =DST
	MOV R9, #9
L2	MOV R10, R9
	MOV R1, R0
	MOV R2, R0
	MOV R2, #4
L1	LDR R3, [R2]
	LDR R4, [R1]
	CMP R3, R4
	BCS UP1
	MOV R1, R2
UP1 ADD R2, #4
	SUBS R10, #1
	BNE L1
	LDR R7, [R0]
	LDR R8, [R1]
	STR R8, [R0]
	STR R7, [R1]
	ADD R0, #4
	SUBS R9, #1
	BNE L2	
STOP B STOP
SRC DCD 0X3, 0X4, 0X1, 0X8, 0X7, 0X9, 0X0, 0X2, 0X6, 0X5
	AREA mydata, DATA, READWRITE
DST DCD 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	END
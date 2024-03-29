;Write a program to add ten 32 bit numbers available in code memory and store the result in data memory
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
	MOV R7, #0
	MOV R5, #10
	LDR R2, [R0], #4
	LDR R3, [R0], #4
	ADDS R4, R2, R3
	ADC R7, #0
	SUB R5, #2
UP	LDR R6, [R0], #4
	ADDS R4, R6
	ADC R7, #0
	SUBS R5, #1
	BNE UP
	STR R4, [R1], #4
	STR R7, [R1]
STOP B STOP
SRC DCD 0X1789ABCD, 0X2789DCFF, 0X3CEDA455, 0X4023CCAA, 0X450015AA, 0X6, 0X7, 0X8236AABB, 0X9, 0XA
	AREA mydata, DATA, READWRITE
DST DCD 0
	END
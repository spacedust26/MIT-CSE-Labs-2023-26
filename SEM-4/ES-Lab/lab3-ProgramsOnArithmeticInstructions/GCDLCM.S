;Write an assembly language program to find GCD and LCM of two 8 bit numbers
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

	;find gcd
	LDR R1, =N1
	LDR R2, =N2
	LDR R0, =HCF
	MOV R7, #0 ;remainder
	LDR R3, [R1]
	LDR R5, [R1]
	LDR R4, [R2]
TOP	CMP R4, #0
	BEQ STORE
UP	SUBS R5, R4
	ADD R7, #1
	CMP R5, R4
	BGE UP
	MOV R3, R4
	MOV R4, R5
	B TOP
STORE STR R3, [R0], #1; HCF

	;find lcm
	MOV R7, #0
	LDR R1, =N1
	LDR R2, =N2
	LDR R5, [R1]
	LDR R4, [R2]
	MUL R5, R4
UP2	SUBS R5, R3
	ADD R7, #1
	CMP R5, R3
	BGE UP2
	STR R7, [R0]; LCM
STOP B STOP
N1 DCD 20
N2 DCD 8
	AREA mydata, DATA, READWRITE
HCF DCD 0
	END
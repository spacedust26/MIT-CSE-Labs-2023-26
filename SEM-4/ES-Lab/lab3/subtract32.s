;Write a program to perform subtraction operation two 32 bit numbers available in the code memory. Store the result in the data memory
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
	LDR R2, [R0]
	LDR R3, [R1]
	SUBS R2, R3;
	LDR R4, =RESULT
	STR R2, [R4]
STOP B STOP
N1 DCD 0X20004500
N2 DCD 0X1000A002
	AREA mydata, DATA , READWRITE
RESULT DCD 0
	END
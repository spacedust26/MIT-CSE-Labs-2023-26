;Write a program to perform subtraction operation on two 32 bit numbers available in the code memory. store the result in the data memory
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
	SUB R4, R3, R2
	LDR R5, =RESULT
	STR R4, [R5]
STOP B STOP
N1 DCD 0X12345678
N2 DCD 0X87654321
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END
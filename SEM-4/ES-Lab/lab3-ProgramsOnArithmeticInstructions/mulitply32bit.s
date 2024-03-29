;Write an asssembly program to multiply 32 bit numbers
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
	LDR R0, =0X12345678
	LDR R1, =0X87654321
	MOV R3, #0
	MOV R2, #0
	UMULL R3,R2,R0,R1
STOP B STOP
	END
	
	
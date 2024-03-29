;Convert a 32 bit packed BCD number into its equivalent hexadecimal number
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
	LDR R1, [R0]
	LDR R2, =DST
	MOV R3, #0XF
	MOV R4, #1
	MOV R7, #0
	MOV R8, #0XA
UP	AND R5, R1, R3
	MLA R7, R5, R4, R7
	MUL R4, R8
	LSR R1, #4
	CMP R1, #0
	BNE UP	
	STR R7, [R2]
STOP B STOP
SRC DCD 0X22222222
	AREA mydata, DATA, READWRITE
DST DCD 0
	END
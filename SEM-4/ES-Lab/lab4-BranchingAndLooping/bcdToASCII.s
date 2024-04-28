;Program to unpack a 32 bit BCD number into eight 32-bit ASCII numbers
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
	MOV R5, #4
UP	LDRB R2, [R0], #1
	AND R3, R2, #0XF
	ADD R3, #0X30
	STR R3, [R1], #4
	AND R3, R2, #0XF0
	LSR R3, #4
	ADD R3, #0X30
	STR R3, [R1], #4
	SUBS R5, #1
	BNE UP
STOP B STOP
SRC DCD 0x12345678
	AREA mydata, DATA, READWRITE
DST DCD 0, 0, 0, 0, 0, 0, 0, 0
	END
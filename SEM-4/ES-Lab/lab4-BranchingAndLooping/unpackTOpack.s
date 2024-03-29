;Write an ARM assembly language progarm to convert a 32 bit BCD number in the unpacked form into packed form
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
	MOV R2, #4
UP	LDRB R3, [R0], #1
	LDRB R4, [R0], #1
	LSL R4, #4
	ORR R4, R3
	STRB R4, [R1], #1
	SUBS R2, #2
	BNE UP
STOP B STOP
SRC DCD 0X01020304
	AREA mydata, DATA, READWRITE
DST DCD 0
	END
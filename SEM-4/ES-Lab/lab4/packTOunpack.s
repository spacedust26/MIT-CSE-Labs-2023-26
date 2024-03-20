;Write an ARM assembly language progarm to convert a 32 bit BCD number in the packed form into unpacked form
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
	MOV R2, #0XF
	LDR R7, [R0]
UP	MOV R3, R7
	AND R4, R3, R2
	LSR R7, #4
	STRB R4, [R1], #1
	CMP R7, #0
	BNE UP
STOP B STOP
SRC DCD 0X1234
	AREA mydata, DATA, READWRITE
DST DCD 0
	END
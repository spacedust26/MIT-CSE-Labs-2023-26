;Write an ARM ALP that contains a list of numbers and makes a count of numbers greater than 10
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
	MOV R7, #8
	LDR R0, =SRC
	LDR R1, =COUNT
	MOV R5, #0
UP	LDR R2, [R0], #4
	CMP R2, #10
	ADDGT R5, #1
	SUBS R7, #1
	BNE UP
	STR R5, [R1]
STOP B STOP
SRC DCD 0X2, 0X96, 0X4, 0X5, 0X6, 0X7, 0X85, 0X11
	AREA mydata, DATA, READWRITE
COUNT DCD 0
	END
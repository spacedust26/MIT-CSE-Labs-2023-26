;Write an ARM assembly language progarm to store data into general purpose registers
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
	MOV R2, #25;
	LDR R1, =0x10000000;
	STR R2, [R1];
STOP B STOP
	END
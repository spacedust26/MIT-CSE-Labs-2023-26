;Write an assembly progarm to multiply two 32 bit numbers
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
	MOV32 R0, #0xABCD2314
	MOV32 R1, #0x45690000
	MOV R2, #0
	MOV R3, #0
	UMULL R3,R2,R0,R1
STOP B STOP
	END
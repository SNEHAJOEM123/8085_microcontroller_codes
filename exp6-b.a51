ORG 000H
LJMP START

ORG 000BH
LJMP TOISR

ORG 0040H
START:MOV P0,#0FFH
MOV P1,#0FFH
MOV R2,#26
MOV IE,#82H
MOV TMOD,#01H
MOV TH0,#00H
MOV TL0,#00H
SETB P2.4
SETB TR0
BACK:MOV A,P0
MOV B,P1
CJNE A,B,LIT
CLR P2.0
SJMP BACK
LIT:SETB P2.0
SJMP BACK
TOISR:DJNZ R2,LABEL
CPL P2.4
CLR TR0
MOV R2,#26
MOV TH0,#00H
MOV TL0,#00H
SETB TR0
RETI
LABEL:CLR TF0
RETI
END
	
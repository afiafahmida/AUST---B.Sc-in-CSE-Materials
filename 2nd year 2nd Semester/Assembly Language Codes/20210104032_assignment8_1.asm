.MODEL SMALL
.STACK 100H 

.DATA
   MSG1 DB 'Enter a string: $'
   MSG2 DB 13, 10, 'Reverse of the String: $'
  
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH, 9
    LEA DX, MSG1
    INT 21H             
    
    XOR CX,CX
    
    MOV AH,1
    INT 21H
    
    WHILE:
    CMP AL,0DH
    ;if AL is carriage
    JE END_WHILE      
    
    ;PUSH IN STACK
    PUSH AX
    INC CX
    INT 21H
    JMP WHILE
    
    
    
    END_WHILE:
    MOV AH,9
    LEA DX, MSG2
    INT 21H
    
    MOV AH,2
    MOV DL,0DH
    INT 21H
    MOV DL,0AH
    INT 21H
    JCXZ EXIT
    
    
    TOP:
    POP DX
    INT 21H
    LOOP TOP
    
    EXIT:
    MOV AH,4CH
    INT 21H
    MAIN ENDP
    END    MAIN 
 
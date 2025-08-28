.MODEL SMALL
.STACK 100H 

.DATA
    MSG1 DB "Enter a Lowercase Letter: $"
    MSG2 DB "Uppercase form : $"
    MSG3 DB "Not a Lowercase Letter :( $"
    MSG4 DB "Please enter a LOWERCASE Letter again: $"
    VAR DB ?

.CODE
   MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH, 9
    LEA DX, MSG1
    INT 21H
    
    INPUT:
    MOV AH, 1
    INT 21H
    
    CMP AL, 'a'
    JL DISPLAY
    CMP AL, 'z'
    JG DISPLAY
    
    ;CONVERTING    
    SUB AL, 32
    MOV VAR, AL
    
    MOV AH, 2
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H
    
    MOV AH, 9
    LEA DX, MSG2
    INT 21H
    
    MOV AH, 2
    MOV DL, VAR
    INT 21H
    JMP DISPLAY2
    
    DISPLAY:
    MOV AH, 2
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H
    
    MOV AH, 9
    LEA DX, MSG3
    INT 21H
    
    MOV AH, 2
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H
    
    MOV AH, 9
    LEA DX, MSG4
    INT 21H
    JMP INPUT
    
    
    DISPLAY2:
    MOV AH, 4CH
    INT 21H 
    
    MAIN ENDP
END MAIN




.MODEL SMALL
.STACK 100H
.DATA

    MSG1 DB "Enter n: $"
    MSG2 DB "Maximum : $"
    MSG3 DB "Minimum : $"  
    N DB ?
    MAX DB ?
    
    
    
.CODE
MAIN PROC
    
    MOV AX ,@DATA
    MOV DS, AX
    
    MOV AH, 9
    LEA DX, MSG1
    INT 21H
    
    MOV AH, 1
    INT 21H
    
   
    MOV N, AL
    SUB N, 48
    MOV CL, N
    
  
    MOV BH, 0
    MOV CH, 57
    
    MOV AH, 2
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H
    
    MOV AH, 1
    
    
    FIRST:
    INT 21H
    CMP AL, BH
    JLE LBL1
    MOV BH, AL
    LBL1:
    CMP AL, CH
    JGE LBL2
    MOV CH, AL
    LBL2:
    DEC CL
    JNZ FIRST
    
    MOV AH, 2
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H
              
    MOV AH, 9
    LEA DX, MSG2
    INT 21H
    
    
    MOV AH, 2
    MOV DL, BH
    INT 21H
    
    MOV AH, 2
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H
    
    
    MOV AH, 9
    LEA DX, MSG3
    INT 21H
    
    
    MOV AH, 2
    MOV DL, CH
    INT 21H

    MOV AH, 4CH
    INT 21H 
    
   MAIN ENDP
END MAIN 




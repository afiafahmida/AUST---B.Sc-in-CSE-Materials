.MODEL SMALL
.STACK 100H

.DATA
   MSG DB 'Enter a lowercase letter: $'
   MSG2 DB 'UPPERCASE: $'               
   
.CODE
   MAIN PROC 
    MOV AX, @DATA  
    MOV DS, AX 
    
    LEA DX, MSG
    MOV AH, 9
    INT 21H
    
    MOV AH, 1
    INT 21H 
    
    MOV BL, AL
      
    ;newline  
    MOV AH, 2
    MOV DL, 10
    INT 21H  
    
    MOV DL, 13
    INT 21H
    
    LEA DX, MSG2
    MOV AH, 9
    INT 21H
    
    
    SUB BL, 32d
    
    MOV AH, 2
    MOV DL, BL
    INT 21H
    
    MOV AH, 4CH
    INT 21H  
  MAIN ENDP  
    
END MAIN    
    
    
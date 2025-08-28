.MODEL SMALL
.STACK 100H 

.DATA
   IN1 DB 'Enter X: $'
   IN2 DB 'Enter Y: $'
   MSG DB 'After swap__ $'
   OP1 DB 'X: $'
   OP2 DB 'Y: $'

.CODE       

   MAIN PROC
         
    MOV AX, @DATA
    MOV DS, AX 

    ;first input
    LEA DX, IN1 
    MOV AH, 9
    INT 21H     
    MOV AH, 1   
    INT 21H     
    MOV BL, AL

    ;NEWLINE
    MOV AH,2
    MOV DL, 13
    INT 21H
    MOV DL, 10
    INT 21H 
 
    ;second input 
    LEA DX, IN2 
    MOV AH, 9
    INT 21H     
    MOV AH, 1   
    INT 21H     
    MOV BH, AL 

    ;NEWLINE
    MOV AH,2
    MOV DL, 13
    INT 21H
    MOV DL, 10
    INT 21H 
 
    ;SWAP
    MOV CL, BL
    INT 21H
    MOV BL, BH 
    INT 21H
    MOV BH, CL
    INT 21H 

 
    ;PRINT
    LEA DX, MSG
    MOV AH, 9
    INT 21H

    ;NEWLINE
    MOV AH,2
    MOV DL, 13
    INT 21H
    MOV DL, 10
    INT 21H 

    ;first output
    LEA DX, OP1   
    MOV AH, 9
    INT 21H     
    MOV AH, 2    
    MOV DL, BL  
    INT 21H 

    ;NEWLINE
    MOV AH,2
    MOV DL, 13
    INT 21H
    MOV DL, 10
    INT 21H 

    ;second output
    LEA DX, OP2     
    MOV AH, 9
    INT 21H
    MOV AH, 2    
    MOV DL, BH 
    INT 21H     


 
   MOV AH, 4CH 
   INT 21H     

END MAIN
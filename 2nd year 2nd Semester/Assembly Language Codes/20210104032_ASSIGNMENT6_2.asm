.MODEL SMALL
.STACK 100H

.DATA
  VAR DB ?
  MSG DB "Enter Character:$"
  MSG2 DB "Enter another character:$"
  UP DB "Uppercase Letter$"
  LW DB "Lowercase Letter$"
  D DB "Digit$"
  S DB "Special Character$"

.CODE
  MAIN PROC
    
    MOV AX,@DATA    
    MOV DS,AX
    
    LEA DX,MSG     
    MOV AH,9
    INT 21H
    
    MOV AH,1
    INT 21H         
    MOV VAR,AL
    
    MOV AH,2
    MOV DL,0DH      
    INT 21H
    MOV DL,0AH
    INT 21H
    
    CMP VAR,'A'
    JNGE LBL1       
    CMP VAR,'Z'
    JLE DISPLAY1
    
    LBL1:
    CMP VAR,'a'
    JNGE LBL2      
    CMP VAR,'z'
    JLE DISPLAY2
    
    LBL2:
    CMP VAR,'1'
    JNGE LBL3
    CMP VAR,'9'    
    JLE DISPLAY3
    
    LBL3:
    LEA DX,S
    MOV AH,9
    INT 21H        
    JMP ENDPR
    
    DISPLAY1:
    LEA DX,UP
    MOV AH,9       
    INT 21H
    JMP ENDPR
    
    DISPLAY2:
    LEA DX,LW
    MOV AH,9       
    INT 21H
    JMP ENDPR
    
    DISPLAY3:
    LEA DX,D
    MOV AH,9
    INT 21H        
    JMP ENDPR
    
    
     
    ENDPR:
    MOV AH,4CH
    INT 21H 
    
 END MAIN


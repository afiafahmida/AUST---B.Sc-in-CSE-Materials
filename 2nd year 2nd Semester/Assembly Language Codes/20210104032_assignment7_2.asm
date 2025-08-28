.MODEL SMALL
.STACK 100H
    
.DATA
    MSG1  DB  'Enter a Hexadecimal 4 digit number: $'
    BINARY DB  0DH,0AH,'Binary form : $'
    AGAIN  DB  0DH,0AH,'Please enter a VALID Input [0-9 or A-F] : $'
    TEMP   DB  ?
     
.CODE
       MAIN PROC
         MOV AX, @DATA                
         MOV DS, AX
         
         
         LEA DX,MSG1             
         MOV AH,9
         INT 21H
    
         JMP BEGIN                       ;30h=0,31h=1                  
    
         ;not valid input
         TOP: 
                           
           LEA DX, AGAIN           
           MOV AH, 9
           INT 21H
    
         BEGIN:                      
           XOR BX, BX
           ;temp = 0                 
           MOV TEMP, 30H              
    
         PROCEED:                  
           MOV AH, 1                 
           INT 21H                    
           
           ;if(AL == carriage)
           CMP AL, 0DH                
           JNE NO_ENTER                   
           
           ;if(temp == 0)
           CMP TEMP, 30H             
           JBE TOP                    
           JMP BINARY_PRINT                  
    
           
           NO_ENTER:                     
            
           ;if(AL<65) 
           CMP AL, "A"                
           JB DECIMAL                 
           
           ;if(AL>70)
           CMP AL, "F"                
           JA TOP                     
           
           ADD AL, 09H                
           JMP BINARY_CONVERT                    
    
           
           DECIMAL:
           ;if(AL<0)                 
           CMP AL, 30H              
           JB TOP                   
             
           ;if(AL>9)
           CMP AL, 39H              
           JA TOP                   
    
           
           BINARY_CONVERT:                       
    
           INC TEMP                  
    
           AND AL, 0FH                
           
           ; CL=4
           MOV CL, 4                  
           SHL AL, CL                 
           
           ; CX=4
           MOV CX, 4                  
    
           LOOP1:                   
           SHL AL, 1                
           RCL BX, 1                
           LOOP LOOP1                
    
          
          CMP TEMP, 34H              
          JE BINARY_PRINT                    
          JMP PROCEED              
    
         
         BINARY_PRINT:                        
    
         LEA DX, BINARY             
         MOV AH, 9                    
         INT 21H
    
         MOV CX, 16                   
         MOV AH, 2                   
                                                                        
         PRINT:                     
         SHL BX, 1
         ; if CF=1                  
         JC ONE                     
         MOV DL, 30H                
         JMP DISPLAY              
    
         ONE:                      
         MOV DL, 31H                                  
    
         DISPLAY:                  
         INT 21H                  
         LOOP PRINT                   
    
    
    EXIT:
         MOV AH, 4CH                 
         INT 21H
       MAIN ENDP
 END MAIN
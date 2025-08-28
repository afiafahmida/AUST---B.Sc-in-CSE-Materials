.MODEL SMALL
.STACK 100H

.DATA
   DECI  DB  'Enter a string of decimal digits: $'
   SUM  DB  0DH,0AH,'Sum of the digits in Hexa : $'
   AGAIN   DB  0DH,0AH,'Please enter valid decimal inputs:  $'
         
.CODE
   MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX       
    LEA DX,DECI          
    MOV AH, 9
    INT 21H

    JMP BEGIN                  

    TOP:                   
    LEA DX, AGAIN  
    MOV AH, 9
    INT 21H
       
    XOR BX, BX                  
    XOR CX, CX                   

    BEGIN:                   
       MOV AH, 1
       INT 21H

       INC CX                     

       CMP AL, 0DH                
       JNE NO_ENTER               

       CMP CX, 1                 
       JB TOP                    
       JMP END_INPUT             

    NO_ENTER:                  
       CMP AL, 30H                
       JB TOP                    
       CMP AL, 39H               
       JA TOP                   

       AND AL, 0FH                
       
       
       XOR AH, AH                 
       ADD BX, AX                 

       JMP BEGIN               

     END_INPUT:               
     LEA DX, SUM           
     MOV AH, 9
     INT 21H

     MOV CX, 4                    
     MOV AH, 2                    

     LOOP1:                    
      
       XOR DX, DX                 

     LOOP2:                     
       SHL BX, 1                  
       RCL DL, 1                  
       INC DH                  
       CMP DH, 4                  
       JNE  LOOP2               

       CMP DL, 9                  
       JBE NUMBER               
       SUB DL, 9                  
       OR DL, 40H                 
       JMP DISPLAY               
                                   
     NUMBER:            
       OR DL, 30H                 

     DISPLAY:                 
       INT 21H                 
       LOOP LOOP1                




   EXIT:
    MOV AH,4CH
    INT 21H
    MAIN ENDP  
   
END MAIN 
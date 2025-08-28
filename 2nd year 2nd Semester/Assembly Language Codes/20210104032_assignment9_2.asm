.MODEL SMALL
.STACK 100H

.DATA
   MSG1  DB  'ENTER M : $'
   MSG2  DB  0DH,0AH,'ENTER N : $'
   MSG3  DB  0DH,0AH,'GCD : $' 
   
 
.CODE
   MAIN PROC
    
     MOV AX,@DATA                
     MOV DS,AX

     LEA DX,MSG1                 
     MOV AH,9
     INT 21H
      
     ;procedure call 
     CALL IN_READ                  
      
     ;stack 
     PUSH AX                     

     LEA DX,MSG2                 
     MOV AH,9
     INT 21H

     CALL IN_READ                  

     MOV BX,AX                   

     POP AX                      
     
     REPEAT:                    
       XOR DX,DX
       ;set AX=DX:AX/BX                 
       DIV BX                    

       CMP DX,0  
       ;if DX =0 jmp                
       JE  END_LOOP              

       MOV AX,BX                 
       MOV BX,DX                 
     JMP  REPEAT                   

     END_LOOP:                  

     LEA DX,MSG3                 
     MOV AH,9
     INT 21H

     MOV AX,BX                   

     CALL OUT_PRINT                 

     MOV AH,4CH                  
     INT 21H
   MAIN ENDP

 ;procedure 
 IN_READ PROC
   PUSH BX                       
   PUSH CX                       
   PUSH DX                       

   JMP READ                      

   SKIP_BACKSPACE:              
   MOV AH,2                      
   MOV DL,20H                    
   INT 21H                       

   READ:                        
   XOR BX,BX                     
   XOR CX,CX                     
   XOR DX,DX                     

   MOV AH,1                      
   INT 21H                       

   CMP AL,"-"                    
   JE  MINUS                     

   CMP AL,"+"                    
   JE  PLUS                      

   JMP SKIP_INPUT                

   MINUS:                        
   MOV CH,1                      
   INC CL                        
   JMP INPUT                     
   
   PLUS:                         
   MOV CH,2                     
   INC CL                        

   INPUT:                        
     MOV AH,1                    
     INT 21H                     

     SKIP_INPUT:                 

     CMP AL,0DH                  
     JE  END_INPUT               

     CMP AL,8H                   
     JNE NOT_BACKSPACE           

     CMP CH,0                    
     JNE REMOVE_MINUS      

     CMP CL,0                    
     JE  SKIP_BACKSPACE          
     JMP MOVE_BACK               

     REMOVE_MINUS:         

     CMP CH,1                    
     JNE REMOVE_PLUS       

     CMP CL,1                    
     JE  REMOVE_PLUS_MINUS       

     REMOVE_PLUS:    

     CMP CL,1                    
     JE  REMOVE_PLUS_MINUS       
     JMP MOVE_BACK               

     REMOVE_PLUS_MINUS:       
       MOV AH,2                  
       MOV DL,20H                
       INT 21H                   

       MOV DL,8H                 
       INT 21H                  

       JMP READ                  
                                  
     MOVE_BACK:                  

     MOV AX,BX                   
     MOV BX,10                   
     DIV BX                      

     MOV BX,AX                  

     MOV AH,2                    
     MOV DL,20H                 
     INT 21H                     

     MOV DL,8H                   
     INT 21H                     

     XOR DX,DX                   
     DEC CL                      

     JMP INPUT                   

     NOT_BACKSPACE:              

     INC CL                     

     CMP AL,30H                 
     JL ERROR                    

     CMP AL,39H                  
     JG  ERROR                   

     AND AX,000FH                

     PUSH AX                     

     MOV AX,10                   
     MUL BX                      
     MOV BX,AX                   

     POP AX                      

     ADD BX,AX 
     ;jump to label ERROR if SF=1                  
     JS  ERROR                   
   JMP INPUT                     

   ERROR:                       

   MOV AH,2                      
   MOV DL,7H                     
   INT 21H                       

   XOR CH,CH                     

   CLEAR:                       
     MOV DL,8H                   
     INT 21H                     

     MOV DL,20H                  
     INT 21H                     

     MOV DL,8H                   
     INT 21H                     
   LOOP CLEAR                    

   JMP READ                      

   END_INPUT:                 

   CMP CH,1                         
   JNE EXIT                      
   NEG BX                        

   EXIT:                         

   MOV AX,BX                     

   POP DX                       
   POP CX                        
   POP BX                       

   RET                           
 IN_READ ENDP
 
 
 
 OUT_PRINT PROC
   PUSH BX                       
   PUSH CX                       
   PUSH DX                       

   CMP AX,0
   ;jump to START if AX>=0                      
   JGE START                    

   PUSH AX                       

   MOV AH,2                      
   MOV DL,"-"                    
   INT 21H                      

   POP AX                        
   ;2's compliment
   NEG AX                        

   START:                      

   XOR CX,CX                     
   MOV BX,10                     

   OUTPUT:                       
     XOR DX,DX                   
     DIV BX                      
     PUSH DX                     
     INC CX                      
     OR AX, AX                   
   JNE  OUTPUT                   

   MOV AH,2                      

   DISPLAY:                   
     POP DX
     ;convert to dec                      
     OR DL,30H                  
     INT 21H                    
   LOOP DISPLAY                 

   POP DX                        
   POP CX                        
   POP BX                        

   RET                           
 OUT_PRINT ENDP

 END MAIN
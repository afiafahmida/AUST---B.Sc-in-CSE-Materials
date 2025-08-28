.MODEL SMALL
.STACK 100H

.DATA
   ENTER   DB  0DH,0AH,'Enter an Algebraic Expression: ',0DH,0AH,'$'
   CORRECT DB  0DH,0AH,'expression is Correct $'
   LEFT    DB  0DH,0AH,'too many left Brackets $'
   RIGHT   DB  0DH,0AH,'too many right Brackets $'
   AGAIN   DB  0DH,0AH,'Mismatch!! $'
   Y       DB  0DH,0AH,'Type Y if you want to Continue : $'
              
 .CODE
   MAIN PROC
     MOV AX,@DATA                
     MOV DS,AX

     START:                     
     MOV AH,9                   
     LEA DX,ENTER               
     INT 21H

     XOR CX,CX                   
     MOV AH,1                    

     INPUT:                      
       INT 21H                   
       CMP AL,0DH                
       JE  END_INPUT             

       CMP AL,"["                
       JE  BRACKET          

       CMP AL,"{"                
       JE  BRACKET          

       CMP AL,"("                
       JE  BRACKET          

       CMP AL,")"                
       JE  ROUND         
                                   
       CMP AL,"}"               
       JE  CURLY         

       CMP AL,"]"               
       JE  SQUARE       

       JMP INPUT                

       BRACKET:           
       PUSH AX                   
       INC CX                    
       JMP INPUT                 

       ROUND:           
       POP DX                    
       DEC CX                    

       CMP CX,0                  
       JL  R_BRACKETS        

       CMP DL,"("                
       JNE MISMATCH              
       JMP INPUT                 
       
       CURLY:           
       POP DX                    
       DEC CX                    

       CMP CX,0                  
       JL  R_BRACKETS        

       CMP DL,"{"                
       JNE MISMATCH              
       JMP INPUT                 

       SQUARE:                                             
       POP DX                    
       DEC CX                    

       CMP CX,0                 
       JL  R_BRACKETS        

       CMP DL,"["               
       JNE MISMATCH             
     JMP INPUT                   

     END_INPUT:                  
     CMP CX,0                    
     JNE L_BRACKETS           

     MOV AH,9                    

     LEA DX,CORRECT                 
     INT 21H                      

     LEA DX,Y                 
     INT 21H                       

     MOV AH,1                    
     INT 21H                     

     CMP AL,"Y"                  
     JNE EXIT                    
     JMP START                   

     MISMATCH:                 
     MOV AH,9
     LEA DX,AGAIN                                     
     INT 21H

     JMP START                   

     L_BRACKETS:              
     MOV AH,9
     LEA DX,LEFT                 
     INT 21H

     JMP START                   

     R_BRACKETS:             
     MOV AH,9
     LEA DX,RIGHT                 
     INT 21H

     JMP START                   

     EXIT:                     
     MOV AH,4CH                  
     INT 21H
   MAIN ENDP
 END MAIN
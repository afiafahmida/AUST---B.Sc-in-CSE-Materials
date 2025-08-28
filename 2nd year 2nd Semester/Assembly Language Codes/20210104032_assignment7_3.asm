.MODEL SMALL
.STACK 100H

 .DATA
   MSG1   DB  'Enter a Hexadecimal number: $'
   MSG2  DB  0DH,0AH,'Enter another Hexadecimal number: $'                         
   SUM  DB  0DH,0AH,'Their sum : $'
   AGAIN   DB  0DH,0AH,'Please enter valid Hexadecimal numbers! $'
   COUNT   DB  ?
   TEMP    DW  ?

 .CODE
   MAIN PROC
     MOV AX, @DATA                
     MOV DS, AX

     JMP FIRST              

     TOP:                   
     LEA DX, AGAIN          
     MOV AH, 9
     INT 21H 
     MOV AH, 2
     MOV DL, 0AH
     INT 21H
     MOV DL, 0DH
     INT 21H
     

     FIRST:                   
       LEA DX, MSG1         
       MOV AH, 9
       INT 21H

       XOR BX, BX                
       MOV COUNT, 30H             

     PROCEED:                  
       MOV AH, 1               
       INT 21H                    

       CMP AL, 0DH                
       JNE NO_ENTER               

       CMP COUNT, 30H             
       JBE TOP                    
       JMP SECOND_INPUT                 

       NO_ENTER:                  

       CMP AL, "A"               
       JB DECIMAL_1               
       CMP AL, "F"                
       JA TOP                      
       
       ADD AL, 09H                
       JMP BINARY                  

       DECIMAL_1:                
       CMP AL, 30H              
       JB TOP                   

       CMP AL, 39H              
       JA TOP                   

       BINARY:                    
       INC COUNT                 

       AND AL, 0FH                

       MOV CL, 4                  
       SHL AL, CL                 

       MOV CX, 4                 
         
         
       LOOP1:                   
       SHL AL, 1                  
       RCL BX, 1                  
       LOOP LOOP1                

       CMP COUNT, 34H             
       JE SECOND_INPUT                 
       JMP PROCEED              
          
          
       SECOND_INPUT:                    

       MOV TEMP, BX             

       LEA DX, MSG2           
       MOV AH, 9
       INT 21H

       XOR BX, BX                
       MOV COUNT, 30H             

       PROCEED_2:                 
         MOV AH, 1               
         INT 21H                  

         CMP AL, 0DH              
         JNE NO_ENTER_2           

         CMP COUNT, 30H           
         JBE TOP                  
         JMP RESULT              

         NO_ENTER_2:              

         CMP AL, "A"              
         JB DECIMAL_2             

         CMP AL, "F"              
         JA JUMP                  
        
        
         ADD AL, 09H              
         JMP BINARY_2                

         DECIMAL_2:              
           CMP AL, 30H            
           JB  JUMP               
           CMP AL, 39H            
           JA  JUMP               
           JMP BINARY_2

         JUMP:                   
           JMP TOP           

         BINARY_2:                

         INC COUNT                

         AND AL, 0FH             

         MOV CL, 4                
         SHL AL, CL               

         MOV CX, 4               

         LOOP2:                 
           SHL AL, 1             
           RCL BX, 1                                               
         LOOP LOOP2              

         CMP COUNT, 34H          
         JE RESULT                
         JMP PROCEED_2            

     RESULT:                  
     LEA DX, SUM               
     MOV AH, 9
     INT 21H

     ADD BX, TEMP               
     JNC SKIP                    
     MOV AH, 2                    
     MOV DL, 31H                  
     INT 21H                     
 
     SKIP:                       
     MOV COUNT, 30H              

     LOOP3:                     
       XOR DL, DL                 
       MOV CX, 4                  

       LOOP4:                   
         SHL BX, 1                
         RCL DL, 1                
       LOOP LOOP4                

       MOV AH, 2                 

       CMP DL, 9                 
       JBE NUMBER          
       SUB DL, 9                  
       OR DL, 40H                
       JMP DISPLAY              

       NUMBER:            
         OR DL, 30H               

       DISPLAY:                 
         INT 21H                  

       INC COUNT                  
       CMP COUNT, 34H             
       JNE LOOP3               

     EXIT:                      

     MOV AH, 4CH                  
     INT 21H
   MAIN ENDP
 END MAIN
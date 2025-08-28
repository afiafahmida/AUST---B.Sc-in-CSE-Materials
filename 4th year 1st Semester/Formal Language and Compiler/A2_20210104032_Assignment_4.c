#include<stdio.h>
#include<string.h>

int error;

struct symbolTable
{
    char name[20][20];
    char idType[20][20];
    char dataType[20][20];
    char scope[20][20];
} sTable;

int p = 0;
void insert(char n[], char iT[], char dT[], char scp[])
{
    strcpy(sTable.name[p],n);
    strcpy(sTable.idType[p],iT);
    strcpy(sTable.dataType[p],dT);
    strcpy(sTable.scope[p],scp);
    p++;
}

int lookUp(char n[],char scp[])
{
    for(int i = 0; i<p; i++)
        if(!strcmp(sTable.name[i],n))
        {

            if(!strcmp(sTable.idType[i],"func"))
                return (i+1);
            else if(!strcmp(sTable.scope[i],scp) || !strcmp(scp,"global") || !strcmp(sTable.scope[i],"global"))
            {
                return (i+1);
            }
        }
    return 0;
}


int id(char lex[])
{
    int i = 0, len, flag;
    if(isalpha(lex[i]) || (lex[i]=='_'))
    {
        flag=1;
        i++;
    }
    else
        flag=0;
    len=strlen(lex);
    if(flag)
    {
        for(; i<len; i++)
        {
            if(isalpha(lex[i]) || (lex[i]=='_') || isdigit(lex[i]))
            {
                flag=1;
            }
            else
            {
                flag=0;
                break;
            }
        }
    }
    return flag;
}



void comment(FILE *fp)
{
    FILE *f;
    f= fopen("comment.txt","w");
    int putfi=1,parf=0,prif=1;
    char c,cb;
    while((c=getc(fp))!=EOF)
    {
        if(c=='(')
            parf = 1;
        if(c=='"' && parf)
            prif = 0;
        if(c== ')')
        {
            prif = 1;
            parf = 0;
        }
        if(prif)
        {
            if (c == cb && c==' ')
                putfi = 0;
            if(c=='/')
            {
                while(c=getc(fp))
                {
                    if(c=='/')
                    {
                        while((c=getc(fp) )!= '\n');
                        break;
                    }
                    else if(c=='*')
                        while((c=getc(fp) )!= '/');
                    putfi=0;
                    break;
                }
            }
        }
        if(putfi)
            fputc(c,f);
        putfi=1;
        cb = c;
    }
    fclose(f);

}



void lineNum(FILE *fp, char inp[],int inpi)
{
    int num=1;
    fprintf(fp,"%d ",num);
    for(int i = 0; i<inpi; i++)
    {
        while(inp[i]!='\n')
        {
            fputc(inp[i],fp);
            i++;
        }
        fputc(inp[i],fp);
        num++;
        fprintf(fp,"%d ",num);
    }
}



int forloop(char inp[],int k)
{
    k--;
    while(inp[k]==' ' && inp[k]!='(')
    {
        k--;
    }

    if(inp[k]=='(')
    {
        if(inp[k-3]=='f' && inp[k-2]=='o' && inp[k-1]=='r')
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

void identifierError(char inp[],int inpi)
{
    FILE *ptr;
    char c,word[20],kword[20],keyW[20]=" ",idW[20]=" ",linec[20];
    int j=0,kwf,idf,wf;
    char scope[20]="global";
    ptr = fopen("space.txt","w");
    for(int i=1; i<inpi; i++)
    {
        if(inp[i]=='(' || inp[i]==';' || inp[i]==',' || inp[i]==')' || inp[i]=='=' || inp[i]=='<')
            fprintf(ptr," %c ",inp[i]);
        else
            fputc(inp[i],ptr);
    }
    fclose(ptr);
    inpi=0;
    ptr= fopen("space.txt","r");
    while((c=fgetc(ptr))!=EOF)
    {
        inp[inpi] = c;
        inpi++;
    }
    fclose(ptr);
    for(int i=0; i<inpi; i++)
    {
        if(inp[i]=='\n')
        {
            strcpy(keyW," ");
            strcpy(idW," ");
            idf=0;
            kwf=0;
            i++;
            j=0;
            while(inp[i] != ' ')
            {
                linec[j] = inp[i];
                i++;
                j++;
            }
            linec[j] = '\0';
            continue;
        }
        if(inp[i]=='}')
        {
            strcpy(scope,"global");
        }
        j=0;
        while(inp[i] != ' ')
        {
            word[j] = inp[i];
            i++;
            j++;
        }
        word[j] = '\0';
        wf = 1;

        ptr = fopen("keyword.txt","r");
        while(fscanf(ptr,"%s ",kword)==1)
        {
            if(!strcmp(kword,word))
            {
                if(kwf && !strcmp(word,keyW) && strcmp(word,"else"))
                {
                    printf("\nDuplicate keyword detected at line %s",linec);
                }
                strcpy(keyW,word);
                kwf = 1;
                wf=0;
            }
        }
        fclose(ptr);



        if(id(word) && wf)
        {
            strcpy(idW,word);
            idf=1;
        }
        if(idf && kwf && strcmp(idW," ") && strcmp(keyW," ") && keyW[0]!='e' && keyW[0]!='r' )
        {
            i++;
            j=0;
            while(inp[i] != ' ')
            {
                word[j] = inp[i];
                i++;
                j++;
            }
            word[j] = '\0';
            if(lookUp(idW,scope))
            {
                printf("\nDuplicate identifier detected at line %s",linec);
            }
            else if(!strcmp(word,"("))
            {

                insert(idW,"func",keyW,scope);
                strcpy(scope,idW);
            }
            else
            {

                insert(idW,"var",keyW,scope);
            }
            idf = 0;
            kwf = 0;
        }
        else if(idf && strcmp(idW," "))
        {
            if(!lookUp(idW,scope))
            {
                //printf("\nUndeclared identifier detected at line %s",linec);

            }
            idf = 0;
        }


    }
}


void unbalanced(char inp[],int inpi)
{
    char linec[20],linecB[20],lineP[20],lineD[20],lineD2[20];
    int i=0, flag=0;
    int j=0, countB=0,countP=0,k;
    int ifflag = 0;
    while(inp[i] != ' ')
    {
        linec[j] = inp[i];
        i++;
        j++;
    }
    linec[j] = '\0';
    for(i = 0; i<inpi; i++)
    {
        if(inp[i] == '\n')
        {
            if(countP>0)
            {
                error=1;
                printf("\nUnbalanced '(' at line %s",lineP);
                countP = 0;
            }
            i++;
            j=0;
            while(inp[i] != ' ')
            {
                linec[j] = inp[i];
                i++;
                j++;
            }
            linec[j] = '\0';
        }
        else if(inp[i] == '{')
        {
            countB++;
            strcpy(linecB,linec);
        }
        else if(inp[i] == '}')
            countB--;
        else if(inp[i] == '(')
        {
            countP++;

            strcpy(lineP,linec);
        }
        else if(inp[i]==';')
        {
            k=i;
            k++;
            while(inp[k]!=';' && inp[k]==' ')
                k++;
            if(inp[k]==';')
                if(!forloop(inp,i))
                {
                    if(strcmp(lineD2,linec))
                    {
                        error=1;
                        printf("\nDuplicate token at line %s",linec);
                        strcpy(lineD2,linec);
                    }
                }
        }
        else if(inp[i] == ')')
            countP--;
        else if(inp[i] == 'i' && inp[i+1] == 'f' && inp[i+2] == '(')
            {
                flag++;
                ifflag = 1;

            }

        else if(inp[i] == 'e' && inp[i+1] == 'l' && inp[i+2] == 's' && inp[i+3] == 'e')
        {

            if(!(inp[i+4] == 'i' && inp[i+5] == 'f'))
            {
                flag--;
            }
        }
        else
            ifflag =0;


        if(countB<0 && strcmp(lineD,linec))
        {
            error=1;
            printf("\nMisplaced '}' at line %s",linec);
            strcpy(lineD,linec);
            countB=0;
        }
        else if(countB < 0)
            countB = 0;

        if(countP<0 && strcmp(lineP,linec))
        {
            error=1;
            printf("\nMisplaced ')' at line %s",linec);
            strcpy(lineP,linec);
            countP=0;
        }
        else if(countP < 0)
            countP = 0;
        if(flag<0)
        {
            error=1;
            printf("\nUnmatched 'else' at line %s",linec);
            flag=0;
        }
    }
    if(countB)
        error=1;
    printf("\nMisplaced '{' at line %s",linecB);

}


int main()
{
    FILE *input, *fp;
    int i = 0;
    char in[1000], c;
    int j, count = 0;

    input = fopen("input.c", "r");
    comment(input);
    fclose(input);

    input = fopen("comment.txt", "r");
    while((c = getc(input))!=EOF)
    {
        in[i] = c;
        i++;
    }
    fclose(input);

    input = fopen("numline.txt", "w");
    lineNum(input, in, i);
    fclose(input);

    input = fopen("numline.txt", "r");
    i = 0;
    printf("Intermediate Output:\n");
    while((c = getc(input))!= EOF)
    {
        printf("%c",c);
        in[i]=c;
        i++;
    }
    fclose(input);

    printf("\n\nDetected Errors:");

    unbalanced(in,i);
    identifierError(in,i);

    if(!error)
        printf("\nNo error.\n");

    return 0;

}


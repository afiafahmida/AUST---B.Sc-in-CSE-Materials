#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // For malloc and free

char a[10000], b[10000], temp[10000], c[1000][100];
int inde[10000];
int cur = 0;

struct data {
    char *name;
    char *idType;
    char *dataType;
    char *scope;
    char *value;
} v[100];

void insert(int ind, char* _name, char* _id, char* _dat, char* _scope, char* _value) {
    v[ind].name = strdup(_name);  // Allocate memory for name
    v[ind].idType = strdup(_id);  // Allocate memory for idType
    v[ind].dataType = strdup(_dat);  // Allocate memory for dataType
    v[ind].scope = strdup(_scope);  // Allocate memory for scope
    v[ind].value = strdup(_value);  // Allocate memory for value
}

void display() {
    int i = 0;
    printf("\nSl. No.\t\tName\t\tId Type\t\tData Type\tScope\t\tValue\n");
    for (i = 0; i < cur; i++) {
        printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", i + 1, v[i].name, v[i].idType, v[i].dataType, v[i].scope, v[i].value);
    }
}

int lookup(char* _name, char* _id, char* _scope) {
    int i = 0;
    for (i = 0; i < cur; i++) {
        if (strcmp(v[i].name, _name) == 0 && strcmp(v[i].idType, _id) == 0 && strcmp(v[i].scope, _scope) == 0) {
            return i;
        }
    }
    return -1;
}

char* modify(char *x) {
    if (strlen(x) == 0)
        return x;
    if (x[0] >= '0' && x[0] <= '9')
        return x;
    return "";
}

void set_attribute(int cur, char* val) {
    free(v[cur].value);  // Free the previous value before setting the new one
    v[cur].value = strdup(val);  // Allocate new memory for value
}

void free_memory() {
    int i;
    for (i = 0; i < cur; i++) {
        free(v[i].name);
        free(v[i].idType);
        free(v[i].dataType);
        free(v[i].scope);
        free(v[i].value);
    }
}

int main() {
    int i, n, t, k, j, x = 0, y = 0, m;
    FILE* fp = fopen("input.txt", "r");  // Open the input file

    // Reading the file into array 'a'
    i = 0;
    while (fscanf(fp, "%c", &a[i]) != EOF) {
        i++;
    }
    a[i] = '\0';
    fclose(fp);

    // Step 1: Tokenization
    k = 0;
    for (i = 0; i < strlen(a); i++) {
        if (a[i] == '[') {
            b[k++] = a[i++];
            j = 0;
            while (a[i] != ' ') {
                temp[j++] = a[i];
                i++;
            }
            temp[j] = '\0';
            if (strcmp(temp, "id") == 0) {
                b[k++] = 'i';
                b[k++] = 'd';
                b[k++] = ' ';
            }
            i++;
            while (a[i] != ']') {
                b[k++] = a[i];
                i++;
            }
            b[k++] = a[i];
        }
    }
    b[k] = '\0';

    // Output Step 1
    printf("\nStep 1: \n");
    puts(b);

    // Write Step 1 to file
    fp = fopen("step1.txt", "w");
    fputs(b, fp);
    fclose(fp);

    // Step 2: Symbol Table Construction
    k = 0;
    for (i = 0; i < strlen(b); i++) {
        if (b[i] == '[') {
            j = 0;
            i++;
            while (b[i] != ']' && b[i] != ' ') {
                c[k][j++] = b[i++];
            }
            c[k][j] = '\0';
            k++;
            if (b[i] == ' ') {
                j = 0;
                i++;
                while (b[i] != ']') {
                    c[k][j++] = b[i++];
                }
                c[k][j] = '\0';
                k++;
            }
        }
    }

    // Step 2 logic for symbol table creation
    int it = 0;
    char *scope = "global";  // Default scope is global
    for (i = 0; i < k; i++) {
        if (strcmp(c[i], "id") == 0) {
            if (strcmp(c[i + 2], "(") == 0) {
                if (strcmp(c[i - 1], "int") == 0 || strcmp(c[i - 1], "double") == 0 || strcmp(c[i - 1], "float") == 0 || strcmp(c[i - 1], "char") == 0) {
                    inde[it++] = cur;
                    insert(cur++, c[i + 1], "func", c[i - 1], scope, "");
                    scope = c[i + 1];
                    i += 2;
                } else {
                    int pq = lookup(c[i + 1], "func", "global");
                    if (pq != -1)
                        inde[it++] = pq;
                    else
                        printf("\nID %s is not declared in global scope\n", c[i + 1]);
                    i += 2;
                }
            } else if (strcmp(c[i + 2], "=") == 0) {
                if (strcmp(c[i - 1], "int") == 0 || strcmp(c[i - 1], "double") == 0 || strcmp(c[i - 1], "float") == 0 || strcmp(c[i - 1], "char") == 0) {
                    if (lookup(c[i + 1], "var", scope) == -1) {
                        inde[it++] = cur;
                        insert(cur++, c[i + 1], "var", c[i - 1], scope, modify(c[i + 3]));
                    } else {
                        printf("\nID %s already declared in %s scope\n", c[i + 1], scope);
                    }
                } else {
                    int pq = lookup(c[i + 1], "var", scope);
                    if (pq == -1) {
                        printf("\nID %s is not declared in %s scope\n", c[i + 1], scope);
                    } else {
                        set_attribute(pq, modify(c[i + 3]));
                        inde[it++] = pq;
                    }
                }
                i += 2;
            } else if (strcmp(c[i + 2], ";") == 0 || strcmp(c[i + 2], ",") == 0 || strcmp(c[i + 2], ")") == 0) {
                if (strcmp(c[i - 1], "int") == 0 || strcmp(c[i - 1], "double") == 0 || strcmp(c[i - 1], "float") == 0 || strcmp(c[i - 1], "char") == 0) {
                    if (lookup(c[i + 1], "var", scope) == -1) {
                        inde[it++] = cur;
                        insert(cur++, c[i + 1], "var", c[i - 1], scope, "");
                    } else {
                        printf("\nID %s already declared in %s scope\n", c[i + 1], scope);
                    }
                    i += 2;
                } else {
                    if (lookup(c[i + 1], "var", scope) == -1) {
                        printf("\nID %s is not declared in %s scope\n", c[i + 1], scope);
                    } else {
                        inde[it++] = lookup(c[i + 1], "var", scope);
                    }
                    i += 2;
                }
            }
        } else if (strcmp(c[i], "}") == 0) {
            scope = "global";
        }
    }

    // Output Step 2 (symbol table)
    printf("\nStep 2: \n");
    display();

    // Write Step 2 to file
    fp = fopen("step2.txt", "w");
    it = 0;
    for (i = 0; i < strlen(b); i++) {
        if (b[i] == '[') {
            fputc(b[i], fp);
            i++;
            while (b[i] != ']') {
                fputc(b[i], fp);
                i++;
            }
            if (b[i] == ' ') {
                fputc(b[i], fp);
                j = 0;
                i++;
                while (b[i] != ']') {
                    i++;
                }
                fputc(inde[it] + 1 + '0', fp);
                it++;
            }
            fputc(b[i], fp);
        } else {
            fputc(b[i], fp);
        }
    }
    fclose(fp);

    // Free allocated memory
    free_memory();

    return 0;
}

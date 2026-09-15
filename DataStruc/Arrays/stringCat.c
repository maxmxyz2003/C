// C program to Append a Character to a String
#include <stdio.h>
#include <string.h>
int main(){
    // declare and initialize string
    char str[6] = "Geek";
    // declare and initialize char
    char ch = 's';
    // print string
    printf("Original String: %s\n", str);
    printf("Character to be appended: %c\n", ch);
    // append ch to str
    strncat(str, &ch, 1);
    // print string
    printf("Appended String: %s\n", str);
    printf("length String: %d\n", strlen(str));
    //printf("letter G inString: %d\n", strchr(str,0));
    strrev(str);
    //printf("letter G inString: %d\n", strchr(str,5));
    //strstr hallar subcadena en cadena 
    //sprintfsprintf(): Writes formatted data to a string.
    //strtok(): Splits a string into tokens.
    printf("Reversed String: %s\n", str);
    return 0;
}

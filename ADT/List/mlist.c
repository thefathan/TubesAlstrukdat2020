#include <stdio.h>
#include "boolean.h"
#include <string.h>
#include "list.c"


/* boolean checker(char input[],char check[]);
int strcmp (const char* str1, const char* str2);

int main() {
    char name[100];
    char cond1[] = "kjhasjhksfjkf";
    char cond2[] = "Ananta";
    int result;
    result = strcmp(cond2, cond1);
    if (result >= 0) {
        printf("%d",result);
        printf("True\n");
    }
    else if(result < 0) {
        printf("%d",result);
        printf("false\n");
    }  // read string
    return 0;
} 
*/

/* #include <stdio.h>
#include <string.h>

 int main()
{
    char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
    int result;

    // comparing strings str1 and str2
    result = strcmp(str1, str2);
    printf("strcmp(str1, str2) = %d\n", result);

    // comparing strings str1 and str3
    result = strcmp(str1, str3);
    printf("strcmp(str1, str3) = %d\n", result);

    return 0;
} */

int main() {
    List L; const char* komponen[255]; int tipe;
    
    L = MakeList();
    // L.A = "Coba Coba";
    L.TipeKomponen = 2;

    printf("%d", L.TipeKomponen);
    PrintList(L);
    printf("kjadjkka");
}
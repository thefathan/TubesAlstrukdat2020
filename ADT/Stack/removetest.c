#include <stdio.h>
#include "stack.c"

int main() {
   Stack S; int i = 1;
   char mark = '.';

   CreateEmptyStack(&S);
   //for (i=0; i<8; i++) {
   printf("cekcek\n");
   Sinfotype input = {"AMD Ryzen 13 1000GB", 6};
   printf("%d %s", input.kodeJenis, input.Nama);
   printf("%d\n", IsStackEmpty(S));
   Push(&S, input);
   //}
   printf("%d\n", IsStackEmpty(S));

   printf("cekcek");
   Sinfotype buang;
   if (i < MaxEl+2) {
      Pop(&S, &buang);
   }
   PrintStack(&S);

   printf("Disini mulai sekali pop\n");
   Sinfotype buang2;
   Pop(&S, &buang2);
   PrintStack(&S);
   printf("cekcek");
   return 0;
}






















//#include <stdio.h>
//#include "stack.c"

/* int MAXSIZE = 8;       
int stack[8];     
int top = -1;            

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}

int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}
*/
/* int main() {
    // push items on to the stack 
    Stack S; infotype x; int i = 1;
    CreateEmpty(&S);
    while (i <= 4) {
        scanf("%c\n", &x);
        Push(&S, x);
        i++;
    }


    // printf("Element at top of the stack: %d\n" , S->TOP);
    printf("Elements: \n");

    // print stack data 
    while(!IsEmpty(S)) {
            infotype data;
            Pop(&S, &data);
            printf("%c\n",data);
    }

    printf("Stack full: %s\n" , IsFull(S)?"true":"false");
    printf("Stack empty: %s\n" , IsEmpty(S)?"true":"false");
    
    return 0;
} */
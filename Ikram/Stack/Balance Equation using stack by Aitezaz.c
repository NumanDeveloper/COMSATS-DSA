#include<stdio.h>
#define max 100
struct stack{
    char array[max];
    int top;
}abc;
void push(char value);
char pop();
int priority(char g);

int main()
{
    abc.top=-1;
    int i=0,j=0,temp=0;
    char value;
   printf("Enter any Expression\n");
   gets(abc.array);

   for(i=0;i<max;i++)
   {
      if(abc.array[i]==NULL)
      {
          break;
      }
      j++;
   }
   for(i=0;i<j;i++)
   {
       if(abc.array[i]=='(')
       {
           push(abc.array[i]);
       }
       if(abc.array[i]=='{')
       {
           push(abc.array[i]);
       }
       if(abc.array[i]=='[')
       {
           push(abc.array[i]);
       }
       if(abc.array[i]==')')
       {
           value=pop();

           if( priority(value)!=1)
           {
              // printf("\nUnBalanced Expression\n");
              temp=1;
               break;
           }
       }
       if(abc.array[i]=='}')
       {
           value=pop();

           if( priority(value)!=2)
           {

               //printf("\nUnBalanced Expression\n");
                temp=1;
               break;
           }
       }
       if(abc.array[i]==']')
       {
           value=pop();

           if( priority(value)!=3)
           {
               //printf("\nUnBalanced Expression\n");
                temp=1;
               break;
           }
       }



       //printf("  %c",abc.array[i]);

   }
   //printf("\n%d\n Top %d",j,abc.top);
   if((abc.top!=-1))
   {
       temp=1;
   }
   if(temp==1)
   {
     printf("\nUnBalanced Expression\n");
   }
   else{
    printf("\nBalanced Expression\n");
   }

}

void push(char value){
    if(abc.top==max-1){
        printf("____________Stack Overflow___________________\n");
    }
    else{
        abc.top++;
        abc.array[abc.top]=value;
    }
}
char pop(){
    char value;
    if(abc.top==-1){
        printf("____________Stack Underflow___________________\n");
        //return;
    }
    else{
        value=abc.array[abc.top];
        abc.top--;
    }
    return value;
}
int priority(char g){
    if(g=='(' )
       {
        return 1;
       }
    if(g=='{')
        {
          return 2;
        }

    if(g=='[')
    {
       return 3;
    }
    if(g==')' )
       {
        return 4;
       }
    if(g=='}')
        {
          return 5;
        }

    if(g==']')
    {
       return 6;
    }

}

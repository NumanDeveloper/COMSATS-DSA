#include<stdio.h>
#define max 10
struct stack{
    char array[max];
    int top;
}abc;
void push(char value);
char pop();
void display();
int priority(char g);
int main(){
    abc.top=-1;
    int num,va,h=0;
    char a[max],b,c;

       printf("Please input the expression:\n\t");
       scanf("%c",&b);
       while(b!='c'){
            if((b=='[') || (b=='{') || (b=='(')){
                push(b);
               }
            if((b==']') || (b=='}') || (b==')')){
                c=pop();
                //va=priority(c);
                if(priority(b)!=priority(c))
                    printf("________Unbalanced Equation________");
                    h++;
               }
            scanf("%c",&b);

       }
       if(h!=0)
       {printf("________Balanced Equation________");}
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
void display(){
    int i;
    printf("\nArray     ");

    for(i=0;i<=abc.top;i++){
            if(abc.top==max)
            {
                printf("Overflow");
            }
            else{
                 printf("%c\t",abc.array[i]);
            }
   }
    printf("\nTop is = %d ",abc.top);
}
int priority(char g){
    if(g=='[' || g==']')
        return 1;
    if(g=='{' || g=='}')
        return 2;
    if(g=='(' || g==')')
        return 3;
}

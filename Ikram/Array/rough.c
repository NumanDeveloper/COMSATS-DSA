#include<stdio.h>
#define max 10
int main()
{
   char arr[max];
   printf("Enter any values\n");
   gets(arr);
   int i,j=0;
   //printf("%s",arr);
   for(i=0;i<max;i++)
   {
       if(arr[i]==NULL)
       {
           break;
       }
       j++;
   }
   printf("\n\nj=%d\n",j);
   for(i=0;i<j;i++)
   {
       printf("%c",arr[i]);
   }


}

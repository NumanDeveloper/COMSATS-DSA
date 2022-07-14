#include<stdio.h>
#define ma 10

struct stac{

    int arra[ma];
    int top;
}var;
void push(int value);
int pop();

int heap[100], n=0,counter=0;

void insertion(int value)
{
	if(n == 0)
	{
		heap[n] = value;
		n++;
	}

	else
	{
		int loc=1, temp, tempN = n;

		heap[n] = value;

		while(loc != 0)
		{
			loc = (tempN-1)/2;

			if(heap[loc] > heap[tempN])
			{
				temp = heap[loc];
				heap[loc] = heap[tempN];
				heap[tempN] = temp;
			}

			tempN = loc;
		}

		n++;
	}
	counter=n;
}

int deletion()
{
	int temp, left, right, tempN = 0, max=0,  ret;

	if(n == 0)
	{
		printf("\nNULL");
		return -1;
	}

	else
	{
		temp = heap[0];
		heap[0] = heap[n-1];
		heap[n-1] = temp;

		ret = heap[n-1];
		heap[n-1] = -1;

		while(heap[tempN] < heap[tempN*2+1] && heap[tempN] < heap[tempN*2+2])
		{
			left = 2*tempN + 1;
			right = 2*tempN + 2;

			if(heap[left] > heap[right])
			{
				max = left;
			}

			else max = right;

			if(heap[tempN] < heap[max])
			{
				temp = heap[tempN];
				heap[tempN] = heap[max];
				heap[max] = temp;
			}

			tempN = max;
		}
		n--;
	}

	return ret;
}
void shift_up()
{
    int temp1,i,j=0;
            for(i=0;i<n;i++)
            {
               for(j=i+1;j<n;j++)
                {
              if(heap[i]>heap[j])
              {
                  temp1=heap[i];
                  heap[i]=heap[j];
                  heap[j]=temp1;
              }
              //i++;
                }
            }
}
int main()
{
    var.top=-1;
	 int input;
    int i;
    int c;
    for(;;)
{

        printf("\n1.Insert value \n2.Sorting in descending order\n");
        scanf("%d",&c);
             switch(c)
    {
    case 1:
        {
            printf("Please enter any value\n");
            scanf("%d",&input);
            insertion(input);
            break;
        }

    case 2:
        {
            int var,var1,k=0;
            for(k=0;k<counter;k++)
            {
                var = deletion();
                push(var);
                shift_up();
            }
            printf("\n After sorting output\n");
            for(k=0;k<counter;k++)
            {
                var1=pop();
                printf("    %d\n",var1);
            }
            break;
        }
    }

}
return 0;
}
void push(int value){
    if(var.top==ma-1){
        printf("____________Stack Overflow___________________\n");
    }
    else{
        var.top++;
        var.arra[var.top]=value;
    }
}
int pop(){
    int value;
    if(var.top==-1){
        printf("____________Stack Underflow___________________\n");

    }
    else{
        value=var.arra[var.top];
        var.top--;
    }
    return value;
}

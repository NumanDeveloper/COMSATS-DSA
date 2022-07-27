#include<stdio.h>

int heap[100], n=0;
int heap2[100];

int k=0;

void insert_min(int value)
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
}
void insert_max(int value)
{
	if(k == 0)
	{
		heap2[k] = value;
		k++;
	}
	else
	{
		int loc=1, temp, tempN = k;
		heap2[k] = value;
		while(loc != 0)
		{
			loc = (tempN-1)/2;
			if(heap2[loc] < heap2[tempN])
			{
				temp = heap2[loc];
				heap2[loc] = heap2[tempN];
				heap2[tempN] = temp;
			}
			tempN = loc;
		}
		k++;
	}
}
int main()
{
        int input;
        int i, var;
    for(;;)
    {   int c;
    printf("\n1.Insertion\n2.change min heap into Max Heap\n3.Display min heap\n");
    scanf("%d",&c);
        switch(c)
        {
        case 1:
            {
                printf("\nEnter value\n");
                scanf("%d",&input);
                insert_min(input);
                break;
            }
        case 2:
            {
              for(i=0;i<n;i++)
              {
                  insert_max(heap[i]);
              }
               for(i=0; i<n; i++)
                {
                printf("\nValue : %d", heap2[i]);
                }
              break;
            }
        case 3:
            {
               for(i=0; i<n; i++)
                {
                printf("\nValue : %d", heap[i]);
                }
              break;
            }
        }
    }
	return 0;
}

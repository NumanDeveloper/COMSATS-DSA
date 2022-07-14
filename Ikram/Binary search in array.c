#include<stdio.h>
#define max 4
int array[max];
void sort();
void binary_search(int arr[]);
void linear_search(int b[]);
void Insertion_sort();
void quick_sort();
void selection_sort();
int main()
{
    int i=0,c=0;
    int x,y,z;
    printf("Enter %d values\n",max);
    for(i=0;i<max;i++)
    {
        scanf("%d",&array[i]);
    }



    for(;;)
    {
       printf("\n1.Linear Search\n2.Binary Search\n3.Insertion sort\n4.Quick Sort\n5.Selection Sort\n6.Display\n");
       scanf("%d",&c);
       switch(c)
    {
       case 1:
        {
            linear_search(array);
            break;
        }
       case 2:
        {
            binary_search(array);
            break;
        }
       case 3:
        {
            Insertion_sort();

            break;
        }
       case 4:
        {
                x=max-1;
                y=1;
                z=0;
            quick_sort(x,y,z);

            break;

        }
       case 5:
        {
            selection_sort();

            break;
        }
       case 6:
        {
             printf("\n     Display\n");
            for(i=0;i<max;i++)
            {
                printf(" %d\n",array[i]);
            }
            break;
        }
    }

    }


}
void linear_search(int b[])
{   int i=0,value=0;
    printf("\n enter number do you want to search\n");
    scanf("%d",&value);
    for(i=0;i<max;i++)
    {
        if(value==b[i])
        {
            printf("\nNumber found at position %d\n",i+1);
            return;
        }
    }
     printf("\nnumber not found\n");

}
void binary_search(int arr[])
{
    int high=0,low=0,middle=0,value=0;
     int i=0,j=0,temp;
     int a[max];
     printf("\n enter number do you want to search\n");
     scanf("%d",&value);
     for(i=0;i<max;i++)
     {
       a[i]=arr[i];
     }
    for(i=0;i<max;i++)
    {
        for(j=i+1;j<max;j++)
        {
            if(a[j]<a[i])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;

            }
        }
    }


       high=max;
    low=0;
    for(i=0;i<max;i++)
    {
        middle=(high+low)/2;
        if(a[middle]==value)
        {
            printf("\nNumber found at position %d\n",middle+1);
            return;
            //break;
        }
        else if(value<a[middle])
        {
            high=middle-1;
        }
        else
        {
            low=middle+1;
        }

    }
    printf("\nNumber not found\n");
}

void Insertion_sort()
{
    int count=0,j=0,temp=0;
    for(count=1;count<max;count++)
    {
        temp=array[count];
        j=count-1;
        while((j>=0)&&(temp<array[j]))
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=temp;
    }
}

void quick_sort(int up,int down,int lb)
{
   int i=0,temp=0;
    int a=array[lb];

       // for(up=d;up>=0;up--)
    while(up>=0)
    {
        if(array[up]<=a)
        {

          break;
        }
    }
     while(down<max)
    {
        if(array[down]>a)
        {

            break;
        }
    }


    printf("\n up %d down %d\n",up,down);
    if(up>down)
    {
        temp=array[down];
        array[down]=array[up];
        array[up]=temp;
    }
    else{
        temp=array[up];
        array[up]=array[lb];
        array[lb]=temp;
        lb=down;
        quick_sort(lb-1,0,lb);
        quick_sort(max-1,lb+1,lb);

    }
}
void selection_sort()
{
    int i=0,j=0,minj=0,minx=0;
    for(i=0;i<max-1;i++)
    {
        minj=i;
        minx=array[i];
        for(j=i+1;j<max;j++)
        {
            if(array[j]<minx)
            {
                minj=j;
                minx=array[j];
            }
        }
        array[minj]=array[i];
        array[i]=minx;
    }
}

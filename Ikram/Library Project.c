#include<stdio.h>               //importing libraries
#include<string.h>
#include<conio.h>
#include<stdlib.h>

#define IN 1
#define OUT 0

void Addbook(int );             //prototype of functions
void Searchbook();
void Update();
void Delete();
void Exit();
void menu();
struct Data
{                    //declaration of Struct
	int isbn;
	int status;
	char name[20];
	char author[20];
	char stats[5];
}book;

FILE *record;
                                //start of main
int main()
{
	printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO LIBRARAY MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n"); //Starting Display
	for(;;)
		menu();                 //calling of menu function
}
void menu()
{                    //displaying menu function
	int c,n,i;
	char d;
	printf("\n\n 1.Add Books\n");
	printf(" 2.Delete Books\n");
	printf(" 3.Search Books\n");
	printf(" 4.Update Record\n");
	printf(" 5.Exit");
	printf("\n\n CHOICE :\n");
	scanf("%d",&c);              // Scanning choice
	if(c==1)
	{
	    Addbook(i+1);
    }
	else if(c==2)
    {
		Delete();
        printf("*****Books Deleted successfully*****\n");                                           // calling of delete function
	}
	else if(c==3)
    {
		Searchbook();                                        // calling of searchbook function
	}
	else if(c==4)
	{
		Update();                                           // calling of update function
	}
	else if(c==5)
	{
		Exit();                                             // calling of Exit function
	}
}
void Addbook(int i)
{
    int n;
    record = fopen("record.txt","a+");

    printf("How many books do you want to enter  : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\t\t***** Book %d *****",i+1);
        printf("\nEnter The ISBN of The Book %d (Integer) :",i+1);
        scanf("%d",&book.isbn);
        fflush(stdin);
        printf("\nEnter The Name of The Book %d : ",i+1);
        gets(book.name);
        printf("\nEnter The Name of Author %d : ",i+1);
        fflush(stdin);
        gets(book.author);
        fprintf(record,"\n ISBN of Book : %d \n Book Name : %s \n Book Author Name : %s\n",book.isbn,book.name,book.author);
    }
    printf("*****Book added successfully*****");
    fclose(record);
                                        //closing file after Adding Information

}
void Searchbook()
{                                                     // Searching of Book
    int i,s,no;
    char Target[25],stats[3];
    int Found=0;
    if((record=fopen("record.txt","r"))==NULL)            // Checking File
    {
        printf(" ! The File is Empty...\n\n");
    }
    else
    {
		printf("\nSearch Book by :\ni) Name\nii) Author\niii) ISBN\n");
		scanf("%d",&s);
		switch(s)
		{                                          // Searching Book...... Starting of Switch Statement
            case 1:
                {
                    printf("\nEnter The Name Of Book : ");
                    scanf("%s",Target);
                    while(!feof(record)&& Found==0)
                    {
                        fscanf(record,"%d %s %s %d ", &book.isbn,book.name,book.author,&book.status);
                        if(strcmp(Target,book.name)==0)
                        Found=1;
                    }
                    if(Found==1)
                    {
                        if(book.status==IN)
                            strcpy(stats,"NOT");
                        else
                        {
                            strcpy(stats,"RES");
                            printf("\nThe Unique ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author is:  %s\nThe Book Status:%s\n\n",book.isbn,book.name,book.author,stats);
                        }
                    }
                    else if(!Found)
                        printf("! There is no such Entry...\n");
                    fclose(record);                                     // closing of File
                    break;
                }
            case 2:
                {
                    printf("\nEnter The Author Of Book : ");
                    scanf("%s",Target);
                    while(!feof(record)&& Found==0)                     // While loop (till END of FILE and Author Not found)
                    {
                        fscanf(record,"%d %s %s %d ", &book.isbn,book.name,book.author,&book.status);
                        if(strcmp(Target,book.author)==0)
                        Found=1;
                    }
                    if(Found)
                    {
                        if(book.status==IN)
                            strcpy(stats,"NOT");
                        else
                            strcpy(stats,"RES");
                        printf("\nThe Unique ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author is:  %s\nThe Book Status:%s\n\n",book.isbn,book.name,book.author,stats);
                    }
                    else if(!Found)
                    printf("! There is no such Entry...\n");
                    fclose(record);
                    break;
                }
            case 3:
                {
                    printf("\nEnter The ISBN Of Book : ");
                    scanf("%d",&no);
                    while(!feof(record)&& Found==0)
                    {
                        fscanf(record,"%d %s %s %d ", &book.isbn,book.name,book.author,&book.status);
                        if(book.isbn==no)
                            Found=1;
                    }
                    if(Found)
                    {
                        if(book.status==IN)
                            strcpy(stats,"NOT");
                        else
                            strcpy(stats,"RES");

                        printf("\nThe Unique ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author is:  %s\nThe Book Status:%s\n\n",book.isbn,book.name,book.author,stats);
                    }
                    else if(!Found)
                        printf("! There is no such Entry...\n");
                    fclose(record);
                    break;
                }
		}
    }
                                                // end of Switch

}
void Delete()
{                                  // Method For deleting book
	FILE *ptr;                                 // declaration of Pointer
	int n;

    printf("\nEnter the ISBN of the Book to Delete :");
    scanf("%d",&n);
	if((record=fopen("record.txt","r"))==NULL)
        printf(" ! The file is empty...\n\n");
    else
    {
    	ptr=fopen("new.txt","w");
    	while(!feof(record))
    	{
    		fscanf(record,"%d %s %s %d ", &book.isbn,book.name,book.author,&book.status);
			if(book.isbn!=n)
			{
                fprintf(record,"\n ISBN of Book : %d \n Book Name : %s \n Book Author Name : %s\n",book.isbn,book.name,book.author);
			}
		}
		fclose(record);
		fclose(ptr);
		remove("record.txt");
		rename("new.txt","record.txt");
	}
}

void Update(){                                      //Start of Updating Method
	FILE *ptr;
	int n;                                          // Declaration of Variables
	int status=IN;
	char name[20];
	char author[20];
	printf("Enter the ISBN of the Book to Update :");                   // Scanning Book Information
	scanf("%d",&n);
	printf("\nEnter Data to Update:\nName : ");
	scanf("%s",&name);
	printf("Author : ");
	scanf("%s",&author);


	if((record=fopen("record.txt","r"))==NULL)
        printf(" ! The file is empty...\n\n");
    else{
    	ptr=fopen("new.txt","w");
    	while(!feof(record)){                                    //Start of While loop
    		fscanf(record,"%d %s %s %d ", &book.isbn,book.name,book.author,&book.status);
			if(book.isbn==n){
				fprintf(ptr,"\n%d\t%s\t%s\t%d    \t",book.isbn,name,author,status);
			}
		else if(book.isbn!=n){
				fprintf(ptr,"\n%d\t%s\t%s\t%d    \t",book.isbn,book.name,book.author,book.status);
			}
		}
		fclose(record);                                 //Close of File
		fclose(ptr);
		remove("record.txt");
		rename("new.txt","record.txt");
		printf("\n\nRecord Updated Sucessfully !\n\n");

	}
}
void Exit(){                                                //Start of Method
	exit(0);
}
// End of Program

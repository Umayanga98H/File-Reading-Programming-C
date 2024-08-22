/******************************
Author Name: A.M.K.H.Umayanga
******************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct book    //user defined structured data type bk
{
    int book_id;          //structured data types
    char book_type[50];
    int quantity;
    float price;
    float total;

} bk;

 bk read_data();  //user defined function definitions
 bk total();

void main()   //main function
{
    printf("*************WELCOME TO Rathna Book Shop***************\n\n");

    bk book1,book2,book3,book4,book5;
    read_data();     //function call

}

bk read_data()     //user defined function to read and store data
 {
      bk newbk[5];
      int i;

      FILE *fp;
      char *ptr;    //dynamic memory allocation

	 fp=fopen("books_details.txt","r");
	 i=0;

	if(fp==NULL)
	{
		printf("Unable to read data file\n\n");
	}

	 ptr=(char*)calloc(100,sizeof(char));     //dynamic memory allocation

	 if(ptr==NULL)
     {
         printf("Memory cannot assign to ptr\n ");
     }

     else
      {
     printf("Book ID\t   Book type\t       Quantity\t           Price\n");

	while(fscanf(fp,"%d",&newbk[i].book_id)!=EOF)
	{
	    fscanf(fp,"%d",&newbk[i].book_id);          //reading data from the file
		fscanf(fp,"%s",newbk[i].book_type);
		fscanf(fp,"%d",&newbk[i].quantity);
		fscanf(fp,"%f",&newbk[i].price);


		printf("%-10d %-21s %-17d %-5.2f\n",newbk[i].book_id,newbk[i].book_type,newbk[i].quantity,newbk[i].price);
		i++;
    }
        }
         free(ptr);   //free memory

    total();    //function call

 }

bk total()    //user defined function to to process data in the array
{
    bk newbk[5];
    int i;

    FILE *fp;


	 fp=fopen("books_details.txt","r");
	 i=0;

	if(fp==NULL)
	{
		printf("Unable to read data file\n\n");
	}

	while(fscanf(fp,"%d",&newbk[i].book_id)!=EOF)
	{
	    fscanf(fp,"%d",&newbk[i].book_id);
		fscanf(fp,"%s",newbk[i].book_type);
		fscanf(fp,"%d",&newbk[i].quantity);
		fscanf(fp,"%f",&newbk[i].price);
		i++;
	}

    for(i=0;i<5;i++)
    {
    printf("\n");
    printf("Total of the %s is : Rs.%.2f",newbk[i].book_type, (float)newbk[i].quantity * newbk[i].price);  //calculate total books
    }

    float store_total;
    store_total=0;

    for(i=0;i<=5;i++)
         {
             newbk[i].total=(float)newbk[i].quantity * newbk[i].price;  //calculate total store value
             store_total=store_total+newbk[i].total;
         }

                  printf("\n\nThe total store value is : Rs.%.2f\n",store_total);
}


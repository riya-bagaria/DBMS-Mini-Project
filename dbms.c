#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
 	int room_no;
	char name[30];
	char disease[30];
	double charges;
}s1;
void input_data()
{
	char ch;
	
	FILE *file=fopen("data.txt","a+");
	if(file==NULL)
	{
		printf("Error in saving patient data");
		return;
	}
	while(1)
	{
		printf("Enter Room no: ");
		scanf("%d",&s1.room_no);
		printf("Enter Name: ");
		scanf("%s",s1.name);
		printf("Enter Disease: ");
		scanf("%s",s1.disease);
		printf("Enter Charges: ");
		scanf("%lf",&s1.charges);
		fprintf(file,"%d\t%s\t%s\t%lf\n",s1.room_no,s1.name,s1.disease,s1.charges);	
		printf("Add more data y/n");
		scanf("%c",&ch);
		ch = getchar();
		if(ch=='N'||ch=='n')
			break;
	}	
	fclose(file);
}

void print_data()
{
	FILE *file1=fopen("data.txt","r");
	
	if(file1==NULL)
	{
		printf("Error in reading patient data");
		return;
	}
	printf("\tRoom_no\tName\tDisease\t\tCharges\n");
	while(1)
	{
		if(feof(file1))
			break;
			
		fscanf(file1,"%d\t%s\t%s\t%lf\n",&s1.room_no,s1.name,s1.disease,&s1.charges);
		printf("\t%d\t%s\t%s",s1.room_no,s1.name,s1.disease);	
		if(strlen(s1.disease)<=7)
		printf("\t\t%.2lf\n",s1.charges);	
		else
		printf("\t%.2lf\n",s1.charges);	

	}	
	fclose(file1);
}

void dis_details(char dis[])
{
	FILE *file1=fopen("data.txt","r");
	if(file1==NULL)
	{
		printf("Error in reading patient data");
		return;
	}
		printf("\tRoom_no\t  Name\t\tCharges\n");
	while(1)
	{
		if(feof(file1))
			break;
			
		fscanf(file1,"%d\t%s\t%s\t%lf\n",&s1.room_no,s1.name,s1.disease,&s1.charges);
		if(strcasecmp(s1.disease,dis)==0)
		{
		printf("\t%d\t  %s",s1.room_no,s1.name);
		if(strlen(s1.name)>5)	
		printf("\t%.2lf\n",s1.charges);
		else
		printf("\t\t%.2lf\n",s1.charges);	
		}
	}
	fclose(file1);
}

int main()
{
	char dis[15];
	int choice;
	do
	{
		printf("\nChoose one\n1. Enter new records\n2. View patient records\n3. View details of patient having a particular disease\n4. Quit\n\n");
		scanf("%d",&choice);
			printf("\n===============================================================\n\n");
		switch(choice)
		{
			case 1:
				input_data();
				break;
			case 2:
				print_data();
				break;

			case 3:
				printf("Enter the disease you want to search for: ");
				scanf("%s",dis);
				dis_details(dis);
				break;
			case 4:
				printf("Quiting\n");
				return 0;
		}

		printf("\n================================================================\n");
	}while(1);
}

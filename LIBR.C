#include<stdio.h>
#include<conio.h>
#include<string.h>

#define RETURNTIME 15

//fuction declration
int passcfm();
void categoryPage();
void addbook();
void deletebook();
void searchbook();
void issuebook();
void viewbook();
void editbookrecord();
void issuerecord();
void loaderanim();

//variable declaration
char pass[10]={"chunnu"};
char passm[25];
int s;
char findbook;

//category declaration
char catagories[][15]={"Computer","Physics","Maths","Chemistry","Biology"};

//list of global files that can be acceed form anywhere in program
FILE *fp,*ft,*fs;


//sturcture for the book record
struct meroDate
{
    int mm,dd,yy;
};
struct books
{
    int id;
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    int rackno;
    char *cat;
    struct meroDate issued;
    struct meroDate duedate;
}a;
int main()
{
	int check=0;
	clrscr();
	check = passcfm();
	if(check == 1)
		categoryPage();
	//getch();
	return 0;
}

int passcfm()
{
	int i=0,ret;
	char ch;
	char head1[]={"Welcome"};
	char foot[]={"library"};
	clrscr();
	printf("\n\n");
	for(i=0;i<20;i++)
	{
		delay(50);
		printf("*");
	}
	delay(100);
	//printf("  Enter Password  ");
	printf("  ");
	for(i=0;i<7;i++)
	{
		printf("%c",head1[i]);
		delay(50);
	}
	printf("  ");
	delay(100);
	for(i=0;i<20;i++)
	{
		delay(50);
		printf("*");
	}
	printf("\n\n\n\n\nEnter the password (6 char) = ");
	i=0;
	while(ch!=13)
	{
		ch=getch();

		if(ch!=13 && ch!=8)
		{
			putch('*');
			passm[i] = ch;
			i++;
		}
	}
	fflush(stdin);
	printf("\n");
	if(strncmp(pass,passm,6)==0){
		gotoxy(18,5);
		for(i=0;i<7;i++)
		{
			delay(100);
			printf("%c",head1[i]);
		}
		for(i=0;i<4;i++)
		{
			delay(100);
			printf(" ");
		}
		for(i=0;i<7;i++)
		{
			delay(100);
			printf("%c",foot[i]);
		}
		delay(2000);
		return 1;
	}
	else {
		clrscr();
		printf("\nWarning. \nPlease enter correct password.\n");
		printf("\xB2\xB2  Closing in 3 sec \xDB\xDB");
		delay(3000);
		exit();
	}
	return 1;
}

void categoryPage()
{
	int i,temp=1;
	char head1[]={"Select"};
	char head2[]={"Category"};
	int choice;
	while(temp==1)
	{
		clrscr();
		printf("\n\n");             //to create animation
		for(i=0;i<20;i++)
		{
			delay(50);
			printf("*");
		}
		delay(100);
		//printf("  Select Category  ");
		printf("  ");
		for(i=0;i<6;i++)
		{
			printf("%c",head1[i]);
			delay(50);
		}
		printf(" ");
		for(i=0;i<8;i++)
		{
			printf("%c",head2[i]);
			delay(50);
		}
		printf("  ");
		delay(100);
		for(i=0;i<20;i++)
		{
			delay(50);
			printf("*");
		}
		printf("\n\n");
		printf("\n--1> Add Book");
		delay(50);
		printf("\n--2> Delete Book");
		delay(50);
		printf("\n--3> Search Book");
		delay(50);
		printf("\n--4> Issue Book");
		delay(50);
		printf("\n--5> View Book");
		delay(50);
		printf("\n--6> Edit Book Record");
		delay(50);
		printf("\n--7> Close Application");
		delay(50);
		printf("\n\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice)
		{
		    case 1:
			loaderanim();
			addbook();
			break;
		    case 2:
			loaderanim();
			deletebook();
			break;
		    case 3:
			loaderanim();
			searchbook();
			break;
		    case 4:
			loaderanim();
			issuebook();
			break;
		    case 5:
			loaderanim();
			viewbook();
			break;
		    case 6:
			loaderanim();
			editbookrecord();
			break;
		    case 7:
			loaderanim();
			temp=0;
			return;
		}
	}
}
void addbook()
{
	int i,temp=1;
	while(temp==1)
	{
		clrscr();
		gotoxy(20,5);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(20,7);
		printf("\xDB\xDB\xDB\xDB\xB2 1. Computer");
		gotoxy(20,9);
		printf("\xDB\xDB\xDB\xDB\xB2 2. physics");
		gotoxy(20,11);
		printf("\xDB\xDB\xDB\xDB\xB2 3. maths");
		gotoxy(20,13);
		printf("\xDB\xDB\xDB\xDB\xB2 4. chemistry");
		gotoxy(20,15);
		printf("\xDB\xDB\xDB\xDB\xB2 5. biology");
		gotoxy(20,17);
		gotoxy(20,19);
		printf("\xDB\xDB\xDB\xDB\xB2 6. Back to main menu");
		gotoxy(20,21);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(20,22);
		printf("Enter your choice:");
		scanf("%d",&s);
		fflush(stdin);
		if(s==6)
			return;
		//system("cls");
		fp=fopen("book.txt","ab+");
		if(getdata()==1)
		{
			a.cat=catagories[s-1];
			fseek(fp,0,SEEK_END);
			fwrite(&a,sizeof(a),1,fp);
			fclose(fp);
			gotoxy(21,14);
			printf("The record is sucessfully saved");
			gotoxy(21,15);
			printf("Save any more?(Y / N):");
			if(getch()=='n')
			    return;
		}
		fclose(fp);
		fflush(stdin);
	}
		return;
}

// supporting funtion
int getdata()
{
	int t;
	clrscr();
	gotoxy(20,3);
	printf("Enter the Information Below");
	gotoxy(20,4);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xB2");
	gotoxy(46,5);
	printf("\xB2");
	gotoxy(20,6);
	printf("\xB2");
	gotoxy(46,6);
	printf("\xB2");
	gotoxy(20,7);
	printf("\xB2");
	gotoxy(46,7);
	printf("\xB2");
	gotoxy(20,8);
	printf("\xB2");
	gotoxy(46,8);
	printf("\xB2");
	gotoxy(20,9);
	printf("\xB2");
	gotoxy(46,9);
	printf("\xB2");
	gotoxy(20,10);
	printf("\xB2");
	gotoxy(46,10);
	printf("\xB2");
	gotoxy(20,11);
	printf("\xB2");
	gotoxy(46,11);
	printf("\xB2");
	gotoxy(20,12);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(21,5);
	printf("Category:");
	gotoxy(31,5);
	printf("%s",catagories[s-1]);
	gotoxy(21,6);
	printf("Book ID:\t");
	gotoxy(30,6);
	scanf("%d",&t);
	fflush(stdin);
	if(checkid(t) == 0)
	{
		gotoxy(21,13);
		printf("\aThe book id already exists\a");
		getch();
		return 0;
	}
	fflush(stdin);
	a.id=t;
	gotoxy(21,7);
	printf("Book Name:");
	gotoxy(33,7);
	scanf("%s",a.name);
	gotoxy(21,8);
	printf("Author:");
	gotoxy(30,8);
	scanf("%s",a.Author);
	gotoxy(21,9);
	printf("Quantity:");
	gotoxy(31,9);
	scanf("%d",&a.quantity);
	gotoxy(21,10);
	printf("Price:");
	gotoxy(28,10);
	scanf("%f",&a.Price);
	gotoxy(21,11);
	printf("Rack No:");
	gotoxy(30,11);
	scanf("%d",&a.rackno);
	return 1;
}
int checkid(int t)  //check whether the book is exist in library or not
{
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	if(a.id==t)
	return 0;  //returns 0 if book exits
	return 1; //return 1 if it not
}

void deletebook()
{
	int d;
	char another='y';
	while(another=='y')  //infinite loop
	{
		clrscr();
		gotoxy(10,5);
		printf("Enter the Book ID to  delete:");
		scanf("%d",&d);
		fflush(stdin);
		fp=fopen("book.txt","rb+");
		rewind(fp);
		while(fread(&a,sizeof(a),1,fp)==1)
		{
		    fflush(stdin);
		    if(a.id==d)
		    {
			gotoxy(10,7);
			printf("The book record is available");
			gotoxy(10,8);
			printf("Book name is %s",a.name);
			gotoxy(10,9);
			printf("Rack No. is %d",a.rackno);
			findbook='t';
		    }
		}
		if(findbook!='t')
		{
		    gotoxy(10,10);
		    printf("No record is found modify the search");
		    if(getch())
		    return;
		}
		if(findbook=='t' )
		{
		    gotoxy(10,9);
		    printf("Do you want to delete it?(Y/N):");
		    if(getch()=='y')
		    {
			ft=fopen("test.txt","wb+");  //temporary file for delete
			rewind(fp);
			while(fread(&a,sizeof(a),1,fp)==1)
			{
			    if(a.id!=d)
			    {
				fseek(ft,0,SEEK_CUR);
				fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
			    }                              //we want to delete
			}
			fflush(stdin);
			fclose(ft);
			fclose(fp);
			remove("book.txt");
			rename("test.txt","book.txt"); //copy all item from temporary file to fp except that
			fp=fopen("book.txt","rb+");    //we want to delete
			if(findbook=='t')
			{
			    gotoxy(10,10);
			    printf("The record is sucessfully deleted");
			    gotoxy(10,11);
			    printf("Delete another record?(Y/N)");
			}
		    }
		else
		return;
		fflush(stdin);
		another=getch();
		}
	}
	gotoxy(10,15);
	return;
}
void  searchbook()
{
	int d;
	REDESIGN:
	clrscr();
	printf("*****************************  Search Books  *********************************");
	gotoxy(20,10);
	printf("\xDB\xDB\xDB\xB2 1. Search By ID");
	gotoxy(20,14);
	printf("\xDB\xDB\xDB\xB2 2. Search By Name");
	gotoxy( 15,20);
	printf("Enter Your Choice");
	fp=fopen("book.txt","rb+"); //open file for reading propose
	rewind(fp);   //move pointer at the begining of file
	switch(getch())
	{
		case '1':
		{
			clrscr();
			gotoxy(25,4);
			printf("****Search Books By Id****");
			gotoxy(20,5);
			printf("Enter the book id:");
			scanf("%d",&d);
			fflush(stdin);
			gotoxy(20,7);
			printf("Searching........");
			while(fread(&a,sizeof(a),1,fp)==1)
			{
				if(a.id==d)
				{
					delay(2);
					gotoxy(20,7);
					printf("The Book is available");
					gotoxy(20,8);
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					gotoxy(20,9);
					printf("\xB2 ID:%d",a.id);
					gotoxy(47,9);
					printf("\xB2");
					gotoxy(20,10);
					printf("\xB2 Name:%s",a.name);
					gotoxy(47,10);
					printf("\xB2");
					gotoxy(20,11);
					printf("\xB2 Author:%s ",a.Author);
					gotoxy(47,11);
					printf("\xB2");
					gotoxy(20,12);
					printf("\xB2 Qantity:%d ",a.quantity);
					gotoxy(47,12);
					printf("\xB2");
					gotoxy(47,11);
					printf("\xB2");
					gotoxy(20,13);
					printf("\xB2 Price:Rs.%.2f",a.Price);
					gotoxy(47,13);
					printf("\xB2");
					gotoxy(20,14);
					printf("\xB2 Rack No:%d ",a.rackno);
					gotoxy(47,14);
					printf("\xB2");
					gotoxy(20,15);
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					findbook='t';
				}

			}
			fflush(stdin);
			if(findbook!='t')  //checks whether conditiion enters inside loop or not
			{
				gotoxy(20,8);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				gotoxy(20,9);
				printf("\xB2");
				gotoxy(38,9);
				printf("\xB2");
				gotoxy(20,10);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				gotoxy(22,9);
				printf("\aNo Record Found");
			}
			gotoxy(20,17);
			printf("Try another search?(Y/N)");
			if(getch()=='y')
			{
				fclose(fp);
				goto REDESIGN;
			}
			else
			{
				fclose(fp);
				return ;
			}
			//break;
		}
		case '2':
		{
			char s[15];
			clrscr();
			gotoxy(25,4);
			printf("****Search Books By Name****");
			gotoxy(20,5);
			printf("Enter Book Name:");
			scanf("%s",s);
			fflush(stdin);
			d=0;
			while(fread(&a,sizeof(a),1,fp)==1)
			{
				if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
				{
					gotoxy(20,7);
					printf("The Book is available");
					gotoxy(20,8);
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					gotoxy(20,9);
					printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
					gotoxy(20,10);
					printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
					gotoxy(20,11);
					printf("\xB2 Author:%s",a.Author);gotoxy(47,11);printf("\xB2");
					gotoxy(20,12);
					printf("\xB2 Qantity:%d",a.quantity);gotoxy(47,12);printf("\xB2");
					gotoxy(20,13);
					printf("\xB2 Price:Rs.%.2f",a.Price);gotoxy(47,13);printf("\xB2");
					gotoxy(20,14);
					printf("\xB2 Rack No:%d ",a.rackno);gotoxy(47,14);printf("\xB2");
					gotoxy(20,15);
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					d++;
				}

			}
			fflush(stdin);
			if(d==0)
			{
				gotoxy(20,8);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				gotoxy(20,9);
				printf("\xB2");
				gotoxy(38,9);
				printf("\xB2");
				gotoxy(20,10);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				gotoxy(22,9);
				printf("\aNo Record Found");
			}
			gotoxy(20,17);
			printf("Try another search?(Y/N)");
			if(getch()=='y')
			{
				fclose(fp);
				goto REDESIGN;
			}
			else
			{
				fclose(fp);
				return ;
			}

		}
		default :
			getch();
			fclose(fp);
			goto REDESIGN;
	}
}
void issuebook()
{
	int t,j,c,p,b;
	char another;
	TOP:clrscr();
	printf("********************************  ISSUE SECTION  **************************");
	gotoxy(10,5);
	printf("\xDB\xDB\xDB\xDb\xB2 1. Issue a Book");
	gotoxy(10,7);
	printf("\xDB\xDB\xDB\xDb\xB2 2. View Issued Book");
	gotoxy(10,9);
	printf("\xDB\xDB\xDB\xDb\xB2 3. Search Issued Book");
	gotoxy(10,11);
	printf("\xDB\xDB\xDB\xDb\xB2 4. Remove Issued Book");
	gotoxy(10,14);
	printf("Enter a Choice:");
	switch(getch())
	{
		case '1':  //issue book
		{
			//system("cls");
			clrscr();
			c=0;
			another='y';
			while(another=='y')
			{
				clrscr();
				gotoxy(15,4);
				printf("***Issue Book section***");
				gotoxy(10,6);
				printf("Enter the Book Id:");
				scanf("%d",&t);
				fflush(stdin);
				fp=fopen("book.txt","rb");
				fs=fopen("Issue.txt","ab+");
				if(checkid(t)==0) //issues those which are present in library
				{
					gotoxy(10,8);
					printf("The book record is available");
					gotoxy(10,9);
					printf("There are %d unissued books in library ",a.quantity);
					gotoxy(10,10);
					printf("The name of book is %s",a.name);
					gotoxy(10,11);
					printf("Enter student name:");
					scanf("%s",a.stname);
					fflush(stdin);
					gotoxy(10,12);
					printf("Issued date=%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
					gotoxy(10,13);
					printf("The BOOK of ID %d is issued",a.id);
					a.duedate.dd=a.issued.dd+RETURNTIME;   //for return date
					a.duedate.mm=a.issued.mm;
					a.duedate.yy=a.issued.yy;
					if(a.duedate.dd>30)
					{
						a.duedate.mm+=a.duedate.dd/30;
						a.duedate.dd-=30;
					}
					if(a.duedate.mm>12)
					{
						a.duedate.yy+=a.duedate.mm/12;
						a.duedate.mm-=12;
					}
					gotoxy(10,14);
					printf("To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
					fseek(fs,sizeof(a),SEEK_END);
					fwrite(&a,sizeof(a),1,fs);
					fclose(fs);
					c=1;
				}
				if(c==0)
				{
					gotoxy(10,11);
					printf("No record found");
				}
				gotoxy(10,15);
				printf("Issue any more(Y/N):");
				fflush(stdin);
				another=getche();
				fclose(fp);
			}
			break;
		}
		case '2':  //show issued book list
		{
			clrscr();
			j=4;
			printf("*******************************Issued book list*******************************\n");
			gotoxy(2,2);
			printf("STUDENT NAME    CATEGORY    ID    BOOK NAME    ISSUED DATE    RETURN DATE");
			fs=fopen("Issue.txt","rb");
			while(fread(&a,sizeof(a),1,fs)==1)
			{

				gotoxy(2,j);
				printf("%s",a.stname);
				gotoxy(18,j);
				printf("%s",a.cat);
				gotoxy(30,j);
				printf("%d",a.id);
				gotoxy(36,j);
				printf("%s",a.name);
				gotoxy(51,j);
				printf("%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy );
				gotoxy(65,j);
				printf("%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
				gotoxy(50,25);
				j++;

			}
			getch();
			fclose(fs);
			gotoxy(1,25);
			return;
		}
		case '3':   //search issued books by id
		{
			clrscr();
			c=0;
			another='y';
			while(another=='y')
			{
				clrscr();
				gotoxy(10,6);
				printf("Enter Book ID:");
				scanf("%d",&p);
				fflush(stdin);
				fs=fopen("Issue.txt","rb");
				while(fread(&a,sizeof(a),1,fs)==1)
				{
					if(a.id==p)
					{
						issuerecord();
						gotoxy(10,12);
						printf("Press any key.......");
						getch();
						c=1;
					}

				}
				fflush(stdin);
				fclose(fs);
				if(c==0)
				{
					gotoxy(10,8);
					printf("No Record Found");
				}
				gotoxy(10,13);
				printf("Try Another Search?(Y/N)");
				another=getch();
			}
		}
		break;
		case '4':  //remove issued books from list
		{
			clrscr();
			another='y';
			while(another=='y')
			{
				clrscr();
				gotoxy(10,5);
				printf("Enter book id to remove:");
				scanf("%d",&b);
				fs=fopen("Issue.txt","rb+");
				while(fread(&a,sizeof(a),1,fs)==1)
				{
					if(a.id==b)
					{
						issuerecord();
						gotoxy(10,12);
						printf("Press any key....");
						getch();
						findbook='t';
					}
				}
				if(findbook=='t')
				{
					gotoxy(10,14);
					printf("Do You Want to Remove it?(Y/N)");
					if(getch()=='y')
					{
						ft=fopen("record.txt","wb+");
						rewind(fs);
						while(fread(&a,sizeof(a),1,fs)==1)
						{
							if(a.id!=b)
							{
								fseek(fs,0,SEEK_CUR);
								fwrite(&a,sizeof(a),1,ft);
							}
						}
						fflush(stdin);
						fclose(fs);
						fclose(ft);
						remove("Issue.txt");
						rename("record.txt","Issue.txt");
						gotoxy(10,16);
						printf("The issued book is removed from list");
						fflush(stdin);
				       }
				}
				if(findbook!='t')
				{
					gotoxy(10,15);
					printf("No Record Found");
				}
				gotoxy(10,20);
				printf("Delete any more?(Y/N)");
				another=getch();
			}
			break;
		}
		default:
			gotoxy(10,18);
			printf("\aWrong Entry!!");
			getch();
			goto TOP;
	 }
	 gotoxy(1,30);
	 return;
}

//supported Funtion
void issuerecord()  //display issued book's information
{
		 clrscr();
		 gotoxy(10,8);
		 printf("The Book has taken by Mr. %s",a.stname);
		 gotoxy(10,9);
		 printf("Issued Date:%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
		 gotoxy(10,10);
		 printf("Returning Date:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
}
void viewbook()
{
	int i=0,j;
	clrscr();
	gotoxy(1,1);
	printf("*********************************  Book List  *****************************");
	gotoxy(2,2);
	printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
	j=4;
	fp=fopen("book.txt","rb");
	while(fread(&a,sizeof(a),1,fp)==1)
	{
		gotoxy(3,j);
		printf("%s",a.cat);
		gotoxy(16,j);
		printf("%d",a.id);
		gotoxy(22,j);
		printf("%s",a.name);
		gotoxy(36,j);
		printf("%s",a.Author);
		gotoxy(50,j);
		printf("%d",a.quantity);
		gotoxy(57,j);
		printf("%.2f",a.Price);
		gotoxy(69,j);
		printf("%d",a.rackno);
		printf("\n\n");
		j++;
		i=i+a.quantity;
	}
	gotoxy(3,25);
	printf("Total Books =%d",i);
	fclose(fp);
	gotoxy(35,25);
	getch();
}
void editbookrecord()
{
	int c=0;
	int d,e;
	char another='y';
	clrscr();
	gotoxy(20,4);
	printf("****  Edit Books Section  ****");
	while(another=='y')
	{
		system("cls");
		gotoxy(15,6);
		printf("Enter Book Id to be edited:");
		scanf("%d",&d);
		fp=fopen("book.txt","rb+");
		while(fread(&a,sizeof(a),1,fp)==1)
		{
			if(checkid(d)==0)
			{
				gotoxy(15,7);
				printf("The book is availble");
				gotoxy(15,8);
				printf("The Book ID:%d",a.id);
				gotoxy(15,9);
				printf("Enter new name:");scanf("%s",a.name);
				fflush(stdin);
				gotoxy(15,10);
				printf("Enter new Author:");scanf("%s",a.Author);
				fflush(stdin);
				gotoxy(15,11);
				printf("Enter new quantity:");scanf("%d",&a.quantity);
				fflush(stdin);
				gotoxy(15,12);
				printf("Enter new price:");scanf("%f",&a.Price);
				fflush(stdin);
				gotoxy(15,13);
				printf("Enter new rackno:");scanf("%d",&a.rackno);
				fflush(stdin);
				gotoxy(15,14);
				printf("The record is modified");
				fseek(fp,ftell(fp)-sizeof(a),0);
				fwrite(&a,sizeof(a),1,fp);
				fclose(fp);
				c=1;
			}
			if(c==0)
			{
				gotoxy(15,9);
				printf("No record found");
			}
		}
		gotoxy(15,16);
		printf("Modify another Record?(Y/N)");
		fflush(stdin);
		another=getch() ;
	}

}
void loaderanim()
{
	int loader;
	clrscr();
	gotoxy(20,10);
	printf("LOADING........");
	printf("\n\n");
	gotoxy(20,11);
	for(loader=1;loader<30;loader++)
	{
		delay(50);
		printf("%c",219);
	}
}
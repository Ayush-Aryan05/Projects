#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<bits/stdc++.h>
#include"customer.cpp"
using namespace std;
int login(){
	int i;
	string Iusername;
    string Ipassword;
	cout<<"\n\n\t Enter the username : ";
    fflush(stdin);
	cin>>Iusername;
	cout<<"\n\n\t Enter the password : ";
    fflush(stdin);
	cin>>Ipassword;

    if(Iusername=="admin" && Ipassword=="password")
      return 1;
      else {
		  return 0;
	  }
}

 
class bookshope
{   int no_copy;
    double price;
		string b_name,a_name,b_id;
	public:
		void control_panel(); 
		void add_book();
		void show_books();
		void check_book();
		void update_book();
		void del_book();
};
	void bookshope::control_panel()
	{
		system("cls");
		cout<<"\n\n\t\t\t\tControl Panel";
		cout<<"\n\n 1. Add New Book";
		cout<<"\n 2. Display Books";
		cout<<"\n 3. Check Specific Book";
		cout<<"\n 4. Update Book";
		cout<<"\n 5. Delete Book";
		cout<<"\n 6. Exit";
	}
	
	void bookshope::add_book()
	{  int flag=0;
	   int flag1=0;
	   int id_chk=0;
		system("cls");
		fstream file;
		int no_copy;
		
		string b_name,a_name,b_idd;
		cout<<"\n\n\t\t\t\t ADD New Book";
		cout<<"\n\n Book ID : ";
		cin>>b_idd;
		file.open("book.txt",ios::in);
		file>>b_id>>b_name>>a_name>>no_copy>>price;
			while(!file.eof())
			{   if(b_idd==b_id){id_chk=1; break;}
				file>>b_id>>b_name>>a_name>>no_copy>>price;
			}
			file.close(); 
        if(id_chk==0){
		cout<<"\n\n Book Name : ";
		cin>>b_name;
		cout<<"\n\n Author Name : ";
		cin>>a_name;
		cout<<"\n\n No. of Copies : ";
		cin>>no_copy;
		cout<<"\n\n Price of the book : ";
		cin>>price;
		if(no_copy<0){
			flag=1;
			cout<<"\n Invalid No. Of copies entered.....";
		}
		if(price < 0)
		{
			flag1=1;
			cout<<"\n Invalid Price Entered......";
		}
		if(flag==0 && flag1==0)
		{
		file.open("book.txt",ios::out|ios::app);
		file<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<" "<<price<<"\n";
		file.close();}
		}
		else{
			cout<<"\n\n Same ID exist please update it.....";
		}
	}
	
	void bookshope::show_books()
	{
		system("cls");
		fstream file;
		// int no_copy
		// string b_name,b_id,a_name;
		cout<<"\n\n\t\t\t\tShow All Books";
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID    Book    Author    No. of Copies     Price\n\n";
			file>>b_id>>b_name>>a_name>>no_copy>>price;
			while(!file.eof())
			{
				cout<<"   "<<b_id<<"     "<<b_name<<"     "<<a_name<<"\t\t"<<no_copy<<" \t    "<<price<<"\n\n";
				file>>b_id>>b_name>>a_name>>no_copy>>price;
			}
			file.close();
		}
	}
	
	void bookshope::check_book()
	{
		system("cls");
		fstream file;
		// int no_copy,count=0;
		int count=0;
		// string b_id,b_name,a_name;
		string b_idd;
		cout<<"\n\n\t\t\t\tCheck Specific Book";
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_idd;
			file>>b_id>>b_name>>a_name>>no_copy>>price;
			while(!file.eof())
			{
				if(b_idd == b_id)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tCheck Specific Book";
					cout<<"\n\n Book ID : "<<b_id;
					cout<<"\n\n\t\t\tName : "<<b_name;
					cout<<"\n\n Author : "<<a_name;
					cout<<"\n\n\t\t\tNo. of Copies : "<<no_copy;
					cout<<"\n\n Price is : "<<price;
					count++;
					break;	
				}
				file>>b_id>>b_name>>a_name>>no_copy>>price;
			}
			file.close();
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
	}
	
	void bookshope::update_book()
	{
		system("cls");
		fstream file,file1;
		int no_co,count=0,pri;
		string b_na,a_na,b_idd;
		cout<<"\n\n\t\t\t\tUpdate Book Record";
		file1.open("book1.txt",ios::app|ios::out);
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_idd;
			file>>b_id>>b_name>>a_name>>no_copy>>price;
			while(!file.eof())
			{
				if(b_idd == b_id)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tUpdate Book Record";
					cout<<"\n\n New Book Name : ";
					cin>>b_na;
					cout<<"\n\n\t\t\tAuthor Name : ";
					cin>>a_na;
					cout<<"\n\n No. of Copies : ";
					cin>>no_co;
					cout<<"\n\n\t\t\tPrice : ";
					cin>>pri;
					file1<<" "<<b_id<<" "<<b_na<<" "<<a_na<<" "<<no_co<<" "<<pri<<"\n";
					count++;
				}
				else
				file1<<" "<<b_id<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<" "<<price<<"\n";
				file>>b_id>>b_name>>a_name>>no_copy>>price;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("book.txt");
		rename("book1.txt","book.txt");
	}
	
	void bookshope::del_book()
	{
		system("cls");
		fstream file,file1;
		// int no_copy,count=0;
		int count=0;
		// string b_id,b_idd,b_name,a_name;
		string b_idd;
		cout<<"\n\n\t\t\t\tDelete Book Record";
		file1.open("book1.txt",ios::app|ios::out);
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_idd;
			file>>b_id>>b_name>>a_name>>no_copy>>price;
			while(!file.eof())
			{
				if(b_idd == b_id)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tDelete Book Record";
					cout<<"\n\n One Book is Deleted Successfully...";
					count++;
				}
				else
				file1<<" "<<b_id<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<" "<<price<<"\n";
				file>>b_id>>b_name>>a_name>>no_copy>>price;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("book.txt");
		rename("book1.txt","book.txt");
	}

	int welcome(){
		cout<<"\n\n\n\n\n\t\t\tWELCOME TO THE BOOK STALL !!!!";
		cout<<"\n1.Admin Portal";
		cout<<"\n2.Customer Portal";
		int opt;
		cout<<"\nEnter Your Choice : ";
		cin>>opt;
		return opt;
	}
int main()
{
	int choice;
	char x;
	bookshope b;
	int w=welcome();
	if(w==1){
		int log=login();
	if(log){
    p:
	b.control_panel();
	cout<<"\n\n Your Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			do
			{
			b.add_book();
			cout<<"\n\n Do You Want to Add another Book (y,n) : ";
			cin>>x;
		    }while(x == 'y');
			break;
		case 2:
			b.show_books();
			break;
		case 3:
			b.check_book();
			break;
		case 4:
			b.update_book();
			break;
		case 5:
			b.del_book();
			break;
		case 6:
            system("cls");
            cout<<"\n\n\n\n\t\t\t\t THANK YOU !!!!!";
			exit(0);
		default:
			cout<<"\n\n Invalid Value...Please Try Again...";
	}
    getch();
    goto p;}
	else{
          system("cls");
		  cout<<"\n\n\n\t\t INVALID USERNAME OR PASSWORD !!!";
		  exit(0);
	}
	}
	else{
		customer c;
		d:
		c.display();
		cout<<"\n\n Your Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 3:
			do
			{
			c.purchase();
			cout<<"\n\n Do You Want to Add another Book (y,n) : ";
			cin>>x;
		    }while(x == 'y');
			break;
		case 1:
			c.show_books();
			break;
		case 2:
			c.check_book();
			break;
		case 4:
            system("cls");
			remove("INVOICE.txt");
            cout<<"\n\n\n\n\t\t\t\t THANK YOU !!!!!";
			exit(0);
		default:
			cout<<"\n\n Invalid Value...Please Try Again...";
			cin>>choice;
			break;
	}
    getch();
    goto d;
	}
	
    return 0;
}
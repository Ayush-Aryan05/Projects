#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
class customer{
	int no_copy;
    double price;
	double total;
		string b_name,a_name,b_id;
		public:
        void display();
    	void show_books();
		void check_book();
        void purchase();
		void update_book(string b_idd , string b_na, string a_na,int cus_copy,double pri);
};
void customer:: display(){
    system("cls");
		cout<<"\n\n\t\t\t\tWelcome to Customer Panel";
		cout<<"\n 1. Show all Books";
		cout<<"\n 2. Check Specific Book";
		cout<<"\n 3. Purchase";
		cout<<"\n 4. Exit";
}
void customer::show_books()
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
				cout<<"   "<<b_id<<"     "<<b_name<<"        \t "<<a_name<<"\t\t"<<no_copy<<" \t    "<<price<<"\n\n";
				file>>b_id>>b_name>>a_name>>no_copy>>price;
			}
			file.close();
		}
	}
	void customer::check_book()
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

void customer::purchase()
{   fstream inv;
	 string b_idd;
     fstream file;
	 int count =0;
	 int flag=0;
	 int co=0;
	 string ub_name,ua_name;
	 int uprice,ucopy;
	
	file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
             cout<<"\n\n Book ID : ";
			cin>>b_idd;
			fflush(stdin);
			cout<<"\n\n Number of copies to buy: ";
			cin>>co;
			file>>b_id>>b_name>>a_name>>no_copy>>price;
			while(!file.eof())
			{  
				if(b_idd==b_id && co<=no_copy)
				{   ub_name=b_name;
				    ua_name=a_name;
					uprice=price;
					ucopy=no_copy;
					system("cls");
					total=co*price;
					/* update book (b_idd,name,author,no_copy-co,price) */
					inv.open("INVOICE.txt",ios::out|ios::app);
					inv<<"   "<<b_id<<"    \t\t "<<b_name<<"    \t "<<a_name<<"\t\t"<<co<<" \t \t \t\t  "<<price<<"   \t\t\t  "<<total<<"\n\n";
					flag=1;
					break;	
				}
				file>>b_id>>b_name>>a_name>>no_copy>>price;
			}
			file.close();
			inv.close();
			if(flag==1){
			 update_book(b_idd,ub_name,ua_name,(ucopy-co),uprice);
			 cout<<"\n\n\n\t\t\t\t\t INVOICE";
			 inv.open("INVOICE.txt",ios::in);
			 inv>>b_id>>b_name>>a_name>>no_copy>>price>>total;
			 cout<<" \n"<<"ID"<<"   "<<"Book Name"<<"  "<<"author NAme"<<"  "<<"copies"<<"   "<<"price"<<"   "<<"TOTAL";
			 while(!inv.eof())
			 {
			     cout<<"\n "<<b_id<<"   "<<b_name<<"    "<<a_name<<"  "<<no_copy<<"   "<<price<<"   "<<total;
				 inv>>b_id>>b_name>>a_name>>no_copy>>price>>total;
			 }
			 }
			if(flag==0)
			{
				cout<<"\n\n\n\n\t\t\t Insufficent Stock.....";
			}
		}
	}
	void customer :: update_book(string b_idd , string b_na, string a_na,int cus_copy,double pri)
	{
         fstream file,file1;
		file1.open("book1.txt",ios::app|ios::out);
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			file>>b_id>>b_name>>a_name>>no_copy>>price;
			while(!file.eof())
			{
				if(b_idd == b_id)
				{
					file1<<" "<<b_id<<" "<<b_na<<" "<<a_na<<" "<<cus_copy<<" "<<pri<<"\n";
				}
				else
				file1<<" "<<b_id<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<" "<<price<<"\n";
				file>>b_id>>b_name>>a_name>>no_copy>>price;
			}
			}
			 file.close();
		file1.close();
		remove("book.txt");
		rename("book1.txt","book.txt");
	}


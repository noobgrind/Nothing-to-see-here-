#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Student
{
	int roll;
	char div;
	char name[100];
	char address[100];

	Student()
	{
		roll = 0;
		div = ' ';
	}
	
	Student(int r,char n[],char d,char a[])
	{
		roll = r;
		div = d;
		strcpy(name,n);
		strcpy(address,a);
	}

	friend class DataBase;
};

class DataBase
{
		string fileName = "student.txt";
		int count = 0;
		fstream finOut;
	public:
		DataBase()
		{
			finOut.open(fileName,ios::out);
			finOut.close();
		}

		void addRecord()
		{
			finOut.open(fileName,ios::app);
			int roll;
			char div,name[100],address[100];

			cin.ignore(); // To clear Input Buffer
			cout<<"Enter Student Name : ";
			scanf("%[^\n]",name); // To take spaces too

			cout<<"Enter Student Roll no. : ";
			cin>>roll;
			cout<<"Enter Student Division : ";
			cin>>div;

			cin.ignore(); // To clear Input Buffer
			cout<<"Enter Student Address : ";
			scanf("%[^\n]",address);

			Student s(roll,name,div,address);

			finOut.write((char*)&s,sizeof(s));
			finOut.close();
			count++;	
		}

		void showRecords()
		{
			Student s;
			finOut.open(fileName,ios::in);
			cout<<"\tRoll No.\tName\tDivision\tAddress"<<endl;

			for(int i = 0; i < count; i++)
			{
				finOut.read((char*)&s,sizeof(s));
				cout<<"\t"<<s.roll<<"\t\t"<<s.name<<"\t"<<s.div<<"\t\t"<<s.address<<endl;
			}
			finOut.close();
		}
		bool search(int e)
		{
			finOut.open(fileName,ios::in);
			Student s;
			for(int i = 0; i < count; i++)
			{
				finOut.read((char*)&s,sizeof(s));
				if(s.roll == e)
				{
					cout<<"\nRecord Found : \n\n";
					cout<<"\tRoll No.\tName\tDivision\tAddress"<<endl;
					cout<<"\t"<<s.roll<<"\t\t"<<s.name<<"\t"<<s.div<<"\t\t"<<s.address<<endl;
					finOut.close();
					return true;
				}
			}			
			finOut.close();	
			return false;

		}
		void del(int e)
		{
			finOut.open(fileName,ios::in);
			Student s[count];

			for(int i = 0; i < count; i++)
				finOut.read((char*)&s[i] , sizeof(s[i]));
			finOut.close();

			finOut.open(fileName,ios::out);
			for(int i = 0; i < count; i++)
			{
				if(s[i].roll != e)
					finOut.write((char*)&s[i], sizeof(s[i]));
			}
			count--;
			cout<<"\nRecord Deleted Successfully!"<<endl<<endl;
			finOut.close();
		}
};

int main()
{
	DataBase db;
	int ch,key;
	do
	{
		cout<<"\n_______MENU_______"<<endl;
		cout<<"1.Add a record."<<endl;
		cout<<"2.Display All Records."<<endl;
		cout<<"3.Delete a record."<<endl;
		cout<<"4.Search a record."<<endl;
		cout<<"5.Exit."<<endl;

		cout<<"Enter Your Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				db.addRecord();
				break;
			case 2:
				db.showRecords();
				break;
			case 3:
				cout<<"Enter Roll no. of the record to be deleted : ";
				cin>>key;
				if(db.search(key))
					db.del(key);
				else
					cout<<"\nRecord Not Found!"<<endl<<endl;
				break;
			case 4:
				cout<<"Enter Roll no. of the record to be Searched : ";
				cin>>key;
				if(!db.search(key))
					cout<<"\nRecord Not Found!"<<endl<<endl;
				break;

		}
	}while(ch != 5);

	return 0;
}
#include<iostream>
using namespace std;

class HashTable
{
	int key;
	long long  tel_no;
	friend class Hashing;
};

class Hashing
{
		HashTable h[10];
	public:
		Hashing()
		{
			for(int i = 0 ; i < 10 ; i++)
			{
				h[i].key = i;
				h[i].tel_no = -1;
			}
		}

		void LinearProbe(long long  ,int);
		void QuadraticProbe(long long ,int);

		void display()
		{
			cout<<"Key\t"<<"Mobile Number"<<endl;
			for(int i = 0 ; i < 10 ; i++)
			{
				cout<<" "<<h[i].key<<"\t "<<h[i].tel_no<<endl;
			}
		}
		void insert(int probe_choice)
		{
			long long  num;
			cout<<"Enter Mobile No. : ";
			cin>>num;
			// if(num_of_digits(num) != 10)
			// {
			// 	cout<<"\nInvalid Number"<<endl;
			// 	return;
			// }
			if(probe_choice == 1)
			{
				int key = num%10;
				if(h[key].tel_no == -1)
					h[key].tel_no = num;
				else
				{
					LinearProbe(num,key);					
				}
			}
			else
			{
				int key = num%10;
				if(h[key].tel_no == -1)
					h[key].tel_no = num;
				else
				{	
					QuadraticProbe(num,key);
				}
			}
		}
		void search(long long  num)
		{
			for(int i = 0; i < 10 ; i++)
			{
				if(h[i].tel_no == num)
				{
					cout<<"\nKey\t"<<"Mobile Number"<<endl;
					cout<<h[i].key<<"\t"<<h[i].tel_no<<endl;
					return;
				}
			}

			cout<<"\nNumber Not Found\n";
		}
};

void Hashing::LinearProbe(long long  num,int coll_pos)
{
    int i = 1;
	int key = num%10;
    while(h[key].tel_no != -1)
    {
        key = (num % 10) + i; 
        i++;  
    }
    h[key].tel_no = num; 
}
void Hashing::QuadraticProbe(long long  num,int key)
{
	int j = 1;
	while(j < 10)
	{
		key = (h[key].tel_no + j*j)%10;
		if(key > 10)
		{
			cout<<"Hash Table Overflow\n"<<endl;
			break;
		}
		if(h[key].tel_no == -1)
		{
			h[key].tel_no = num;
			break;
		}
		j++;
	}

}
int main()
{
	Hashing h1;
	long long key,ch,probe_choice;
	do
	{
		cout<<"\n-----MENU-----"<<endl;
		cout<<"1.Insert an element in the Hashtable"<<endl;
		cout<<"2.Display the Hashtable"<<endl; 
		cout<<"3.Search a Number"<<endl; 
		cout<<"4.Exit"<<endl;
		cout<<"Enter Your Choice : "; 
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n1.Linear Probing"<<endl;
				cout<<"2.Quadratic Probing"<<endl;
				cout<<"Enter Your Choice : ";
				cin>>probe_choice;
				h1.insert(probe_choice);
				break;
			case 2:
				h1.display();
				break;
			case 3:
				cout<<"Enter the Number to be searched : ";
				cin>>key;
				h1.search(key);
				break;
		}

	}while(ch != 4);

	return 0;
}

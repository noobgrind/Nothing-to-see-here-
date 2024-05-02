#include<iostream>
using namespace std;

class Set
{
		int set[20];
		int size;
	public:
		Set() : size(0)
		{}
		
		void insert(int);
		
		void display()
		{
			cout<<"Set Contains : ";
			for(int i = 0 ; i < size ; i++)
				cout<<set[i] << "\t" ;
			cout<<"\n\n";
		}
		int search(int key)
		{
		    for(int i = 0; i < size ; i++)
		    {
		        if(set[i] == key)
		            return i+1;
		    }
		    return 0;
		}
		
		void remove(int key) 
		{
			int index = search(key);
			if(index)
			{
				for(int i = index - 1 ; i < size ; i++)
				{
					set[i] = set[i+1];	
					
				}
				size--;
			}
			else
			{
				cout<<"Element Not Found!\n";
			}
		}
		
		void uni(Set& s)
		{
			Set temp;
			
			for(int i = 0; i < size; i++)
			{
				temp.insert(set[i]);				
			}
			
			for(int j = 0; j < s.size; j++)
			{
				int index = temp.search(s.set[j]);
				if(!index)
				{
					temp.insert(s.set[j]);
				}				
			}
			cout<<"\n-----After Union-----\n";
			temp.display();					
		}
		void intersection(Set& s)
		{
			Set temp;
			int index;
			for(int j = 0; j < s.size; j++)
			{
				index = search(s.set[j]);
				if(index)
				{
					temp.insert(s.set[j]);
				}
			}
			cout<<"\n-----After Intersection-----\n";
			if(temp.size == 0)
				cout<<"It is a Null Set\n";
			else
				temp.display();
		}
		void difference(Set& s)
		{
			Set temp;
			
			int index;
			for(int j = 0; j < s.size; j++)
			{
				index = search(s.set[j]);
				if(!index)
				{
					temp.insert(s.set[j]);
				}
			}
			cout<<"\n-----After Difference Operation-----\n";
			temp.display();
		}
		int subset(Set& s)
		{
			for(int i = 0; i < s.size ; i++)
			{
				if(!search(s.set[i]))
					return 0;
			}
			return 1;
		}
		
		
}; 
void Set::insert(int ele)
{
	set[size++] = ele;	
}
int main()
{
	Set s1,s2;
	int ch;
		
	do
	{
		cout<<"\n----MENU----\n";
		cout<<"1.Add an element in Set 1\n";
		cout<<"2.Display Set 1\n";
		cout<<"3.Search an element in Set 1\n";
		cout<<"4.Remove an element in Set 1\n";
		
		cout<<"\n5.Add an element in Set 2\n";
		cout<<"6.Display Set 2\n";
		cout<<"7.Search an element in Set 2\n";
		cout<<"8.Remove an element in Set 2\n\n";
		
		cout<<"9.Union of Set 1 and Set 2\n";
		cout<<"10.Intersection of Set 1 and Set 2\n";
		cout<<"11.Difference of Set 1 and Set 2\n";
		cout<<"12.Check if Set 2 is subset of Set 1\n";
		
		cout<<"13.Exit\n\n";
		cout<<"Enter your choice : ";	
		cin>>ch;
		int ele,key;
		int index;
		switch(ch)
		{
			case 1:
				cout<<"Enter the Element to be inserted : ";
				cin>>ele;
				s1.insert(ele);
				break;
			case 2:
				s1.display();
				break;
		    case 3:
		        cout<<"Enter the element to be searched : ";
		        cin>>key;
		        index = s1.search(key);
		        
		        if(index)
		            cout<<"Element found at "<<index<<"th location\n";
		        else
		            cout<<"Element Not Found!\n";
		        break;
			case 4:
		        cout<<"Enter the element to be Removed : ";
		        cin>>key;
		        s1.remove(key);
		        break;
		  	
		  	case 5:
				cout<<"Enter the Element to be inserted : ";
				cin>>ele;
				s2.insert(ele);
				break;
			case 6:
				s2.display();
				break;
		    case 7:
		        cout<<"Enter the element to be searched : ";
		        cin>>key;
		        index = s2.search(key);
		        
		        if(index)
		            cout<<"Element found at "<<index<<"th location\n";
		        else
		            cout<<"Element Not Found!\n";
		        break;
			case 8:
		        cout<<"Enter the element to be Removed : ";
		        cin>>key;
		        s2.remove(key);
		        break; 
		    
		   	case 9:
		   		s1.uni(s2);
		   		break;
		   	case 10:
		   		s1.intersection(s2);
		   		break;
		   	case 11:
		   		s2.difference(s1);
		   		break;
		   	case 12:
		   		key = s1.subset(s2);
		   		if(key)
		   			cout<<"Set 2 is a Subset of Set 1"<<endl;
		   		else
		   			cout<<"Set 2 is not a Subset of Set 1"<<endl;

		  
		}
	}while(ch != 13);
	return 0;
}

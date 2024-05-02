#include<iostream>
using namespace std;

class Graph
{
		string* names;
		int** edges;
		int size;
	public:
		Graph(int n)
		{
			size = n;
			names = new string[n];

			edges = new int*[n];
			for(int i = 0; i<n; i++)
			{
				edges[i] = new int[n];
				for(int j=0; j<n ; j++)
					edges[i][j] = 0;				
			}	
			input();
		}
		int getIndex(string s)
		{
			for(int i = 0; i < size; i++)
				if(names[i] == s)
					return i;
			return -1;
		}
		void input()
		{
			

			cout<<"Enter "<<size<<" Names "<<endl;
			for(int i = 0; i < size; i++)
				cin>>names[i];

			cout<<"How many Edges : ";
			int e;
			cin>>e;

			cout<<"Enter Data for "<<e<<" Edges "<<endl;
			for(int i = 0; i < e; i++)
			{
				string src,dest;
				cout<<"Enter Source and Destination for "<<i+1<<"th Edge : ";
				cin>>src>>dest;
				
				int si = getIndex(src);
				int di = getIndex(dest);

				edges[si][di] = edges[di][si] = 1;
			}
		}
		void dfs()
		{
			int visited[size];
			for(int i = 0; i < size; i++)
				visited[i] = 0;
			cout<<"Enter Source Index : ";
			string s;
			cin>>s;
			class Stack
			{
					int top = -1;
					int arr[20];
				public:
					void push(int e)
					{
						arr[++top] = e;
					}
					int isEmpty()
					{
						return top == -1;
					}
					int pop()
					{
						if(!isEmpty())
							return arr[top--];
						return -1;
					}
					bool search(int e)
					{
						for(int i = 0; i <= top; i++)
							if(arr[i] == e)
								return true;
						return false;
					}
			}stck;

			stck.push(getIndex(s));
			while(!stck.isEmpty())
			{
				int current = stck.pop();
				cout<<names[current]<<" ";
				visited[current] = 1;

				for(int i = 0; i < size; i++)
				{
					if(edges[current][i])
						if(!visited[i] && !stck.search(i))
							stck.push(i);
				}
			}

		}
		void bfs()
		{
			int visited[size];
			for(int i = 0; i < size; i++)
				visited[i] = 0;

			class Queue
			{
					int arr[20];
					int front,rear;
				public:
					Queue()
					{
						front = rear = -1;
					}
					void enque(int e)
					{
						if(front == -1)
							front = 0;
						arr[++rear] = e;
					}
					int deque()
					{
						if(!isEmpty())
							return arr[front++];
						return -1;
					}
					int isEmpty()
					{
						return front == rear + 1;
					}
					int search(int e)
					{
						for(int i = front; i <= rear; i++)
							if(arr[i] == e)
								return 1;
						return 0;
					}

			}que;
			string src;
			cout<<"Enter Source Index : ";
			cin>>src;
			que.enque(getIndex(src));
			while(!que.isEmpty())
			{
				int current = que.deque();
				cout<<names[current]<<" ";
				visited[current] = 1;

				for(int i = 0; i < size; i++)
					if(edges[current][i])
						if(!visited[i] && !que.search(i))
							que.enque(i);

			}
		}
		void showG()
		{
			cout<<endl;
			for(int i = 0; i < size; i++)
				for(int j = 0; j < size; j++)
					if(edges[i][j])
						cout<<names[i]<<"--->"<<names[j]<<endl;
		}
};

int main()
{
	int n,ch;
	cout<<"How many Nodes : ";
	cin>>n;
	Graph g(n);

	do
	{
		cout<<"\n------MENU------"<<endl;
		cout<<"1.DFS."<<endl;
		cout<<"2.BFS."<<endl;
		cout<<"3.Exit."<<endl;
		cout<<"Enter Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				g.dfs();
				break;
			case 2:
				g.bfs();
				break;
		}

	}while(ch != 3);
	return 0;
}
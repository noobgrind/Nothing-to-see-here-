#include<iostream>
using namespace std;

class Edge
{
		int src;
		int weight;
		int dest;
	public:
		Edge()
		{
			
		}
		void setEdge(int s, int d, int w)
		{
			src = s;
			dest = d;
			weight = w;
		}
		static int findParent(int parent[], int v)
		{
			if(parent[v] == v)
				return v;
			return findParent(parent,parent[v]);
		}
		static void sort(Edge* edges, int e)
		{
			for(int i = 0; i < e - 1; i++)
				for(int j = i + 1; j < e; j++)
					{
						if(edges[i].weight > edges[j].weight)
						{
							Edge temp = edges[i];
							edges[i] = edges[j];
							edges[j] = temp;
						
						}
					}
		}

		static Edge* kruskals(Edge* edges,int e,int v)
		{
			int* parent = new int[v];
			for(int i = 0; i < v; i++)
				parent[i] = i;

			Edge* output = new Edge[v-1];

			int j = 0, i = 0;
			
			while(j < v - 1)
			{
				int srcparent = findParent(parent,edges[i].src);
				int destparent = findParent(parent,edges[i].dest);

				if(srcparent != destparent)
				{
					output[j++] = edges[i];
					parent[srcparent] = destparent;
				}
				i++;
			}
			int sum = 0;
			for(int i = 0; i < v - 1; i++)
				sum+=output[i].weight;

			cout<<"*****"<<sum<<"******"<<endl<<endl;

			return output;
		}
		static void showEdges(string names[],Edge* edges, int e)
		{
			cout<<"\tSource\tDestination\tWeight"<<endl;
			for(int i = 0; i < e; i++)
				cout<<"\t"<<names[edges[i].src]<<"\t"<<names[edges[i].dest]<<"\t\t"<<edges[i].weight<<endl;
		}
		friend int search(string[] ,string, int);

};
int search(string names[], string n, int v)
{
	for(int i = 0; i < v; i++)
		if(names[i] == n)
			return i;
	return -1;

}
int main()
{
	int e,v;
	cout<<"How many Cities and Wire Lines : ";
	cin>>v>>e;
	string names[v];

	cout<<"Enter City Names : ";
	for(int i = 0; i < v; i++)
	{
		cin>>names[i];
	}


	Edge* edges = new Edge[e];
	for(int i = 0; i < e; i++)
	{
		cout<<"Enter Source, Destination and Weight for "<<i + 1<<"th Edge : ";
		string s,d;
		int w;
		cin>>s>>d>>w;

		int si = search(names,s,v);
		int di = search(names,d,v);

		edges[i].setEdge(si,di,w);
	}
	Edge::showEdges(names,edges,e);
	Edge::sort(edges,e);
	cout<<endl;
	Edge::showEdges(names,edges,e);
	cout<<endl;
	Edge* output = Edge::kruskals(edges,e,v);
	Edge::showEdges(names,output,v-1);
	return 0;
}
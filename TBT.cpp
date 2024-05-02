/*
	
	Problem Statment -
		Consider threading a binary tree using preorder threads rather than inorder threads.
		Design an algorithm for traversal without using stack and analyse its complexity.
*/

#include<iostream>
using namespace std;

class Node
{
	Node* left;
	Node* right;
	bool rthread;
	bool lthread;
	int data;

	Node(int d)
	{
		data = d;
		rthread = lthread = false;
		left = right = NULL;
	}
	friend class TBST;
};

class TBST
{
		Node* root = NULL;
	public:
		void insert(Node* root,int d)
		{
			Node* p =  new Node(d);
			if(this -> root == NULL)
			{
				this -> root = p;
				return;
			}
			if(root -> data > d)
			{
				if(root -> left && root -> lthread == false)
					insert(root -> left,d);
				else
				{
					p -> left = root -> left;
					p -> lthread = root -> lthread;

					root -> left = p;
					root -> lthread = false;

					p -> right = root;
					p -> rthread = true;
				}
			}
			else
			{
				if(root -> right && root -> rthread == false)
					insert(root -> right,d);
				else
				{
					p -> right = root -> right;
					p -> rthread = root -> rthread;

					root -> right = p;
					root -> rthread = false;

					p -> left = root;
					p -> lthread = true;
				}
			}
		}
		Node* leftMost(Node* current)
		{
			if(current == NULL)
				return NULL;
			while(current -> left && current -> lthread == false)
				current = current -> left;
			return current;
		};

		Node* rightMost(Node* current)
		{
			if(current == NULL)
				return NULL;
			while(current -> right && current -> rthread == false)
				current = current -> right;
			return current;
		};

		Node* InSucc(Node* current)
		{
			if(current -> rthread)
				return current -> right;
			return leftMost(current -> right);
		}

		Node* InPred(Node* current)
		{
			if(current -> lthread)
				return current -> left;
			return rightMost(current -> left);
		}

		Node* getRoot()
		{
			return root;
		}

		void InOrder()
		{
			Node* current = leftMost(root);
			while(current)
			{
				cout<<current -> data<<" ";
				current = InSucc(current);
			}
		}
		void PreOrder()
		{
			Node* current = root;
			Node* temp;
			while(1)
			{
				while(current)
				{
					cout<<current -> data<<" ";
					temp = current;
					if(current -> lthread == false)
						current = current -> left;
					else
						break;
				}
				current = temp;

				while(current -> rthread)
					current = current -> right;
				current = current -> right;

				if(current == NULL)
					break;
			}
		}
};

int main()
{
	TBST t;
	int ch;
	int d;
	do
	{
		cout<<"\n-----MENU-----"<<endl;
		cout<<"1.Insert a Node."<<endl;
		cout<<"2.Inorder Traversal."<<endl;
		cout<<"3.PreOrder Traversal."<<endl;
		cout<<"4.Exit."<<endl;
		cout<<"Enter Your Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter Node to be inserted : ";
				cin>>d;
				t.insert(t.getRoot(),d);
				break;
			case 2:
				cout<<"\nInorder : ";
				t.InOrder();
				cout<<endl;
				break;
			case 3:
				cout<<"\nPreOrder : ";
				t.PreOrder();
				cout<<endl;
				break;

		}
	}while(ch != 4);

	
	return 0;
}

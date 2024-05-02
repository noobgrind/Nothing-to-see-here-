#include<iostream>
using namespace std;

class Tnode
{
	Tnode* left;
	Tnode* right;
	char data;
	Tnode(char d)
	{
		left = right = NULL;
		data = d;
	}
	friend class ExpTree;
	friend class Stack;
};

class Stack
{
	Tnode* arr[100];
	int top;
	Stack() : top(-1)
	{}
	void push(Tnode* e)
	{
		arr[++top] = e;
	}
	Tnode* pop()
	{
		if(!isEmpty())
			return arr[top--];
		return NULL;
	}
	int isEmpty()
	{
		return top == -1;
	}
	Tnode* peek()
	{
		return arr[top];
	}
	friend class ExpTree;
};

class ExpTree
{
		Tnode* root = NULL; 
	public:
		int isOperator(char e)
		{
			return e == '+' || e == '/' || e == '*' || e == '-' || e == '%'; 
		}

		void create(char prefix[])
		{
			int j = 0,i = 0;
			while(prefix[j])
				j++;
			j--;
			while(j > i)
			{
				char temp = prefix[i];
				prefix[i] = prefix[j];
				prefix[j] = temp;
				i++;
				j--;
			}
			Tnode* p;
			Stack stack;
			i = 0;
			
			while(prefix[i]) //  FED/CB*A--+
			{
				p = new Tnode(prefix[i]);
				if(isOperator(prefix[i]))
				{
					p -> left = stack.pop();
					p -> right = stack.pop();
					stack.push(p);
				}
				else
				{
					stack.push(p);
				}
				i++;
			}
			root = stack.pop();

		}
		void post()
		{
			Stack s1,s2;
			s1.push(root);
			while(!s1.isEmpty())
			{
				Tnode* temp = s1.pop();
				s2.push(temp);
				if(temp -> left)
					s1.push(temp -> left);
				if(temp -> right)
					s1.push(temp -> right);
			}
			while(!s2.isEmpty())
			{
				cout<<s2.pop() -> data<<" ";
			}
		}
		void post_wor()
		{
			Stack stack;
			Tnode* root = this -> root;
			while(true)
			{
				while(root)
				{
					if(root -> right)
						stack.push(root -> right);
					stack.push(root);
					root = root -> left;
				}
				root = stack.pop();
				if(root -> right && root -> right == stack.peek())
				{
					stack.pop();
					stack.push(root);
					root = root -> right;
				}
				else
				{
					cout<<root -> data<<" ";
					root = NULL;
				}
				if(stack.isEmpty())
					break;
			}
		}
		void inorder(Tnode* root)
		{
			if(root)
			{
				inorder(root -> left);
				cout<<root -> data<<" ";
				inorder(root -> right);
			}
		}
		void preorder(Tnode* root)
		{
			if(root)
			{
				cout<<root -> data<<" ";
				preorder(root -> left);
				preorder(root -> right);
			}
		}
		void postorder(Tnode* root)
		{
			if(root)
			{
				postorder(root -> left);
				postorder(root -> right);
				cout<<root -> data<<" ";

			}
		}
		void delTree(Tnode* root)
		{
			if(root)
			{
				delTree(root -> left);
				delTree(root -> right);
				delete root;
			}
		}
		void reset()
		{
			root = NULL;
		}

		Tnode* getRoot()
		{
			return root;
		}
};

int main()
{
	char prefix[100];
	int ch;
	ExpTree exptree;
	do
	{
		cout<<"\n-------MENU-------\n"<<endl;
		cout<<"1.Create an Expression"<<endl;
		cout<<"2.Inorder Traversal"<<endl;
		cout<<"3.Pre-Order Traversal"<<endl;
		cout<<"4.Post-Order Traversal"<<endl;
		cout<<"5.Post-Order Without Recursion"<<endl;
		cout<<"6.Delete the entire Tree"<<endl;
		cout<<"7.Exit"<<endl;
		cout<<"Enter Your Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter an Prefix Expression : ";
				cin>>prefix;
				exptree.create(prefix);
				break;
			case 2:
				cout<<"Infix : ";
				exptree.inorder(exptree.getRoot());
				cout<<endl;
				break;
			case 3:
				cout<<"Prefix : ";
				exptree.preorder(exptree.getRoot());
				cout<<endl;
				break;
			case 4:
				cout<<"Postfix : ";
				exptree.postorder(exptree.getRoot());
				cout<<endl;
				break;
			case 5:
				cout<<"Postfix Without Recursion : ";
				exptree.post();
				cout<<endl;
				break;
			case 6:
				exptree.delTree(exptree.getRoot());
				exptree.reset();
				cout<<"Tree Deleted Successfully"<<endl;
				break;
		}



	}while(ch != 7);
	
	return 0;
}

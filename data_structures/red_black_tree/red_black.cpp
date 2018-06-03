#include <bits/stdc++.h>

using namespace std;

#define dont_change 0
#define change	1

typedef int data_type;

typedef
struct node
{
	data_type val;
	bool red;
	node *parent, *left, *right;
	node()
	{
		parent = left =right = NULL;
		red = true;
	}
}
*nptr;

void level_order(nptr root);

void left_left_rotation(nptr &n)
{
	// n is newly inserted node
	nptr temp = n->parent->right;
	
	// setting childs
	n->parent->right  = n->parent->parent;
	n->parent->parent->left = temp;
	
	//setting parents
	n->parent->parent = n->parent->parent->parent;
	n->parent->right->parent = n->parent;
	
	//setting colors
	n->parent->red = false;
	n->parent->right->red = true;
}

void right_right_rotation(nptr &n)
{
	nptr temp = n->parent->left;
	
	n->parent->left = n->parent->parent;
	n->parent->parent->right = temp;
	
	n->parent->parent = n->parent->parent->parent;
	n->parent->left->parent = n->parent;
	
	n->parent->red = false;
	n->parent->left->red = true;
}

void left_right_rotation(nptr &n)
{
	nptr temp = n->left;
	
	n->left = n->parent;
	n->parent->right = temp;
	
	n->parent = n->parent->parent;
	n->left->parent = n;
	
	left_left_rotation(n);
}

void right_left_rotation(nptr &n)
{
	nptr temp  = n->right;
	
	n->right = n->parent;
	n->parent->left = temp;
	
	n->parent = n->parent->parent;
	n->right->parent = n;
	
	right_right_rotation(n);
}

int balance(nptr &n)
{
	if(n->parent == NULL)
	{
		n->red = false;
		return dont_change;
	}
	if(n->parent->red)
	{
		// parent is red
		
		// find uncle
		nptr uncle = NULL;
		if( n->parent->parent && n->parent->parent->left == n->parent)
		{
			uncle = n->parent->parent->right;
		}
		else if(n->parent->parent)
		{
			uncle = n->parent->parent->left;			
		}
		
		if(uncle != NULL && uncle->red )
		{
			n->parent->red = uncle->red = false;		// changed to false
			n->parent->parent->red = true;				// grand parent to red
			balance(n->parent->parent);
		}
		else
		{
			// uncle is black
				
			// detect configuration
			
			if(n->parent->left == n)
			{
				if(n->parent->parent->left == n->parent)
				{
					// left left left
					cout<<"\nLeft left rotation"<<endl;
					left_left_rotation(n);
					return change;
				}
				else
				{
					// right left
					cout<<"\nright left rotation\n";
					right_left_rotation(n);
					return change;
				}
			}
			else
			{
				if(n->parent->parent->right == n->parent)
				{
					cout<<"right right right rotation\n";
					//right right right
					right_right_rotation(n);
					return change;
				}
				else
				{
					cout<<"\nleft right rotation\n";
					// left right
					left_right_rotation(n);
					return change;
				}
			}
		}
	}
	return dont_change;
}

int insert(nptr &root, nptr parent, data_type val)
{
	if(!root)
	{
		root = new node();
		root->val = val;
		root->parent = parent;
		if(root->parent && root->parent->parent && root->parent->parent->parent == NULL)
		{
			// balancing includes root node
			return balance(root);
		}
		balance(root);
		return dont_change;
	}
	else
	{
		if(root->val < val)
		{
			return insert(root->right,root,val);
		}
		else
		{
			return insert(root->left,root,val);
		}
	}
}

void in_order(nptr root)
{
	if(root)
	{
		in_order(root->left);
		cout<<root->val<<" ";
		in_order(root->right);
	}
}

void dlr(nptr root)
{
	if(root)
	{
		cout<<root->val<<" ";
		dlr(root->left);
		dlr(root->right);
	}
}

void level_order(nptr root)
{
	nptr dummy = new node();
	queue<nptr> q;
	q.push(root);
	q.push(dummy);
	cout<<endl;
	while( !q.empty() )
	{
		nptr n = q.front();
		q.pop();
		if(n == dummy)
		{
			cout<<endl;
			if( q.empty())
				break;		// empty
			n = q.front();
			q.pop();
			q.push(dummy);
		}
		if(n)
		{
			cout<<"{ "<<n->val<<" ";
			if(n->red)
				cout<<"R";
			else
				cout<<"B";
			if(n->left)
			{
				q.push(n->left);
				cout<<" L";
			}
				
			if(n->right)
			{
				q.push(n->right);
				cout<<" R";	
			}
			cout<<" }";
		}
	}
	cout<<endl;
}

int main()
{
	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());
	
	
	int n;
	cin>>n;
	nptr root = NULL;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(insert(root,NULL,x))
		{
			root = root->parent;	
		}
		cout<<"\nInserted : "<<x<<endl;
		level_order(root);
		cout<<"\n------------------------------------------------------\n";
	}
	return 0;
}

#include<iostream>

using namespace std;

int d=1;     // global d

void set_d()
{
  cout<<"\nEnter value of d : ";
  cin>>d;
}

//structure definition

typedef
struct btree
{
  int count;
  int keys[2];
  btree* ptr[4];
}
*btptr;

//structure to be used while sorting the overflow node
struct btkey
{
  btptr lchild;
  int data;
  btptr rchild;
};

typedef
struct llist
{
  btptr data;
  llist* next;
}
*lptr;

struct que
{
  lptr first;
  lptr data;
  lptr rare;
};

// llist funcitons

void initialize(lptr &);
void addback(lptr&,btptr&);

//queue funcions

void initialize(que&);
btptr deq(que&);
void enq(que& ,btptr&);
bool empty(que);

//btkey functions

void initialize(btkey&);
bool check(btkey);  //check for NULL empty key

//sort
void bubble_sort(btkey* ,int);
void node_sort(btptr&);
// structure functions declarations

void print_list(btptr);
void initialize(btptr &);
int level_max(btptr t);
void reset(btptr&);
btkey split(btptr &,int key);
int insert(btptr &,int); //set overflow node also
void add(btptr &,int );
void print(btptr t);
void print2(btptr ); // to print each node first and then the other children
void print_node(btptr t);
void pr(btkey* ,int );
void level_print(btptr );

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
  btptr t=NULL;
  int input[20]={2,4,5,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,7}; // 18=34
  for(int i=0;i<50;i++)
  {
    add(t,i+1);
    //cout<<"\nAfter adding "<<input[i]<<endl;
    //print(t);
  }
  cout<<"\nprinting in main\n";
  print(t);
  cout<<"\n\n";
  cout<<"\ntype 2 printing \n";
  level_print(t);
  cout<<"\nprinting list \n";

  print_list(t);

  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//function definitions


//llist funcitons

void initialize(lptr &l)
{
  l=new llist;
  l->data=NULL;
  l->next=NULL;
}

void addback(lptr& l,btptr &t)
{
  if(l!=NULL)
  {
    if(l->next!=NULL)
    {
    addback(l->next,t);
    return;
    }
    initialize(l->next);
      l->next->data=t;
      return;
  }
  else
  {
    initialize(l);
    l->data=t;
  }
}

//queue functions

void initialize(que &q)
{
  q.first=NULL;
  q.data=NULL;
  q.rare=NULL;
}

void enq(que &q,btptr &t)
{
  //make sure q is initialized

  addback(q.data,t);
  if(q.first==NULL)
  q.first=q.data;
  lptr x=q.data;
  while(x->next!=NULL)
  {
    x=x->next;
  }
  q.rare=x;

}

btptr deq(que& q)
{
  if(q.data!=NULL)
  {
  q.first=q.data->next;
  btptr x=q.data->data;
  q.data=q.data->next;
  if(q.data==NULL)
  q.rare=NULL;
  return x;
  }
  else
  {
    cout<<"\nqueue is empty\n";
    return NULL;
  }
}

bool empty(que q)
{
  if((q.first==q.rare)&&(q.first==NULL)||q.data==NULL)
  {
    return true;
  }
  return false;
}


// btkey functions


bool check(btkey key)
{
  if(key.lchild==NULL && key.rchild==NULL and key.data==-1)
  return false;
  return true;
}

void initialize(btkey &key)
{
  key.lchild=NULL;
  key.rchild=NULL;
  key.data=-1;
}

//btree functions

void print_node(btptr t)
{
  //cout<<"\nprinting node\n";
  cout<<" /";
  if(t!=NULL)
  {
    //cout<<"\nhere\n";
    for(int i=0;i<t->count;i++)
    {
      if(i!=0)
      cout<<",";
      cout<<t->keys[i];
    }
  }
  cout<<"/ ";
}

void pr(btkey *arr,int size)
{
  cout<<"\n";
  for(int i=0;i<size;i++)
  {
    cout<<arr[i].data<<" ";
    if(arr[i].lchild!=NULL)
    cout<<arr[i].lchild->keys[0]<<" ";
    if(arr[i].rchild!=NULL)
    cout<<arr[i].rchild->keys[0]<<" ";
    cout<<"\n";

  }
}

void bubble_sort(btkey *arr,int size)
{
  for(int i=0;i<size-1;i++)
  {
    for(int j=1;j<size-i;j++)
    {
      if(arr[j].data<arr[j-1].data)
      {
        btkey temp=arr[j];
        //
        arr[j]=arr[j-1];
        //
        arr[j-1]=temp;
      }
    }
  }
}

void initialize(btptr &t)
{
  t=new btree;
  for(int i=0;i<(2*d+2);i++)
  {
    t->ptr[i]=NULL;
  }
  for(int i=0;i<(2*d);i++)
  {
    t->keys[i]=0;
  }
  t->count=0;
}

void reset(btptr &t)
{
  for(int i=0;i<(2*d+1);i++)
  {
    t->ptr[i]=NULL;
  }
  for(int i=0;i<(2*d);i++)
  {
    t->keys[i]=0;
  }
  t->count=0;
}

int insert(btptr &t,int key)
{
  if(t!=NULL)
  {
    //cout<<"\nt is not null\n";
    int i=0;
    for(i;i<t->count;i++)
    {
      if(t->keys[i]>key)
      break;
    }
    if(t->ptr[i]!=NULL)
    {
      return(insert(t->ptr[i],key));
    }
    if(t->count<2*d)
    {
      //rearrange

      btkey arr[t->count+1];
      int size=0;
      //cout<<"\nbefore rearranging node is : ";
      //print(t);
      for(size=0;size<t->count;size++)
      {
        arr[size].lchild=t->ptr[size];
        arr[size].rchild=t->ptr[size+1];
        arr[size].data=t->keys[size];
      }

      arr[size].lchild=NULL;
      arr[size].rchild=NULL;
      arr[size].data=key;
      size++;

      //cout<<"\nbefore sorting\n";
    //pr(arr,size);

      bubble_sort(arr,size);

      reset(t);

      for(t->count=0;t->count<size;t->count++)
      {
        t->keys[t->count]=arr[t->count].data;
        t->ptr[t->count]=arr[t->count].lchild;
        t->ptr[t->count+1]=arr[t->count].rchild;
      }

      return 0;
    }
    else
    return 1;
  }
}

btkey split(btptr &t,int key)
{
  static int level=0;
  static int max_level=0;
  if(level==0)
  {
    max_level=level_max(t);
  }
  btkey this_key;
  initialize(this_key);
  if(t!=NULL)
  {
    //cout<<"\nspliting for "<<key<<endl;
    int i=0;
    for(i=0;i<t->count;i++)
    {
      if(t->keys[i]>key)
      break;
    }
    if(t->ptr[i]!=NULL)
    {
      level++;
      this_key=split(t->ptr[i],key);
      level--;
    }
    if(check(this_key)||t->ptr[i]==NULL)
    {
      //print_node(t);
      if(!check(this_key))
      {
        this_key.data=key;
        this_key.lchild=NULL;
        this_key.rchild=NULL;
      }

      btkey arr[2*d+1];
      int size=0;
      for(size=0;size<t->count;size++)
      {
        arr[size].lchild=t->ptr[size];
        arr[size].data=t->keys[size];
        arr[size].rchild=t->ptr[size+1];
      }

      arr[size]=this_key;
      size++;
      //
      bubble_sort(arr,size);
      //
      int mid=d;

      if(t->count<2*d)
      {
        reset(t);
        for(int x=0;x<size;x++)
        {
          t->keys[x]=arr[x].data;
          t->ptr[x]=arr[x].lchild;
          t->ptr[x+1]=arr[x].rchild;
          t->count++;
        }
        initialize(this_key);
        return this_key;
      }
      else
      {
      btptr new_node;
      initialize(new_node);

      reset(t);
      for(int j=0;j<mid;j++)
      {
        t->keys[j]=arr[j].data;
        t->ptr[j]=arr[j].lchild;
        t->ptr[j+1]=arr[j].rchild;
        t->count++;
      }

      int z=mid+1;
      int size2=0;
      if(level==max_level)
      {
        //cout<<"\nmax level for key : "<<key<<" is "<<max_level<<endl;
        new_node->keys[size2]=arr[mid].data;
        new_node->ptr[0]=NULL;
        new_node->ptr[1]=NULL;
        size2++;
        new_node->count++;
      }
      for(int j=0;j<mid;j++,z++,size2++)
      {
        new_node->keys[size2]=arr[z].data;
        new_node->ptr[size2]=arr[z].lchild;
        new_node->ptr[size2+1]=arr[z].rchild;
        new_node->count++;
      }

      arr[mid].lchild=t;
      arr[mid].rchild=new_node;

      if(level==max_level)
      {
        new_node->ptr[2*d+2]=t->ptr[2*d+2];
        t->ptr[2*d+2]=new_node;
      }

      if(level==0)
      {
        btptr node3;
        initialize(node3);
        node3->count=1;
        node3->ptr[0]=arr[mid].lchild;
        node3->ptr[1]=arr[mid].rchild;
        node3->keys[0]=arr[mid].data;
        initialize(this_key); // not initializing just reseting
        t=node3;
        return  this_key;
      }
      else
      {
      return arr[mid];
      }
      }
    }
    //initialize(this_key);
    return this_key;
  }
}

void add(btptr &t,int key)
{
  if(t==NULL)
  {
    //will initialize if root node is not present
  //  cout<<"\nInitialzing\n";
    initialize(t);
    t->keys[0]=key;
    t->count++;
    return;
  }

  if(insert(t,key))
  {
    btkey x=split(t,key);
    /*if(check(x))
    {
      cout<<"\nNot working correctly\n";
    }
    else
    {
      cout<<"\ndone splitting\n";
    }*/
  }
  /*else
  {
    cout<<"\nsimple insertion is done .printing\n";
    print(t);
  }*/

}

void print(btptr t)
{
  if(t!=NULL)
  {
    int i=0;
    for(i=0;i<t->count;i++)
    {
      print(t->ptr[i]);
      cout<<t->keys[i]<<" ";
    }
    print(t->ptr[i]);
  }
}

void print2(btptr t)
{
  static int level=0;
  if(t!=NULL)
  {
    cout<<"\nNode is at level "<<level<<endl;
    print_node(t);
    int i=0;
    for(i;i<t->count;i++)
    {
      level++;
      print2(t->ptr[i]);
      level--;
    }
    level++;
    print2(t->ptr[i]);
    level--;
  }
}

int level_max(btptr t)
{
  int count=0;
  while(t->ptr[0]!=NULL)
  {
    count++;
    t=t->ptr[0];
  }
  return count;
}

void print_list(btptr t)
{
  if(t!=NULL)
  {
    while(t->ptr[0]!=NULL)
    t=t->ptr[0];
    btptr x=t;
    while(x!=NULL)
    {
      print_node(x);
      x=x->ptr[2*d+2];
    }
  }
}

void level_print(btptr t)
{
  que q;
  initialize(q);
  enq(q,t);
  btptr flag;
  initialize(flag);
  enq(q,flag);
  while(!empty(q))
  {
    btptr node=deq(q);
    if(node==flag)
    {
      cout<<"\n";
      if(!empty(q))
      {
      node=deq(q);
      enq(q,flag);
      }
      else
      break;
    }
    if(node!=NULL&&node!=flag)
    {
    print_node(node);
    int i;
    for(i=0;i<node->count;i++)
    {
      enq(q,node->ptr[i]);
    }
    enq(q,node->ptr[i]);
    }
  }
}

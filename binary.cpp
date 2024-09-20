#include<iostream>
using namespace std;
class node 
{ 
public:
int data;
int ith , rth ;
node *left, *right;
};
class thread 
{
public :
node *head;
node *newnode , *root, *temp , *parent;

thread()
{
root = NULL;
}
void create ();
void insert (node* , node*);
void display_inorder(node* , node*);
void display_preorder(node* ,node*);
};
void thread :: create()
{
newnode = new node;
newnode->left =NULL; 
newnode->right =NULL;
newnode->ith =0;
newnode->rth =0;
cout<<" \n Enter the element ";
cin >>newnode->data;
if (root == NULL)
{
root = newnode;
head = new node ;
//head->data =-999
head->left=head;
root->right=head;
}
else 
{
insert(root,newnode);
}  
void thread::insert(node *ptr,node *newnode)
{
if (newnoe->data<ptr->data)
{
if(ptr->ith==0)
{
newnode->left=ptr->left;
newnode->right=ptr;
ptr->left = newnode;
ptr->ith=1;
}
else{
insert (ptr->left, newnode);
}
if (ptr->rth==0)
{
newnode->right=ptr->right;
newnode->left=ptr;
ptr->right = newnode;
ptr->rth=1;
}
else
{
insert (ptr->right, newnode);
}
}
void thread :: display_inorder(node *temp,node *d)
{
while (temp!=d)
{
while(temp->ith==1)
{
temp=temp->left;
}
cout << " "<temp->data;
while (temp=rth==0)
{
temp=temp->right;
if(temp==d)
return;
cout<< " temp-> data"; 
} 
temp =temp->right;
}
}
void thread ::display_preorder(node *temp, node *head)
{
int flag =0;
while (temp!=head)
{
if(flag==0)
cout << " "<<temp->data;
if ((temp->ith==1)&&(flag==0))
{
temp=temp->left;
}
else
{
while(1)
{
if (temp->rth==1)
{
flag=0;
temp=temp->right;
break;
}
else
{
if(temp!=head)
{
flag=1;
temp=temp->right;
break;
}
}
}
}
}
}
int main()
{
int choice;
thread th;
do
{
cout<"\n Program for threaded binary tree\n";
cout<<"\n 1) create \n 2)Display inporder\n 3) Dislpay preorder 4) Exit";
cout << "\n Enter your choice :";
cin>>choice;
switch(choice)
{
case1:
th.create();
break;
case 2:
th.display_inorder(th.root,th.head);
break;
case 3:
th.display_preorder(th.root,th.head);
break;
}
}
while(choice!=4);
return 0;
}
}
} 


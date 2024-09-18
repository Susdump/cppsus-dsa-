#include <iostream>

using namespace std;
struct node
{
    int data;

    node *right, *left;
} *root = NULL, *new_node, *ptr, *loc, *suc, *par, *parsuc, *save;

void insertion(int da)
{
    new_node = new node;
    new_node->data = da;
    new_node->left = NULL;
    new_node->right = NULL;

    if (root == NULL)
    {
        root = new_node;
    }
    else
    {
        ptr = root;
        struct node *parent;
        while (ptr != NULL)
        {
            parent = ptr;
            if (ptr -> data == da)
            {
                cout<<"\nSame element exist in the tree can't insert\n";
                return;
            }
            if (da > (ptr->data))
            {
                ptr = ptr->right;
            }
            else
            {
                ptr = ptr->left;
            }
            
            
        }
        if (da > parent->data)
        {
            parent->right = new_node;
        }
        else
        {
            parent->left = new_node;
        }
    }
}

void inorder(struct node *pt = root)
{
    if (pt != NULL)
    {
        inorder(pt->left);
        cout << pt->data << " ";
        inorder(pt->right);
    }
}
void postorder(struct node *pt = root)
{
    if (pt != NULL)
    {
        inorder(pt->left);
        inorder(pt->right);
        cout << pt->data << " ";
    }
}
void preorder(struct node *pt = root)
{
    if (pt != NULL)
    {
        cout << pt->data << " ";
        inorder(pt->left);
        inorder(pt->right);
    }
}

void search(int chk){
    ptr = root;
    if (ptr == NULL)
    {
        cout<<"Tree is empty \n";
    }
    while (ptr != NULL)
    {
        if (ptr ->data == chk)
        {
            cout<<"\nElement Exist's in the tree\n";
            break;
        }
        else if (ptr -> data > chk)
        {
            ptr = ptr -> left;
        }
        
        else{
            ptr = ptr -> right;
        }
            
    }

}
void case_a(node *loc , node *par){
    node *child;
    if (loc -> left == NULL and loc -> right == NULL)
    {
        child = NULL;
    }
    else if(loc -> left != NULL){
        child = loc -> left;
    }
    else{
        child = loc -> right;
    }
    if (par != NULL)
    {
        if (loc == par ->left)
        {
            par ->left = child;
        }
        
        else
        {
            par = child ->right;
        }
    }
    else{
        root = child;
    }
}
void case_b(){
    node *suc , *parsuc, *save;
    ptr = loc -> right;
    save = loc;
    while (ptr -> left != NULL)
    {
        save = ptr;
        ptr = ptr -> left;
    }
    suc = ptr;
    parsuc = save;
    case_a(suc , parsuc);
    if (par != NULL)
    {
        if (loc == par -> left)
        {
            par -> left = suc;
        }
        else{
            par -> right = suc;
        }   
    }
    else {
        root = suc;
    }
    suc -> left = loc -> left;
    suc -> right = loc ->right;
}
void deletion(int x){
    struct node *loc , *par;
    loc = root;
    while (loc != NULL and x != loc->data)
    {
        par = loc;
        if (x < loc -> data)
        {
            loc = loc -> left;
        }
        else{loc = loc -> right ;}
    }
    if (loc == NULL)
    {
        cout<<"\n Element not found in Tree \n";
    }
    if (loc -> right != NULL and loc -> left != NULL)
    {
        case_b();
    }
    else{
        case_a(loc , par);
    }
    delete loc;
}

int depth(struct node *ptr2){
    if (ptr2 == NULL)
    {
        return 0;
    }

    int lh = depth(ptr2 ->left);
    int rh = depth(ptr2 -> right);

    if (lh >= rh)
    {
        return lh + 1;
    }
    else{
        return rh + 1;
    }    
}

int main()
{
    int ch, d , chk;

    while (ch != 10)
    {
        cout << "\nSelect option from below \n"
             << "1 .Insert Data in Tree: \n"
             << "2. Traverse Tree\n"
             << "3. Search Element in Tree\n"
             << "4. Check Depth of the Tree\n"
             << "5. Check Height of the Tree\n"
             << "6. Delete Element in the Tree\n"
             <<"10. Exit\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter Data to Inserted: ";
            cin >> d;
            insertion(d);
            break;
        case 2:
            cout << "inorder: ";
            inorder();
            cout << '\n';
            cout << "postorder: ";
            postorder();
            cout << '\n';
            cout << "preorder: ";
            preorder();
            cout << '\n';
            break;
        case 3: 
            cout<<"Enter The Element Data you want to check: ";
            cin>>chk;
            search(chk);
            break;
        case 4:
            cout<<"\nThe Depth of the tree is: " << depth(root)<<"\n";
            break;
        case 5:
            cout<<"\nThe Height of the tree is: " << depth(root) + 1 <<"\n";
            break;
        case 6:
            cout<<"Enter The Element Data you want to delete: ";
            cin>>chk;
            deletion(chk);
        default:
            break;
        }
    }

    return 0;
}
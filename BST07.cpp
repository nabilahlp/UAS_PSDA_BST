#include <iostream>
#include <cstdlib>
using namespace std;
struct node {
    int data;
    struct node *left; 
	struct node *right;
};
node* root;

class BST {
public:
    BST();
    void insert1(int);
    node* insert2(node*, node*);
    void del(int);
    void preorder(node*);
    void inorder(node*);
    void postorder(node*);
   	void search(node*, int);
    int maxval (node*);
    int minval (node*);
};
BST :: BST()
{
    root = NULL;
}
node* BST :: insert2(node* temp, node* newnode)
{
    if (temp == NULL) {
        temp = newnode;
    }
    else if (temp->data < newnode->data) {
        insert2(temp->right, newnode);
        if (temp->right == NULL)
            temp->right = newnode;
    }
    else {
        insert2(temp->left, newnode);
        if (temp->left == NULL)
            temp->left = newnode;
    }
    return temp;
}
void BST::insert1(int key)
{
    node *temp = root, *newnode;
    newnode = new node;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = key;
    root = insert2(temp, newnode);
    
}
void BST::preorder(node* t = root)
{
    if (root == NULL) {
        cout << "Nothing to display";
    }
    else if (t != NULL) {
        cout << t->data << " ";
        preorder(t->left);
        preorder(t->right);
    }
}
void BST::inorder(node* t = root)
{
    if (root == NULL) {
        cout << "Nothing to display";
    }
    else if (t != NULL) {
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }
}
void BST::postorder(node* t = root)
{
    if (root == NULL) {
        cout << "Nothing to display";
    }
    else if (t != NULL) {
        postorder(t->left);
        postorder(t->right);
        cout << t->data << " ";
    }
}
void BST::del(int key)
{
    node *temp = root, *parent = root, *marker;
    if (temp == NULL)
        cout << "The tree is empty" << endl;
    else {
        while (temp != NULL && temp->data != key) {
            parent = temp;
            if (temp->data < key) {
                temp = temp->right;
            }
            else {
                temp = temp->left;
            }
        }
    }
    marker = temp;
    if (temp == NULL)
        cout << "No node present";
    else if (temp == root) {
        if (temp->right == NULL && temp->left == NULL) {
            root = NULL;
        }
        else if (temp->left == NULL) {
            root = temp->right;
        }
        else if (temp->right == NULL) {
            root = temp->left;
        }
        else {
            node* temp1;
            temp1 = temp->right;
            while (temp1->left != NULL) {
                temp = temp1;
                temp1 = temp1->left;
            }
            if (temp1 != temp->right) {
                temp->left = temp1->right;
                temp1->right = root->right;
            }
            temp1->left = root->left;
            root = temp1;
        }
    }
    else {
        if (temp->right == NULL && temp->left == NULL) {
            if (parent->right == temp)
                parent->right = NULL;
            else
                parent->left = NULL;
        }
        else if (temp->left == NULL) {
            if (parent->right == temp)
                parent->right = temp->right;
            else
                parent->left = temp->right;
        }
        else if (temp->right == NULL) {
            if (parent->right == temp)
                parent->right = temp->left;
            else
                parent->left = temp->left;
        }
        else {
            node* temp1;
            parent = temp;
            temp1 = temp->right;
            while (temp1->left != NULL) {
                parent = temp1;
                temp1 = temp1->left;
            }
            if (temp1 != temp->right) {
                temp->left = temp1->right;
                temp1->right = parent->right;
            }
            temp1->left = parent->left;
            parent = temp1;
        }
    }
    delete marker;
}
/*void BST::search(node* t, int key)
{	
	if (t == NULL)
		return;
	else if(key < t->data)
		return search(t->left, key);
	else if(key > t->data)
		return search(t->right, key);
	else
		return;
}*/
int BST :: maxval (node* t)
{
    node* current = t;
    while (current && current->left != NULL)
        current = current->left;

    return current->data;
}

int BST::minval(node* t)
{
	node* current = t;
    while (current && current->right != NULL)
        current = current->right;

    return current->data;
}
int main()
{
	BST b;
	int pilih, n, t, key;
	while(1) {
		cout<<"MENU :";
		cout<<endl;
		cout<<"1. Insert\n";
		cout<<"2. Delete\n";
		cout<<"3. Search\n";
		cout<<"4. In-Order Tranversal\n";
		cout<<"5. Pre-Order Tranversal\n";
		cout<<"6. Post-Order Tranversal\n";
		cout<<"7. Maximum Value\n";
		cout<<"8. Minimum Value\n";
		cout<<"9. Reset BST\n";
		cout<<"0. EXIT\n";
		cout << "Enter your choice: \n";
        cin >> pilih;
        switch (pilih) {
        case 1:
            cout << "Enter item: ";
            cin >> n;
            b.insert1(n);
            break;
        case 2:
            cout << "Enter node to be deleted : ";
            cin >> key;
            b.del(key);
            break;
       	/*case 3:
        	cout << "Enter node to search :";
        	cin >> key;
        	if(b.search(t, n))
        		cout<<"Data ditemukan";
        	else
				cout<<"Data tidak ditemukan";	
        	break;  */
		case 4:
            cout << "Pre-Order Tranversal : " <<endl;
            b.preorder();
            break;
        case 5:
            cout << "In-Order Tranversal :"<<endl;
            b.inorder();
            break;
        case 6:
            cout << "Post-Order Tranversal :"<<endl;
            b.postorder();
            break;
        case 7:
			cout << "Maximum Node is : "<<endl;
			cin >> key;
			b.maxval(root);
			break;
		case 8:
			cout << "Minimum Node is : "<<endl;
			b.minval(root);
			break;
		case 9:
			exit(0);	
	}
}	
return 0;
}   
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

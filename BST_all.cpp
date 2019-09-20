#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *left, *right;
};
node* findMin(node* root)
{
	while(root->left!=NULL) 
		root = root->left;
	return root;
}
node* findMax(node* root)
{
	while(root->right!=NULL) 
		root = root->right;
	return root;
}
node* getNewNode(int data)
{
	node* newNode = new node();
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;
}
node* insert_node(node* root, int data)
{
	if(root==NULL)
		root=getNewNode(data);
	else if(data<=root->data)
		root->left=insert_node(root->left, data);
	else
		root->right=insert_node(root->right, data);
	return root;
}
node* delete_node(node* root, int data)
{
	if(root==NULL)
		return root;
	else if(data<root->data)
		root->left=delete_node(root->left, data);
	else if(data>root->data)
		root->right=delete_node(root->right, data);
	else
	{
		if(root->left==NULL and root->right==NULL)
		{
			delete root;
			root=NULL;
		}
		else if(root->left==NULL)
		{
			struct node* temp=root;
			root=root->right;
			delete temp;
		}
		else if(root->right==NULL)
		{
			struct node* temp=root;
			root=root->left;
			delete temp;
		}
		else
		{
			struct node* temp=findMin(root->right);
			root->data=temp->data;
			root->right=delete_node(root->right, temp->data);
		}
	}
	return root;
}
bool search(node* root, int data)
{
	if(root==NULL)
		return false;
	if(root->data==data)
		return true;
	if(data<root->data)
		return search(root->left, data);
	return search(root->right, data);

}
void Preorder(node *root) 
{
	if(root == NULL) 
		return;
	printf("%c ",root->data);
	Preorder(root->left);
	Preorder(root->right);
}
void Inorder(node *root) 
{
	if(root == NULL)
	 return;
	Inorder(root->left);
	printf("%d ",root->data);
	Inorder(root->right);
}
void Postorder(node *root) {
	if(root == NULL) 
		return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%c ",root->data);
}
int main()
{
	node* root=NULL;
	root=insert_node(root, 3);
	root=insert_node(root, 2);
	root=insert_node(root, 4);
	return 0;
}

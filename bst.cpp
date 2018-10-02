  #include<bits/stdc++.h>
using namespace std;
struct bst
{
	long long data;
	bst *left,*right;
};
bst* findmin(bst* root)
{
	while(root->left!=NULL)
		root=root->left;
	return root;
}
bst* insert(bst *root,long long info)
{
	struct bst*node=new bst();
	node->data=info;
	node->left=NULL;
	node->right=NULL;
		if(root!=NULL){
		if(info>root->data)
			root->right=insert(root->right,info);
		else if(info<=root->data)
			root->left=insert(root->left,info);
		}
		else
			root=node;
	return root;
}
bst* del(bst *root, long long info)
{

	if(root->data>info)
		root->left=del(root->left,info);
	else if(root->data<info)
		root->right=del(root->right,info);
	else{
		if(root->left==NULL&&root->right==NULL){
			delete root;			
			root=NULL;
			}
		else if(root->left==NULL){
			bst *temp=root;
			delete root;
			root=temp->right;
			}
		else if(root->right==NULL){
			bst *temp=root;
			delete root;
			root=temp->left;
			}
		else if(root->left&&root->right){
			struct bst *temp=findmin(root->right);
			root->data=temp->data;
			root->right=del(root->right,temp->data);
			}
	}
	return root;
}
void inorder(bst *root)
{
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
		
int main()
{
	struct bst *root=NULL;
	long long choice,item;
	while(1){
		cout<<"Press 1 to insert"<<endl;
		cout<<"Press 2 to delete"<<endl;
		cout<<"Press 3 to inorder display"<<endl;
		cout<<"Press 4 to exit"<<endl;
		cin>>choice;
		switch(choice){
			case 1: cout<<"Enter element to be inserted";
			cin>>item;
			root=insert(root,item);
			break;
			case 2:cout<<"Enter element to be deleted";
				cin>>item;
				root=del(root,item);
				break;
			case 3:inorder(root);
			cout<<endl;
			break;
			case 4: exit(0);
			}
		}
	return 0;
}


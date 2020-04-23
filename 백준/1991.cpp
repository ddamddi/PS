#include <iostream>
using namespace std;

typedef struct Node {
	char name;
	Node *left, *right;
}node;

bool isExist(node* root, char name){
	if(root == NULL)
		return false;
	
	if(root->name == name)
		return true;
	
	bool l = isExist(root->left, name);
	bool r = isExist(root->right, name);
	
	if(l || r)
		return true;
	return false;
}

node* find(node* root, char name){
	if(root == NULL)
		return NULL;
	
	if(root->name == name)
		return root;
	
	node* l = find(root->left, name);
	if(l != NULL) return l;
	
	node* r = find(root->right, name);
	if(r != NULL) return r;
	
	return NULL;
}

void preorder(node* root){
	if(root != NULL){
		cout << (root->name);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node* root){
	if(root != NULL){
		inorder(root->left);
		cout << (root->name);
		inorder(root->right);
	}
}

void postorder(node* root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout << (root->name);
	}
}



int main(){
	int N;
	cin >> N;
	
	// Root
	node* root = (node*)malloc(sizeof(node));
	root->name = 'A';
	root->left = root->right = NULL;
	
	for(int i=0; i<N; i++){
		char x, y, z;
		cin >> x >> y >> z;
		
		node *x_node, *y_node, *z_node;
		
		if(!isExist(root, x)){
			x_node = (node*)malloc(sizeof(node));
			x_node->name = x;
			x_node->left = x_node->right = NULL;
		}
		else{
			x_node = find(root, x);
		}
			
	
		if(y != '.'){
			if(!isExist(root, y)){
				y_node = (node*)malloc(sizeof(node));
				y_node->name = y;
				y_node->left = y_node->right = NULL;
			}
			else{
				y_node = find(root, y);
			}
			x_node->left = y_node;
		}
		
		if(z != '.'){
			if(!isExist(root, z)){
				z_node = (node*)malloc(sizeof(node));
				z_node->name = z;
				z_node->left = z_node->right = NULL;
			}
			else{
				z_node = find(root, z);
			}
			x_node->right = z_node;
		}
	}
	
	preorder(root);
	cout << '\n';
	inorder(root);
	cout << '\n';
	postorder(root);
	cout << '\n';
}

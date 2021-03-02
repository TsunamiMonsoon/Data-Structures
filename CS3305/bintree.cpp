/*

* Class: CS 3305/04

* Term: Spring 2019

* Name: Heather Willis

* Instructor: Monisha Verma

* Assignment: 8

*/

#include <iostream>
#include "bintree.h"
using namespace std;

struct BSTreeNode{
	int data;
	struct BSTreeNode* left;
	struct BSTreeNode* right;
};

struct BSTreeNode* newBSTreeNode(int data);

//balanced binary search tree from sortedArrayay
struct BSTreeNode* sortedArrayToBalanceBSTree(int sortedArray[], int start, int end){
	//pre condition check
	if (start > end)
		return NULL;

	//middle element to root
	int mid = (start + end)/2;
	struct BSTreeNode *root = newBSTreeNode(sortedArray[mid]);

	//recursively construct left sub tree and make the left child to root
	root->left = sortedArrayToBalanceBSTree(sortedArray, start, mid-1);

	//recursively construct right sub tree and make the right child to root
	root->right = sortedArrayToBalanceBSTree(sortedArray, mid+1, end);

		return root;
	}

//create new node
struct BSTreeNode* newBSTreeNode(int data){
	struct BSTreeNode* node = new BSTreeNode;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

		return node;
	}

//preorder
void preOrder(struct BSTreeNode* node){
	if (node == NULL)
		return;
	cout<<node->data<<" ";
	preOrder(node->left);
	preOrder(node->right);
	}

//main
int main(){
  
	int sortedArray[50];
	int n;
  
	cout<<"Enter number of elements :";
	cin>>n;
  
	cout<<"Enter elements in sorted order : \n";
		for(int i=0;i<n;i++){
			cin>>sortedArray[i];
		}
  
	//call sortedArrayToBalanceBSTree
	struct BSTreeNode *root = sortedArrayToBalanceBSTree(sortedArray, 0, n-1);
	cout<<"\nPreOrder Traversal of BST : \n";
	preOrder(root);
	cout<<endl;
		return 0;
	}
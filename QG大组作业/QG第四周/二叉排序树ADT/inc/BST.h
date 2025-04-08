//
// Created by k on 25-4-6.
//

#ifndef BST_H
#define BST_H
#include <iostream>
#include <stack>
#include <queue>


struct TreeNode
{
     int value;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};


class BST
{
private:
     TreeNode* root;
     TreeNode* insertNode(TreeNode* node,const int& val);
     TreeNode* searchNode(TreeNode* node,const int& val);
     TreeNode* deleteNode(TreeNode* node,const int& val);
     TreeNode* findMin(TreeNode* node);
     void preOrderRecursive(TreeNode* node);
     void inOrderRecursive(TreeNode* node);
     void postOrderRecursive(TreeNode* node);

public:
     BST():root(nullptr){}
     void insert(const int& val);
     TreeNode* search(const int& val);
     void deleteNode(const int& val);
     void preOrder();
     void preOrderNonRecursive();
     void inOrder();
     void inOrderNonRecursive();
     void postOrder();
     void postOrderNonRecursive();
     void levelOrder();
};



#endif

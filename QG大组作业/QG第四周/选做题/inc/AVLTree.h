//
// Created by k on 25-4-8.
//

#ifndef AVLTREE_H
#define AVLTREE_H



#include <iostream>

// 定义AVL树节点类
class AVLNode
{
public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};

// 定义AVL树类
class AVLTree
{
private:
    AVLNode* root;

    // 获取节点的高度
    int getHeight(AVLNode* node)
    {
        return node ? node->height : 0;
    }

    // 获取节点的平衡因子
    int getBalance(AVLNode* node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // 右旋操作
    AVLNode* rightRotate(AVLNode* y)
    {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // 左旋操作
    AVLNode* leftRotate(AVLNode* x)
    {

        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // 插入节点
    AVLNode* insert(AVLNode* node, int key)
    {
        if (!node) return new AVLNode(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // 左左情况
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // 右右情况
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // 左右情况
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // 右左情况
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // 查找最小节点
    AVLNode* minValueNode(AVLNode* node)
    {
        AVLNode* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    // 删除节点
    AVLNode* deleteNode(AVLNode* root, int key)
    {
        if (!root)
        {
            cerr<<"删除失败！"<<endl;
            return root;
        }
        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else
        {
            if ((root->left == nullptr) || (root->right == nullptr))
            {
                AVLNode* temp = root->left ? root->left : root->right;
                if (!temp)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else
            {
                AVLNode* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (!root) return root;

        root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

        // 左左情况
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // 左右情况
        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // 右右情况
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // 右左情况
        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // 中序遍历
    void inorder(AVLNode* root)
    {
        if (root != nullptr)
        {
            inorder(root->left);
            std::cout << root->key << " ";
            inorder(root->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key)
    {
        root = insert(root, key);
    }

    void deleteKey(int key)
    {
        root = deleteNode(root, key);
    }

    void inorderTraversal()
    {
        inorder(root);
        std::cout << std::endl;
    }
};




#endif //AVLTREE_H

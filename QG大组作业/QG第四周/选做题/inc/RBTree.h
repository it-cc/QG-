//
// Created by k on 25-4-8.
//

#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>

// 定义颜色枚举
enum class Color { RED, BLACK };

// 定义红黑树节点类
class RBNode
{
public:
    int key;
    RBNode* left;
    RBNode* right;
    RBNode* parent;
    Color color;

    RBNode(int value) : key(value), left(nullptr), right(nullptr), parent(nullptr), color(Color::RED) {}
};

// 定义红黑树类
class RBTree
{
public:
    RBNode* root;
    RBNode* NIL;

    // 左旋操作
    void leftRotate(RBNode* x)
    {
        RBNode* y = x->right;
        x->right = y->left;
        if (y->left != NIL)
        {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == NIL)
        {
            root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    // 右旋操作
    void rightRotate(RBNode* y)
    {
        RBNode* x = y->left;
        y->left = x->right;
        if (x->right != NIL)
        {
            x->right->parent = y;
        }
        x->parent = y->parent;
        if (y->parent == NIL)
        {
            root = x;
        }
        else if (y == y->parent->right)
        {
            y->parent->right = x;
        }
        else
        {
            y->parent->left = x;
        }
        x->right = y;
        y->parent = x;
    }

    // 插入修复
    void insertFixup(RBNode* z)
    {
        while (z->parent->color == Color::RED)
        {
            if (z->parent == z->parent->parent->left)
            {
                RBNode* y = z->parent->parent->right;
                if (y->color == Color::RED)
                {
                    z->parent->color = Color::BLACK;
                    y->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->right)
                    {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    rightRotate(z->parent->parent);
                }
            }
            else
            {
                RBNode* y = z->parent->parent->left;
                if (y->color == Color::RED)
                {
                    z->parent->color = Color::BLACK;
                    y->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->left)
                    {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = Color::BLACK;
    }

    // 插入节点
    void insert(RBNode* z)
    {
        RBNode* y = NIL;
        RBNode* x = root;

        while (x != NIL)
        {
            y = x;
            if (z->key < x->key)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }

        z->parent = y;
        if (y == NIL)
        {
            root = z;
        }
        else if (z->key < y->key)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }

        z->left = NIL;
        z->right = NIL;
        z->color = Color::RED;

        insertFixup(z);
    }

    // 中序遍历
    void inorder(RBNode* node)
    {
        if (node != NIL)
        {
            inorder(node->left);
            std::cout << node->key << " ";
            inorder(node->right);
        }
    }

    // 查找节点
    RBNode* search(RBNode* node, int key)
    {
        if (node == NIL || node->key == key)
        {
            return node;
        }
        if (key < node->key)
        {
            return search(node->left, key);
        }
        else
        {
            return search(node->right, key);
        }
    }

public:
    RBTree()
    {
        NIL = new RBNode(0);
        NIL->color = Color::BLACK;
        root = NIL;
    }



    void insert(int key)
    {
        RBNode* z = new RBNode(key);
        insert(z);
    }

    void inorderTraversal()
    {
        inorder(root);
        std::cout << std::endl;
    }

    RBNode* search(int key)
    {
        return search(root, key);
    }
};




#endif //RBTREE_H

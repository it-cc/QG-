//
// Created by k on 25-4-6.
//

#include "BST.h"

TreeNode* BST::insertNode(TreeNode *node, const int &val)
{
     // 如果当前节点为空，创建一个新节点并返回
     if (node ==nullptr) return new TreeNode(val);
     // 如果当前节点的值大于要插入的值，递归插入到左子树
     if (node->value > val)
     {
          node->left = insertNode(node->left,val);
     }
     // 如果当前节点的值小于要插入的值，递归插入到右子树
     else if (node->value < val)
     {
          node->right = insertNode(node->right,val);
     }
     return node;
}

TreeNode* BST::searchNode(TreeNode *node, const int &val)
{
     if (node ==nullptr || node->value==val) return node;
     // 如果当前节点的值大于要搜索的值，递归搜索左子树
     if (node->value > val)
     {
          return searchNode(node->left,val);
     }
     // 否则递归搜索右子树
     return searchNode(node->right,val);
}

TreeNode* BST::deleteNode(TreeNode *node, const int &val)
{
     // 情况 1：如果当前节点为空，说明未找到要删除的节点，直接返回 nullptr
     if (node == nullptr)
     {
          std::cerr<<"删除失败！"<<std::endl;
          return node;
     }
     // 情况 2：要删除的值小于当前节点的值，递归到左子树中删除
     if (val < node->value)
     {
          node->left = deleteNode(node->left, val);
     }
     // 情况 3：要删除的值大于当前节点的值，递归到右子树中删除
     else if (val > node->value)
     {
          node->right = deleteNode(node->right, val);
     }
     // 情况 4：找到要删除的节点
     else
     {
          std::cout<<"删除成功！"<<std::endl;
          // 情况 4.1：当前节点的左子节点为空
          if (node->left == nullptr)
          {
               TreeNode* temp = node->right;
               // 释放当前节点的内存
               delete node;
               return temp;
          }
          // 情况 4.2：当前节点的右子节点为空
          else if (node->right == nullptr)
          {
               TreeNode* temp = node->left;
               // 释放当前节点的内存
               delete node;
               return temp;
          }
          // 情况 4.3：当前节点的左右子节点都不为空
          TreeNode* temp = findMin(node->right);
          // 将右子树中最小节点的值赋给当前节点
          node->value = temp->value;
          // 递归地在右子树中删除该最小节点
          node->right = deleteNode(node->right, temp->value);
     }
     // 返回当前节点（可能已更新）作为新的子树根节点
     return node;
}

TreeNode* BST::findMin(TreeNode *node)
{
     // 不断向左遍历，直到左子节点为空
     while (node->left != nullptr)  node = node->left;
     return node;
}

void BST::preOrderRecursive(TreeNode *node)
{
     if (node != nullptr)
     {
          std::cout << node->value << " ";//前序位置
          preOrderRecursive(node->left);
          preOrderRecursive(node->right);
     }
}

void BST::inOrderRecursive(TreeNode *node)
{
     if (node != nullptr)
     {
          inOrderRecursive(node->left);
          std::cout << node->value << " ";//中序位置
          inOrderRecursive(node->right);
     }
}

void BST::postOrderRecursive(TreeNode *node)
{
     if (node != nullptr)
     {
          postOrderRecursive(node->left);
          postOrderRecursive(node->right);
          std::cout << node->value << " ";//后序位置
     }
}
//对外接口
void BST::insert(const int &val)
{
     root = insertNode(root, val);
}

TreeNode * BST::search(const int &val)
{
     return searchNode(root, val);
}

void BST::deleteNode(const int &val)
{
     root = deleteNode(root, val);
}

void BST::preOrder()
{
     preOrderRecursive(root);
}

void BST::preOrderNonRecursive()
{
     if (root == nullptr) return;
     std::stack<TreeNode*> stack;
     stack.push(root);
     while (!stack.empty())
     {
          TreeNode* node = stack.top();
          stack.pop();
          std::cout << node->value << " ";
          // 先将右子节点入栈
          if (node->right != nullptr)
          {
               stack.push(node->right);
          }
          // 再将左子节点入栈
          if (node->left != nullptr)
          {
               stack.push(node->left);
          }
     }
     std::cout << std::endl;
}

void BST::inOrder()
{
     inOrderRecursive(root);
}

void BST::inOrderNonRecursive()
{
     std::stack<TreeNode*> stack;
     TreeNode* current = root;
     while (current != nullptr || !stack.empty())
     {
          // 不断将左子节点入栈
          while (current != nullptr)
          {
               stack.push(current);
               current = current->left;
          }
          // 取出栈顶节点
          current = stack.top();
          stack.pop();
          std::cout << current->value << " ";
          current = current->right;
     }
     std::cout << std::endl;
}

void BST::postOrder()
{
     postOrderRecursive(root);
}

void BST::postOrderNonRecursive()
{
     if (root == nullptr) return;
     std::stack<TreeNode*> stack1, stack2;
     // 将根节点压入栈 1
     stack1.push(root);
     while (!stack1.empty())
     {
          // 取出栈 1 的栈顶节点
          TreeNode* node = stack1.top();
          stack1.pop();
          // 将该节点压入栈 2
          stack2.push(node);
          // 先将左子节点压入栈 1
          if (node->left != nullptr)
          {
               stack1.push(node->left);
          }
          // 再将右子节点压入栈 1
          if (node->right != nullptr)
          {
               stack1.push(node->right);
          }
     }
     while (!stack2.empty())
     {
          // 取出栈 2 的栈顶节点并访问
          std::cout << stack2.top()->value << " ";
          stack2.pop();
     }
     std::cout << std::endl;
}

void BST::levelOrder()
{
     if (root == nullptr) return;
     std::queue<TreeNode*> queue;
     queue.push(root);
     while (!queue.empty())
     {
          // 取出队首节点
          TreeNode* node = queue.front();
          queue.pop();
          std::cout << node->value << " ";
          // 如果左子节点不为空，将其入队
          if (node->left != nullptr)
          {
               queue.push(node->left);
          }
          // 如果右子节点不为空，将其入队
          if (node->right != nullptr)
          {
               queue.push(node->right);
          }
     }
     std::cout << std::endl;
}

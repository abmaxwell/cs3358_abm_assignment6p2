#include "btNode.h"

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
   if (bst_root == 0) return;
   int dumpIndex = 0;
   dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
   if (bst_root == 0) return;
   dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
   dumpArray[dumpIndex++] = bst_root->data;
   dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}

void bst_insert(btNode*& bst_root, int insInt){

   /// Create new node to insert.
   btNode* newBtNode = new btNode;
   newBtNode->data = insInt;
   newBtNode->left,newBtNode->right = 0;

   /// Check for empty tree.
   if(bst_root == 0){
      bst_root = newBtNode;
      return;
   }

   btNode* cursor = bst_root;
   btNode* lastBtNode = 0;

   /// Check whether to insert LST or RST.
   while(cursor != 0) {

      // Current node is the last node presently.
      lastBtNode = cursor;

      // insInt matches value already in the tree. Overwrite value.
      if(cursor->data == insInt){
         cursor->data = insInt;
         return;
      }

      if (cursor->data > insInt) {
         // insInt is less than root node insert LST.
         cursor = cursor->left;
      } else {
         // insInt is greater than root node insert RST.
         cursor = cursor->right;
      }
   }

   /// Last node in LST or RST found. Choose insertion path.

   if(lastBtNode->data > insInt){
      // insInt is less than root node insert LST.
      lastBtNode->left = newBtNode;
      return;
   } else {
      // insInt is greater than root node insert RST.
      lastBtNode->right = newBtNode;
      return;
   }
}
bool bst_remove(btNode*& bst_root, int remInt){

}
void bst_remove_max(btNode*& bst_root, int& data){
   /// Check to see if tree is empty. Don't do anything.
   if(bst_root == 0){return;}

   if(bst_root->right == 0){
      // Tree has NO right child, largest item at root.
      btNode* deleteNode = bst_root;
      data = bst_root->data;
      bst_root = bst_root->left;
      delete deleteNode;
   } else {
      // Tree HAS right child, largest item NOT at root.
      bst_remove_max(bst_root->right, data);
   }
}



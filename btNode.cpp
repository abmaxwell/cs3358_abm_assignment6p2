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

   if(bst_root == 0){
      /// Tree is empty. Root becomes new item.
      btNode* new_root = new btNode;
      new_root->data = insInt;
      new_root->left = new_root->right = 0;
      bst_root = new_root;
      return;
   }

   // Create cursor to traverse tree.
   btNode* cursor = bst_root;

   /// Check whether to insert LST or RST.
   while (cursor != 0) {

      if (cursor->data > insInt) {
         /// Insert new node LST.
         if(cursor->left == 0){
            // Empty spot found.
            cursor->left = new btNode;
            cursor->left->data = insInt;
            cursor->left->left = cursor->left->right = 0;
            return;
         } else {
            // Keep searching.
            cursor = cursor->left;
         }
      } else if(cursor->data < insInt){
         /// Insert new node RST.
         if(cursor->right == 0) {
            // Empty spot found.
            cursor->right = new btNode;
            cursor->right->data = insInt;
            cursor->right->left = cursor->right->right = 0;
            return;
         } else {
            // Keep searching.
            cursor = cursor->right;
         }
      } else {
         /// Parent's data matches new item. No change.
         return;
      }
   }

}

bool bst_remove(btNode*& bst_root, int remInt){
   /// Check to see if tree is empty. Don't do anything.
   if(bst_root == 0){return false;}

   if(bst_root->data > remInt){
      // Target int is less than root.
      bst_remove(bst_root->left, remInt);

   } else if(bst_root->data < remInt) {
      // Target int is greater than root.
      bst_remove(bst_root->right, remInt);

   } else {
      /// Target int is equal to root. Special conditions present.

      if(bst_root->left != 0 && bst_root->right != 0){
         /// Case where BOTH LST and RST children present.
         bst_remove_max(bst_root->left, bst_root->data);
      } else {
         /// Cases where only LST or RST or non children present.
         btNode* old_bst_root = bst_root;
         if(bst_root->left == 0 && bst_root->right != 0){
            // Has RST but no LST.
            bst_root = bst_root->right;
         } else if (bst_root-> left != 0 && bst_root->right == 0){
            // Has LST but no RST.
            bst_root = bst_root->left;
         } else {
            // No LST or RST children, parent only.
            bst_root = 0;
         }
         // Free up old head.
         delete old_bst_root;
      }
      return true;
   }
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



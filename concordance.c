// Author : Ansley Orrell

#include <stdio.h>
#include "bst.h"

bstnode_t *bst_search(const bstnode_t *root, const char *word) {
    if (root == NULL) {
        return NULL; 
    }

    int cmp = strcasecmp(word, root->word); //not case sensetive

    if (cmp == 0) {
        return root; //word has been found
    } else if (cmp < 0) {
        return bst_search(root->left, word); //search left side
    } else {
        return bst_search(root->right, word); //serch right side
    }
}



int main(int argc, char *argv[]) {
    if (argc > 1) {
        fprintf(stderr, "usage: concordance");
        return 1;
    }

    bstnode_t *root = NULL; //Initializing an empty BST

    char *word = NULL; //pointer for word



#define _DEFAULT_SOURCE
#include <stdio.h>
#include "bst.h"
#include <string.h>
#include <stdlib.h>



void bst_traverse(const bstnode_t *root) {
    if (root == NULL) {
        return; // base case
    }

    // left side of the tree
    bst_traverse(root->left);

    // prints the word & frequency
    printf("%s (%u):", root->word, root->freq); //%u unsigned
    
    // reference list
    for (int i = 0; i < root->freq; i++) {
        printf(" %d,", root->refs[i]);
    }

    printf("\n");

    // right side of tree
    bst_traverse(root->right);
}

void bst_insert(bstnode_t **bp, const char *word) {
    if (*bp == NULL) {

        *bp = (bstnode_t *)malloc(sizeof(bstnode_t));

        //dynamically allocate the correct amount of space 
        //and will copy the NUL-terminated string src into that space, returning the pointer to that space to you.
        (*bp)->word = strdup(word);

        // Initialize frequency, reference list capacity, left, and right pointers
        (*bp)->freq = 1;
        (*bp)->reflen = 1; 
        (*bp)->refs = (unsigned int *)malloc(sizeof(unsigned int) * (*bp)->reflen);
        (*bp)->refs[0] = 1;  // add the first reference
        (*bp)->left = NULL;
        (*bp)->right = NULL;

    } else {

        // compare the word with the current node's word
        int cmp = strcasecmp(word, (*bp)->word);

        if (cmp == 0) {
            (*bp)->freq++;
        } else if (cmp < 0) {
            // Insert in the left subtree
            bst_insert(&(*bp)->left, word);
        } else {
            // Insert in the right subtree
            bst_insert(&(*bp)->right, word);
        }
    }
}





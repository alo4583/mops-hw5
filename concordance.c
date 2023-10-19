// Author : Ansley Orrell

#define _DEFAULT_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bst.h"

const bstnode_t *bst_search(const bstnode_t *root, const char *word) {
    if (root->word == NULL || word == NULL) {
        return NULL;
    }

    int cmp = strcasecmp(word, root->word); 

    if (cmp == 0) {
        return root; // Word has been found
    } else if (cmp < 0) {
        // < 0 means alphabetically smaller
        return bst_search(root->left, word); // Search the left side
    } else {
        return bst_search(root->right, word); // Search the right side
    }
}




int main(int argc, char *argv[]) {
    if (argc > 1) {
        fprintf(stderr, "usage: concordance");
        return 1;
    }

    char *buf = NULL;  // important: must initially be NULL
    size_t len = 0;    // should initially be 0
    size_t bytesRead = 0;

    while(getline(&buf,&len,stdin) != -1 ) {
        //printf( "line was %d bytes long: %s", bytesRead, buf);
        char *temp = strdup( buf );
        printf("\n");
    }

    if( buf != NULL ) {
        free( buf );  // must deallocate this space!
    }

    return( 0 );

    // bstnode_t *root = NULL;
    // char *buf = NULL;  // important: must initially be NULL
    // size_t len = 0;    // should initially be 0

    // while (getline(&buf, &len, stdin) != -1) {
    //     char *word = strtok(buf, " "); 

    //     while (word != NULL) {
    //         bstnode_t *existingNode = bst_search(&root, word);

    //         if (existingNode) {
    //             // Word already exists, update the existing node
    //             existingNode->freq++;

    //             // need to update the reference list with the line number 

    //         } else {
    //             bst_insert(&root, word);

    //             word = strtok(NULL, " \t\n"); // get the next word
    //         }
            
    //     }
    // }
    // if( buf != NULL ) {
    //     free( buf );  //deallocate this space
    // }

    // bst_traverse(root);
}




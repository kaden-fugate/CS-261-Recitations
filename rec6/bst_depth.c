#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void maxHelper(struct TreeNode *root, int *max, int *cur)
{
    if(!root){ return; }

    if(root->left){ 
        (*cur)++;
        if( (*cur) > *max){ *max = *cur; }  
        maxHelper(root->left, max, cur);
    }

    else if(root->right){ 
        (*cur)++;
        if( (*cur) > *max){ *max = *cur; }  
        maxHelper(root->right, max, cur);
    }
    
}

int maxDepth(struct TreeNode* root)
{
    if(!root){ return -1; }
    if( !root->left && !root->right ){ return 0; }
    int max = 0, cur = 0;

    maxHelper(root, &max, &cur);

    return max;

}

void minHelper(struct TreeNode *root, int *min, int cur)
{

    if( !root->left && !root->right ){ 
        if( cur < *min ) { *min = cur; }
        return;
    }
    cur++; // when not leaf node, add to depth
    if(root->left){ minHelper(root->left, min, cur); }
    if(root->right){ minHelper(root->right, min, cur); }

}

int minDepth(struct TreeNode* root)
{
    
    if(!root){ return -1; }
    if(!root->left && !root->right){ return 0; }

    int min = 100001, cur = 0; // 100001 = 10^5 + 1 (greater than bounds)

    minHelper(root, &min, cur);

    return min;
}

struct TreeNode* newNode(int val){
    struct TreeNode *n = malloc(sizeof(struct TreeNode));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main(void)
{
    
    //test 1: Empty Tree
    printf("\nTest1: Empty Tree....\n");
    printf("Max Depth:\nExpected: -1\nActual: %d\n\n", maxDepth(NULL));
    printf("Min Depth:\nExpected: -1\nActual: %d\n\n", minDepth(NULL));
    
    //  1
    //2    

    struct TreeNode *root = newNode(20);

    //test 2: Tree with only a root node
    printf("\nTest2....\n");
    printf("Max Depth:\nExpected: 0\nActual: %d\n\n", maxDepth(root));
    printf("Min Depth:\nExpected: 0\nActual: %d\n\n", minDepth(root));
    

    struct TreeNode *node1 = newNode(18);
    root->left = node1;

    struct TreeNode *node2 = newNode(16);
    node1->left = node2;

    struct TreeNode *node3 = newNode(14);
    node2->left = node3;

    struct TreeNode *node4 = newNode(12);
    node3->left = node4;

    //test 3:
    //            20
    //         18
    //      16
    //   14
    //12
    printf("\nTest3....\n");
    printf("Max Depth:\nExpected: 4\nActual: %d\n\n", maxDepth(root));
    printf("Min Depth:\nExpected: 4\nActual: %d\n\n", minDepth(root));

    //test 4:
    //            20
    //         18    22
    //      16
    //   14
    //12
    struct TreeNode *node5 = newNode(22);
    root->right = node5;
    printf("\nTest4....\n");
    printf("Max Depth:\nExpected: 4\nActual: %d\n\n", maxDepth(root));
    printf("Min Depth:\nExpected: 1\nActual: %d\n\n", minDepth(root));


    //test 5:
    //            20
    //         18    22
    //      16    21    26 
    //   14                30
    //12
    struct TreeNode *node6 = newNode(21);
    node5->left = node6;
    struct TreeNode *node7 = newNode(26);
    node5->right = node7;
    struct TreeNode *node8 = newNode(30);
    node7->right = node8;
    printf("\nTest5....\n");
    printf("Max Depth:\nExpected: 4\nActual: %d\n\n", maxDepth(root));
    printf("Min Depth:\nExpected: 2\nActual: %d\n\n", minDepth(root));

    free(root);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
    free(node7);
    free(node8);




    return 0;
}
// By: Gonçalo Leão

#include "exercises.h"

int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    int parcialsum = 0 ,maxSum = 0;
    for (int k = 0; k < n ; ++k) {
        parcialsum = 0;
        for(int a = k; a<n;a++){
            parcialsum += A[a];
        }
        if(maxSum <parcialsum){
            i = k;
            j = n;
            maxSum = parcialsum;
        }
    }
    for (int k = n; k > 0 ; --k) {
        parcialsum = 0;
        for(int a = 0; a<k;a++){
            parcialsum += A[a];
        }
        if(maxSum <parcialsum){
            i = k;
            j = n;
            maxSum = parcialsum;
        }
    }
    
    
    
    return maxSum;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex2, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequence(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}
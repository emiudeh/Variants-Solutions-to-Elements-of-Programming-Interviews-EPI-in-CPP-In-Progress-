/* 
*************************************************************************************
    OBJECTIVE: Given an array, compute the k-th permutation under lexicographic 
    ordering, starting from the identity permutation, which is the first permutation 
    in lexicographic ordering
*************************************************************************************
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> kth_permutation(vector<int>myVec, int level){
    
    //sorted case is 1st permutation
    sort(myVec.begin(), myVec.end());
    while(level > 1){
        int breakpoint = myVec.size() - 2;
        while (breakpoint >= 0 && myVec[breakpoint] > myVec[breakpoint + 1])
            breakpoint--;
            
        if (breakpoint == -1)
            return {};
        
        int swappoint;
        for (int i = breakpoint + 1; i < myVec.size(); i++){
            if (myVec[i] > myVec[breakpoint])
                swappoint = i;
            else break;
        }
        
        swap(myVec[breakpoint], myVec[swappoint]);
        reverse(myVec.begin() + breakpoint + 1, myVec.end());
        
        level--;
    }
    return myVec;
}
 //TEST
int main() {
	vector<int> myVec {7,6,5,4,3,2,1};
	myVec = kth_permutation(myVec, 3);
    
    for (auto i : myVec)
        cout << i << ", " ;
    return 0;
}

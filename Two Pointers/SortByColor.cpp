//https://www.interviewbit.com/problems/sort-by-color/

/*
void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;
    int n = A.size();
    for(int i=0; i<n; i++){
        if(A[i]==0){
            count_0++;
        } else if(A[i]==1){
            count_1++;
        } else {
            count_2++;
        }
    }
    A.clear();
    while(count_0>0){
        A.push_back(0);
        count_0 --;
    }
    while(count_1>0){
        A.push_back(1);
        count_1 --;
    }
    while(count_2>0){
        A.push_back(2);
        count_2 --;
    }
}
*/
//M2 - Using two pointers
void Solution::sortColors(vector<int> &A) {

    int n = A.size();
    int s = 0;
    int e = n-1;
    int i = 0;
    while(i <= e){
        if(A[i] == 0){
            swap(A[i], A[s]);
            s++;
        } else if(A[i] == 2){
            swap(A[i], A[e]);
            e --;
            continue;
            
        }
        i++;
    }
return ;
    
}

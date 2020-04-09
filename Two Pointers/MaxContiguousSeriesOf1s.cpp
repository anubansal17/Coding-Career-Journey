//https://www.interviewbit.com/problems/max-continuous-series-of-1s/
vector<int> Solution::maxone(vector<int> &A, int B) {
    int n = A.size();
    int s = 0, e = 0;
    int ansS = 0, ansE = 0;
    int flips = 0;
    while (e<n){
        //Window expansion
        while (e<n && flips<=B){
            if(A[e] == 0){
                flips++;
            }
            if(flips<=B && (e-s) > (ansE - ansS)){
                ansE = e;
                ansS = s;
            }
            e ++;
        }
        //Window contraction
        while (s<e && flips>B){
            if(A[s]==0){
                flips --;
            }
            s++;
        }
    }
    vector <int> v{};
    for(int i=ansS; i<=ansE; i++){
        v.push_back(i);
    }
    return v;
}

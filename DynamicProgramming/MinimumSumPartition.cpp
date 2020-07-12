#include<iostream>
#include<vector>
using namespace std;
vector <int> knapsack(vector<int> input, int n, int sum) {
    int tp[n+1][sum+1];
    for (int i=0; i<n+1; i++) {
        for(int j=0; j<sum+1; j++) {
        // Base condition: If number of elements are zero
        if(i == 0 and j != 0) {
            tp[i][j] = 0;
            } 
        // If reqd sum is zero, this subset sum is possible so initialising it with 1
        else if(j == 0) {
            tp[i][j] = 1;
            }
        // If current element value is greater than reqd sum
        else if(input[i-1] > j) {
            tp[i][j] = tp[i-1][j];
            } 
        // If current element value is less than the reqd sum
        else {
            tp[i][j] = tp[i-1][j-input[i-1]] || tp[i-1][j];
            }
        }
    }
    vector <int> possibleSum;
    for (int i=0; i<sum+1; i++) {
        possibleSum.push_back(tp[n][i]);
        //cout<<tp[n][i];
    }
    //cout<<endl;
    return possibleSum;
}
int main()
 {
int T, n;
	cin>>T;
	for (int i=0; i<T; i++)
	{
	    cin>>n;
	    vector <int> input;
	    for (int j=0; j<n; j++) {
	        int x;
	        cin>>x;
	        input.push_back(x);
	    }
	    int ans;
	    // As we want S1- S2 -> minimum
	    // S1+S2 = Range
	    // S2 = Range - S1
	    // We have to minimze Range - 2S1
	    // To minimize above, we need to maximize S1
	    // S1 will lie between 0 to Range/2
	    // We can find the max sum possible till range/2 and that would be our answer
	    // We can use subset sum problem to find out the maximum sum possible between 0 and range/2
	    // Last row in Output matrix of subset sum problem, tells us which subset sum is possible and which is not
	    int sum = 0;
	    for (int j=0; j<n; j++) {
	        sum += input[j];
	    }
	    vector <int> sumPossible;
	    sumPossible = knapsack(input, input.size(), sum);
	    // Maximum sum possible between 0 and totalSum/2
	    int maxPartSum = 0;
	    for(int j=0; j<=sum/2; j++) {
	        if(sumPossible[j] == 1) {
	            maxPartSum = j;
	        } 
	    }
	    cout<<sum - 2*maxPartSum<<endl;
	}
	return 0;
}

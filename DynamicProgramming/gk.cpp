#include<iostream>
#include<vector>
using namespace std;
int main() {
	int t;
	cin>>t;
	for (int i=0; i<t; i++) {
		int n;
		cin>>n;
		vector<int> input;
		vector<int> key(n,0);
		// A-1, B-2, C-3, D-4
		for(int j=0; j<n; j++) {
			int x;
			cin>>x;
			input.push_back(x);
		}
		int ans = 0;
		int firstKey = 0;
		if(input[0] == input[1]) {
			for (int i=0; i<n-1; i++) {
				if(input[i] < input[i+1]) {
					firstKey = 1;
					break;
				} else if(input[i] > input[i+1]) {
					firstKey = 4;
					break;
				}
			}
		}
		for (int j=0; j<n-1; j++) {
			// Incase there is only one element in array
			if(n == 1){
				break;
			}
			// Incase its the first element and size is atleast 2
			else if(j == 0) {
				// if first element is greater than second element
				if(input[j]>input[j+1]){
					key[j] = 4;
				}
				// if first element is less than second element 
				else if(input[j] < input[j+1]) {
					key[j] = 1;
				} else{
					// Check if all the elements are equal or not
					if(firstKey != 0){
						key[j] = firstKey;
					} else {
						break;
					}
				}
			}
			// Incase of other elements
			else {
				// If current element is less than previous element
				if(input[j] < input[j-1]) {
					// If key lies between 1 and 4
					if(key[j-1] - 1 >=1 and key[j-1] - 1 <= 4)
						key[j] = key[j-1] - 1;
					// If it doen't lie between 1 and 4
					else{
						// Increment violation count
						ans++;
						// check if the current element is greater than next one and then assign it the highest note
						if(input[j] > input[j+1]) {
							key[j] = 4;
						}
						// Check if the current element is less than the next one and assign it the lowest note 
						else if(input[j] < input[j+1])
							key[j] = 1;
						// Check if the current element is equal to next element then scan through the whole array
						else {
							// pending
							key[j] = 1;
						}
					}
				}
				// If current element is greater than previous element 
				else if(input[j] > input[j-1]) {
					if(key[j-1] + 1 >=1 and key[j-1] + 1 <= 4)
						key[j] = key[j-1] + 1;
					else {
						ans++;
						if(input[j] > input[j+1]) {
							key[j] = 4;
						} else if(input[j] < input[j+1])
							key[j] = 1;
						else {
							// pending
							key[j] = 1;
						}
					}
				}
				// If current element is equal to previous element 
				else {
					key[j] = key[j-1];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

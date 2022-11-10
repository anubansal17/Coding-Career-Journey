#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
/*
Consider two lists: one representing a paragraph, and one representing a list of keywords. For a given paragraph and keyword list, determine the smallest subarray of the paragraph which covers all of the keywords. The keywords’ order of appearance does not matter. Keywords may or may not be separated by other words.

Paragraph:
how green now green brown how cow now brown cow
     ^                         ^
Keywords:
how now brown cow - m
Output:
brown how cow now OR how cow now brown 

Ans1 : how green now green brown how cow

*/
bool isEqual(unordered_map<string, int> &targetMap, unordered_map<string, int> &wordMap) {
    for(auto word : targetMap) {
        if(wordMap[word.first] < targetMap[word.first])
            return 0;
    }
    return 1;
    
}
vector<string> findSmallestSubarray(vector<string> paragraph, vector<string> keywords) {
    unordered_map<string, int> targetMap;
    for(string key: keywords) {
        targetMap[key]++;
    }
    int n = paragraph.size();
    int start = 0;
    int end = 0;
    int minStartIndex = 0;
    int minEndIndex = INT_MAX;
    int minLength = INT_MAX;
    unordered_map<string, int> wordMap;
    while(start < n and end < n) {
        cout<< paragraph[end]<<" "<<endl;
        if(targetMap.find(paragraph[end]) != targetMap.end()) {
            cout<< paragraph[end]<<" "<<endl;
            wordMap[paragraph[end]]++;
            if(isEqual(targetMap, wordMap)) {
                if(minLength > end-start) {
                 minStartIndex = start;
                 minEndIndex = end;
                 minLength = end - start;   
                }
                wordMap[paragraph[start]]--;
                start++;
            } else {
                end++;
            }
        }
        else if(end < n)
            end++;
    }
    vector<string> ans;
    for(int i=minStartIndex; i<=minEndIndex; i++) {
        ans.push_back(paragraph[i]);
    }
    return ans;
}

int main() {
    int num1, num2;
    int sum;
    cin>>num1>>num2;
    vector<string> target = {"the", "to"};
    vector<string> paragraph = {"I", "pledge", "allegiance", "to", "the", "flag", "of", "the", "United", "States", "of", "America", "and", "to", "the"};
    vector<string> ans = findSmallestSubarray(paragraph, target);
    for(string str: ans){
        cout<<str<<" ";
    }

    return 0;
}

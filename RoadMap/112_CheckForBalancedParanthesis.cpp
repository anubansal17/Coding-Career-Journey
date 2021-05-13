// Approach 1: Count number of operators and number of brackets
/*
- If it turns out to be not equal then we have redundant braces otherwise not
Approach 2: Using stacks
- Need to understand using stacks
*/
int Solution::braces(string A) {
    int countBrackets = 0;
    int countOps = 0;
    for (char ch : A) {
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            countOps++;
        }
        else if(ch == ')') {
            countBrackets++;
        }
    }
    return (countOps < countBrackets);
}

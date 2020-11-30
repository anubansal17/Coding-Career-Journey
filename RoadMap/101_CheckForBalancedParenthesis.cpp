class Solution {
public:
    bool isValid(string s) {
       stack <char> charStack;
	int size = s.size();
	for (int i=0; i<size; i++) {
			if(s[i] == '{' || s[i] == '[' || s[i] == '(') {
				charStack.push(s[i]);
			}
			else {
                if(charStack.empty()) {
                    return false;
                }
                else if(s[i] == '}') {
                    if(charStack.top() != '{'){
                        return false;
                    } 
                    charStack.pop();
                }
                else if(s[i] == ']') {
                    if(charStack.top() != '[') {
                        return false;
                    }
                    charStack.pop();
                }
                else if(s[i] == ')') {
                    if(charStack.top() != '(') {
                        return false;
                    } 
                        charStack.pop();
 			}
	    }
    }
	if(!charStack.empty()) {
		return false;
	}
	return true; 
    }
};

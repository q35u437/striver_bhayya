string minRemoveToMakeValid(string s) {
    stack<int> st;
    for(int index = 0; index < s.size(); index++){
        if(s[index] == '('){
            st.push({index});
            s[index] = '*';
        }else if(s[index] ==')'){
            if(!st.empty()){
                s[st.top()] = '(';
                st.pop();
            }else{
                s[index] = '*';
            }
        }
    }
    while(!st.empty()){
        s[st.top()] = '*';
        st.pop();
    }
    string result = "";
    for(char ch : s){
        if(ch != '*')
            result += ch;
    }
    return result;
}

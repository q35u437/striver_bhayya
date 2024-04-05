int numSub(string s) {
    long long total = 0, counter = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '1'){
            counter++;
            total += counter;
        }else{
            counter = 0;
        }
    }
    return total % 1000000007;
}

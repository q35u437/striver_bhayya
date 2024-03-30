int numberOfSubstrings(string s) {
    int index = s.size()-1, totalways = 0, length = s.size();
    int a = -1, b = -1, c = -1;
    while(index >= 0){
        if(s[index] == 'a')
            a = index;
        
        if(s[index] == 'b')
            b = index;

        if(s[index] == 'c')
            c = index;
        
        if(a!=-1 and b!=-1 and c!=-1){
            totalways += length - max(a,max(b,c));
        }
        index--;
    }
    return totalways;
}

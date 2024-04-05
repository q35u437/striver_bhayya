int minFlips(string target) {
    int total = 0;
    int start = target.find('1');
    if(start == -1){
        return total;
    }else{
        for(;start < target.size();){
            char ch = target[start];
            while(ch == target[start]){
                start++;
            }
            total++;
        }
        return total;
    }
}

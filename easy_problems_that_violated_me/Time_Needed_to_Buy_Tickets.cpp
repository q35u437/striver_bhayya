int timeRequiredToBuy(vector<int>& tickets, int k) {
    //nice approach that i've seen :)
    int answer = 0, target = tickets[k];
    for(int i=0;i<=k;i++)
        answer += min(tickets[i],target);
    target--;
    for(int i=k+1;i<tickets.size();i++)
        answer += min(tickets[i],target);
    return answer;
}

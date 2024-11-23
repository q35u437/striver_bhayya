class Solution {
public:
    int countPrimes(int n) {

        vector<bool> primes(n+1, true);


        for(int number=2;number*number <= n; number++){
            if(primes[number]){
                for(int multiples = number * number; multiples <= n; multiples += number){
                    primes[multiples] = false;
                }
            }
        }

        int counter = 0;
        for(int p = 2; p < n; p++){
            counter+=primes[p];
        }

        return counter;
    }
};

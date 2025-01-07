class Solution {
    public StringBuilder getStringRep(int number){
        if(number == 0) return new StringBuilder("0");
        StringBuilder rep = new StringBuilder("");
        while(number > 0){
            rep.append(number%2);
            number /= 2;
        }
        rep.reverse();
        return rep;
    }
    public int[][] substringXorQueries(String s, int[][] queries) {

        // a little bit of pre-processing
        HashMap<String, Integer> myMap = new HashMap<String, Integer>();
        for(int i = 0; i < s.length(); i++){
            StringBuilder gg = new StringBuilder("");
            for(int j = i; j < Math.min(i+30,s.length()); j++){
                gg.append(s.charAt(j));
                if(!myMap.containsKey(gg.toString())){
                    myMap.put(gg.toString(), i);
                }
            }
        }

        int counter = 0;
        int[][] answer = new int[queries.length][2];
        for(int[] query : queries){
            int first = query[0];
            int second = query[1];

            // value ^ first = second can be re-written such that value = first ^ second
            int search = first ^ second;

            String str_representation = this.getStringRep(search).toString();

            if(myMap.containsKey(str_representation)){
                answer[counter++] = new int[]{myMap.get(str_representation), myMap.get(str_representation)+ (str_representation.length()-1)};
            }else{
                answer[counter++] = new int[]{-1, -1};
            }
        }
        return answer;
    }
}

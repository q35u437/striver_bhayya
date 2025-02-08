class NumberContainers {
    private HashMap<Integer, Integer> number_at_index;
    private HashMap<Integer, TreeSet<Integer>> index_at_number;
    public NumberContainers() {
        number_at_index = new HashMap<Integer, Integer>();
        index_at_number = new HashMap<Integer, TreeSet<Integer>>();
    }
    
    public void change(int index, int number) {
        if(!number_at_index.containsKey(index)){
            number_at_index.put(index, number);
        }else{
            int previous_number = number_at_index.get(index);
            number_at_index.put(index, number);
            index_at_number.get(previous_number).remove(index);
        }

        if(!index_at_number.containsKey(number)){
            index_at_number.put(number, new TreeSet<Integer>());
            index_at_number.get(number).add(index);
        }else{
            index_at_number.get(number).add(index);
        }
    }
    
    public int find(int number) {
        if(!index_at_number.containsKey(number) || index_at_number.get(number).size() == 0){
            return -1;
        }else{
            return index_at_number.get(number).first();
        }
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */

class MKAverage {
    ArrayList<Integer> v = new ArrayList<>(), v2 = new ArrayList<>();
    int m, k, sum;
    public MKAverage(int m1, int k1) {
        m = m1;
        k = k1;
        sum = 0;
    }
    
    public void addElement(int num) {
        if(v.size() >= m) {
            int num2remove = v.get(v.size()-m);
            v2.remove(new Integer(num2remove)); sum -= num2remove; 
        };
        v.add(num);
        sum += num;
        int res = Collections.binarySearch(v2, num);
        if(res < 0) res = (res*-1) - 1;
        v2.add(res, num);
    }
    
    public int calculateMKAverage() {
        return (v.size() < m ? -1 : ((int)Math.floor(sum / m-k*2)));
    }
}

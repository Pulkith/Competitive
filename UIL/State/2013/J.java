import java.util.*;


public class J {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = Integer.parseInt(s.nextLine());
        while(T-- > 0) {
            char[] ar = s.nextLine().toCharArray();
            int n = Integer.parseInt(s.nextLine());
            String[] list = new String[n];
            for(int i = 0; i < n; ++i)
                list[i] = s.nextLine();
            HashMap<Character, Integer> map = new HashMap<>();
            int i = 0;
            for(char c : ar){
                map.put(c, i++);
            }
            Arrays.sort(list, new Comparator<String>(){
                public int compare(String s1, String s2){
                    if(s1.startsWith(s2) || s2.startsWith(s1))
                        return (s2.length()>s1.length()) ? -1 : 1;
                        int min = Math.min(s1.length(), s2.length());
                        for(int i = 0; i < min; ++i  ){
                            if(s1.charAt(i) == s2.charAt(i)) continue;
                            return (int)Math.signum(map.get(s1.charAt(i)) - map.get(s2.charAt(i)));
                        }
                    return 0;
                }
            });
            for(String str : list)
                System.out.println(str);
            System.out.println();
        }
    }
}

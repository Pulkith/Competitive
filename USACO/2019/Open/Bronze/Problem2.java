import java.util.*;
import java.io.*;
import java.awt.*;
import java.util.List;


public class Problem2 {
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(new File("milkorder.in"));
        //Scanner s = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milkorder.out")));
        //PrintWriter out = new PrintWriter(System.out);
        int C = s.nextInt();
        Integer[] cows = new Integer[C+1];
        int O = s.nextInt(), D = s.nextInt();
        ArrayList<Integer> order = new ArrayList<>();
        while(O -- > 0) {
            order.add(s.nextInt());
        }
        while(D-- > 0) {
            int t = s.nextInt();
            cows[s.nextInt()] = t;
        }

        List<Integer> cow = new ArrayList<>();
        for(Integer i : cows) {
            cow.add(Objects.requireNonNullElse(i, 0));
        }
        Collections.reverse(order);
        for(int i = cow.size() - 1; i >= 1 && order.size() > 0; i--) {
            int find = cow.indexOf(order.get(0));
            if(find != -1) {
                i = find;
                order.remove(0);
            } else {
                while(cow.get(i) != 0) {
                    --i;
                }
                cow.set(i, order.get(0));
                order.remove(0);
            }


        }
        System.out.println(cow);
        for(int i = 1; i < cow.size(); ++i) {
            if(cow.get(i) == 0){
                out.println(i);
                break;
            }
        }

        out.close();
    }
}
/*
4 2 1
3 2
2 1
// 2 3 0 1


*/
import java.util.*;
import java.io.*;
import java.awt.*;

public class Problem3 {
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(new File("badmilk.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("badmilk.out")));
        int N = s.nextInt(), M = s.nextInt(), D = s.nextInt(), S = s.nextInt();
        int max = 0;
        ArrayList<Point> arr[] = new ArrayList[N];
        for(int i = 0; i < arr.length; ++i)
            arr[i] = new ArrayList<Point>();
        for(int i = 0; i < D; ++i) {
            arr[s.nextInt()-1].add(new Point(s.nextInt(), s.nextInt()));
        }
        ArrayList<Integer> sus = new ArrayList<>();
        for (ArrayList<Point> points : arr) {
            points.sort((a, b) -> (a.y - b.y));
        }
        for(int i = 0; i < S; ++i) {
           ArrayList<Integer> ex = new ArrayList<>();
           int person = s.nextInt(), time = s.nextInt();
           ArrayList<Point> x = arr[person-1];

           int po = 0;
           do {
               ex.add(x.get(po).x);
               ++po;
           }
           while(po < x.size() && x.get(po).y < time);
            if(sus.size() == 0)
                sus.addAll(ex);
            else
                sus.retainAll(ex);

        }

        for(int i = 0; i < sus.size(); ++i) {
            int cur = 0;
            for(int j = 0; j < arr.length; ++j) {
                for(int k = 0; k < arr[(j)].size(); ++k) {
                    if(arr[j].get(k).x == sus.get(i)) {
                        ++cur;
                        break;
                    }
                }
            }
            max = Math.max(cur, max);
        }
        out.println(max);
        out.close();

    }
}
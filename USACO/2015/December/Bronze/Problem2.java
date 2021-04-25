import java.util.*;
import java.io.*;
import java.awt.*;
public class Problem2 {
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(new File("speeding.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("speeding.out")));
        //new BufferedWriter(new FileWriter("paint.out"))
        int m = s.nextInt(), n = s.nextInt();
        Queue<Point> q = new LinkedList<>();
        for(int i = 0; i < m; ++i) {
            q.add(new Point(s.nextInt(), s.nextInt()));
        }
        int max = 0;
        for(int i = 0; i < n; ++i) {
            int len = s.nextInt(), speed = s.nextInt();

            while(len > 0) {
                if(len >= q.peek().x) {
                    Point  p = q.poll();
                    len -= p.x;
                    max = Math.max(max, speed - p.y);
                } else {
                    q.peek().x -= len;
                    max = Math.max(max, speed - q.peek().y);
                    len = 0;
                }

            }
        }
        out.println(max);
        out.close();
    }
}

import java.util.*;
import java.awt.Point;


public class Problem4 {
   public static void main(String[] args) {
       Scanner s = new Scanner(System.in);

        int T = Integer.parseInt(s.nextLine());
        for(int TC = 1; TC <= T; ++TC) {
            int N = Integer.parseInt(s.nextLine());
            ArrayList<ArrayList<Point>> l = new ArrayList<>();
            for(int i = 0; i < 12; ++i)
                l.add(new ArrayList<Point>());
                List<String> months = Arrays.asList("January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December");

            while(N -- > 0) {
                String[] sp = s.nextLine().split(" ");
                l.get(months.indexOf(sp[0])).add(new Point( Integer.parseInt(sp[1]), Integer.parseInt(sp[3])));
            
            }
            int min = 0, max = 0;
            for(int i = 0; i < 12; ++i) {
                if(l.get(i).size() > 0) {
                    ArrayList<Point> arr = l.get(i);
                    arr.sort((a, b) -> (a.y - b.y));
                    TreeSet<Integer> t = new TreeSet<>();
                    TreeSet<Integer> t2 = new TreeSet<>();
                   for(Point p : arr) {
                        if(t.size() > 0 && t.last() < p.y) {
                            if(t.last() > p.x) {
                                t.add(t.last()+1);
                            } else {
                                t.add(p.x);
                            }
                            ++max;
                          
                        } else if(t.size() == 0) {
                            ++max;
                            t.add(p.x);
                        }
                        //If the dates set is empty or if the latest date from the set isnt in the current range, add the latest possible date in the current range.
                        if(t2.size() == 0 || !(t2.last() <= p.y && p.x <= t2.last())) {
                            ++min;
                            t2.add(p.y);
                        }  
                   }
                }
            }
            System.out.println("Case #"+TC+ ": " + min + " " + max);


        }
   } 
}

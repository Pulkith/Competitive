import java.awt.*;
import java.io.File;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;

public class Problem12 {
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(new File("/Users/despicablemonkey/Desktop/UILDistricts2021/src/P12.txt"));
        TreeMap<Integer, Integer> t = new TreeMap<>();
        while(s.hasNext()){
            int i = s.nextInt();
            t.put(i, t.containsKey(i) ? t.get(i)+1 : 0);
        }
        for(Map.Entry<Integer, Integer> k : t.descendingMap().entrySet()) {
            System.out.println(k.getKey() + ((k.getValue()) > 0 ? (" "+k.getValue()) : ""));
        }
        Point p = new Point();
    }
}

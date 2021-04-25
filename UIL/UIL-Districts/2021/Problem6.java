import java.util.*;
import java.awt.*;

public class Problem6 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int T = Integer.parseInt(s.nextLine());


        HashMap<String, Point> hm = new HashMap<>();
        hm.put("Charlotte", new Point(0, 1));
        hm.put("Orlando", new Point(1, 1));
        hm.put("Houston", new Point(2, 0));
        hm.put("Denver", new Point(3, -1));
        hm.put("San Diego", new Point(4, -2));

        int[][] map = {
            {0, 89, 130, Integer.MAX_VALUE, 263 },
            {89, 0, 121, Integer.MAX_VALUE,  Integer.MAX_VALUE},
            {130, 121, 0, 125, 174},
            {Integer.MAX_VALUE, Integer.MAX_VALUE, 125, 0, 119},
            {263, Integer.MAX_VALUE, 174, 119, 0},
        };
        while(T-- >  0) {
            String str = s.nextLine();
            String[] dat = str.split(" ");
            int offset = 0;
            String city = dat[0];
            if(Character.isAlphabetic(dat[1].charAt(0))) {
                city = "San Diego";
                offset = 1;
            }
            String fin = dat[dat.length - 1];
            if(dat[dat.length-1].equals("Diego")) 
                fin = "San Diego";
            
            String[] time = dat[1+offset].split(":");
            int tim = Integer.parseInt(time[0])* 60 + Integer.parseInt(time[1]);
            if(dat[2+offset].equals("P.M.") && tim != (60*12)) {
                tim += (60*12);
            } else {
                if(tim == 60*12 && dat[2+offset].equals("A.M."))
                    tim = 0;
            }

            int flight = map[hm.get(city).x][hm.get(fin).x];
            tim += flight;
            int timezone = Math.abs(hm.get(city).y - hm.get(fin).y);
            timezone *= (hm.get(city).y > hm.get(fin).y) ? -1 :1;
            
            tim += timezone*60;
            String finTime = "";
            String zone = "";

            if(tim < 0) {
                tim = (24*60) - Math.abs(tim);
            }
            if(tim == 0 || tim == (12*60)) {
                finTime = "12:00";
                zone = (tim == 0) ? "A.M." : "P.M.";
            }
            else if(tim > (24*60)) {
                tim %= (24*60);
                zone = "A.M.";
                finTime = con(tim);
            } else if(tim > (60 * 12)) {
                tim %= (12 * 60);
                zone = "P.M.";
                finTime = con(tim);
            }
            else if(tim > 0) {
                zone = "A.M.";
                finTime = con(tim);
            }
            System.out.println(city + " " + dat[1+offset] + " " + dat[2+offset]+ " " + fin + " " + finTime + " " + zone);
            
            
        }
    }
    public static String con(int tim) {
        return (tim / 60) + ":" + String.format("%02d",(tim % 60));
    }
}
/*
3
Houston 6:00 A.M. Orlando
Orlando 1:25 P.M. Charlotte
Charlotte 7:30 A.M. San Diego


*/
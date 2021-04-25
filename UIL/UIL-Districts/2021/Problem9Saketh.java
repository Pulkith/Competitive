import java.io.*;
import java.util.*;
class Problem9Saketh {
    public static void main(String args[]) throws FileNotFoundException {
        Scanner scan = new Scanner(System.in);
        int n = Integer.parseInt(scan.nextLine());
        ArrayList<Pair> p = new ArrayList<>();
        p.add(new Pair("Denver", "San Diego", "1:59"));
        p.add(new Pair("Denver", "Houston", "2:05"));
        p.add(new Pair("San Diego", "Houston", "2:54"));
        p.add(new Pair("San Diego", "Charlotte", "4:23"));
        p.add(new Pair("Charlotte", "Houston", "2:10"));
        p.add(new Pair("Charlotte", "Orlando", "1:29"));
        p.add(new Pair("Houston", "Orlando", "2:01"));
        for(int i = 0; i<n; i++){
            String[] line = scan.nextLine().split(" ");
            String city = line[0];
            int increment = 0;
            if(city.equals("San")){
                increment = 1;
                city = "San Diego";
            }
            String time = line[1 + increment];
            String time_period = line[2 + increment];
            String destination = line[3 + increment];
            if(line[line.length - 2].equals("San")){
                destination = "San Diego";
            }
            String ans = solve(city, time, time_period, destination, p);
            System.out.println(city + " " + time + " " + time_period + " " + destination + " " + ans);
        }
    }
    public static String addTimes(String time1, String time2, String time_period, int increase){
        String[] t1 = time1.split(":");
        String[] t2 = time2.split(":");
        int hours = Integer.parseInt(t1[0]) + Integer.parseInt(t2[0]);
        int minutes = Integer.parseInt(t1[1]) + Integer.parseInt(t2[1]);
        boolean period_flipped = false;
        if(minutes > 60){
            minutes = minutes - 60;
            hours++;
        }
        hours = hours + increase;
        if(hours > 12){
            period_flipped = true;
            hours = hours - 12;
        }
        if(hours < 0){
            period_flipped = true;
            hours = 12 - Math.abs(hours);
        }
        if(time_period.equals("A.M.") && period_flipped == true){
            time_period = "P.M.";
        }
        else if(time_period.equals("P.M.") && period_flipped == true){
            time_period = "A.M.";
        }
        String minute_ans = "";
        if(minutes < 10){
            minute_ans += "0";
        }
        minute_ans += Integer.toString(minutes);
        return hours + ":" + minute_ans + " " + time_period;


    }
    public static String solve(String start_city, String time, String time_period, String end, ArrayList<Pair> p){
        int increase = increment(start_city, end);
        for(int i = 0; i<p.size(); i++){
            Pair a = p.get(i);
            if((a.city1.equals(start_city) && a.city2.equals(end)) || (a.city1.equals(end) && a.city2.equals(start_city))){
                String t = a.time;
                String added = addTimes(time,t, time_period, increase);
                return added;
            }
        }
        return "";
    }
    public static int increment(String start, String end){
        int time1 = 0;
        int time2 = 0;
        if(start.equals("Charlotte") || start.equals("Orlando")){
            time1 = 4;
        }
        if(start.equals("Houston")){
            time1 = 3;
        }
        if(start.equals("Denver")){
            time1 = 2;
        }
        if(start.equals("San Diego")){
            time1 = 1;
        }

        if(end.equals("Charlotte") || end.equals("Orlando")){
            time2 = 4;
        }
        if(end.equals("Houston")){
            time2 = 3;
        }
        if(end.equals("Denver")){
            time2 = 2;
        }
        if(end.equals("San Diego")){
            time2 = 1;
        }
        return time2 - time1;
    }
    static class Pair{
        String city1;
        String city2;
        String time;
        public Pair(String s1, String s2, String time){
            city1 = s1;
            city2 = s2;
            this.time = time;
        }
    }
}
import java.util.*;
import java.io.*;
public class Problem10 {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 0; t < T; t++) {
            double lat1 = in.nextDouble(), lon1 = in.nextDouble(), lat2 = in.nextDouble(), lon2 = in.nextDouble();
            double theta_lon = lon2 - lon1;
            double theta_lat = lat2 - lat1;
            double a = Math.pow(Math.sin(Math.toRadians(theta_lat/2)), 2) + Math.cos(Math.toRadians(lat1)) * Math.cos(Math.toRadians(lat2)) * Math.pow(Math.sin(Math.toRadians(theta_lon/2)), 2);
            double c  = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a));
            double d = c * 6371000;
            System.out.printf("The distance between (%.5f, %.5f) and (%.5f, %.5f) is %d meters.%n", lat1, lon1, lat2, lon2, (int)Math.round(d));
        }
    }

}
/*


4
31.37646 -100.44892 31.36184 -100.43369
30.28017 -97.73871 30.27521 -97.74011
30.28642 -97.73645 30.28771 -97.73333
30.26557 -97.74465 29.76694 -95.37830

 */
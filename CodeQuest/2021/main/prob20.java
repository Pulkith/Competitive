import java.io.*;
import java.util.*;
import java.text.*;
public class prob20 {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for(int i = 0; i<t; i++){
            double x = scan.nextDouble();
            double y = scan.nextDouble();
            double h = scan.nextDouble();
            int n = scan.nextInt();
            for(int j = 0; j<n; j++){
                if(x == 0){
                    y = y + h * 1;
                }
                else {
                    y = y + h * (Math.sin(x) / x);
                }
                x+=h;
            }
            DecimalFormat df = new DecimalFormat("#.###");
            System.out.println(df.format(y));
        }
    }
}
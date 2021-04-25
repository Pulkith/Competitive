import java.util.*;

public class G {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        while(s.hasNext()) {
            double house = s.nextDouble(), dp=s.nextDouble(), APR=s.nextDouble(), num=s.nextDouble();
                double result = (house - dp) * ((APR/12) * Math.pow((1+(APR/12)),num)) / (Math.pow((1+(APR/12)), num)-1);
                result *= 1000;
                result = (int)result;
                result /= 1000;
                result = Math.ceil(result);
                System.out.println("$" + (long)result);
        
        }
    }
}

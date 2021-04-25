import java.util.Scanner;

public class Problem9 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = Integer.parseInt(s.nextLine());

        while(T-- > 0) {
            int product = 1;
            int i = Integer.parseInt(s.nextLine());
            System.out.print(i + " -> ");
            while(i > 9) {
                product = 1;
                while(i > 0) {
                    product *= (i%10 == 0) ? 1 : i%10;
                    i /= 10;
                }
                i = product;
            }
            System.out.println(i);

        }
    }
}

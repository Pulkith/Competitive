import java.util.*;

public class dryrun {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int sum = 0;
		while(N -- > 0) {
			int x = scan.nextInt();
			sum += x;
		}
		System.out.println(sum);
	}
}
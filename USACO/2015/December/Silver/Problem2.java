import java.io.*;
import java.util.*;
public class Problem2 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("highcard.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("highcard.out")));
		int n = Integer.parseInt(br.readLine());
		boolean[] elsieOwns = new boolean[2*n+1];
		for(int i = 0; i < n; i++) {
			elsieOwns[Integer.parseInt(br.readLine())] = true;
		}
		ArrayList<Integer> bessie = new ArrayList<Integer>();
		ArrayList<Integer> elsie = new ArrayList<Integer>();
		int points = 0;
		// because we loop over the values in increasing order, the two lists will be in sorted order
		for(int i = 1; i <= 2*n; i++) {
			if(elsieOwns[i]) {
				elsie.add(i);
			}
			else {
				bessie.add(i);
			}
		}
		int bessieIndex = 0;
		int elsieIndex = 0;
		while(bessieIndex < n && elsieIndex < n) {
			if(bessie.get(bessieIndex) > elsie.get(elsieIndex)) {
				points++;
				bessieIndex++;
				elsieIndex++;
			}
			else {
				bessieIndex++;
			}
		}
		pw.println(points);
		pw.close();
	}
}
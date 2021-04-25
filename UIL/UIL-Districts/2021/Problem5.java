import java.io.*;
import java.util.*;
public class Problem5 {
    public static void main(String args[]) throws IOException {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        for(int k =0 ; k<n; k++){
            String[][] arr = new String[5][5];
            for(int i = 0; i<5; i++) {
                String line = scan.next();
                for (int j = 0; j < line.length(); j++) {
                    String sub = line.substring(j, j + 1);
                    arr[i][j] = sub;
                }
            }
            String dashes = scan.next();
            boolean valid = valid(arr);
            System.out.println(valid ? "valid": "invalid");
        }
    }
    public static boolean valid(String[][] arr){
        int count = 0;
        for(int i = 0; i<5; i++){
            for(int j = 0; j<5; j++){

                if(arr[i][j].equals(".")){continue;}
                ++count;
                if(j>1 && i>1){
                    if(arr[i-2][j-2].equals("a")){
                        return false;
                    }
                }
                if(j>1 && i<3){
                    if(arr[i+2][j-2].equals("a")){
                        return false;
                    }
                }
                if(j<3 && i>1){
                    if(arr[i-2][j+2].equals("a")){
                        return false;
                    }
                }
                if(j<3 && i<3){
                    if(arr[i+2][j+2].equals("a")){
                        return false;
                    }
                }
            }
        }
        if(count != 9)
            return false;
        return true;
    }
}



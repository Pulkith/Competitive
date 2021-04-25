import java.util.*;

public class F {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        while(s.hasNext()) {
            String str = s.nextLine();
            String[] arg = str.split(": ");
            int seed = 97;
            String name = arg[0];
            for(int i  = 0; i < name.length(); ++i)
                seed ^= (name.charAt(i));
            
           String msg = arg[1];
           String result = "";
           for(int i= 0; i < msg.length(); ++i)
                result += String.format("%8s", Integer.toBinaryString(msg.charAt(i))).replace(" ", "0");
            if(result.length() > 5){
                String tmp = result.substring(result.length()-5);
                result = tmp + result.substring(0, result.length()-5);
            }
            System.out.print(name+": ");
            String res = "";
            for(int i = 0; i < result.length(); i+=8) {
                String byt = result.substring(i, i+8);
                int val = Integer.parseInt(byt, 2) ^ seed;
                res += String.format("0x%02X ", val);
            }
            System.out.println(res.trim());
        }
    }
}

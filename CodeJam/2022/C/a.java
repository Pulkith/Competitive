import java.util.*;


class n {
  n next;
  String value;
}

public class a {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int T = scan.nextInt();
    while(T-- > 0) {
      int N = scan.nextInt();
      String[] words = new String[N];
      for(int i = 0; i < N; ++i) words[i]  = scan.next();

      boolean ok = true;

      for(int l = 0; l < 26; ++l) {
        for(int i = 0; i < N; ++i) {
          int cnt =0 ;
          boolean hit = false;
          for(int j = 0; j < words[i].length(); ++j) {
            if(words[i].charAt(j) == (l + 'A')) {
              if(!hit) {
                hit = true;
                ++cnt;
              } else hit = false;
            }
          }
          if(cnt > 1) ok = false;
        }
      }
      if(ok = false) {
        System.out.println("IMPOSSIBLE");
        continue;
      }

      n head = new n();
      head.value = words[0];

      for(int i = 1; i < N; ++i) {
        n p = head;
        while(p != null) {
          if(p.value.charAt(p.value.length() - 1) == words[i].charAt(0) && (p.next == null || p.next.value.charAt(0) != words[i].charAt(0))) {
            n v = new n();
            v.value = words[i];
            v.next = p.next;
            p.next = v;
          }
          else if(p.value.charAt(0) == words[i].charAt(words[i].length() - 1)) {
            n v = new n();
            v.next = p.next;
            p.next = v;
            v.value = p.value;
            p.value = words[i];
          }
          p = p.next;
        }
      }

      String res = "";
      while(head != null) {
        res += head.value;
        head = head.next;
      }
      if(res.charAt(0) == res.charAt(res.length() - 1)) System.out.println("IMPOSSIBLE");
      else System.out.System.out.print(res);

    }
  }
}
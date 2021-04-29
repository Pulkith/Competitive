import java.util.*;
import java.io.*;
import java.awt.*;


public class Problem1 {
  public static void main(String[] args) throws Exception {
    //Scanner s = new Scanner(new File("tttt.in"));
    Scanner s = new Scanner(System.in);
    //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("tttt.out")));
    PrintWriter out = new PrintWriter(System.out);

    char[][] c = new char[3][3];
    HashSet<Character> ind = new HashSet<>();
    HashSet<String> team = new HashSet<>();
    for(int i = 0; i < 3; ++i) {
        String str = s.nextLine();
        for(int j = 0; j < 3; ++j)
            c[i][j] = str.toCharArray()[j];
    }

    for(int i = 0; i < 3; ++i) {
        HashSet<Character> t = new HashSet<>();
        for(int j = 0; j < 3; ++j) {
            t.add(c[i][j]);
        }
        Iterator iter = t.iterator();
        if(t.size() == 1)
            ind.add((Character)iter.next());
        else if(t.size() == 2){
            char a = (Character)iter.next(), b = (Character)iter.next();
            team.add(Math.min(a, b) + ""+Math.max(a, b));
        }
            
    }
    for(int i = 0; i < 3; ++i) {
        HashSet<Character> t = new HashSet<>();
        for(int j = 0; j < 3; ++j) {
            t.add(c[j][i]);
        }
        Iterator iter = t.iterator();
        if(t.size() == 1)
            ind.add((Character)iter.next());
        else if(t.size() == 2){
            char a = (Character)iter.next(), b = (Character)iter.next();
            team.add(Math.min(a, b) + ""+Math.max(a, b));
        }
    }

    HashSet<Character> t = new HashSet<>();
    t.add(c[0][0]); 
    t.add(c[1][1]); 
    t.add(c[2][2]); 
    Iterator iter = t.iterator();
    if(t.size() == 1)
        ind.add((Character)iter.next());
    else if(t.size() ==2){
        char a = (Character)iter.next(), b = (Character)iter.next();
        team.add(Math.min(a, b) + ""+Math.max(a, b));
    }

    t.clear();
    t.add(c[0][2]); 
    t.add(c[1][1]); 
    t.add(c[2][0]); 
    iter = t.iterator();
    if(t.size() == 1)
        ind.add((Character)iter.next());
    else if(t.size() ==2){
        char a = (Character)iter.next(), b = (Character)iter.next();
        team.add(Math.min(a, b) + ""+Math.max(a, b));
    }

    out.println(ind.size());
    out.println(team.size());

    out.close();
  }  
}

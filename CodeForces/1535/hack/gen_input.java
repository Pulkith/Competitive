import java.util.*;

public class gen_input {
    public static void main(String[] args) {
        System.out.print("1\n");
        System.out.print("200000 1 1000000000\n");
        int total = 200000;

        Random gen = new Random(500344944);

        for(int i = 0; i < total; ++i)
            System.out.print("" + ((int)(gen.nextDouble() * 1000000000) + 1) + (i == total - 1 ? '\n' : " "));
    }
}
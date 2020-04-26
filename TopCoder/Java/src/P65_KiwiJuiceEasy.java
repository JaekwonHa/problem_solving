import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Scanner;

public class P65_KiwiJuiceEasy {

    public static void main(String[] args) {

        try(InputStream in = new FileInputStream("res/P65_KiwiJuiceEasy.txt")) {

            Scanner scanner = new Scanner(in);

            int N = scanner.nextInt();
            int[] capacities = new int[N];
            int[] bottles = new int[N];

            for(int i=0; i<N; i++) capacities[i] = scanner.nextInt();
            for(int i=0; i<N; i++) bottles[i] = scanner.nextInt();


            int M = scanner.nextInt();
            int[] fromId = new int[M];
            int[] toId = new int[M];

            for(int i=0; i<M; i++) fromId[i]=scanner.nextInt();
            for(int i=0; i<M; i++) toId[i]=scanner.nextInt();

            for(int i=0; i<M; i++) {
                int f = fromId[i];
                int t = toId[i];
                int sum = bottles[f] + bottles[t];

                bottles[t] = Math.min(capacities[t], sum);
                bottles[f] = sum - bottles[t];
            }

            for(int i=0; i<N; i++) System.out.print(bottles[i]+" ");

        } catch (Exception e) {
            e.printStackTrace();
        }


    }
}

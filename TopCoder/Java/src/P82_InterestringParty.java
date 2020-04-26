import java.io.FileInputStream;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Created by jaekwonha on 2018. 1. 3..
 */
public class P82_InterestringParty {

    public static void main(String[] argv) {
        try(InputStream in = new FileInputStream("res/P82_InterestingParty.txt")) {
            Scanner scanner = new Scanner(in);

            int N;
            HashMap<String, Integer> m = new HashMap<>();

            N = scanner.nextInt();
            scanner.nextLine();
            String[] str = scanner.nextLine().split(" ");
            for(String s : str) {
                if(!m.containsKey(s))
                    m.put(s, 1);
                else
                    m.put(s, m.get(s)+1);
            }
            str = scanner.nextLine().split(" ");
            for(String s : str) {
                if(!m.containsKey(s))
                    m.put(s, 1);
                else
                    m.put(s, m.get(s)+1);
            }
            int answer = m.entrySet().stream()
                            .map(p -> p.getValue())
                            .max((p1,p2) -> Integer.compare(p1, p2))
                            .get();

            System.out.println(answer);


        } catch(Exception e) {
            e.printStackTrace();
        }
    }


}

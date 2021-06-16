package codewars;

public class FindSquares {

    public static String findSquares(int n){
        long start = (long) Math.sqrt(n);
        long end = (long) Math.pow(n, 2);
        for (long i = start; i <= end; i++) {
            if (i*i - (i-1)*(i-1) == n) {
                return i*i + "-" + (i-1)*(i-1);
            }
        }
        return "no-answer";
    }
}

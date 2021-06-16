package codewars;

public class DecimalToFactorialAndBack {

    private static final String mapping = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    public static String dec2FactString(long nb) {
        StringBuilder answer = new StringBuilder("0");
        for (int i=2; i<37; i++) {
            if (nb <= 0) {
                break;
            }
            answer.append(mapping.charAt((int)(nb % i)));
            nb = nb / i;
        }
        return answer.reverse().toString();
    }

    public static long factString2Dec(String str) {
        long answer = 0;
        long fac = 1;
        for (int i=1, j=str.length()-2; j>=0; i++, j--) {
            fac *= i;
            answer += fac * mapping.indexOf(str.charAt(j));
        }
        return answer;
    }
}

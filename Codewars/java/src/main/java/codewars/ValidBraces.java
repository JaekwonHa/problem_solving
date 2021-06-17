package codewars;

import java.util.Map;
import java.util.Stack;

public class ValidBraces {

    public static boolean isValid(String str) {
        Map<Character, Character> braces = Map.of(
                '{', '}',
                '[', ']',
                '(', ')'
        );

        Stack<Character> stack = new Stack<>();

        for (char s : str.toCharArray()) {
            if (braces.containsKey(s)) {
                stack.push(s);
            } else if (stack.size() == 0 || s != braces.get(stack.pop())) {
                return false;
            }
        }
        return stack.size() == 0;
    }
}

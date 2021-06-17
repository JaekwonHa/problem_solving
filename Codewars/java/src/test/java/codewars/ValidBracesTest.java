package codewars;

import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

import static org.junit.jupiter.api.Assertions.*;

class ValidBracesTest {

    @ParameterizedTest
    @MethodSource("source_solution")
    void solution(String str, boolean answer) {
        assertEquals(answer, ValidBraces.isValid(str));
    }

    static Stream<Arguments> source_solution() {
        return Stream.of(
                Arguments.of("(){}[]", true),
                Arguments.of("[({})](]", false)
        );
    }
}

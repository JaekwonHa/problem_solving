package codewars;

import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

import static org.junit.jupiter.api.Assertions.*;

class FindSquaresTest {

    @ParameterizedTest
    @MethodSource("source_solution")
    void solution(int n, String answer) {
        assertEquals(answer, FindSquares.findSquares(n));
    }

    static Stream<Arguments> source_solution() {
        return Stream.of(
                Arguments.of(9, "25-16"),
                Arguments.of(5, "9-4"),
                Arguments.of(7, "16-9"),
                Arguments.of(1, "1-0"),
                Arguments.of(1887, "891136-889249"),
                Arguments.of(99991, "2499600016-2499500025")
        );
    }
}

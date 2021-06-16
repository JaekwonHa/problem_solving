package codewars;

import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

import static org.junit.jupiter.api.Assertions.*;

class DecimalToFactorialAndBackTest {

    @ParameterizedTest
    @MethodSource("source_dec2FactString")
    void dec2FactString(Long nb, String answer) {
        assertEquals(DecimalToFactorialAndBack.dec2FactString(nb), answer);
    }

    @ParameterizedTest
    @MethodSource("source_factString2Dec")
    void factString2Dec(String nb, Long answer) {
        assertEquals(DecimalToFactorialAndBack.factString2Dec(nb), answer);
    }


    static Stream<Arguments> source_dec2FactString() {
        return Stream.of(
                Arguments.of(463L, "341010"),
                Arguments.of(2982L, "4041000")
        );
    }

    static Stream<Arguments> source_factString2Dec() {
        return Stream.of(
                Arguments.of("341010", 463L),
                Arguments.of("4041000", 2982L)
        );
    }
}

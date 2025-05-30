package tests;

import java.util.Arrays;
import solutions.Solution;

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();

        class TestCase {
            int n;
            int[][] flights;
            int src, dst, k, expected;

            TestCase(int n, int[][] flights, int src, int dst, int k, int expected) {
                this.n = n;
                this.flights = flights;
                this.src = src;
                this.dst = dst;
                this.k = k;
                this.expected = expected;
            }
        }

        TestCase[] tests = {
                new TestCase(4,
                        new int[][] { { 0, 1, 100 }, { 1, 2, 100 }, { 2, 0, 100 }, { 1, 3, 600 }, { 2, 3, 200 } }, 0, 3,
                        1, 700),
                new TestCase(3, new int[][] { { 0, 1, 100 }, { 1, 2, 100 }, { 0, 2, 500 } }, 0, 2, 1, 200),
                new TestCase(3, new int[][] { { 0, 1, 100 }, { 1, 2, 100 }, { 0, 2, 500 } }, 0, 2, 0, 500),
                new TestCase(2, new int[][] {}, 0, 1, 1, -1)
        };

        boolean failed = false;

        for (int i = 0; i < tests.length; i++) {
            int res = sol.findCheapestPrice(tests[i].n, tests[i].flights, tests[i].src, tests[i].dst, tests[i].k);
            System.out.print("Test Case " + (i + 1) + ": ");
            if (res == tests[i].expected) {
                System.out.println("PASSED ✅ (Output: " + res + ")");
            } else {
                System.out.println("FAILED ❌ (Output: " + res + ", Expected: " + tests[i].expected + ")");
                failed = true;
            }
        }

        if (failed) {
            System.exit(1);
        } else {
            System.exit(0);
        }
    }
}

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
                new TestCase(5,
                        new int[][] { { 0, 1, 100 }, { 1, 2, 100 }, { 2, 3, 100 }, { 3, 4, 100 }, { 0, 4, 1000 } },
                        0, 4, 3, 400), // Path: 0→1→2→3→4 (3 stops, total cost 400)

                new TestCase(4,
                        new int[][] { { 0, 1, 100 }, { 1, 2, 100 }, { 2, 3, 100 }, { 0, 3, 500 } },
                        0, 3, 1, 500), // Path: 0→3 (0 stop)

                new TestCase(4,
                        new int[][] { { 0, 1, 300 }, { 1, 2, 300 }, { 2, 3, 300 }, { 0, 2, 1000 }, { 0, 3, 2000 } },
                        0, 3, 2, 900), // Path: 0→1→2→3 (2 stops)

                new TestCase(5,
                        new int[][] { { 0, 1, 50 }, { 1, 2, 50 }, { 2, 3, 50 }, { 3, 4, 50 }, { 0, 4, 1000 } },
                        0, 4, 1, 1000), // Cannot reach in 1 stop, must take direct flight

                new TestCase(3,
                        new int[][] { { 0, 1, 100 }, { 1, 0, 100 }, { 1, 2, 300 } },
                        0, 2, 10, 400), // Cycle 0→1→0→1→2 allowed due to high k, but optimal is 0→1→2

                new TestCase(6,
                        new int[][] { { 0, 1, 10 }, { 1, 2, 10 }, { 2, 3, 10 }, { 3, 4, 10 }, { 4, 5, 10 },
                                { 0, 5, 1000 } },
                        0, 5, 4, 50), // 0→1→2→3→4→5 (4 stops, total cost 50)

                new TestCase(3,
                        new int[][] { { 0, 1, 100 }, { 1, 2, 100 } },
                        0, 2, 0, -1), // Not reachable in 0 stops

                new TestCase(3,
                        new int[][] { { 0, 1, 100 }, { 1, 2, 100 }, { 0, 2, 600 } },
                        0, 2, 2, 200), // Cheaper through 1→2

                new TestCase(4,
                        new int[][] { { 0, 1, 1 }, { 1, 2, 1 }, { 2, 3, 1 }, { 0, 3, 100 } },
                        0, 3, 2, 3), // Path with stops is cheaper

                new TestCase(3,
                        new int[][] {},
                        0, 2, 1, -1) // No flights at all

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

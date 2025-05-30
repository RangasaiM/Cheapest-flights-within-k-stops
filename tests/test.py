
import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from solutions.solution import Solution

def run_test(n, flights, src, dst, k, expected, test_num):
    sol = Solution()
    result = sol.findCheapestPrice(n, flights, src, dst, k)
    print(f"Test Case {test_num}: ", end="")
    if result == expected:
        print(f"PASSED [OK] (Output: {result})")
        return False
    else:
        print(f"FAILED [Failed] (Output: {result}, Expected: {expected})")
        return True

if __name__ == "__main__":
    test_cases = [
        (4, [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], 0, 3, 1, 700),
        (3, [[0,1,100],[1,2,100],[0,2,500]], 0, 2, 1, 200),
        (3, [[0,1,100],[1,2,100],[0,2,500]], 0, 2, 0, 500),
        (2, [], 0, 1, 1, -1),  # no flights at all
    ]

    failed = False
    for i, (n, flights, src, dst, k, expected) in enumerate(test_cases, 1):
        if run_test(n, flights, src, dst, k, expected, i):
            failed = True

    if failed:
        print("\n[Failed] Some test cases failed.")
        sys.exit(1)
    else:
        print("\n[OK] All test cases passed.")
        sys.exit(0)

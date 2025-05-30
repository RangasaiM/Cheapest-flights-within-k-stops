
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
    (5, [[0,1,100],[1,2,100],[2,3,100],[3,4,100],[0,4,1000]], 0, 4, 3, 400),
    (4, [[0,1,100],[1,2,100],[2,3,100],[0,3,500]], 0, 3, 1, 500),
    (4, [[0,1,300],[1,2,300],[2,3,300],[0,2,1000],[0,3,2000]], 0, 3, 2, 900),
    (5, [[0,1,50],[1,2,50],[2,3,50],[3,4,50],[0,4,1000]], 0, 4, 1, 1000),
    (3, [[0,1,100],[1,0,100],[1,2,300]], 0, 2, 10, 400),
    (6, [[0,1,10],[1,2,10],[2,3,10],[3,4,10],[4,5,10],[0,5,1000]], 0, 5, 4, 50),
    (3, [[0,1,100],[1,2,100]], 0, 2, 0, -1),
    (3, [[0,1,100],[1,2,100],[0,2,600]], 0, 2, 2, 200),
    (4, [[0,1,1],[1,2,1],[2,3,1],[0,3,100]], 0, 3, 2, 3),
    (3, [], 0, 2, 1, -1)
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

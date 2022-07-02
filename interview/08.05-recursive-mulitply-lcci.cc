class Solution {
    int do_multiply(int A, int B) {
        if (B == 1) return A;

        int y = do_multiply(A, B/2);
        return B % 2 ? (y << 1) + A : y << 1;
    }

public:
    int multiply(int A, int B) {
        return A < B ? do_multiply(B, A) : do_multiply(A, B);
    }
};
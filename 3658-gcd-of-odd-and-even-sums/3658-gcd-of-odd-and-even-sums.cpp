class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        //Sum of first n odd numbers = n²
        //Sum of first n even numbers = n² + n

        // gcd(n², (n²+n)) = n * gcd(n, n+1)
        // Since consecutive numbers are always coprime => gcd(n, n+1) = 1

        // Therefore, gcd(n², (n²+n)) = n

        //T.C. = O(1) = S.C.
        return n;
    }
};
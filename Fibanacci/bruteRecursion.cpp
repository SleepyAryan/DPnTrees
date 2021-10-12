class Solution {
public:

    int fib(int n) {
        if(n <= 1) return n;
        n=fib(n-1)+fib(n-2);
        return n;
    }
}
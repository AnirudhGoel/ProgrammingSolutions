class Solution {
public:
    long long int A[20001], E[20001], I[20001], O[20001], U[20001];
    
    int countVowelPermutation(int n) {
        for(int i=0; i<=n; i++) {
            A[i] = -1;
            E[i] = -1;
            I[i] = -1;
            O[i] = -1;
            U[i] = -1;
        }
        
        return (a(n) + e(n) + i(n) + o(n) + u(n)) % 1000000007;
    }
    
    long long int a(int n) {
        if(n == 1) return 1;
        
        if(A[n] != -1) return A[n];
        else A[n] = e(n-1) % 1000000007;
        
        return A[n];
    }
    
    long long int e(int n) {
        if(n == 1) return 1;
        
        if(E[n] != -1) return E[n];
        else E[n] = (a(n-1) + i(n-1)) % 1000000007;
        
        return E[n];
    }
    
    long long int i(int n) {
        if(n == 1) return 1;
        
        if(I[n] != -1) return I[n];
        else I[n] = (a(n-1) + e(n-1) + o(n-1) + u(n-1)) % 1000000007;
        
        return I[n];
    }
    
    long long int o(int n) {
        if(n == 1) return 1;
        
        if(O[n] != -1) return O[n];
        else O[n] = (i(n-1) + u(n-1)) % 1000000007;
        
        return O[n];
    }
    
    long long int u(int n) {
        if(n == 1) return 1;
        
        if(U[n] != -1) return U[n];
        else U[n] = a(n-1) % 1000000007;
        
        return U[n];
    }
};
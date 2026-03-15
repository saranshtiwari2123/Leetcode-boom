class Fancy {
public:
    long long mod = 1000000007;
    vector<long long> seq;
    long long mul = 1;
    long long add = 0;

    Fancy() {
        
    }

    long long modInverse(long long x) {
        long long res = 1, p = mod - 2;
        while (p) {
            if (p & 1) res = (res * x) % mod;
            x = (x * x) % mod;
            p >>= 1;
        }
        return res;
    }

    void append(int val) {
        long long v = ((val - add + mod) % mod) * modInverse(mul) % mod;
        seq.push_back(v);
    }

    void addAll(int inc) {
        add = (add + inc) % mod;
    }

    void multAll(int m) {
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }

    int getIndex(int idx) {
        if (idx >= seq.size()) return -1;
        return (seq[idx] * mul % mod + add) % mod;
    }
};
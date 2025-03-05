const int MAX_VAL = 28123;
        set<int> st;

        auto abundant = [&](int n) {
            int ans = 1;
            for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    ans += i;
                    ans += (n/i != i) ? n/i : 0;
                }
            }
            return ans > n;
        };

        for (int i = 12; i <= MAX_VAL; i++) {
            if (abundant(i)) 
                st.insert(i);
        }

        int ans = 0;
        for (int i = 1; i <= MAX_VAL; i++) {
            bool found = false;
            for (int j = 1; j < i; j++) {
                if (st.find(j) != st.end() && st.find(i - j) != st.end()) {
                    found = true;
                    break;
                }
            }
            if (!found) ans += i;
        }

        cout<<ans<<endl;

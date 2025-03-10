#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream file("name.txt");
    set<string> st;
    std::string line;
    
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        string name;
        while (std::getline(ss, name, ',')) {
            name = name.substr(1, name.size() - 2);
            st.insert(name);
        }
    }

    file.close();
    
    int i = 1;
    long ans = 0;
    
    
    for (auto &x: st) {
        int cur = 0;
        for (auto &y: x) {
            cur += (y - 'A' + 1);
        }
        ans += (1ll * i++ * cur);
    }
    
    cout<<ans<<endl;
    return 0;
}

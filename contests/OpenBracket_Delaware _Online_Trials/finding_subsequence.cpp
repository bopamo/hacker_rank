#include <bits/stdc++.h>

using namespace std;

string get_sub(const string& str, int k) {

    string s = str;

    sort(s.begin(),s.end());

    stack<char> s_stack;

    for(const auto& i : s) {
        s_stack.push(i);
    }

    unordered_multimap<char,int> m;

    for(int i = 0; i < str.size(); ++i) {
        m.insert( make_pair(str[i], i));
    }

    string sub_str;

    int pos = -1;

    while(!s_stack.empty()) {
        char c = s_stack.top();
        s_stack.pop();

        auto range = m.equal_range(c);

        auto min_range = range.second;
        int min_pos = static_cast<int>(str.size());

        for(auto& it = range.first; it != range.second; ++it) {

            if( it->second < min_pos) {
                min_range = it;
                min_pos = it->second;
            }
        }

        m.erase(min_range);

        if( min_pos > pos ) {
            sub_str += c;
            pos = min_pos;
        }
    }

    return sub_str;
}


string s_strip(string s, int k) {

    unordered_map<char, int> m;

    for(const auto& i : s) {
        m[i]++;
    }


    string s_adj;
    for(const auto& i : s) {

        auto got = m.find (i);

        if( got->second >= k) s_adj += got->first;
    }
    
    return s_adj;
}


string solve(string s, int k) {
    // Complete this function

    s = s_strip(s, k);

    auto max_pos = max_element(s.begin(), s.end());

    string shrunk;

    shrunk.assign(max_pos, s.end());

    s = shrunk;

    string s_sorted = s;

    string t = get_sub(s, k);


    unordered_map<char, int> mm;

    for(const auto& i : t) {
        mm[i]++;
    }

    string tt;

    for(const auto& i : t) {

        auto got = mm.find (i);
        
        if( got->second >= k) tt += got->first;
    }
    
    return tt;
}


int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    string result = solve(s, k);
    cout << result << endl;
    return 0;
}

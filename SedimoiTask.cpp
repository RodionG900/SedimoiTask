#include <iostream>
#include <vector>
#include <list>

using namespace std;

list<pair<int, int>> operator *(list<pair<int, int>> a, int k) {
    list<pair<int, int>> s;
    for (auto t = a.begin(); t != a.end(); t++) {

        s.push_back(make_pair(t->first, k*t->second));
    }
    return s;
}

list<pair<int, int>> operator *(list<pair<int, int>> t1, pair<int, int> t2) {
    list<pair<int, int>> s;
    for (auto t = t1.begin(); t != t1.end(); t++) {
        pair<int, int> r(0, 0);
        r.first = t->first + t2.first;
        r.second = t->second * t2.second;
        s.push_back(r);
    }
    return s;
}

list<pair<int, int>> operator +(list<pair<int, int>>t, list<pair<int, int>> a) {
    list<pair<int, int>> s;
    list<pair<int, int>>::iterator t1 = t.begin();
    list<pair<int, int>>::iterator a1 = a.begin();
    while (t1 != t.end() && a1 != a.end()) {
        if (t1->first == a1->first) {
            
            s.push_back(make_pair(t1->first, t1->second + a1->second));
            t1++; a1++;
        }
        else if (t1->first > a1->first) {
            s.push_back(*t1);
            t1++;
        }
        else {
            s.push_back(*a1);
            a1++;
        }
    }
    while (t1 != t.end()) {
        s.push_back(*t1);
        t1++;
    }
    while (a1 != a.end()) {
        s.push_back(*a1);
        a1++;
    }
    return s;
}

int main()
{
    vector<list<pair<int, int>>> V;
    pair<int, int> t0(0, 1);
    pair<int, int> t1(1, 2);
    list<pair<int, int>> T0 = { t0 };
    list<pair<int, int>> T1 = { t1 };
    V.push_back(T0);
    V.push_back(T1);
    V.at(1) = T1;

    int n = 11;

    for (int i = 2; i < n; i++) {
        V.push_back(((V[i - 1] * make_pair(1, 2)) + (V[i - 2] * (-1))));
    }



    for (vector<list<pair<int, int>>>::iterator w = V.begin(); w != V.end(); w++) {
        int m = w->size();
        auto t = w->begin();
        if (m == 1) {
            if (t->first == 0) cout << 1;
            else cout << "1x^1";
        }
        else {
            cout << t->second << "x^" << t->first;
            t++;
            for (int i = 1; i < m - 1; i++) {
                if (t->second > 0)cout << "+" << t->second << "x^" << t->first;
                else cout << "" << t->second << "x^" << t->first;
                t++;
            }
            if (t->first == 0) {
                if (t->second > 0) cout << "+" << t->second;
                else cout << "" << t->second;
            }

            else {
                if(t->second > 0) cout << "+" << t->second << "x^" << t->first;
                else cout << "" << t->second << "x^" << t->first;
            }
        }

        cout << endl;
    }

}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Tekst {
private:
    string tekst;
public:
    Tekst(const char _op[]) : tekst(_op) {};
    Tekst() {};
    friend Tekst operator *(Tekst t,int d) {
        Tekst pom;
        pom.tekst = t.tekst;
        for (int i = 0; i < d - 1; i++) {
           pom.tekst+=t.tekst;
        }
        return pom;
    };
    friend Tekst operator *(int d, Tekst t) {
        string pom;
        pom = t.tekst;
        for (int i = 0; i < d-1; i++) {
            cout << pom;
        }
        return t;
    }
    friend ostream& operator <<(ostream& os, Tekst _p) {
        os << _p.tekst;
        return os;
    };
    friend Tekst operator +(Tekst t,Tekst p) {
        Tekst pom;
        pom.tekst = t.tekst + p.tekst;
        return pom;
    }
    friend Tekst operator -(Tekst t, char a) {
        Tekst pom;
        for (int i = 0; i <= t.tekst.size(); i++) {
            if (t.tekst[i] != a) {
                pom.tekst.push_back(t.tekst[i]);
            }
        }
        return pom;
    }
};

int main()
{
    Tekst t = "abc";
    Tekst p = t * 3;                // "umnozavanje" teksta
    cout << p << endl;                // ispisuje abcabcabc
    cout << 2 * t << endl;            // ispisuje abcabc

    // t mora ostati nepromijenjen!!!
    cout << t << endl;                // ispisuje abc

    cout << t + p << endl;            // ispisuje abcabcabcabc
    cout << t + p - 'a' << endl;    // ispisuje bcbcbcbc

    // p i t moraju ostati nepromijenjeni!!!
    cout << p << endl;                // ispisuje abcabcabc
    cout << t << endl;                // ispisuje abc
    return 0;
}
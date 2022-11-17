#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>


using namespace std;
class Zaposlenik {
public:
    string ime;
    string prezime;
    Zaposlenik(string _ime, string _prezime) : ime(_ime), prezime(_prezime) {
        cout << "Zaposlenik constructor called" << endl;
    }
    ~Zaposlenik() {
        cout << "Zaposlenik destructor called" << endl;
    }
    Zaposlenik() {}
};

class Firma {
private:
    string naziv;
    int oib;
    string adresa;
    vector<Zaposlenik> Z;
public:
    void setNaziv(string _naziv) {
        if (_naziv.length() < 4) {
            cout << "naziv je manji od 5 slova" << endl;
        }
        else {
            naziv = _naziv;
        }
    }
    int count_digit(int number) {
        return int(log10(number) + 1);
    }
    void setOib(int _oib) {
        if (count_digit(_oib)<11 || count_digit(_oib) >11) {
            cout << "oib ima manje od 11 znamenaka" << endl;
        }
        else {
            oib = _oib;
        }
    }
    void setAdresa(string _adresa) {
        adresa = _adresa;
    }
    void dodajZaposlenika1(Zaposlenik z){
        Z.push_back(z);
    }
    void dodajZaposlenika2(Zaposlenik& z){
        Zaposlenik* i;
        i = &z;
        Z.push_back(*i);
    }
    void dodajZaposlenika3(Zaposlenik* z){
        Z.push_back(*z);
    }
    void ispisSvihZaposlenika(vector<Zaposlenik>_Z){
        for (int i = 0; i < _Z.size(); i++) {
            cout << "Zaposlenik" << i << " " << _Z.at(i).ime << endl;
            cout << "Zaposlenik" << i << " " << _Z.at(i).prezime << endl;
        }
    }
    Zaposlenik nadjiZaposlenika1(string _ime, string _prezime,vector<Zaposlenik> z);
    Zaposlenik* nadjiZaposlenika2(string _ime, string _prezime, Zaposlenik* z);
    Zaposlenik& nadjiZaposelnika3(string _ime, string _prezime, Zaposlenik& z);
};

Zaposlenik Firma::nadjiZaposlenika1(string _ime, string _prezime, vector<Zaposlenik> z){
    Zaposlenik k;
    k.ime = _ime;
    k.prezime = _prezime;
    z[0] = k;
    return k;
}
Zaposlenik* Firma::nadjiZaposlenika2(string _ime, string _prezime, Zaposlenik* z) {
    z[1].ime = _ime;
    z[1].prezime = _prezime;
    return z;
}

Zaposlenik& Firma::nadjiZaposelnika3(string _ime, string _prezime, Zaposlenik& z) {
    z.ime = _ime;
    z.prezime = _prezime;
    return z;
}

int main()
{
   

    return 0;
}


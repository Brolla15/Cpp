#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;
class Predmet {
private:
    string naziv;
    int vrijednost;
public:
    Predmet(string _naziv, int _vrijednost) {
        naziv = _naziv;
        vrijednost = _vrijednost;
    }
    Predmet() {}
    string getNaziv() {
        return naziv;
    }
    int getVrijednost() {
        return vrijednost;
    }
};

class Garaza {
private:
    int velicina1,velicina2;
    bool autom_uprav;
    string lokacija;
    vector<Predmet> pred;

public:
      Garaza(int _velicina1, int _velicina2, bool _autom_uprav, string _lokacija,vector<Predmet> _pred) {
          velicina1 = _velicina1;
          velicina2 = _velicina2;
          autom_uprav = _autom_uprav;
          lokacija = _lokacija;
          pred = _pred;
      }
      Garaza(){}
      string getLokacija() {
          return lokacija;
      }
      bool getAutom_uprav() {
          return autom_uprav;
      }
      int getVelicina1() {
          return velicina1;
      }
      void setVelicina1(int _velicina1) {
          velicina1 = _velicina1;
      }
      int getVelicina2() {
          return velicina2;
      }
      void setVelicina2(int _velicina2) {
          velicina2 = _velicina2;
      }
      vector<Predmet> getPredmeti(){
          return pred;
      }
      void setPredmeti(vector<Predmet> _pred) {
          pred=_pred;
      }
};



int main() {
    int velicina1, velicina2;
    bool autom_uprav;
    string autom;
    string lokacija;
    string naziv;
    int vrijednost;
    int N;
    int M;
    vector<Garaza> garaza;
    vector<Predmet> pred;
    int redni_broj;
    string naziv_pred;
    int vrijednost_pred;


    cout << "Unesite broj garaža (N):";
    cin >> N;

    for (int i = 0; i < N; i++) {
        cout << "Unesite velicinu, lokaciju i podatak o vratima za "<<i+1<<". garazu:";
        cin >> velicina1>>velicina2>>lokacija>>autom;
        if (autom == "DA") {
            autom_uprav = true;
        }
        else {
            autom_uprav = false;
        }
        garaza.push_back(Garaza(velicina1,velicina2, autom_uprav,lokacija,pred));
    }

    cout << "Unesite broj predmeta (M):";
    cin >> M;

    for (int i = 0; i < M; i++) {
        cout << "Unesite redni broj garaze u koju spada " << i+1 << ". predmet:";
        cin >> redni_broj;
        cout << "Unesite naziv i vrijednost predmeta:";
        cin >> naziv_pred>>vrijednost_pred;
        pred = garaza.at(redni_broj - 1).getPredmeti();
        pred.push_back(Predmet(naziv_pred, vrijednost_pred));
        garaza.at(redni_broj - 1).setPredmeti(pred);
    }
    for (int i = 0; i < garaza.size(); i++) {
        for (int j = 0; j < garaza.at(i).getPredmeti().size(); j++) {
            cout << i+1 << ". " << garaza.at(i).getLokacija() << " " << garaza.at(i).getVelicina1() << "x" << garaza.at(i).getVelicina2() << " - predmeti: " << garaza.at(i).getPredmeti().at(j).getNaziv()<<"("<< garaza.at(i).getPredmeti().at(j).getVrijednost()<<"kn)"<<endl;
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

class Element{
public:
	double obujam;
	string naziv;
	static int broj;

	Element(double _obujam, string _naziv) :obujam(_obujam), naziv(_naziv) {
		if (_obujam > 3) {
			broj++;
		}
	}
	Element(){}
	static int getVelikiElementi(){
		return broj;
	}
};

namespace Zgrada {
	class Stan {
	public:
		vector<Element> elementi;
		template<class... T>
		Stan(T... a) : elementi({ a... }) {}
		
		Stan(initializer_list<Element> arg) : elementi({ arg }) {}
		virtual string getVrsta() {
			return "obican stan";
		}
		Stan() {}
		bool operator()(Element prvi, Element drugi) {
			if (prvi.obujam != drugi.obujam) {
				return prvi.obujam > drugi.obujam;
			}
			else {
				return prvi.naziv < drugi.naziv;
			}
		}
	};
	Stan operator+(Stan a,Stan b) {
		Stan c;
		for(int i=0;i<a.elementi.size();i++)
			c.elementi.push_back(a.elementi[i]);
		for (int i = 0; i < b.elementi.size(); i++)
			c.elementi.push_back(b.elementi[i]);

		return c;
	}
	class Garsonijera : public Stan {
	public:
		string getVrsta()override {
			return "Garsonijera";
		}
	};
	class Apartman : public Stan {
	public:
		string getVrsta()override {
			return "Apartman";
		}
	};
}
int Element::broj = 0;

bool usporediElemente(Element prvi, Element drugi) {
	if (prvi.obujam != drugi.obujam) {
		return prvi.obujam > drugi.obujam;
	}
	else {
		return prvi.naziv < drugi.naziv;
	}
}
class Vlasnik {
public:
	Zgrada::Stan* stan;
	Vlasnik(){}
	Vlasnik(const Vlasnik& v) {
		*stan = *v.stan;
		cout << "konstruktor";
	}
	Vlasnik& operator=(Vlasnik&& v) {
		delete[] stan;
		stan = v.stan;
		return *this;
	}
	~Vlasnik() {
		delete[] stan;
		cout << "destruktor";
	}
};
int main()
{
	Element a(50, "ab");
	Element b(1, "ba");
	Element c(4,"cb");
	Element n(50, "br");
	Element m(1, "cd");
	Element k(4, "de");
	cout << Element::getVelikiElementi()<<endl;

	Zgrada::Stan e(c,b,a);
	Zgrada::Stan d{ n,m,k };
	for (int i = 0; i < d.elementi.size(); i++) {
		cout << d.elementi[i].naziv << ","<<d.elementi[i].obujam << endl;
	}
	Zgrada::Stan f;
	f=Zgrada::operator+(e, d);
	for (int i = 0; i < f.elementi.size(); i++) {
		cout << f.elementi[i].naziv << "," << f.elementi[i].obujam << endl;
	}
	Zgrada::Apartman apartman;
	Zgrada::Garsonijera garsonijera;
	cout << apartman.getVrsta() << endl;
	cout << garsonijera.getVrsta() << endl;

	sort(f.elementi.begin(), f.elementi.end(), [](Element prvi, Element drugi) {
		if (prvi.obujam != drugi.obujam) {
			return prvi.obujam > drugi.obujam;
		}
		else {
			return prvi.naziv < drugi.naziv;
		}
		}
	);

	sort(f.elementi.begin(), f.elementi.end(), usporediElemente);
	sort(f.elementi.begin(), f.elementi.end(), Zgrada::Stan());

	for (int i = 0; i < f.elementi.size(); i++) {
		cout << f.elementi[i].naziv << "," << f.elementi[i].obujam << endl;
	}
	return 0;
}

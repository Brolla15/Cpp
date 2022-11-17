#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class Knjiga {
public:
	string naziv;
	int primjerci;
	static int popularne;
	Knjiga(string naz,int prim) : naziv(naz),primjerci(prim){
		if (prim > 10) {
			popularne++;
		}
	};
	static int getPopularnaKnjiga() {
		return popularne;
	}
};
int Knjiga::popularne = 0;

namespace Knjiznica {
	class Polica {
	public:
		vector<Knjiga> knjiga;
		template<class... T>
		Polica(T...a) :knjiga({ a... }) {};
		Polica(initializer_list<Knjiga> a) :knjiga({ a }) {};
	};
	Polica& operator-(Polica jedna, Knjiga a) {
		Polica pom;
		for (int i = 0; i < jedna.knjiga.size(); i++) {
			if (jedna.knjiga[i].naziv != a.naziv) {
				pom.knjiga.push_back(jedna.knjiga[i]);
			}
		}
		return pom;
	}
}

int main()
{
	Knjiga a("prva", 5);
	Knjiga b("druga", 25);
	Knjiga c("treca", 15);
	cout << Knjiga::getPopularnaKnjiga()<<endl;
	Knjiznica::Polica desno(a,b,c);
	Knjiznica::Polica lijevo{ c,b,a };
	for (int i = 0; i < desno.knjiga.size(); i++) {
		cout << desno.knjiga[i].naziv<<endl;
	}
	for (int i = 0; i < lijevo.knjiga.size(); i++) {
		cout << lijevo.knjiga[i].naziv << endl;
	}

	Knjiznica::Polica g;
	g=Knjiznica::operator-(lijevo, a);

	for (int i = 0; i < g.knjiga.size(); i++) {
		cout << g.knjiga[i].naziv << endl;
	}
	return 0;
}

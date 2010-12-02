#include <iostream> // Für Ausgabe (cout)
#include <string> //Für Strings
#include <vector> // Für Vectors
#include <algorithm> //Für for_each
#include <boost/utility.hpp> //keine Kopie
#include <tr1/functional>
#include <tr1/memory>

using namespace std;
using namespace tr1;
using namespace placeholders;

typedef shared_ptr<class Duck> DuckPtr;

//Duckklasse mit privatem Konstruktor -> keine Objekte ausserhalb der Klasse erzeugbar
//mit Faktory-Memberfunktion 'make10Ducks', welche 10 Duck-Objekte in Vector abfühlt
class Duck: boost::noncopyable {
private:
	Duck(){} //Privater-(Standard)-Konstruktor
	Duck(string s, int n):name(s), number(n){} //Privater-Konstruktor
	string name;
	int number;
	//Duck(const Duck& x){} //Kopierkonstruktor überschreiben
	//Duck& operator=(const Duck& x){} //Zuweisungsoperator überschreiben
public:
	static void make10Ducks(vector<DuckPtr> &list){
		for(int i = 0; i < 10; ++i){
			list.push_back(DuckPtr(new Duck("DuckyDuck", i+1)));
		}
	};

	void print(){
		cout << name << number << endl;
	}
};

int main(){

	vector<DuckPtr> duckList;
	//make10Ducks mit DuckList aufrufen, um vector mit 10 Duck-Objekte zu befüllen -> da make10Ducks mit Referenz auf vector arbeitet wird Objekt direkt verändert.
	Duck::make10Ducks(duckList);
	cout << duckList.size() << endl;
	for_each(duckList.begin(), duckList.end(), bind(mem_fun_ref(&Duck::print), bind(&DuckPtr::operator*, _1)));
}
/*
10
DuckyDuck1
DuckyDuck2
DuckyDuck3
DuckyDuck4
DuckyDuck5
DuckyDuck6
DuckyDuck7
DuckyDuck8
DuckyDuck9
DuckyDuck10
 */

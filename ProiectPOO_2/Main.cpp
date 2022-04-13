#include <iostream>

#include <vector>

#include <string>

#include <cstring>

using namespace std;

class Contract {
    int nr_contract;
    int an_contract;
    string beneficiar;
    string furnizor;
    double valoare;
public:

    virtual void citire() {
        cout << "Numar contract: ";
        cin >> nr_contract;
        cout << "An contract: ";
        cin >> an_contract;
        cout << "Beneficiar contract: ";
        cin >> beneficiar;
        cout << "Furnizor contract: ";
        cin >> furnizor;
        cout << "Valoare contract: ";
        cin >> valoare;
    }
    virtual void afisare() {
        cout << "Numar contract: " << nr_contract << endl;
        cout << "An contract: " << an_contract << endl;
        cout << "Beneficiar contract: " << beneficiar << endl;
        cout << "Furnizor contract: " << furnizor << endl;
        cout << "Valoare contract: " << valoare << endl;

    }
    Contract() {

        nr_contract = 0;
        an_contract = 0;
        beneficiar = "Neprecizat";
        furnizor = "Neprecizat";
        valoare = 0;
    }
    Contract(int nr, int an, string ben, string furn, double val) {
        nr_contract = nr;
        an_contract = an;

        beneficiar = ben;

        furnizor = furn;

        valoare = val;

    }

    ~Contract() {
        cout << "Am apelat destructorul";
    }

    friend istream& operator >> (istream& in, Contract& ob) {
        cout << "Introduceti numarul contractului : "; in >> ob.nr_contract;
        cout << "Introduceti anul contractului : "; in >> ob.an_contract;
        cout << "Introduceti beneficiarul contractului : "; in >> ob.beneficiar;
        cout << "Introduceti furnizorul contractului : "; in >> ob.furnizor;
        cout << "Introduceti valoarea contractului : "; in >> ob.valoare;
        cout << endl;
        return in;
    }

    friend ostream& operator << (ostream& out,
        const Contract& ob) {
        out << "Numarul Contractului :" << ob.nr_contract << endl;
        out << "Anul contractului : " << ob.an_contract << endl;
        out << "Beneficiarul contractului : " << ob.beneficiar << endl;
        out << "Furnizorul contractului : " << ob.furnizor << endl;
        out << "Valoarea contractului : " << ob.valoare << endl;
        out << endl;

        return out;
    }

};

class ContractInchiriere : Contract {

    int perioada;
public:
    void citire() {
        Contract::citire();
        cout << "Perioada Contractului : ";
        cin >> perioada;
    }
    void afisare() {
        Contract::afisare();
        cout << "Perioada Contractului : " << perioada << endl;
    }
    friend class Dosar;
};

class Dosar {
    vector < ContractInchiriere* > v;
    int nr_contracte_inchiriere;

public:
    Dosar() {
        nr_contracte_inchiriere = 0;
    }

    Dosar(int nr_con_inchir) {
        nr_contracte_inchiriere = nr_con_inchir;
    }

    int get_nr_con_inchir() {

        return nr_contracte_inchiriere;
    }

    void citire_afisare_v() {                    // citirea si afisarea din vectorul de pointeri de obiecte.
        cout << "Introduceti numarul de contracte : ";
        cin >> nr_contracte_inchiriere;
        cout << endl;
        for (int i = 0; i < nr_contracte_inchiriere; i++)
            v.push_back(new ContractInchiriere());

        int i = 0;
        for (auto p = v.begin(); p != v.end(); p++) {
            cout << "                         Contractul cu numarul : " << i << endl;
            (*p)->citire();
            i++;
            cout << endl;
        }

        i = 0;
        cout << "                         Afisarea Contractelor" << endl << endl;
        for (vector < ContractInchiriere* > ::iterator p = v.begin(); p != v.end(); p++) {
            cout << endl << "                         Contractul numarul : " << i << endl << endl;
            i++;
            (*p)->afisare();
        }

    }

};

int main() {
    Dosar d(4);
    Dosar d1;

    d1.citire_afisare_v();

    return 0;

}
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

    Contract(const Contract& ob) {
        nr_contract = ob.nr_contract;
        an_contract = ob.an_contract;
        beneficiar = ob.beneficiar;
        furnizor = ob.furnizor;
        valoare = ob.valoare;

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
    Contract& operator = (Contract& ob) {
        {
            if (this != &ob) {
                nr_contract = ob.nr_contract;
                an_contract = ob.an_contract;
                beneficiar = ob.beneficiar;
                furnizor = ob.furnizor;
                valoare = ob.valoare;
            }
            return *this;
        }
    }
    int get_nr_contract() {
        return nr_contract;
    }
    int get_an_contract() {
        return an_contract;
    }
    string get_beneficiar() {
        return beneficiar;
    }
    string get_furnizor() {
        return furnizor;
    }
    int get_valoare() {
        return valoare;
    }

    void set_nr_contract(int nc) {
        nc = nr_contract;
    }
    void set_an_contract(int ac) {
        ac = an_contract;
    }
    void set_beneficiar(string b) {
        b = beneficiar;
    }
    void set_furnizor(string f) {
        f = furnizor;
    }
    void set_valoare(int val) {
        val = valoare;
    }

};

class ContractInchiriere : public Contract {

    int perioada;
public:

    ContractInchiriere() : Contract() {
        perioada = 0;
    }

    ContractInchiriere(ContractInchiriere& ob) : Contract(ob) {
        perioada = ob.perioada;
    }

    ContractInchiriere(int a, int b, string c, string d, int e, int f) : Contract(a, b, c, d, e), perioada(f) {}

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

    void set_perioada(int per) {
        per = perioada;
    }
    int get_perioada() {
        return perioada;
    }
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

    Dosar(Dosar& ob) {
        nr_contracte_inchiriere = ob.nr_contracte_inchiriere;
    }

    int get_nr_con_inchir() {

        return nr_contracte_inchiriere;
    }

    ~Dosar() {
        for (int i = 0; i < v.size(); i++) {
            delete this->v.at(i);

        }
        v.clear();
    }

    void citire_v() { // citirea si afisarea din vectorul de pointeri de obiecte.
        cout << endl << "Introduceti numarul de contracte : ";
        cin >> nr_contracte_inchiriere;
        cout << endl;
        for (int i = 0; i < nr_contracte_inchiriere; i++)
            v.push_back(new ContractInchiriere());

        int i = 0;
        for (auto p = v.begin(); p != v.end(); p++) {
            cout << "Contractul cu numarul : " << i + 1 << endl << endl;
            (*p)->citire();
            i++;
            cout << endl;
        }
    }
    void afisare_v() {
        if (v.empty())
            cout << endl << "Nu sunt contracte in dosar" << endl;

        else {

            int i = 1;
            cout << "                         Afisarea Contractelor" << endl << endl;
            for (vector < ContractInchiriere* > ::iterator p = v.begin(); p != v.end(); p++) {
                cout << endl << "Contractul numarul : " << i << endl << endl;
                i++;
                (*p)->afisare();
            }
        }

    }
    void stergere_last_v() {
        if (v.empty())
            cout << endl << "Nu exista contracte in dosar, asadar nu putem elimina un contract" << endl;
        else {
            v.pop_back();
        }
    }
    int get_v_size() {
        return v.size();
    }

    int get_nr_contracte_inchirieri() {
        return nr_contracte_inchiriere;
    }

    void set_contracte_inchiriere(int nrci) {
        nrci = nr_contracte_inchiriere;
    }
};

int main() {
    int choice;
    Dosar d1;

    do {
        cout << "Salut! Ce doresti sa faci mai departe? " << endl << endl;
        cout << "1.Adauga contracte in dosar " << endl;
        cout << "2.Afiseaza contractele din dosar" << endl;
        cout << "3.Elimina ultimul contract din dosar" << endl;
        cout << "4.Iesi din program" << endl << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Numarul de contracte in dosar la momentul actual : " << d1.get_v_size() << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        cin >> choice;
        switch (choice) {
        case 1:
            d1.citire_v();
            cout << endl;
            break;

        case 2:
            d1.afisare_v();
            cout << endl;
            break;
        case 3:
            d1.stergere_last_v();
            cout << endl;
            break;

        case 4:
            return 0;
        }

    } while (choice != 4);
}
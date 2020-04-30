#ifndef LL1_GIC_H
#define LL1_GIC_H

#include <iostream>
#include <vector>

using namespace std;

struct tranzitie {
    char N;
    string productie;
};

class GIC {
private:
    int numarNeterminale, numarTerminale, numarTranzitii;
    vector<char> neterminale, terminale;
    vector<tranzitie> vectorTranzitii;
public:
    GIC();

    int hasNeterminal(string other);

    bool verificareAcceptareCuvant(char *word);

    friend istream &operator>>(istream &in, GIC &other);

    friend ostream &operator<<(ostream &out, GIC &other);

    ~GIC();
};

#endif //LL1_GIC_H

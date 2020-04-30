#include "GIC.h"
#include <queue>
#include <cstring>

GIC::GIC() {
    numarNeterminale = numarTerminale = numarTranzitii = 0;
}

istream &operator>>(istream &in, GIC &other) {
    cout << "Numar neterminale = ";
    in >> other.numarNeterminale;
    char temp;
    int it;
    cout << "\nIntroduceti neterminalele : ";
    for (it = 0; it < other.numarNeterminale; it++) {
        in >> temp;
        other.neterminale.push_back(temp);
    }
    cout << "\nNumar Terminale = ";
    in >> other.numarTerminale;
    cout << "\nIntroduceti terminalele : ";
    for (it = 0; it < other.numarTerminale; it++) {
        in >> temp;
        other.terminale.push_back(temp);
    }
    cout << "\nNumar Tranzitii = ";
    in >> other.numarTranzitii;
    cout << "\nIntroduceti tranzitiile : \n";
    for (it = 0; it < other.numarTranzitii; it++) {
        tranzitie tranzitieTemp;
        in >> tranzitieTemp.N;
        in >> tranzitieTemp.productie;
        if (tranzitieTemp.productie == "lambda")
            tranzitieTemp.productie = '\0';
        other.vectorTranzitii.push_back(tranzitieTemp);
        cout << '\n';
    }
    return in;
}

ostream &operator<<(ostream &out, GIC &other) {
    out << " Numar N = " << other.numarNeterminale << '\n';
    int it;
    for (it = 0; it < other.numarNeterminale; it++) {
        out << other.neterminale[it] << " ";
    }
    out << '\n';
    out << "Numar T = " << other.numarTerminale << '\n';
    for (it = 0; it < other.numarTerminale; it++) {
        out << other.terminale[it] << " ";
    }
    out << '\n';
    out << "Numar tranzitii = " << other.numarTranzitii << '\n';
    for (it = 0; it < other.numarTranzitii; it++) {
        out << other.vectorTranzitii[it].N << " ";
        out << other.vectorTranzitii[it].productie << '\n';
    }
    return out;
}

int GIC::hasNeterminal(string other) {
    for (int it = 0; it < other.size(); it++)
        for (int iterator = 0; iterator < numarNeterminale; iterator++) {
            if (other[it] == neterminale[iterator])
                return it;
        }
    return -1;
}

bool GIC::verificareAcceptareCuvant(char *word) {
    queue<string> coada;
    string cuvant;
    cuvant.append(word);
    int it;
    for (it = 0; it < numarTranzitii; it++) {
        if (vectorTranzitii[it].N == neterminale[0])
            coada.push(vectorTranzitii[it].productie);
    }
    while (!coada.empty()) {
        string temp;
        temp = coada.front();
        coada.pop();
        if (this->hasNeterminal(temp) >= 0) {

            int indice = this->hasNeterminal(temp);
            for (it = 0; it < numarTranzitii; it++)
                if (vectorTranzitii[it].N == temp[indice]) {
                    string temp2;
                    char aux1[255], aux2[255];
                    size_t lenght;
                    lenght = temp.copy(aux1, temp.size() - indice - 1, indice + 1);
                    aux1[lenght] = '\0';
                    lenght = temp.copy(aux2, indice, 0);
                    aux2[lenght] = '\0';
                    temp2.append(aux2);
                    lenght = vectorTranzitii[it].productie.copy(aux2, vectorTranzitii[it].productie.size(), 0);
                    aux2[lenght] = '\0';
                    temp2.append(aux2);
                    temp2.append(aux1);
                    if (temp2.size() <= (strlen(word) + 1))
                        coada.push(temp2);
                    if (temp2 == cuvant)
                        return true;
                }
        }
    }
    return false;
}

GIC::~GIC() {
    numarNeterminale = numarTerminale = numarTranzitii = 0;
    vectorTranzitii.clear();
    neterminale.clear();
    terminale.clear();
}

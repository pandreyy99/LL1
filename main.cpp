#include <iostream>
#include "GIC.h"

using namespace std;

int main() {
    GIC G1;
    char word[255];
    cout << "Incepem sa citim gramatica :\n";
    cin >> G1;
    cout << "Cuvantul introdus = ";
    cin >> word;
    if (G1.verificareAcceptareCuvant(word))
        cout << "Cuvantul este generat de gramatica data!";
    else cout << "Cuvantul nu este generat de gramatica data!";
    return 0;
}
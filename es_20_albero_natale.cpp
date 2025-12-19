#include <iostream>
using namespace std;

int main() {
    int h;
    cout << "Inserisci l'altezza del triangolo: ";
    cin >> h;

    int centro_colonna = 40;   // centro orizzontale (80 / 2)
    int riga_inizio = 12 - h / 2; // centro verticale

    // sposta il cursore in alto a sinistra
    cout << "\033[H";

    for (int i = 0; i < h; i++) {
        // sposta il cursore alla riga e colonna corrette
        cout << "\033[" << (riga_inizio + i) << ";" 
             << (centro_colonna - i) << "H";

        // stampa le stelle
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
    }

    // porta il cursore sotto il triangolo
    cout << "\033[" << (riga_inizio + h + 1) << ";1H";

    return 0;
}


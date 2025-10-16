#include <iostream>
#include <vector>
#include <algorithm> // för sort()
#include <locale>
using namespace std;

void laggTill(vector<double>& lista);
void visaLista(const vector<double>& lista);
void sortera(vector<double>& lista, bool stigande);

int main() {
    setlocale(LC_ALL, "sv_SE.UTF-8");

    vector<double> lista;
    int val;
    bool stigande = true;

    do {
        cout << "\n--- MENY ---\n";
        cout << "1. Lägg till värden\n";
        cout << "2. Visa lista\n";
        cout << "3. Sortera lista\n";
        cout << "4. Avsluta\n";
        cout << "Val: ";
        cin >> val;

        if (!cin) {
            cout << "Felaktig inmatning.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (val) {
            case 1:
                laggTill(lista);
                break;
            case 2:
                visaLista(lista);
                break;
            case 3:
                cout << "1 = stigande, 0 = fallande: ";
                cin >> stigande;
                sortera(lista, stigande);
                break;
            case 4:
                cout << "Avslutar programmet...\n";
                break;
            default:
                cout << "Ogiltigt val.\n";
        }
    } while (val != 4);

    return 0;
}

// ===== Lägg till värden =====
void laggTill(vector<double>& lista) {
    int n;
    cout << "Hur många värden vill du lägga till? ";
    cin >> n;

    if (!cin || n <= 0) {
        cout << "Felaktig inmatning.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    for (int i = 0; i < n; i++) {
        double v;
        cout << "Värde " << (lista.size() + 1) << ": ";
        cin >> v;
        if (!cin) {
            cout << "Felaktig inmatning.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }
        lista.push_back(v);
    }
}

// ===== Visa lista =====
void visaLista(const vector<double>& lista) {
    if (lista.empty()) {
        cout << "Listan är tom.\n";
        return;
    }

    cout << "Listans värden:\n";
    for (double v : lista)
        cout << v << " ";
    cout << "\n";
}

// ===== Sortera lista =====
void sortera(vector<double>& lista, bool stigande) {
    if (lista.empty()) {
        cout << "Listan är tom.\n";
        return;
    }

    if (stigande)
        sort(lista.begin(), lista.end());
    else
        sort(lista.rbegin(), lista.rend());

    cout << "Listan sorterad " << (stigande ? "stigande" : "fallande") << ".\n";
    visaLista(lista);
}
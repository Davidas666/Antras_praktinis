#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char abc[] = "abcdefghijklmnopqrstuvwxyz1234567890";
int ilgis = strlen(abc);

void sifravimas() {
    string tekstas;
    string raktas;
    string rezultatas;
    int uzsifruotas1[100];
    int uzsifruotas2[100];
    int uzsifruotas3[100] = { 0 };

    cout << "Įveskite norimą tekstą užšifravimui" << endl;
    getline(cin, tekstas);

    cout << "Įveskite norimą raktą (ne ilgesnį nei 100 simbolių)" << endl;
    getline(cin, raktas);

    if (raktas.length() < 1) {
        cout << "Raktas turi būti bent 1 simbolio ilgio." << endl;
        return;
    }

    int raktoIlgis = raktas.length();

    for (int i = 0; i < tekstas.length(); i++) {
        int z = 0;
        while (abc[z] != tekstas[i]) {
            z = (z + 1) % ilgis;
        }
        uzsifruotas1[i] = z;
    }

    for (int i = 0; i < raktas.length(); i++) {
        int z = 0;
        while (abc[z] != raktas[i]) {
            z = (z + 1) % ilgis;
        }
        uzsifruotas2[i] = z;
    }

    for (int i = 0; i < tekstas.length(); i++) {
        if (uzsifruotas1[i] + uzsifruotas2[i] >= ilgis) {
            uzsifruotas3[i] = uzsifruotas1[i] + uzsifruotas2[i] - ilgis;
        }
        else {
            uzsifruotas3[i] = uzsifruotas1[i] + uzsifruotas2[i];
        }
        rezultatas += abc[uzsifruotas3[i]];
    }

    cout << "Užšifruotas tekstas: " << rezultatas << endl;
}

void isifravimas() {
    string uzsifruotasTekstas;
    string raktas;
    string rezultatas;
    int uzsifruotas1[100];
    int uzsifruotas2[100];
    int uzsifruotas3[100] = { 0 };

    cout << "Įveskite užšifruotą tekstą" << endl;
    getline(cin, uzsifruotasTekstas);

    cout << "Įveskite raktą (ne ilgesnį nei 100 simbolių)" << endl;
    getline(cin, raktas);

    for (int i = 0; i < uzsifruotasTekstas.length(); i++) {
        int z = 0;
        while (abc[z] != uzsifruotasTekstas[i]) {
            z = (z + 1) % ilgis;
        }
        uzsifruotas1[i] = z;
    }

    for (int i = 0; i < raktas.length(); i++) {
        int z = 0;
        while (abc[z] != raktas[i]) {
            z = (z + 1) % ilgis;
        }
        uzsifruotas2[i] = z;
    }
    for (int i = 0; i < uzsifruotasTekstas.length(); i++) {
        if (uzsifruotas1[i] - uzsifruotas2[i] < 0) {
            uzsifruotas3[i] = uzsifruotas1[i] - uzsifruotas2[i] + ilgis;
        }
        else {
            uzsifruotas3[i] = uzsifruotas1[i] - uzsifruotas2[i];
        }
        rezultatas += abc[uzsifruotas3[i]];
    }

    cout << "Atšifruotas tekstas: " << rezultatas << endl;
}
void sifravimasSuASCII() {
    string tekstas;
    string rezultatas;

    cout << "Įveskite tekstą šifravimui su ASCII koduote" << endl;
    getline(cin, tekstas);

    for (int i = 0; i < tekstas.length(); i++) {
        char raidute = tekstas[i];

        int asciiValue = int(raidute);
        string asciiString = to_string(asciiValue);

        if (asciiValue < 100) {
            asciiString = "0" + asciiString;
        }

        rezultatas += asciiString + " ";
    }

    cout << rezultatas << endl;
}



void isifravimasSuASCII() {
    string uzsifruotasTekstas;
    string rezultatas;

    cout << "Įveskite užšifruotą tekstą su ASCII koduote (pries issifruojant paspauskite du kartus space)" << endl;
    cin.ignore();
    getline(cin, uzsifruotasTekstas);

    istringstream stream(uzsifruotasTekstas);
    int asciiValue;

    while (stream >> asciiValue) {
        rezultatas += static_cast<char>(asciiValue);
    }

    cout << "Atšifruotas tekstas su ASCII koduote: " << rezultatas << endl;
}


int main() {
    string operacija;
    setlocale(LC_ALL, "Lithuanian");
    while (true) {
        cout << "1. Šifravimas" << endl;
        cout << "2. Dešifravimas" << endl;
        cout << "3. Šifravimas su ASCII koduote" << endl;
        cout << "4. Dešifravimas su ASCII koduote" << endl;
        cout << "Įveskite 'stop', jei norite baigti programą." << endl;
        cout << "Kokią operaciją norite atlikti? ";
        cin >> operacija;

        cin.ignore();

        if (operacija == "1") {
            sifravimas();
        }
        else if (operacija == "2") {
            isifravimas();
        }
        else if (operacija == "3") {
            sifravimasSuASCII();
        }
        else if (operacija == "4") {
            isifravimasSuASCII();
        }
        else if (operacija == "stop") {
            break;
        }
        else {
            cout << "Neteisinga operacija" << endl;
        }
    }

    return 0;
}
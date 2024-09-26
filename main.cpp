#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "hash_function.h"  // Įtraukite savo hash funkcijos antraštę

using namespace std;

// Pagalbinė funkcija nuskaityti failo turinį
string readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Nepavyko atidaryti failo: " << filename << endl;
        return "";
    }

    string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    file.close();
    return content;
}

int main() {
    int pas;
    cout << "Pasirinkite: " << endl;
    cout << "1 - įvesti simbolius" << endl;
    cout << "2 - atidaryti failus, sudarytus tik iš vieno, bet skirtingo simbolio." << endl;
    cout << "3 - atidaryti failus, sudarytus iš daug (> 1000) atsitiktinai sugeneruotų simbolių." << endl;
    cout << "4 - atidaryti failus, sudarytus iš daug (> 1000) simbolių, bet besiskiriančių vienas nuo kito tik vienu simboliu." << endl;
    cout << "5 - atidaryti tuščią failą." << endl;
    cout << "6 - BAIGTI DARBĄ." << endl;
    cin >> pas;

    while (cin.fail() || (pas < 1 || pas > 6)) {
        cout << "Netinkamas pasirinkimas. Įveskite 1, 2, 3, 4, 5 arba 6: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> pas;
    }

    if (pas == 1) {
        // Įvedami simboliai ranka
        string input;
        cout << "Įveskite simbolius, kuriuos norėtumėte naudoti: " << endl;
        cin >> input;

        std::string hash = generateHash(input);
        cout << "Original string: " << input << endl;
        cout << "Hash: " << hash << endl;

    } else if (pas == 2) {
        // Failai su vienu simboliu
        string input1 = readFile("vienas_a.txt");
        string input2 = readFile("vienas_b.txt");

        if (!input1.empty()) {
            std::string hash1 = generateHash(input1);
            cout << "Original string (vienas_a.txt): " << input1 << endl;
            cout << "Hash: " << hash1 << endl;
        }

        if (!input2.empty()) {
            std::string hash2 = generateHash(input2);
            cout << "Original string (vienas_b.txt): " << input2 << endl;
            cout << "Hash: " << hash2 << endl;
        }

    } else if (pas == 3) {
        // Failai su > 1000 atsitiktiniais simboliais
        string input1 = readFile("random_input_1.txt");
        string input2 = readFile("random_input_2.txt");

        if (!input1.empty()) {
            std::string hash1 = generateHash(input1);
            cout << "Hash: " << hash1 << endl;
        }

        if (!input2.empty()) {
            std::string hash2 = generateHash(input2);
            cout << "Hash: " << hash2 << endl;
        }

    } else if (pas == 4) {
        // Failai, kurie skiriasi vienu simboliu
        string input1 = readFile("1_random_input_symbol.txt");
        string input2 = readFile("2_random_input_symbol.txt");

        if (!input1.empty()) {
            std::string hash1 = generateHash(input1);
            cout << "Hash: " << hash1 << endl;
        }

        if (!input2.empty()) {
            std::string hash2 = generateHash(input2);
            cout << "Hash: " << hash2 << endl;
        }

    } else if (pas == 5) {
        // Tuščias failas
        cout << "Tuščias failas sukurtas (tuscias.txt). Galite redaguoti failą ranka." << endl;
        ofstream emptyFile("tuscias.txt");
        if (emptyFile.is_open()) {
            emptyFile.close();
        } else {
            cerr << "Nepavyko sukurti tuščio failo." << endl;
        }

    } else if (pas == 6) {
        cout << "Užbaigėte darbą." << endl;
        return 0;  // Išeiname iš programos
    }

    return 0;
}

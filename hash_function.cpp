#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <chrono>
#include <random>

// Funkcija, kuri konvertuoja simbolių eilutę į ASCII kodus
std::string stringToASCII(const std::string& input) {
    std::stringstream asciiStream;

    for (char c : input) {
        asciiStream << std::setw(2) << std::setfill('0') << std::hex << (int)c;
    }

    return asciiStream.str();
}

std::string modifyString(const std::string& input) {
    std::string modified = input;

    for (size_t i = 0; i < modified.length(); i++) {
        char& c = modified[i];
        if (isalpha(c)) {
            int base = isupper(c) ? 'A' : 'a';
            int alphabeticPosition = c - base;

            int shift = (alphabeticPosition + (i + 1)) % 26; // apskaičiuojame perkėlimą
            c = base + shift; // perkeliamas į naują vietą
        }
    }

    return modified;
}

// Funkcija, kuri sumažina kiekvieną skaitmenį iki vieno skaitmens po daugybos
int reduceToOneDigit(int num) {
    int product = 1, sum = 0;

    // Sudauginame skaitmenis
    while (num > 0) {
        int digit = num % 10;
        product *= digit;
        num /= 10;
    }

    // Sudedame daugybos rezultatą
    while (product > 0) {
        sum += product % 10;
        product /= 10;
    }

    // Jei suma daugiau nei vienženklis, tęsiame procesą
    if (sum > 9) {
        return reduceToOneDigit(sum);
    }

    return sum;
}

// Funkcija, kuri apdoroja simbolius, jei ilgis > 64
std::string processLongerInput(const std::string& input) {
    std::vector<int> results;
    std::string hexResult;

    // Padaliname į 32 dalis
    int chunkSize = input.length() / 32;

    for (int i = 0; i < 32; ++i) {
        int chunkSum = 0;

        // Kiekvieną dalį verčiame į ASCII ir atliekame operacijas
        for (int j = 0; j < chunkSize; ++j) {
            char c = input[i * chunkSize + j];
            int asciiValue = static_cast<int>(c);
            chunkSum += reduceToOneDigit(asciiValue);
        }

        // Kiekvieną sumažintą reikšmę konvertuojame į hex formatą
        std::stringstream ss;
        ss << std::hex << chunkSum;
        hexResult += ss.str();
    }

    // Apkarpome iki 64 simbolių
    if (hexResult.length() > 64) {
        hexResult = hexResult.substr(0, 64);
    }

    return hexResult;
}

// Funkcija, kuri generuoja atsitiktinį skaičių
int generateRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100); // Generuojame skaičius nuo 1 iki 100
    return dis(gen);
}

// Maišos funkcija, kuri sugeneruoja 64 simbolių ilgumo maišos kodą
std::string generateHash(const std::string& input) {
    auto start = std::chrono::high_resolution_clock::now(); // Pradėti matuoti laiką

    std::string hash;

    // Įvesčių ilgiui < 64
    if (input.length() <= 64) {
        std::string asciiHash = stringToASCII(input);

        // Pridedame daugiau simbolių, jei reikia
        while (asciiHash.length() < 64) {
            std::string modifiedInput = modifyString(input);
            asciiHash += stringToASCII(modifiedInput);
        }

        // Pridėkite atsitiktinį skaičių prie ASCII hash
        int randomNum = generateRandomNumber();
        asciiHash += std::to_string(randomNum);

        // Pakeiskime keletą simbolių, kad rezultatas pasikeistų
        for (size_t i = 0; i < asciiHash.length(); i++) {
            if (i % 5 == 0) { // Pakeisti kas penktą simbolį
                asciiHash[i] = 'A' + (randomNum % 26); // Atsitiktinai pasirinktas simbolis
            }
        }

        // Apkarpome iki 64 simbolių
        if (asciiHash.length() > 64) {
            asciiHash = asciiHash.substr(0, 64);
        }

        hash = asciiHash;

    } else {
        // Jei įvesties ilgis > 64, naudojame antrąjį metodą
        hash = processLongerInput(input);
    }

    auto end = std::chrono::high_resolution_clock::now(); // Pabaigti matuoti laiką
    std::chrono::duration<double, std::milli> elapsed = end - start; // Laikas milisekundėmis

    std::cout << "Hash sukurimo laikas: " << elapsed.count() << " ms" << std::endl; // Atspausdinti laiką

    return hash;
}

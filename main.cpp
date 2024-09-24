
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

std::string stringToASCII(const std::string& input) {
    std::stringstream asciiStream;

    for (char c : input) {
        // Konvertuojame kiekvieną simbolį į jo ASCII reikšmę ir paverčiame į hex formatą
        asciiStream << std::setw(2) << std::setfill('0') << std::hex << (int)c;
    }

    return asciiStream.str();
}

std::string modifyString(const std::string& input) {
    std::string modified = input;

    for (char& c : modified) {
        // Pakeičiame kiekvieną simbolį kitu, perėję kelis simbolius abėcėlėje
        if (isalpha(c)) {
            c = (c + 2); // Perkeliame 2 raides į priekį
            if (c > 'z') {
                c -= 26; // Grįžtame į abėcėlės pradžią, jei peržengėme z
            }
        }
    }

    return modified;
}

std::string generateHash(const std::string& input) {
    std::string asciiHash = stringToASCII(input);

    // Kiek reikia papildomų simbolių, kad pasiektume 64 simbolius
    while (asciiHash.length() < 64) {
        std::string modifiedInput = modifyString(input);
        asciiHash += stringToASCII(modifiedInput);
    }

    // Apkarpome iki 64 simbolių, jei viršijama
    if (asciiHash.length() > 64) {
        asciiHash = asciiHash.substr(0, 64);
    }

    return asciiHash;
}

int main() {
    std::string input = "laba";
    std::string hash = generateHash(input);

    std::cout << "Original string: " << input << std::endl;
    std::cout << "Hash: " << hash << std::endl;

    return 0;
}

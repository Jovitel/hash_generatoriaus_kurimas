#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

std::string generateRandomString(int length) {
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()";
    std::string randomString;

    for (int i = 0; i < length; ++i) {
        // Pasirinkti atsitiktinį simbolį iš simbolių rinkinio
        randomString += characters[rand() % characters.length()];
    }

    return randomString;
}

void createTestFiles() {
    for (int i = 1; i <= 2; ++i) {
        std::ofstream file("random_input_" + std::to_string(i) + ".txt");

        if (file.is_open()) {
            std::string randomString = generateRandomString(1200); // Generuoti 1200 simbolių
            file << randomString; // Rašyti į failą
            file.close();
            std::cout << "Sukurtas failas: random_input_" << i << ".txt" << std::endl;
        } else {
            std::cerr << "Klaida: Nepavyko atidaryti failo random_input_" << i << ".txt" << std::endl;
        }
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Inicializuojame atsitiktinį generatorių
    createTestFiles();
    return 0;
}

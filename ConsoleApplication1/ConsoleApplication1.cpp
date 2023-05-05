//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int countWords(string str) {
//    stringstream ss(str);
//    string word;
//    int count = 0;
//
//    while (ss >> word) {
//        count++;
//    }
//
//    return count;
//}
//
//int main() {
//    string filename = "texto.txt";
//    ifstream file(filename);
//
//    if (!file.is_open()) {
//        cout << "El archivo " << filename << " no existe. Se creará uno nuevo." << endl;
//        ofstream newFile(filename);
//        newFile.close();
//        file.open(filename);
//    }
//
//    string line;
//    int totalWords = 0;
//
//    while (getline(file, line)) {
//        totalWords += countWords(line);
//    }
//
//    file.close();
//
//    cout << "El archivo " << filename << " contiene " << totalWords << " palabras." << endl;
//
//    return 0;
//}
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return 1;
    }

    std::string word;
    std::cout << "Ingrese la palabra a buscar: ";
    std::cin >> word;

    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find(word);
        while (pos != std::string::npos) {
            count++;
            pos = line.find(word, pos + 1);
        }
    }

    std::cout << "La palabra \"" << word << "\" aparece " << count << " veces en el archivo." << std::endl;

    file.close();
    return 0;
}


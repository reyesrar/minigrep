#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

int main(int argc, char* argv[]){

    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <archivo> <cadena de busqueda>" << endl;
        return 1;
    }

    string filename = argv[1];
    string searchString = argv[2];

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo: " << filename << endl;
        return 0;
    }

    string line;
    int lineNumber = 1;
    int linesMatches = 0;
    int matches = 0;

    cout<<"\n"<<endl;
    while (getline(file, line)) {
        if (line.find(searchString) != string::npos) {
            cout << "Linea " << lineNumber << ": " << line << endl;
            linesMatches++;
            matches += std::count(line.begin(), line.end(), searchString[0]);
        }
        lineNumber++;
    }
    file.close();

    cout << "Numero de lineas con coincidencias: " << linesMatches << endl;
    cout << "Numero de coincidencias: " << matches << endl;
    cout<<"\n"<<endl;

    return 0;
        
}
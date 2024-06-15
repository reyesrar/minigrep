#include<iostream>
#include<fstream>
#include<string>
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

    cout<<"\n"<<endl;
    while (getline(file, line)) {
        if (line.find(searchString) != string::npos) {
            cout << "Linea " << lineNumber << ": " << line << endl;
        }
        lineNumber++;

    }
    cout<<"\n"<<endl;
    file.close();

    return 0;
        
}
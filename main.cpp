#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

void matchColor(int color){
        cout<<"\033["<<color<<"m";
    }

int main(int argc, char* argv[]){

    
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <archivo> <cadena de busqueda>" << endl;
        return 1;
    }

    string filename = argv[1];
    string searchString = argv[2];

    transform(searchString.begin(), searchString.end(), searchString.begin(), ::tolower); // Convertir la cadena de búsqueda a minúsculas

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
        string temp = line;
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        size_t found = line.find(searchString);
        if (found != string::npos) {
            cout << "Linea " << lineNumber << ": ";
            cout<<temp.substr(0,found);
            matchColor(32);
            cout<<temp.substr(found, searchString.size());
            matchColor(0);
            cout<<temp.substr(found + searchString.size());
            cout<<"\n"<<endl;
            linesMatches++;
            matches += count(line.begin(), line.end(), searchString[0]);
        }
        lineNumber++;
    }
    file.close();

    cout<<"\n"<<endl;
    cout << "Numero de lineas con coincidencias: " << linesMatches << endl;
    cout << "Numero de coincidencias: " << matches << endl;
    cout<<"\n"<<endl;

    return 0;
        
}
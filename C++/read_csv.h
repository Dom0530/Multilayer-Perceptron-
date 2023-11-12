#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para cargar datos desde un archivo CSV, empezando desde la columna 3 porque desde aqui comienzan los features
vector<vector<double>> loadCSV(string filename) {
    vector<vector<double>> data;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return data;
    }

    string line, cell;
    while (getline(file, line)) {
        istringstream lineStream(line);
        vector<double> entry;
        int colCount = 0;
        while (getline(lineStream, cell, ',')) {
            if (colCount >= 2) {
                entry.push_back(stod(cell));
            }
            colCount++;
        }
        if (entry.size() > 0) {
            data.push_back(entry);
        }
    }

    file.close();
    return data;
}

// Función para cargar las etiquetas o labels M (maligno) = 0, B (benigno) = 1
vector<int> loadLabels(string filename) {
    vector<int> labels;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return labels;
    }

    string line, label;
    while (getline(file, line)) {
        istringstream lineStream(line);
        int colCount = 0;
        while (getline(lineStream, label, ',')) {
            if (colCount == 1) {
                if (label == "M") {
                    labels.push_back(0);
                } else if (label == "B") {
                    labels.push_back(1);
                }
            }
            colCount++;
        }
    }

    file.close();
    return labels;
}

// Función para dividir el dataset en entrenamiento y prueba
void splitTrainTest(const vector<vector<double>>& data, const vector<int>& labels, vector<vector<double>>& trainX, vector<int>& trainY, vector<vector<double>>& testX, vector<int>& testY, double trainRatio) {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (size_t i = 0; i < data.size(); i++) {
        if ((double)rand() / RAND_MAX < trainRatio) {
            trainX.push_back(data[i]);
            trainY.push_back(labels[i]);
        } else {
            testX.push_back(data[i]);
            testY.push_back(labels[i]);
        }
    }
}

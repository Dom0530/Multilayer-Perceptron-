#include "forward/MLP.h"
#include "read_csv.h"

int main() {

    // Cargar el dataset desde un archivo CSV
    string filename = "dataset_cancer.csv";
    vector<vector<double>> dataset = loadCSV(filename);
    vector<int> labels = loadLabels(filename);

    // Dividir los datos en conjuntos de entrenamiento y prueba (70% - 30%)
    vector<vector<double>> trainSetX, testSetX;
    vector<int> trainSetY, testSetY;
    double trainRatio = 0.7;
    splitTrainTest(dataset, labels, trainSetX, trainSetY, testSetX, testSetY, trainRatio);

    MLP mlp(3, 6, 6, 1, relu);
    //mlp.show_weights();

    vector<matrix> X = {{{2,4,5}}, {{1,1,5}}, {{5,8,7}}, {{6,4,3}}, {{9,1,4}}, {{1,2,3}}, {{4,3,2}}, {{2,1,5}}, {{1,1,1}}, {{4,6,3}}};
    vector<matrix*> pred = mlp.predict(X);

    for (int k = 0; k < pred.size(); k++) {
        for (int i = 0; i < (*pred[k]).size(); i ++) { 
            for (int j = 0; j < (*pred[k])[0].size(); j++)
                cout << (*pred[k])[i][j] << " ";
            cout << "\n";
        }
    }


    return 0;

}
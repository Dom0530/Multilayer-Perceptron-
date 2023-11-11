#include "MLP.h"

int main() {

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
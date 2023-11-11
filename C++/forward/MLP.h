#include "Functions.h"

#define matrix vector<vector<double>>
#define uint unsigned int

class MLP {
private:
    uint numof_features;
    uint numof_hidd_layers;
    uint neurons_per_hidd_layers;
    uint neurons_of_out_layer;
    double (*act_func) (double);

    vector<matrix> weights;

public:
    vector<matrix*> predict(vector<matrix> &X_pred);
    void activation(matrix* C);
    void show_weights();

    MLP(uint num_features_, uint num_h_layers_, uint ne_p_h_layers_, uint ne_o_layer_, double (*act_func_)(double));
    ~MLP();
};

vector<matrix*> MLP::predict(vector<matrix> &X_pred) {
    
    vector<matrix*> predicts(X_pred.size());
    matrix* C, *temp;
    for(int i = 0; i < X_pred.size(); i ++) {
        C = &X_pred[i]; 
        
        for(int k = 0; k < weights.size(); k++) {
            temp = C;
            C = dot(*C, this->weights[k]);
            
            if (k > 0)
                delete temp;
        }

        activation(C);
        predicts[i] = C;

    }
    
    return predicts;
}

void MLP::activation(matrix *C) {
    for (int i = 0; i < C->size(); i++) 
        for (int j = 0; j < (*C)[0].size(); j++)
            (*C)[i][j] = this->act_func((*C)[i][j]);
    
}

void MLP::show_weights() {
    for (int k = 0; k < weights.size(); k++) {
        cout << "Matrix " << k << " :\n"; 
        for (int i = 0; i < weights[k].size(); i ++) { 
            for (int j = 0; j < weights[k][0].size(); j++)
                cout << weights[k][i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
    }
}

MLP::MLP(uint num_features_, uint num_h_layers_, uint ne_p_h_layers_, uint ne_o_layer_, double (*act_func_)(double)) {
    this->numof_features = num_features_;
    this->numof_hidd_layers = num_h_layers_;
    this->neurons_per_hidd_layers = ne_p_h_layers_;
    this->neurons_of_out_layer = ne_o_layer_;
    this->act_func = act_func_;

    weights = vector<matrix>(this->numof_hidd_layers + 1);
    weights[0] = matrix(this->numof_features, vector<double>(this->neurons_per_hidd_layers, 0.0)); 
    for (int i = 1; i < weights.size() - 1; i++) 
        weights[i] = matrix(this->neurons_per_hidd_layers, vector<double>(this->neurons_per_hidd_layers, 0.0)); 
    weights[weights.size()-1] = matrix(this->neurons_per_hidd_layers, vector<double>(this->neurons_of_out_layer, 0.0));  

    uniform_real_distribution<> dist(0, 1);
    random_device rd;
    mt19937 gen(rd());

    for (int k = 0; k < weights.size(); k++) 
        for (int i = 0; i < weights[k].size(); i ++) 
            for (int j = 0; j < weights[k][0].size(); j++)
                weights[k][i][j] = dist(gen);
        
    
    
}

MLP::~MLP()
{
}

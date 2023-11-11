#include <cmath>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <random>
#include <iostream>

using namespace std;

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double my_tanh(double x) {
    return tanh(x);
}

double relu(double x) {
    return max(0.0, x);
}

vector<vector<double>>* dot(const vector<std::vector<double>> &A, const vector<std::vector<double>> &B) {
  
  if (A[0].size() != B.size()) {
    throw invalid_argument("Las matrices no son compatibles para la multiplicacion");
  }

  vector<std::vector<double>>* C = new vector<std::vector<double>>(A.size(), vector<double>(B[0].size(), 0.0));

  for (unsigned int i = 0; i < A.size(); i++) 
    for (unsigned int j = 0; j < B[0].size(); j++) 
      for (unsigned int k = 0; k < A[0].size(); k++) 
        (*C)[i][j] += A[i][k] * B[k][j];
      
  return C;
}



#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct DataPoint {
    vector<double> features; // Đặc trưng
    int label;               // Nhãn (+1 hoặc -1)
};

// Hàm tính tích vô hướng
double dotProduct(const vector<double>& v1, const vector<double>& v2) {
    double result = 0.0;
    for (size_t i = 0; i < v1.size(); ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}

struct SVM {
    vector<double> weights; // Vector trọng số w
    double bias;            // Sai số b
    double learningRate;    // Tốc độ học
    double regularization;  // Tham số điều chỉnh C

    SVM(size_t featureSize, double lr = 0.01, double reg = 0.1) {
        weights = vector<double>(featureSize, 0.0);
        bias = 0.0;
        learningRate = lr;
        regularization = reg;
    }

    void train(const vector<DataPoint>& data, size_t epochs) {
        for (size_t epoch = 0; epoch < epochs; ++epoch) {
            for (const auto& point : data) {
                double prediction = dotProduct(weights, point.features) + bias;
                double margin = point.label * prediction;

                if (margin >= 1) {
                    // Gradient descent for regularization
                    for (size_t i = 0; i < weights.size(); ++i) {
                        weights[i] -= learningRate * regularization * weights[i];
                    }
                } else {
                    // Gradient descent for misclassified points
                    for (size_t i = 0; i < weights.size(); ++i) {
                        weights[i] -= learningRate * (regularization * weights[i] - point.label * point.features[i]);
                    }
                    bias += learningRate * point.label;
                }
            }
        }
    }

    int predict(const vector<double>& features) {
        double result = dotProduct(weights, features) + bias;
        return (result >= 0) ? 1 : -1;
    }
};

int main() {
    // Tạo dữ liệu mẫu
    vector<DataPoint> data = {
        {{2.0, 3.0}, 1},
        {{1.0, 1.0}, -1},
        {{2.5, 3.5}, 1},
        {{1.5, 2.0}, -1},
    };

    // Khởi tạo SVM
    SVM svm(2, 0.01, 0.1);

    // Huấn luyện
    svm.train(data, 1000);

    // Dự đoán
    vector<double> testPoint = {2.0, 2.5};
    int prediction = svm.predict(testPoint);

    cout << "Prediction for test point: " << (prediction == 1 ? "Positive" : "Negative") << endl;

    return 0;
}

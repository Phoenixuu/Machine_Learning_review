#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <Eigen/Dense> // Thư viện Eigen

using namespace Eigen;

// Hàm đọc dữ liệu từ tệp và trả về ma trận X và vector Y
bool readData(const std::string& filename, MatrixXd& X, VectorXd& Y) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Không thể mở tệp: " << filename << "\n";
        return false;
    }

    std::vector<double> x_values, y_values;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        double x, y;
        if (iss >> x >> y) {
            x_values.push_back(x);
            y_values.push_back(y);
        }
    }
    file.close();

    if (x_values.empty() || y_values.empty() || x_values.size() != y_values.size()) {
        std::cerr << "Dữ liệu không hợp lệ\n";
        return false;
    }

    // Chuyển đổi dữ liệu sang dạng Eigen Matrix/Vector
    int n = x_values.size();
    X = MatrixXd(n, 2); // Ma trận X với cột đầu tiên là 1 (bias), cột thứ hai là giá trị x
    Y = VectorXd(n);

    for (int i = 0; i < n; ++i) {
        X(i, 0) = 1.0;    // Bias
        X(i, 1) = x_values[i];
        Y(i) = y_values[i];
    }

    return true;
}

int main() {
    // Ma trận X và vector Y
    MatrixXd X;
    VectorXd Y;

    // Đọc dữ liệu từ tệp
    if (!readData("data.txt", X, Y)) {
        return 1;
    }

    // Phương pháp bình phương tối thiểu (Least Squares)
    VectorXd theta = (X.transpose() * X).ldlt().solve(X.transpose() * Y);

    // Xuất kết quả
    std::cout << "Hệ số góc (Slope): " << theta(1) << "\n";
    std::cout << "Giao điểm với trục y (Intercept): " << theta(0) << "\n";

    return 0;
}

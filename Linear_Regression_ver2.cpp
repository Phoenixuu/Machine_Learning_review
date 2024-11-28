#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

// Hàm tính trung bình
double mean(const std::vector<double>& data) {
    double sum = 0;
    for (double val : data) {
        sum += val;
    }
    return sum / data.size();
}

// Hàm Linear Regression
void linearRegression(const std::vector<double>& x, const std::vector<double>& y, double& slope, double& intercept) {
    double x_mean = mean(x);
    double y_mean = mean(y);
    double numerator = 0, denominator = 0;

    for (size_t i = 0; i < x.size(); ++i) {
        numerator += (x[i] - x_mean) * (y[i] - y_mean);
        denominator += (x[i] - x_mean) * (x[i] - x_mean);
    }

    slope = numerator / denominator;
    intercept = y_mean - slope * x_mean;
}

int main() {
    // Khởi tạo vector để lưu dữ liệu
    std::vector<double> x;
    std::vector<double> y;

    // Đọc dữ liệu từ tệp
    std::ifstream file("data.txt");
    if (!file) {
        std::cerr << "Không thể mở tệp data.txt\n";
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        double xi, yi;
        if (iss >> xi >> yi) {
            x.push_back(xi);
            y.push_back(yi);
        }
    }
    file.close();

    // Kiểm tra dữ liệu có đủ hay không
    if (x.empty() || y.empty() || x.size() != y.size()) {
        std::cerr << "Dữ liệu không hợp lệ\n";
        return 1;
    }

    // Tính toán Linear Regression
    double slope, intercept;
    linearRegression(x, y, slope, intercept);

    // Xuất kết quả
    std::cout << "Hệ số góc (Slope): " << slope << "\n";
    std::cout << "Giao điểm với trục y (Intercept): " << intercept << "\n";

    return 0;
}

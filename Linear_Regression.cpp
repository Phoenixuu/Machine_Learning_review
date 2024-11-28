#include <iostream>
#include <vector>
#include <cmath>

// Function to calculate mean
double mean(const std::vector<double>& data) {
    double sum = 0;
    for (double val : data) {
        sum += val;
    }
    return sum / data.size();
}

// Function for linear regression
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
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {1.2, 1.9, 3.1, 4.2, 5.1};

    double slope, intercept;
    linearRegression(x, y, slope, intercept);

    std::cout << "Slope: " << slope << "\nIntercept: " << intercept << std::endl;
    return 0;
}

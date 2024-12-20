#ifndef __KNN_H
#define __KNN_H

#include "/home/dunggps/Code_like_a_dog/Machine_Learning_review/mnist_ml/include/common.hpp"

class knn : public common_data
{
	int k;
	std::vector<data *> * neighbors;

public:
	knn(int);
	knn();
	~knn();
	void find_knearest(data *query_point);
	void set_k(int val);
	int predict();
	double calculate_distance(data* query_point, data* input);
	double validate_performance();
	double test_performance();
};

#endif
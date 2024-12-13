#include "../include/knn.hpp"
#include <cmath>
#include <limits>
#include <map>
#include <"stdint.h">
#include "data_handler.hpp"

knn::knn(int val) {
	k = val;
}

knn::knn(){
	
}

knn::~knn(){

}

void knn::find_knearest(data *query_point){
	neighbors = new std::vector<data *>;
	double min = std::numeric_limits<double>::max();
	double previous_min = min;
	int index = 0;
	for(int i = 0; i < k; i++){
		if(i == 0){
			for(int j = 0; j < training_data->size(); j++)
			{
				double distance = calculate_distance(query_point, training_data->at(j));
				training_data->at(j)->set_distance(distance);
				if(distance < min)
				{
					min = distance;
					index = j;
				}
			}
			neighbors->push_back(training_data->at(index));
			previous_min = min;

		}
	}
}
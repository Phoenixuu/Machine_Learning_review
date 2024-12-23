#ifndef __KMEANS_HPP
#define __KMEANS_HPP

#include "/home/dunggps/Code_like_a_dog/Machine_Learning_review/mnist_ml/include/common.hpp"
#include <unordered_set>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <map>
#include "/home/dunggps/Code_like_a_dog/Machine_Learning_review/mnist_ml/include/data_handler.hpp"

typedef struct cluster
{
    std::vector<double> *centroid;
    std::vector<data *> *cluster_points;
    std::map<int, int> class_counts;
    int most_frequent_class;

    cluster(data *initial_point)
    {
        centroid = new std::vector<double>;
        cluster_points = new std::vector<data *>;
        for(auto value : *(initial_point->get_feature_vector()))
        {
            centroid->push_back(value);
        }
        cluster_points->push_back(initial_point);
        class_counts[initial_point->get_label()] = 1;
        most_frequent_class = initial_point->get_label();
    }

    void add_to_cluster(data *point)
    {
        
    }
} cluster_t;

#endif
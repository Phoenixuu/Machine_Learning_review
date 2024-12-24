#include "../include/kmeans.hpp"

kmeans::kmeans(int k)
{
    num_cluster = k;
    cluster = new std::vector<cluster_t *>;
    used_indexes = new std::unordered_set<int>;
}
void kmeans::init_clusters()
{
    for(int i = 0; i < num_cluster; i++)
    {
        int index = (rand() % training_data->size());
        while(used_indexes->find(index) != used_indexes->end())
        {
            index = (rand() % training_data->size());
        }
        cluster->push_back(new cluster(training_data->at(index)));
        used_indexes->insert(index);
    }
}

void kmeans::init_clusters()
{
    std::unordered_set<int> classes_used;
    for(int i = 0; i < training_data->size(); i++)
    {
        if(classes_used.find(training_data->at(i)->get_label()) == classes_used.end())
        {
            cluster->push_back(new cluster_t(training_data->at(i));
            classes_used.insert(training_data->at(i)->get_label());
            used_indexes->insert(i);
        }
    }
}
void kmeans::init_clusters_for_each_class();
void kmeans::train();
double kmeans::euclidean_distance(std::vector<double> *, data *);
double kmeans::validate();
double kmeans::test();

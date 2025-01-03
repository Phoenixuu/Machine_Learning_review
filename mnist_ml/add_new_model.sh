#! /bin/bash

export MNIST_ML_ROOT=/home/dunggps/Code_like_a_dog/Machine_Learning_review/mnist_ml

if [[ -z $MNIST_ML_ROOT ]]; then
    echo "Please define MNIST_ML_ROOT"
    exit 1
fi

dir=$(echo "$@" | tr a-z A-Z) # make input all uppercase
model_name_lower=$(echo "$@" | tr A-Z a-z)

mkdir -p $MNIST_ML_ROOT/$dir/include $MNIST_ML_ROOT/$dir/src
touch $MNIST_ML_ROOT/$dir/Makefile
touch $MNIST_ML_ROOT/$dir/include/"$model_name_lower.hpp"
touch $MNIST_ML_ROOT/$dir/src/"$model_name_lower.cc"

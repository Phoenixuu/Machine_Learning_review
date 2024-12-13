CC=g++
INCLUDE_DIR := $(K_Means_Clustering_ROOT)/include
SRC := $(K_Means_Clustering_ROOT)/src
CFLAGS := -shared -std=c++11 -g
LIB_DATA := libdata.so

all : $(LIB_DATA)

$(LIB_DATA) : libdir objdir obj/data_handler.o obj/data.o obj/common.o
	$(CC) $(CFLAGS) -o $(K_MEANS_Clustering_ROOT)/lib/$(LIB_DATA) obj/*.o
	rm -r $(K_MEANS_Clustering_ROOT)/obj

libdir:
	mkdir -p $(K_MEANS_Clustering_ROOT)/lib

objdir:
	mkdir -p $(K_MEANS_Clustering_ROOT)/obj

obj/data_handler.o : $(SRC)/data_handler.cc
	$(CC) -fPIC $(CFLAGS) -o obj/data_dandler.o -I$(INCLUDE_DIR) -c $(SRC)/data_dandler.cc

obj/data.o : $(SRC)/data.cc
	$(CC) -fPIC $(CFLAGS) -o obj/data.o -I$(INCLUDE_DIR) -c $(SRC)/common.cc


clean:
	rm -r $(K_MEANS_Clustering_ROOT)/lib
	rm -r $(K_MEANS_Clustering_ROOT)/obj
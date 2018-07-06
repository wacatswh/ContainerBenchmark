all: list map umap

list: list.cpp
	g++ list.cpp -std=c++11 -o list

map: map.cpp
	g++ map.cpp -std=c++11 -o map

umap: umap.cpp
	g++ umap.cpp -std=c++11 -o umap

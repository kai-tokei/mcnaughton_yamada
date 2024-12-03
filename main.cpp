#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "./vertex.cpp"
#include "./utils.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    string graph_data_path; // グラフデータのpath
    int dim, from, to;

    // グラフデータファイルのpathを読み込む
    if (argc < 5)
    {
        cerr << "Error: No graph data !!" << endl;
        return 0;
    }
    else
    {
        graph_data_path = argv[1];
        dim = stoi(argv[2]);
        from = stoi(argv[3]);
        to = stoi(argv[4]);
    }

    vector<Vertex> vtxs;                     // 頂点テーブル
    vtxs = read_graph_data(graph_data_path); // グラフデータを読み取る

    return 0;
}

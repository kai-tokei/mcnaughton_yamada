#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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

    // 公式に合わせるため、indexを+1ずらす
    vtxs.insert(vtxs.begin(), Vertex(0, 0));
    for (int i = 0; i < vtxs.size(); i++)
        for (int j = 0; j < vtxs[i].to.size(); j++)
            for (int k = 0; k < vtxs[i].to[j].size(); k++)
                vtxs[i].to[j][k]++;

    vector<vector<vector<string>>> regular(dim, vector<vector<string>>(dim, vector<string>(dim))); // 正規表現表

    // 最小の状態推移を求める
    for (int i = 1; i < vtxs.size(); i++)
    {
        for (int j = 0; j < vtxs[i].to.size(); j++)
        {
        }
    }

    return 0;
}

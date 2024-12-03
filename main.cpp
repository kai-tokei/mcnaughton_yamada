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

    vector<vector<vector<string>>> regular(vtxs.size(), vector<vector<string>>(vtxs.size(), vector<string>(vtxs.size(), ""))); // 正規表現表

    // 最小の状態推移を求める
    for (int i = 0; i < vtxs.size(); i++)
    {
        for (int j = 0; j < vtxs.size(); j++)
        {
            for (const vector<int> &vec : vtxs[i].to)
            {
                for (int k = 0; k < vec.size(); k++)
                {
                    if (vec[k] == i)
                    {
                        regular[0][i][j] += " + " + to_string(k) + " + e";
                    }
                    else
                    {
                        regular[0][i][j] += " + " + to_string(k);
                    }
                }
            }
        }
    }

    // それぞれの推移の状態推移から正規表現を生成
    for (int k = 1; k < vtxs.size(); k++)
    {
        for (int i = 1; i < vtxs.size(); i++)
        {
            for (int j = 1; j < vtxs.size(); j++)
            {
                for (const vector<int> &vec : vtxs[i].to)
                {
                    for (int k = 0; k < vec.size(); k++)
                    {
                        regular[k][i][j] +=
                            regular[k - 1][i][j] + regular[k - 1][i][k] + "(" + regular[k - 1][k][k] + ")*" + regular[k - 1][k][j];
                    }
                }
            }
        }
    }

    cout << regular[dim - 1][from - 1][to - 1] << endl;

    return 0;
}

#include <boost/assign/list_of.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <chrono>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

typedef boost::adjacency_list<boost::listS, boost::vecS, boost::directedS,
                              boost::no_property, boost::property<boost::edge_weight_t, int>>
    Graph;
typedef std::pair<int, int> Edge;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

enum
{
    S,
    A,
    B,
    C,
    D,
    E,
    F,
    N
};
const std::string Names = "SABCDEF";

// グラフを作る
Graph make_graph()
{
    const std::vector<Edge> edges = boost::assign::list_of<Edge>(S, A)(S, C)(S, B)(A, C)(A, D)(B, C)(B, E)(C, F)(D, F)(E, F);

    const std::vector<int> weights = boost::assign::list_of(30)(10)(15)(25)(60)(40)(20)(35)(20)(30);

    return Graph(edges.begin(), edges.end(), weights.begin(), N);
}

int main()
{
    auto start = std::chrono::system_clock::now();
    const Graph g = make_graph();
    const Vertex from = S; // 開始地点
    const Vertex to = F;   // 目的地

    std::vector<Vertex> parents(boost::num_vertices(g));
    std::vector<std::size_t> distance(boost::num_vertices(g));

    // 最短経路を計算
    boost::dijkstra_shortest_paths(g, from,
                                   boost::predecessor_map(&parents[0]).distance_map(&distance[0]));

    // 経路なし
    if (parents[to] == to)
    {
        std::cout << "no path" << std::endl;
        return 1;
    }

    // 最短経路の頂点リストを作成
    std::deque<Vertex> route;
    for (Vertex v = to; v != from; v = parents[v])
    {
        route.push_front(v);
    }
    route.push_front(from);

    // 経路の長さを計算
    const std::size_t n = distance[to];
    std::cout << "route length:" << n << std::endl;

    // 最短経路を出力
    for (const Vertex v : route)
    {
        std::cout << Names[v] << std::endl;
    }
    auto end = std::chrono::system_clock::now(); // 計測終了時刻を保存
    auto dur = end - start;                      // 要した時間を計算
    auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    // 要した時間をミリ秒（1/1000秒）に変換して表示
    std::cout << msec << " milli sec \n";
}

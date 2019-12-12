// Graph.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"GraphAdjlist.h"
#include"GraphAdjMatrix.h"
#include<string>

using namespace std;
static constexpr int MAX_NUM_NODE = 13;
static constexpr int MAX_NUM_NODE_SHORTEST = 7;
static const int MAX_DISTANCE = 2147483647;

void init_graph(GraphAdjlist &graph)
{
	graph.add_list_node(0, "0"); graph.add_list_node(1, "1"); graph.add_list_node(2, "2"); graph.add_list_node(3, "3");
	graph.add_list_node(4, "4"); graph.add_list_node(5, "5"); graph.add_list_node(6, "6"); graph.add_list_node(7, "7");
	graph.add_list_node(8, "8"); graph.add_list_node(9, "9"); graph.add_list_node(10, "10"); graph.add_list_node(11, "11");
	graph.add_list_node(12, "12");

	graph.add_arc_node(0, 1);graph.add_arc_node(0, 2);graph.add_arc_node(0, 3);
	graph.add_arc_node(1, 4); graph.add_arc_node(1, 5);
	graph.add_arc_node(2, 6);
	graph.add_arc_node(3, 7); graph.add_arc_node(3, 8);
	graph.add_arc_node(4, 9); graph.add_arc_node(4, 10);

	graph.add_arc_node(6, 11);

	graph.add_arc_node(8, 12);
}

void init_graphShortest(GraphAdjlist& graph)
{
	graph.add_list_node(0, "A"); graph.add_list_node(1, "B"); 
	graph.add_list_node(2, "C"); graph.add_list_node(3, "D");
	graph.add_list_node(4, "E"); graph.add_list_node(5, "F"); 
	graph.add_list_node(6, "G"); 
/*  ---------------------------------------------------------------------------------------------------*/
	graph.add_arc_node(0, 1, 2); graph.add_arc_node(0, 5, 2); graph.add_arc_node(0, 6, 4);
	graph.add_arc_node(1, 2, 9); 
	graph.add_arc_node(2, 3, 4);
	graph.add_arc_node(3, 6, 6); 
	graph.add_arc_node(4, 3, 6); 
	graph.add_arc_node(5, 4, 6);
	graph.add_arc_node(6, 1, 6); graph.add_arc_node(6, 2, 2); graph.add_arc_node(6, 3, 5); graph.add_arc_node(6, 4, 7); graph.add_arc_node(6, 5, 7);
}

void DFS_BFS()
{
	GraphAdjlist graph;
	init_graph(graph);
	cout << "Hello World!\n";
	graph.print_adjlist();
	cout << "Hello World!\n\n\n";
	vector<int> visitedDFS(MAX_NUM_NODE, 0);
	vector<int> visit_orderDFS;
	graph.DFS(0, visitedDFS, visit_orderDFS);
	cout << "After DFS :";
	for (auto i = 0; i < visit_orderDFS.size(); i++)
		cout << visit_orderDFS[i] << " ";
	cout << endl;
	vector<int> visit_orderBFS;
	vector<int> visitedBFS(MAX_NUM_NODE, 0);
	graph.BFS(0, visitedBFS, visit_orderBFS);
	cout << "After BFS :";
	for (auto i = 0; i < visit_orderBFS.size(); i++)
		cout << visit_orderBFS[i] << " ";
	cout << endl;
}

void DJ()
{
	GraphAdjlist graph;
	init_graphShortest(graph);
	graph.print_adjlist(graph);
	cout << "\n" << endl;
	vector<int> visited_DJ(MAX_NUM_NODE_SHORTEST, 0);
	vector<int> distance(MAX_NUM_NODE_SHORTEST, MAX_DISTANCE);
	vector<int> visited_order;
	int start = 0;
	graph.Djikstra(0, 4, visited_DJ, distance, visited_order);
	//for (auto i = 0; i < distance.size(); i++)
		//cout << distance[i] << " ";
	//cout << endl;
}

void init_matrix(GraphAdjMatrix& graph)
{
	graph.init_adj_matrix(6);
	graph.add_node_to_matrix(0, 1, 12); graph.add_node_to_matrix(0, 5, 14);
	graph.add_node_to_matrix(1, 2, 18); graph.add_node_to_matrix(1, 4, 29);
	graph.add_node_to_matrix(2, 3, 17);

	graph.add_node_to_matrix(4, 2, -22); graph.add_node_to_matrix(4, 3, -22);
	graph.add_node_to_matrix(5, 2, -22); graph.add_node_to_matrix(5, 4, 21);
}
int main()
{
	//DFS_BFS();
	DJ();
	GraphAdjMatrix graph;
	init_matrix(graph);
	cout << "\n\n*********************************************************************************************************" << endl;
	cout << "                             Bellman-Ford" << endl;
	cout << "*********************************************************************************************************" << endl;
	graph.print_matrix();
	cout << "\n\n\n";
	graph.BellmanFord(0);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#include <iostream>
#include"GraphAdjlist.h"
#include<string>
using namespace std;
static constexpr int MAX_NUM_NODE = 13;

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
int main()
{
	GraphAdjlist graph;
	init_graph(graph);
	cout << "Hello World!\n";
	graph.print_adjlist();
    cout << "Hello World!\n";
	vector<int> visited(MAX_NUM_NODE, 0);
	vector<int> visit_order;
	return 0;
}

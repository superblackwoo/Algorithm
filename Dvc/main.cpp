#include <iostream>
#include"GraphAdjlist.h"
#include<string>
using namespace std;
static const int MAX_NUM_NODE = 13;

string list_num[MAX_NUM_NODE] = { "0","1","2","3","4","5","6","7","8","9","10","11","12" };
int main()
{
	cout << "Hello World!\n";
	GraphAdjlist graph;
	cout << "Hello World!\n";
	graph.add_list_node(1, "0");
	cout << "Hello World!\n";
	graph.add_list_node(1,"1"); graph.add_list_node(2,"2"); graph.add_list_node(3,"3");
	graph.add_list_node(4,"4"); graph.add_list_node(5,"5"); graph.add_list_node(6,"6"); graph.add_list_node(7,"7");
	graph.add_list_node(8,"8"); graph.add_list_node(9,"9"); graph.add_list_node(10,"10"); graph.add_list_node(11,"11");
	graph.add_list_node(12,"12");
    cout << "Done !\n";
    return 0;
}

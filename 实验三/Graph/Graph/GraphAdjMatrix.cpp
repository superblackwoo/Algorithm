#include<iostream>
#include"GraphAdjMatrix.h"
#include<vector>
using namespace std;
static const int WEIGHT_INDEX = 0;
static const int NODE_INDEX = 1;
static const int MAX_DISTANCE = 2147483647;

void GraphAdjMatrix::init_adj_matrix(int num_of_node)
{
	vector <int>line(num_of_node, 0);
	for (int i = 0; i < num_of_node; i++)
	{
		adj_matrix.push_back(line);
	}
}

void GraphAdjMatrix::add_node_to_matrix(int start, int end, int weight)
{
	if (start >= adj_matrix.size() || end >= adj_matrix.size())  //防止访问下标越界
		cout << "Wrong: The start or end input wrong, graph haven't that's points." << endl;
	adj_matrix[start][end] = weight;
}

void GraphAdjMatrix::print_matrix()
{
	for (auto i = 0; i < adj_matrix.size(); i++)
	{
		for (auto j = 0; j < adj_matrix[i].size(); j++)
			cout << adj_matrix[i][j] << "   ";
		cout << endl;
	}
}

void GraphAdjMatrix::BellmanFord(int start)
{
	vector<vector<int>> the_list;
	vector<string> names = {"A","B","C","D","E","F"};
	vector<int> node(2, MAX_DISTANCE);
	int  iteration = 0;
	int flag = 0;
	for (auto i = 0; i < adj_matrix.size(); i++)  //初始化“权值-边” 表
	{
		the_list.push_back(node);
	}
	if (start > the_list.size())
	{
		cout << "Can't find the start node, please input the right one" << endl;
		exit(0);
	}
	the_list[start][WEIGHT_INDEX] = 0; the_list[start][NODE_INDEX] = start;
	while (iteration < the_list.size())
	{
		for (auto i = 0; i < the_list.size(); i++)
		{
			for (auto j = 0; j < the_list.size(); j++)
			{
				if (adj_matrix[i][j] != 0 && the_list[i][WEIGHT_INDEX]< MAX_DISTANCE             //i,j之间有路径。 能从起点到i
					&& the_list[j][WEIGHT_INDEX] > the_list[i][WEIGHT_INDEX] + adj_matrix[i][j]) //
				{
					the_list[j][WEIGHT_INDEX] = adj_matrix[i][j] + the_list[i][WEIGHT_INDEX]; the_list[j][NODE_INDEX] = i;
					++flag;
				}
			}
		}
		if (flag = 0) break;
		flag = 0;
		++iteration;
	}

/*/-----------------------------------------------------------printf-----------------------------------------------------------------------------*/

	int index = 0;
	for(auto ii = 0;ii<the_list.size();ii++)
	{
		index = ii;
		cout << names[ii];
		while(the_list[index][NODE_INDEX] != start)
		{
			cout << "<-" << names[the_list[index][NODE_INDEX]];
			index = the_list[index][NODE_INDEX];
		}
		cout <<"<-"<<names[start]<<".    The shortest distance is: "<<the_list[ii][WEIGHT_INDEX]<< endl;
	}
	

	
	/*for (auto i = 0; i < the_list.size(); i++)
	{
		cout <<endl<< i << " " << the_list[i][WEIGHT_INDEX] << " " << the_list[i][NODE_INDEX] << endl;
	}*/
}
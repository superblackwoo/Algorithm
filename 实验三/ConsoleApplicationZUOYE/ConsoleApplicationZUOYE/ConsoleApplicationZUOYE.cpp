// ConsoleApplicationZUOYE.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//typedef int DATA_TYPE;  // 权值为int型

//邻接表
struct AdjTableGraph
{
	vector<vector<int> > adjTable;
	vector<vector<int> > adjWeights;  
};
void AdjTableDFS(AdjTableGraph graph, vector<int>& visited, vector<int>& visitOrder, int startNode)
{
	visited[startNode] = 1;
	visitOrder.push_back(startNode);

	if (graph.adjTable[startNode].size() > 0)
	{
		for (size_t i = 0; i < graph.adjTable[startNode].size(); ++i)
		{
			if (visited[graph.adjTable[startNode][i]] == 0)
			{
				AdjTableDFS(graph, visited, visitOrder, graph.adjTable[startNode][i]);
			}
		}
	}
}
vector<int> AdjTableBFS(AdjTableGraph graph, int startNode)
{
	int vertexNum = graph.adjTable.size();
	vector<int> visited(vertexNum, 0);
	vector<int> visitOrder;
	queue<int> trace;
	trace.push(startNode);
	visited[startNode] = 1;

	while (!trace.empty())
	{
		int currentNode = trace.front();
		trace.pop();
		visitOrder.push_back(currentNode);

		if (graph.adjTable[currentNode].size() > 0)
		{
			for (size_t i = 0; i < graph.adjTable[currentNode].size(); ++i)
			{
				if (visited[graph.adjTable[currentNode][i]] == 0)
				{
					trace.push(graph.adjTable[currentNode][i]);
					visited[graph.adjTable[currentNode][i]] = 1;
				}
			}
		}
	}

	return visitOrder;
}
vector<int> DFSBFS_next(AdjTableGraph graph, int startNode)
{
	int nodeNum = graph.adjTable.size();
	int currentNode = startNode;
	vector<int> visited (nodeNum, 0);
	vector<int> visitOrder;
	queue<int> q;
	q.push(startNode);
	visited[startNode] = 1;
	while (!q.empty()) {
		if (graph.adjTable[currentNode].size() > 0)
		{
			for (int i = 0; i < graph.adjTable[currentNode].size(); i++)
			{ //DFS
				if (visited[graph.adjTable[currentNode][i]] != 1) 
				{
					currentNode = graph.adjTable[currentNode][i];
					q.push(currentNode);
					visited[startNode] = 1;
					break;
				}
			}
		}
		else if (graph.adjTable[currentNode].size() == 0)
		{
			//currentNode = q.front();
			if (graph.adjTable[q.front()].size() == 0) 
			{

			}
			else {
				for (int i = 0; i < graph.adjTable[q.front()].size(); i++)
				{

				}
			}
		}
	}
	return visitOrder;
}
int main()
{
	AdjTableGraph graph;
	graph.adjTable.push_back(vector<int>{1, 2, 3});
	graph.adjTable.push_back(vector<int>{4, 5});
	graph.adjTable.push_back(vector<int>{6});
	graph.adjTable.push_back(vector<int>{7, 8});
	graph.adjTable.push_back(vector<int>{9, 10});
	graph.adjTable.push_back(vector<int>{});
	graph.adjTable.push_back(vector<int>{11});
	graph.adjTable.push_back(vector<int>{});
	graph.adjTable.push_back(vector<int>{12});
	graph.adjTable.push_back(vector<int>{});
	graph.adjTable.push_back(vector<int>{});
	graph.adjTable.push_back(vector<int>{});
	graph.adjTable.push_back(vector<int>{});
	vector<int> visited(graph.adjTable.size(), 0);
	vector<int> visitOrder;
	AdjTableDFS(graph, visited, visitOrder, 0);
	cout << "DFS : ";
	for (size_t i = 0; i < visitOrder.size(); ++i)
	{
		cout << visitOrder[i] << " ";
	}
	cout << endl;

	vector<int> visitOrder2 = AdjTableBFS(graph, 0);
	cout << "BFS： ";
	for (size_t i = 0; i < visitOrder2.size(); ++i)
	{
		cout << visitOrder2[i] << " ";
	}
	cout << endl;
	//cout << "1 2 4 3 6 5 7" << endl;
	cout << "0 1 3 2 5 4 6" << endl;
	std::cout << "Hello World!\n";
	int i = 2147483647;
	cout << i << endl;
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

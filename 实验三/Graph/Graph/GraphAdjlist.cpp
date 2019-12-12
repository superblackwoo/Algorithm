#include<string>
#include<stdlib.h>
#include "GraphAdjlist.h"
#include <iostream>
#include<queue>
using namespace std;
static const int MAX_NUM_NODE = 13;
static const int MAX_NUM_NODE_SHORTEST = 7;
static const int MAX_DISTANCE = 2147483647;

void GraphAdjlist::add_list_node(const int index, const string &namea) 
{
	if (index < MAX_NUM_NODE) 
	{
		list_node new_node;
		new_node.name = namea;
		new_node.first = nullptr;
		list[index] = new_node;  //列表节点存入边表
		//cout << "add_list_node done !!!" << endl;
	}
	else
		cout<<"index OVERFLOW"<<endl;
}

void GraphAdjlist::add_arc_node(int list_index, int arc_node_index) //插入边表的位置  和插入点的
{
	arc_node* new_arcnode; 
	if (!(new_arcnode = (arc_node*)malloc(sizeof(arc_node)))) 
	{
		cout << "fail to malloc" << endl;
		exit(0);
	}
	new_arcnode->adjindex = arc_node_index;
	new_arcnode->weight = 0;
	new_arcnode->next = nullptr;

	if (list[list_index].first!=nullptr) 
	{  //如果边表的first上已经有结点
		arc_node* last_arc_node;
		if (!(last_arc_node = (arc_node*)malloc(sizeof(arc_node))))
		{
			cout << "fail to malloc" << endl;
			exit(0);
		}
		last_arc_node->next = list[list_index].first; //last_arc_node指向list[list_index]
		while (last_arc_node->next != nullptr)
			last_arc_node = last_arc_node->next;  //找到最小的结点为止
		last_arc_node->next = new_arcnode;
	}
	else {
		list[list_index].first = new_arcnode;
	}
}

void GraphAdjlist::add_arc_node(int list_index, int arc_node_index, int weight)
{
	arc_node* new_arcnode;
	if (!(new_arcnode = (arc_node*)malloc(sizeof(arc_node))))
	{
		cout << "fail to malloc" << endl;
		exit(0);
	}
	new_arcnode->adjindex = arc_node_index;
	new_arcnode->weight = weight;
	new_arcnode->next = nullptr;

	if (list[list_index].first != nullptr)
	{  //如果边表的first上已经有结点
		arc_node* last_arc_node;
		if (!(last_arc_node = (arc_node*)malloc(sizeof(arc_node))))
		{
			cout << "fail to malloc" << endl;
			exit(0);
		}
		last_arc_node->next = list[list_index].first; //last_arc_node指向list[list_index]
		while (last_arc_node->next != nullptr)
			last_arc_node = last_arc_node->next;  //找到最后的结点为止
		last_arc_node->next = new_arcnode;
	}
	else {
		list[list_index].first = new_arcnode;
	}
}

void GraphAdjlist::print_adjlist( )
{
	int i;
	for (i = 0; i < MAX_NUM_NODE; i++) {
		if (list[i].first != nullptr) {
			cout << list[i].name << "-> " ;
			arc_node* temp = list[i].first;
			cout << temp->adjindex << "-> ";
			while (temp->next != nullptr) {
				temp = temp->next;  //遍历与list[i]相连的所有节点
				cout << temp->adjindex << "-> ";
			}
			cout << "nullptr" << endl;
			
		}
		else
			cout << list[i].name << "-> nullptr" << endl;
	}
}

void GraphAdjlist::print_adjlist(GraphAdjlist graph)  //graph 2
{
	int i;
	for (i = 0; i < MAX_NUM_NODE_SHORTEST; i++) {
		if (list[i].first != nullptr) {
			cout << list[i].name << "-> ";
			arc_node* temp = list[i].first;
			cout << "(" << list[temp->adjindex].name << "," << temp->weight << ")" << "-> ";
			while (temp->next != nullptr) {
				temp = temp->next;  //遍历与list[i]相连的所有节点
				cout << "(" << list[temp->adjindex].name << "," << temp->weight << ")" << "-> ";
			}
			cout << "nullptr" << endl;

		}
		else
			cout << list[i].name << "-> nullptr" << endl;
	}
}

void GraphAdjlist::DFS(int start, vector <int> &visited, vector<int> &order)
{
	arc_node* last_arc_node;
	if (!(last_arc_node = (arc_node*)malloc(sizeof(arc_node))))
	{
		cout << "fail to malloc" << endl;
		exit(0);
	}
	last_arc_node->next = list[start].first;
	visited[start] = 1;
	order.push_back(start);
	//cout << "正在访问节点:  " << start << endl;

	while (last_arc_node->next != nullptr)
	{
		//cout << "正在while  " << endl;
		DFS(last_arc_node->next->adjindex, visited, order);
		//cout << "正在递归调用DFS  " << endl;
		last_arc_node = last_arc_node->next;
	}
}

void GraphAdjlist::BFS(int start, vector <int>& visited, vector<int>& order)
{
	queue<int> q;
	arc_node* now_arc_node;
	if (!(now_arc_node = (arc_node*)malloc(sizeof(arc_node))))
	{
		cout << "fail to malloc" << endl;
		exit(0);
	}
	visited[start] = 1;
	order.push_back(start);
	q.push(start);  //起始点入队
	while (!q.empty())
	{
		now_arc_node->next = list[q.front()].first;  //指向队首结点的*first
		while (now_arc_node->next != nullptr)
		{
			visited[now_arc_node->next->adjindex] = 1;
			order.push_back(now_arc_node->next->adjindex);
			q.push(now_arc_node->next->adjindex);
			now_arc_node = now_arc_node->next; //指向下一个结点
		}
		//if (last_arc_node->next == nullptr)
			q.pop();
	}
}

void GraphAdjlist::Djikstra(int start, int end,vector<int>& visited_DJ, vector<int>& distance, vector<int>&visited_order)
{
	vector<int> path(MAX_NUM_NODE_SHORTEST,222);
	arc_node* now_arc_node;
	int remain_node = MAX_NUM_NODE_SHORTEST;
	int shor_distannce_u = MAX_DISTANCE, shor_distannce_x = MAX_DISTANCE;
	int shor_node_u, shor_node_x;
	int path_index;
	if (!(now_arc_node = (arc_node*)malloc(sizeof(arc_node))))
	{
		cout << "fail to malloc" << endl;
		exit(0);
	}
	visited_DJ[start] = 1;
	visited_order.push_back(start);
	now_arc_node->next = list[start].first;

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/

		//now_arc_node->next = list[start].first;  //指向队首结点的*first
	for (; now_arc_node->next != nullptr; now_arc_node = now_arc_node->next)  //初始化与原点所有相连的点
	{
		distance[now_arc_node->next->adjindex] = now_arc_node->next->weight;
		path[now_arc_node->next->adjindex] = 0;  //标记路径
		if (now_arc_node->next->weight < shor_distannce_u)
		{
			shor_distannce_u = now_arc_node->next->weight;
			shor_node_u = now_arc_node->next->adjindex;   //选好最近的个结点  shor_node_u
		}
	}
	if (shor_node_u == end) exit(0);
	visited_DJ[shor_node_u] = 1;
	visited_order.push_back(shor_node_u);
	--remain_node;
	now_arc_node->next = list[shor_node_u].first;
	shor_node_x = shor_node_u;//方便迭代
		while(remain_node>1){
			for (; now_arc_node->next != nullptr; now_arc_node = now_arc_node->next)
			{
				//cout << "now_arc_node->next->adjindex:  " << now_arc_node->next->adjindex << endl;  //下面一行有错distance[now_arc_node->adjindex]
				if (distance[now_arc_node->next->adjindex] > distance[shor_node_x] + now_arc_node->next->weight)
				{
					distance[now_arc_node->next->adjindex] = distance[shor_node_x] + now_arc_node->next->weight;
					path[now_arc_node->next->adjindex] = shor_node_x;
				}
			}
			for (int j = 0; j < distance.size(); j++) //找下一个距离最短的白点
			{
				if (visited_DJ[j] == 0 && distance[j] < shor_distannce_x)
				{
					shor_distannce_x = distance[j];
					shor_node_x = j;
				}
			}
			shor_distannce_x = MAX_DISTANCE;
			visited_DJ[shor_node_x] = 1;
			visited_order.push_back(shor_node_x);
			--remain_node;
			now_arc_node->next = list[shor_node_x].first;
			for (auto i = 0; i < distance.size(); i++)
				cout << distance[i] << " ";
			for (auto i = 0; i < visited_order.size(); i++)
				cout << "\n  ********  "<<visited_order[i] << " ";
		
			cout << "\n\n\n"<<endl;
		}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/
	
		cout << "The shortest paths from " << list[start].name << " to " << list[end].name << " is:  " <<endl;
		cout << list[start].name;
		path_index = path[end];
		while (path_index != start)
		{
			cout << "->" << list[path_index].name;
			path_index = path[path_index];
		}
		cout << "->" << list[end].name << ".\nThe shortest distance is  "<<distance[end]<<endl;

}

/*void GraphAdjlist::DFS(int start)
{
	//int temp = start;
	if (start < MAX_NUM_NODE) { //限制非法访问
		vector <int> visit_stack(MAX_NUM_NODE, 0);
		int top = 0;
		vector<int> visited(MAX_NUM_NODE, 0);// 标记访问过的节点
		list_node* temp_l = &list[start];
		arc_node* temp_a = temp_l->first;
		visit_stack[top++] = start;
		visited[start] = 1;
		cout << start << " " << endl;
		while (top != 0) {
			if (temp_l->first != nullptr ) {
				while (visited[temp_a->adjindex] == 1)
					temp_a = temp_a->next;
				if (temp_a == nullptr) {
					top--;
					temp_l = &list[top - 1];
				}
				//templ = &list[templ->first->adjindex];
				else {
					visit_stack[top++] = temp_a->adjindex;  //存入访问栈
					visited[temp_a->adjindex] = 1;  //标记已访问
					temp_l = &list[temp_l->first->adjindex];
				}
			}
			else if (temp_l->first == nullptr) 
			{
				/*指向前一个点
				*  此时栈顶为最后一个元素+1.所以上一个节点的栈标为[top-2]
				
				top--;
				temp_l = &list[visit_stack[top - 1]];//指向前一个点，此时栈顶为自己+1所以top-2
				if (temp_a->next != nullptr && visited[temp_a->adjindex] == 0) {  //temp_a是链表第一个元素
					visit_stack[top++] = temp_a->adjindex;   //链表中的节点的next非空，且未被访问这入访问栈
					visited[temp_a->adjindex] = 1;
					temp_l = &list[temp_a->adjindex];
					temp_a = temp_a->next;  //指向链表下一个节点
				}
				else if(temp_a->next == nullptr){
					top--;
					top--;
					temp_l = &list[visit_stack[top - 1]];

				}

			}
		}
	}
	else {
		cout << "can't find the start node in DFS";
		exit(0);
	}
}*/
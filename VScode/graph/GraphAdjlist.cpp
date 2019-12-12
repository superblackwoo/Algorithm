#include<string>
#include<stdlib.h>
#include "GraphAdjlist.h"
#include <iostream>
using namespace std;

void GraphAdjlist::add_list_node(const int index, const string &namea) 
{
	if (index < MAX_NUM_NODE) {
		list_node new_node;
		new_node.name = namea;
		new_node.first = nullptr;
		list[index] = new_node;  //列表节点存入边表
		//cout << "add_list_node done !!!" << endl;
	}
	else
		cout<<"index OVERFLOW"<<endl;
}

void GraphAdjlist::add_arc_node(int list_index, int arc_node_index) 
{
	arc_node* new_arcnode, * last_arc_node;
	if (!(new_arcnode = (arc_node*)malloc(sizeof(arc_node)))) {
		cout << "fail to malloc" << endl;
		exit(0);
	}
	if (!(last_arc_node = (arc_node*)malloc(sizeof(arc_node)))) {
		cout << "fail to malloc" << endl;
		exit(0);
	}
	new_arcnode->adjindex = arc_node_index;
	new_arcnode->weight = 0;
	new_arcnode->next = nullptr;
	//f = list[list_index].first;
	if (list[list_index].first!=nullptr) {  //如果边表的first上已经有结点
		last_arc_node->next = list[list_index].first; //last_arc_node指向list[list_index]
		while (last_arc_node->next != nullptr)
			last_arc_node = last_arc_node->next;  //找到最小的结点为止
		last_arc_node->next = new_arcnode;
	}
	else {
		list[list_index].first = new_arcnode;
	}
}

void GraphAdjlist::print_adjlist()
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
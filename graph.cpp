#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<forward_list>
#include<queue>

//普适性较高的图结构
//图中的结点
class Node {
public:
	//结点值
	int value;
	//入度
	int in;
	//出度
	int out;
	//存放直接相连的结点
	std::vector<Node> nexts;
	//存放属于当前结点的边
	std::vector<Edge> edges;
	Node(int _value = 0) {
		this->value = _value;
		this->in = 0;
		this->out = 0;
		nexts = std::vector<Node>();
		edges = std::vector<Edge>();
	}
};
//图中的每一条边
class Edge {
public:
	//权值
	int weight;
	//边的起始
	Node from;
	Node to;
	Edge(int _weight, Node _from, Node _to) : weight(_weight), from(_from), to(_to) {}
};

class Graph {
public:
	//图中的点（int为几号结点）
	std::unordered_map<int, Node> nodes;
	//该图中的所有的边集
	std::unordered_set<Edge> edges;

	Graph() {
		nodes = std::unordered_map<int, Node>();
		edges = std::unordered_set<Edge>();
	}
};


class SolutionOfDfsBfs {
public:
	//本质即一条路一直走到底，当路不通了再依次返回之前走过的结点康康是否有新的路
	void dfs_graph(Node node) {
		//用于进行dfs的栈
		std::stack<Node> sNode;
		//用于记录处理过的结点（防止环中死循环）
		std::unordered_set<Node> hashRecord;
		//先将第一个结点放入栈中，并在set中进行记录
		sNode.push(node);
		hashRecord.emplace(node);
		//入栈后直接进行相应的处理
		std::cout << node.value << " " << std::endl;
		while (!sNode.empty()) {
			//取出栈顶元素
			Node cur = sNode.top();
			sNode.pop();
			//遍历找到第一个未在set中记录的结点
			for (auto& next : cur.nexts) {
				if (!hashRecord.contains(next)) {
					//当找到了一个nextNode则先将当前结点入栈
					//该栈始终保存的是当前遍历所走过的路径（这样才能够进行回溯）
					sNode.push(cur);
					//再将next结点入栈，并在set中添加记录
					sNode.push(next);
					hashRecord.emplace(next);
					//入栈后直接进行处理即可
					std::cout << next.value << " " << std::endl;
					break;
				}
			}
		}
	}
	//每次都是将一个结点中未被记录的所有nexts（邻居结点）放入队列中
	//依次都是先处理完一个结点的所有nexts才进行下一个结点的nexts
	void bfs_solution(Node node) {
		//用于进行bfs的队列
		std::queue<Node> bfsNode;
		//用于记录处理过的结点（防止环中死循环）
		std::unordered_set<Node> findNode;
		//先将第一个结点放入队列中，并在set中进行记录
		bfsNode.push(node);
		findNode.insert(node);
		while (!bfsNode.empty()) {
			//取出队首的结点
			Node cur = bfsNode.front();
			bfsNode.pop();
			//取出结点直接处理
			std::cout << cur.value << std::endl;
			//将当前处理结点的nexts遍历一遍，如果有未被记录过的则直接入队列并在set中进行记录
			for (auto next : cur.nexts) {
				if (!findNode.contains(cur)) {
					bfsNode.push(next);
					findNode.insert(next);
				}
			}
		}
	}
};

//namespace std {//需要为标准库的空间中的hash提供散列函数
//	template<>//空模板实例
//	struct hash<Node> {//散列自定义的类型
//		size_t operator()(const Node& key) {//通过size_t的大小进行散列
//			return  hash<int>()(key.value);//类似于调用了内置模板类的实例化匿名对象的伪函数，指定了该如何散列该类型
//			tips（key一般都要特定化，确保key值唯一）
//		}
//	};
//}

//简称K算法
class Kruskal {
public:
	class MySets {
	public:
		//记录结点以及结点所属的集合
		std::unordered_map < Node, std::forward_list<Node>> setMap;
		//将所有的结点都在setMap进行记录，进行初始化
		MySets(std::forward_list<Node> nodes) {
			for (auto& cur : nodes) {
				std::forward_list<Node>set = std::move(std::forward_list<Node>());
				//每个结点初始时，其对应的集合里只有自己一个结点
				set.push_front(cur);
				//插入map中进行记录
				setMap.emplace(std::move(cur),std::move(set));
			}
		}
		//判断一条边的两个节点是否为同一个集合
		bool isSameSet(Node from, Node to) {
			//首先分别取出该边的起始结点在map中记录的集合
			auto fromSet = setMap.at(from);
			auto toSet = setMap.at(to);
			//判断该两个集合是否为同一个集合
			return fromSet == toSet;
		}
		//合并两个集合（如果一条边的两个节点不是一个集合，则将该两个节点所属集合进行合并
		//合并后的集合也同时更新到toNode在map中的记录
		void union_list(Node from, Node to) {
			auto fromSet = setMap.at(from);
			auto toSet = setMap.at(to);
			for (auto toNode : toSet) {
				fromSet.push_front(toNode);
				setMap.insert(std::make_pair(toNode, fromSet));
			}
		}
	};
};



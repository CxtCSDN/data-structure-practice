#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<forward_list>
class Node {
public:
	int value;
	int in;
	int out;
	std::vector<Node> nexts;
	std::vector<Edge> edges;

	Node(int _value = 0) {
		this->value = _value;
		this->in = 0;
		this->out = 0;
		nexts = std::vector<Node>();
		edges = std::vector<Edge>();
	}
};

class Edge {
public:
	int weight;
	Node from;
	Node to;
	Edge(int _weight, Node _from, Node _to) : weight(_weight), from(_from), to(_to) {}
};

class Graph {
public:
	std::unordered_map<int, Node> nodes;
	std::unordered_set<Edge> edges;

	Graph() {
		nodes = std::unordered_map<int, Node>();
		edges = std::unordered_set<Edge>();
	}
};


class Solution {
public:
	void dfs_graph(Node node) {
		std::stack<Node> sNode;
		std::unordered_set<Node> hashRecord;
		sNode.push(node);
		hashRecord.emplace(node);
		std::cout << node.value << " " << std::endl;
		while (!sNode.empty()) {
			Node cur = sNode.top();
			sNode.pop();
			for (auto& next : cur.nexts) {
				if (!hashRecord.contains(next)) {
					sNode.push(cur);
					sNode.push(next);
					hashRecord.emplace(next);
					std::cout << next.value << " " << std::endl;
					break;
				}
			}
		}
	}
};
namespace std {//需要为标准库的空间中的hash提供散列函数
	template<>//空模板实例
	struct hash<Node> {//散列自定义的类型
		size_t operator()(const Node& key) {//通过size_t的大小进行散列
			return  hash<int>()(key.value);//类似于调用了内置模板类的实例化匿名对象的伪函数，指定了该如何散列该类型
			//tips（key一般都要特定化，确保key值唯一）
		}
	};
}
class Kruskal {
public:
	class MySets {
	public:
		std::unordered_map < Node, std::forward_list<Node>> setMap;
		MySets(std::forward_list<Node> nodes) {
			for (auto& cur : nodes) {
				std::forward_list<Node>set = std::move(std::forward_list<Node>());
				set.push_front(cur);
				setMap.emplace(std::move(cur),std::move(set));
			}
		}
		bool isSameSet(Node from, Node to) {
			auto fromSet = setMap.find(from);
			auto toSet = setMap.find(to);
			return fromSet == toSet;
		}
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

int main()
{

	return 0;
}

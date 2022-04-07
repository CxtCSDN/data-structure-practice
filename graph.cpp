#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<forward_list>
#include<queue>

//�����Խϸߵ�ͼ�ṹ
//ͼ�еĽ��
class Node {
public:
	//���ֵ
	int value;
	//���
	int in;
	//����
	int out;
	//���ֱ�������Ľ��
	std::vector<Node> nexts;
	//������ڵ�ǰ���ı�
	std::vector<Edge> edges;
	Node(int _value = 0) {
		this->value = _value;
		this->in = 0;
		this->out = 0;
		nexts = std::vector<Node>();
		edges = std::vector<Edge>();
	}
};
//ͼ�е�ÿһ����
class Edge {
public:
	//Ȩֵ
	int weight;
	//�ߵ���ʼ
	Node from;
	Node to;
	Edge(int _weight, Node _from, Node _to) : weight(_weight), from(_from), to(_to) {}
};

class Graph {
public:
	//ͼ�еĵ㣨intΪ���Ž�㣩
	std::unordered_map<int, Node> nodes;
	//��ͼ�е����еı߼�
	std::unordered_set<Edge> edges;

	Graph() {
		nodes = std::unordered_map<int, Node>();
		edges = std::unordered_set<Edge>();
	}
};


class SolutionOfDfsBfs {
public:
	//���ʼ�һ��·һֱ�ߵ��ף���·��ͨ�������η���֮ǰ�߹��Ľ�㿵���Ƿ����µ�·
	void dfs_graph(Node node) {
		//���ڽ���dfs��ջ
		std::stack<Node> sNode;
		//���ڼ�¼������Ľ�㣨��ֹ������ѭ����
		std::unordered_set<Node> hashRecord;
		//�Ƚ���һ��������ջ�У�����set�н��м�¼
		sNode.push(node);
		hashRecord.emplace(node);
		//��ջ��ֱ�ӽ�����Ӧ�Ĵ���
		std::cout << node.value << " " << std::endl;
		while (!sNode.empty()) {
			//ȡ��ջ��Ԫ��
			Node cur = sNode.top();
			sNode.pop();
			//�����ҵ���һ��δ��set�м�¼�Ľ��
			for (auto& next : cur.nexts) {
				if (!hashRecord.contains(next)) {
					//���ҵ���һ��nextNode���Ƚ���ǰ�����ջ
					//��ջʼ�ձ�����ǵ�ǰ�������߹���·�����������ܹ����л��ݣ�
					sNode.push(cur);
					//�ٽ�next�����ջ������set����Ӽ�¼
					sNode.push(next);
					hashRecord.emplace(next);
					//��ջ��ֱ�ӽ��д�����
					std::cout << next.value << " " << std::endl;
					break;
				}
			}
		}
	}
	//ÿ�ζ��ǽ�һ�������δ����¼������nexts���ھӽ�㣩���������
	//���ζ����ȴ�����һ����������nexts�Ž�����һ������nexts
	void bfs_solution(Node node) {
		//���ڽ���bfs�Ķ���
		std::queue<Node> bfsNode;
		//���ڼ�¼������Ľ�㣨��ֹ������ѭ����
		std::unordered_set<Node> findNode;
		//�Ƚ���һ������������У�����set�н��м�¼
		bfsNode.push(node);
		findNode.insert(node);
		while (!bfsNode.empty()) {
			//ȡ�����׵Ľ��
			Node cur = bfsNode.front();
			bfsNode.pop();
			//ȡ�����ֱ�Ӵ���
			std::cout << cur.value << std::endl;
			//����ǰ�������nexts����һ�飬�����δ����¼������ֱ������в���set�н��м�¼
			for (auto next : cur.nexts) {
				if (!findNode.contains(cur)) {
					bfsNode.push(next);
					findNode.insert(next);
				}
			}
		}
	}
};

//namespace std {//��ҪΪ��׼��Ŀռ��е�hash�ṩɢ�к���
//	template<>//��ģ��ʵ��
//	struct hash<Node> {//ɢ���Զ��������
//		size_t operator()(const Node& key) {//ͨ��size_t�Ĵ�С����ɢ��
//			return  hash<int>()(key.value);//�����ڵ���������ģ�����ʵ�������������α������ָ���˸����ɢ�и�����
//			tips��keyһ�㶼Ҫ�ض�����ȷ��keyֵΨһ��
//		}
//	};
//}

//���K�㷨
class Kruskal {
public:
	class MySets {
	public:
		//��¼����Լ���������ļ���
		std::unordered_map < Node, std::forward_list<Node>> setMap;
		//�����еĽ�㶼��setMap���м�¼�����г�ʼ��
		MySets(std::forward_list<Node> nodes) {
			for (auto& cur : nodes) {
				std::forward_list<Node>set = std::move(std::forward_list<Node>());
				//ÿ������ʼʱ�����Ӧ�ļ�����ֻ���Լ�һ�����
				set.push_front(cur);
				//����map�н��м�¼
				setMap.emplace(std::move(cur),std::move(set));
			}
		}
		//�ж�һ���ߵ������ڵ��Ƿ�Ϊͬһ������
		bool isSameSet(Node from, Node to) {
			//���ȷֱ�ȡ���ñߵ���ʼ�����map�м�¼�ļ���
			auto fromSet = setMap.at(from);
			auto toSet = setMap.at(to);
			//�жϸ����������Ƿ�Ϊͬһ������
			return fromSet == toSet;
		}
		//�ϲ��������ϣ����һ���ߵ������ڵ㲻��һ�����ϣ��򽫸������ڵ��������Ͻ��кϲ�
		//�ϲ���ļ���Ҳͬʱ���µ�toNode��map�еļ�¼
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



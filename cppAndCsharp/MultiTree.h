#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

template<typename T>
class MultiTree {
	//��������� �����
	struct Node {
		T info;
		//������� ������ �� �������� �����
		vector <Node *> vectPoint;
		Node(T info) {
			this->info = info;
		}
	};
	Node *main_root = NULL;
public:
	MultiTree();
	void printWidth();
	void printDepth();
private:
	void Write_R(Node *root);
	void printDepth_R(Node *root);
};

//����������� ������
template<typename T>
MultiTree<T>::MultiTree() {
	cout << "Write the main root info field:\t";
	T a;
	cin >> a;
	cin.ignore();
	main_root = new Node(a);
	Write_R(main_root);
}

template<typename T>
void MultiTree<T>::Write_R(Node *root) {
	int n;// ���-�� ��������
	T num; // �������� ������ � ����-����
	int answ; // ���������� ��� ������� �� ����������� ���������� ���������
	cout << "How many subtrees you want? ";
	cin >> n;
	cin.ignore();
	for (int j = 0; j < n; j++) {
		cout << "Write number: ";
		cin >> num;
		root->vectPoint.push_back(new Node(num));
		cout << "Do you want to continue to enter a new subtree??\nWrite 1,if YES,and 0,if NO: ";
		cin >> answ;
		// ���� �������� 0,�� ���� "�����" ��������� �������� � ������������� �� ���������� ������ �����
		if (answ == 0)
			cout << "Subtree is end" << endl;
		// ����� ���������� �������� ���� ������ ��������� 
		else
			Write_R(root->vectPoint[j]);
	}
}

//������ ��������� � ������� � �������
template<typename T>
void MultiTree<T>::printDepth() {
	printDepth_R(main_root);
	cout << endl;
}

// ����������� ����� ������ � ������� 
template<typename T>
void MultiTree<T>::printDepth_R(Node *root) {
	int len = root->vectPoint.size();
	if (len != 0) {
		// ��������� �������� �� ��������� ������� ����������
		for (int i = 0; i < len; i++)
			printDepth_R(root->vectPoint[i]);
	}
	cout << root->info << " ";
}

//������ ��������� � ������� � ������
template<typename T>
void MultiTree<T>::printWidth() {
	cout << main_root->info << " ";
	queue <Node *> Width;
	// ����� ������
	Width.push(main_root);
	int len;
	while (!Width.empty()) {
		len = Width.front()->vectPoint.size();
		// ��������� ������� ��������
		if (len != 0) {
			// ���� ��� ����,�� ���������� �� � ����� � �������
			for (int i = 0; i < len; i++) {
				cout << Width.front()->vectPoint[i]->info << " ";
				Width.push(Width.front()->vectPoint[i]);
			}
		}
		// ����������� � ������ ����
		Width.pop();
	}
	cout << endl;
}

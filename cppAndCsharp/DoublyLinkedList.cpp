#include <iostream>
using namespace std;

//���������� ������
class list {
	struct Node {
		int info;//���.����
		Node *next;//��������� �� ��������� �������
		Node *last;//��������� �� ���������� �������
		//�����������
		Node(int a, Node *next = NULL,Node *last = NULL) {
			info = a;
			this->next = next;
			this->last = last;
		}
	};
	Node *head = NULL;//��������� �� ������ ������
	Node *tail = NULL;//��������� �� ����� ������
public:
	~list();
	void Add(int a, int i);
	void AddBeg(int a);
	void AddEnd(int a);
	void Remove(int i);
	int Get(int i);
	friend ostream& operator<<(ostream& str, list& list);
	friend istream& operator>>(istream& str, list& list);
	int operator[](int i);
	void ReverseList();
};

//����������
list:: ~list() {
	while (head != NULL) {
		Remove(0);
	}
}

//����� ���������� �� �������
void list::Add(int a, int i) {
	//������� ������ �������
	if (i == 0) {
		head = new Node(a, head);
		if (head->next != NULL) {
			head->next->last = head;
		}
		return;
	}
	//������
	if (i < 0) {
		cout << "[ERROR]";
		return;
	}
	Node *current = head;
	for (int j = 0; current != NULL && j != i - 1; j++, current = current->next);//������ �� ������
	if (current != NULL) {
		current->next = new Node(a, current->next,current);
		if (current->next->next == NULL)
			tail = current->next;
		else
			current->next->next->last = current->next;
	}
}

//����� ���������� � ������
void list::AddBeg(int a) {
	Add(a, 0);
}

//����� ���������� � �����
void list::AddEnd(int a) {
	if (head == NULL) {
		head = new Node(a, head);
		tail = head;
	}
	else {
		Node *current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new Node(a, current->next, current);
		tail = current->next;
	}
}

//����� ��������
void list::Remove(int i) {
	//������
	if (head == NULL || i < 0) {
		cout << "[ERROR]";
		return;
	}
	//������� ������
	if (i == 0) {
		Node *p = head;
		head = p->next;
		if (head != NULL) {
			head->last = NULL;
		} else {
			tail = head;
		}
		delete p;
		return;
	}
	Node *current = head;
	for (int j = 0; current->next != NULL && j != i - 1; j++, current = current->next);
	//�������� �� �������������
	if (current->next != NULL) {
		Node *p = current->next;
		current->next = p->next;
		p->next->last = current;
		delete p;
	}
}

//����� ��������� �������� ������ �� �������
int list::Get(int i) {
	Node *current = head;
	for (int j = 0; current != NULL && j != i - 1; j++, current = current->next);
	if (current != NULL) {
		return current->info;
	}
}

int list::operator[](int i) {
	return Get(i);
}

//���������� ��������� <<
ostream& operator<<(ostream& str, list& list) {
	//���� ������ ������ ����,�� ������ ����
	if (list.head == NULL) {
		str << "List is empty" << endl;
		return str;
	}
	else {
		for (list::Node *current = list.head; current != NULL; current = current->next) {
			str << current->info << " ";
		}
		return str;
	}
}

//���������� ��������� >>
istream& operator>>(istream& str, list& list) {
	int n, a;
	str >> n;
	for (int i = 0; i < n; i++) {
		str >> a;
		list.AddEnd(a);
	}
	return str;
}

//����� ���������� ������
void list::ReverseList() {
	Node *current = head, *temp = NULL;
	while (current != NULL) {
		temp = current->last;
		current->last = current->next;
		current->next = temp;
		current = current->last;
	}
	if (temp!=NULL)
		head = temp->last;
}

int main() {
		list one;
		cin >> one;
		//one.ReverseList();
		cout << one << endl;
		one.Add(55, 3);
		cout << one << endl;
		one.AddBeg(66);
		cout << one << endl;
		one.Remove(3);
		cout << one << endl;
		one.AddEnd(44);
		cout << one << endl;
		one.ReverseList();
		cout << one << endl;
		cout << one[3] << endl;
		cout << one << endl;
	system("pause");
	return 0;
}
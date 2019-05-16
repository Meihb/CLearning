#include <iostream>
using namespace std;
typedef int ElemType;
typedef int Status;
#define FALL 0
#define OK 1
#define MAX_SIZE 100
 // ��̬�ĵ�һ������curָ���������е�һ�������±꣬
// ���һ�����Ҳ������lits��MAX_SIZE-1����cruָ���һ��������������±�
struct Mystruct
{
	ElemType data;
	int cur;
};
typedef Mystruct ListNode;
class StaticLinkList{
private:
	ListNode list[MAX_SIZE];
public:
	void InitList();// ��ʼ����̬����
	int GetNode(int i);// ��ȡ��i��Ԫ�ص��±�
	Status DeleteNode(int i); // ɾ����i��Ԫ��
	Status InsertNode(int i, ElemType e); // �ڵ�i�����ǰ���һ��Ԫ��
	int Malloc();  // ����ռ䣬���ر��������һ�������±�
	void Free(int  index); // ���±�Ϊindex�Ľڵ����������������
	int GetLength(); // ���ؾ�̬�����к��������������
	void printList(); // ��ӡ����

};
void StaticLinkList::InitList()
{
	for (int i = 0; i < MAX_SIZE - 1; i++)
	{
		list[i].cur = i + 1;
	}
	list[MAX_SIZE-1].cur = 0;
}
int StaticLinkList::GetNode(int i)
{
	int index = MAX_SIZE - 1;
	for (int j = 1; j<= i ; j++)
	{
		index = list[index].cur;
	}
	return index;
}
int StaticLinkList::GetLength()
{
	int cnt = 0;

	int index = list[MAX_SIZE - 1].cur;
	while (index!=0)
	{
		index = list[index].cur;
		cnt++;
	}
	return cnt;
}
int StaticLinkList::Malloc()
{
	int index = list[0].cur;
	if (index)
	{
		list[0].cur = list[index].cur;
	}
	return index;
}
void StaticLinkList::Free(int index)
{
	list[index].cur = list[0].cur;
	list[0].cur = index;
}
Status StaticLinkList::DeleteNode(int i)
{
	if (i<0 || i>GetLength())
		return FALL;
	int index = GetNode(i - 1);
	int j = list[index].cur;
	list[index].cur = list[j].cur;
	Free(j);
	return OK;
}
Status StaticLinkList::InsertNode(int i, ElemType e)
{
	if (i<1 || i>GetLength()+1)
		return FALL;
	else
	{
			int index = GetNode(i - 1);
			int j = Malloc();
			 list[j].data=e;
			list[j].cur = list[index].cur;
			list[index].cur = j;
			return OK;
	}

}
void StaticLinkList::printList()
{
	int index_start = list[MAX_SIZE - 1].cur;
	int index_end = list[0].cur;
	for (int i = index_start; i < index_end; i++)
	{
		cout << list[i].data << " ";
	}
}
int main()
{
	StaticLinkList list;
	int data = 1;
	list.InitList();
	list.InsertNode(1, data);
	cout << "��������������\n";
	list.printList();
}

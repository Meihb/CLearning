#include <iostream>
using namespace std;
typedef int ElemType;
typedef int Status;
#define FALL 0
#define OK 1
#define MAX_SIZE 100
 // 静态的第一个结点的cur指向备孕链表中第一个结点的下标，
// 最后一个结点也，就是lits【MAX_SIZE-1】的cru指向第一个存有数据项的下标
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
	void InitList();// 初始化静态链表
	int GetNode(int i);// 获取第i个元素的下标
	Status DeleteNode(int i); // 删除第i个元素
	Status InsertNode(int i, ElemType e); // 在第i个结点前添加一个元素
	int Malloc();  // 申请空间，返回备用链表第一个结点的下标
	void Free(int  index); // 将下标为index的节点添加至备用链表中
	int GetLength(); // 返回静态链表中含有数据项的项数
	void printList(); // 打印链表

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
	cout << "链表中数据如下\n";
	list.printList();
}

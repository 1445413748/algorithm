#include<iostream>
#include<cstdio>
using namespace std;
template<class T> 
class linkNode{
public:
	linkNode();
	~linkNode();
	T data;
	linkNode<T> *next;
};
template<class T>
linkNode<T>::linkNode()
{
}
template<class T>
linkNode<T>::~linkNode()
{
}
template<class T>
class linklist{
public:
	linklist();
	~linklist();
protected:
	linkNode<T> *head;
public:
	linklist(T *a,long count);
	bool insert(long positiob,T newData);
	bool Delete(long position,T &deleteData);
	bool getData(long position,T &data);
	bool updata(long position,T newData);
	bool search(T Data,long &position);
	long count();  
	void print();
	linkNode<T> *gethead();
	bool invert();   //逆置单链表 
};
template<class T>
linklist<T>::linklist()
{
	head=new linkNode<T>;
	if(head==NULL){
		cerr<<"分配内存失败.\n";
		exit(1);
	}
	head->next=NULL;
 } 
 template<class T>
 linklist<T>::~linklist()
 {
	linkNode<T> *deleteNode,*current=head;
	while(current)
	{
		deleteNode=current;
		current=current->next;
		delete deleteNode;
	 }
	 head=NULL;
 }
 template<class T>
bool linklist<T>::getData(long position,T &data)
 {
	if(position<1)
	return false;
	linkNode<T> *current=head->next;
	int count=1;
	while(current && count<position)
	{
		current=current->next;
		count++;
	 }
	 if(current)
	 {
		data=current->data;
		return true;
	 }
	 else
	 {
		cout<<"未找到第"<<position<<"个元素.\n";
	 return false;
	}
 }
 template<class T>
bool  linklist<T>::updata(long position,T newData)
 {
	if(position<1)
	return false;
	linkNode<T> *current=head->next;
	int count=1;
	while(current && count<position)
	{
		current=current->next;
		count++;
	 }
	 if(current)
	 {
		current->data=newData;
		return true;
	 }
	 else
	 {
		cout<<"未找到第"<<position<<"个元素.\n";
	 return false;
}
 }
 template<class T>
bool linklist<T>::search(T Data,long &position)
 {
	linkNode<T> *current=head->next;
	position=1;
	while(current && current->data!=Data)
	{
		current=current->next;
		position++;
	 }
	 if(current)
	 {
		return true;
	 }
	 else
	 return false;
 }
 template<class T>
 bool linklist<T>::insert(long position,T newData)
 {
	linkNode<T> *current=head;
	int currentposition=0;
	while(current && currentposition<position-1)
	{
		current=current->next;
		currentposition++;
	 }
	 if(current)
	 {
		linkNode<T> *newNode=new linkNode<T>;
		if(newNode==NULL)
		{
			cerr<<"分配内存失败.\n";
			return false;
		 }
		 else
		 {
			newNode->data=newData;
			newNode->next=current->next;
			current->next=newNode;
			return true;
		 }
	 }
	 else
	 return false;
 }
template<class T>
bool linklist<T>::Delete(long position,T &deleteData)
{
	linkNode<T> *current=head;
	int currentposition=0;
	while(current && currentposition<position-1)
	{
		current=current->next;
		currentposition++;
	}
	if(current && current->next)
	{
		linkNode<T> *deleteNode=current->next;
		deleteData=deleteNode->data;
		current->next=deleteNode->next;
		delete deleteNode;
		return true;
	}
	else
	return false;
}
template<class T>
long linklist<T>::count()
{
	linkNode<T> *current=head->next;
	long count=0;
	while(current)
	{
		current=current->next;
		count++;
	}
	return count;
}
template<class T>
void linklist<T>::print()
{
	linkNode<T> *current=head->next;
	while(current)
	{
		cout<<current->data<<" ";
		current=current->next;
	}
 } 
 template<class T>
 linkNode<T> *linklist<T>::gethead()
 {
	return head;
 }
 template<class T>
bool linklist<T>::invert()
{
	if(head==NULL)
	return false;
	linkNode<T> *first,*current=head->next;
	head->next=NULL;
	while(current)
	{
		first=current;
		current=current->next;
		first->next=head->next;
		head->next=first;
	}
	return true;
}
template<class T>
linklist<T>::linklist(T *a,long count)
{
	head=new linkNode<T>;
	if(head==NULL)
	{
		cerr<<"分配内存失败.\n";
		exit(1);
	 } 
	 linkNode<T> *rear=head;
	 for(int i=0;i<count;i++)
	 {
		linkNode<T> *current=new linkNode<T>;
		 if(current==NULL)
		 {
			cerr<<"分配内存失败.\n";
			exit(1);
		  } 
		  current->data=a[i];
		  rear->next=current;
		  rear=rear->next;
	 }
	 rear->next=NULL;
}
 int main()
 {
	linklist<int> l;
	int n;
	cout<<"请输入要插入单链表的元素个数:";
	cin>>n;
	int newData,deleteData; 
	for(int i=0;i<n;i++)
	{
		cin>>newData;
		if(l.insert(i+1,newData))
		{
			cout<<"元素"<<newData<<"已成功插入单链表.\n"; 
		 } 
		 else
		 {
			cout<<"插入元素失败.\n";
		 }
	} 
	l.print();
//	cout<<"逆置单链表:";
//	l.Invert();
//	l.Print();
	cout<<"请输入要删除的第几个元素:";
	cin>>n;
	if(l.Delete(n,deleteData))
	{
		cout<<"元素"<<deleteData<<"已成功从单链表删除.\n"; 
	}
	else
	{
		cout<<"删除元素失败.\n";
	}
	cout<<"请输入要查询的元素值:";
	cin>>newData;
	long position;
	if(l.search(newData,position))
	{
		cout<<"元素"<<newData<<"在第"<<position<<"个位置上.\n"; 
	}
	else
	{
		cout<<"未找到该元素.\n";
	}
	cout<<"遍历单链表:";
	l.print(); 
	cout<<"单链表中元素个数:";
	cout<<l.count()<<endl; 
	cout<<"逆置单链表:";
	l.invert();
	l.print();
	
	cout<<endl;
	cout<<"使用数组a[5]={6,7,8,9,0}初始化单链表:";
	int a[5]={6,7,8,9,0};
	linklist<int> l2(a,5);
	l2.print();
	return 0;
 }

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template <class T>
struct BiNode{
	T data;
	BiNode<T> *lchild;
	BiNode<T> *rchild;
}; 
template <class T>
class BiTree{
private:
		BiNode<T> *root;
		BiNode<T> * CreateByPre(vector<T>&pre,int &i);      
		BiNode<T>* CreateByPreMid(vector<T> &pre,vector<T> &mid,int ipre,int imid,int n);
		BiNode<T>* Copy(BiNode<T>* p); 
		void preorder(BiNode<T> *p);
		void inorder(BiNode<T> *p);
		void postorder(BiNode<T> *p);
		void levelorder(BiNode<T> *p);
		int Count(BiNode<T> *p);
		int Height(BiNode<T> *p);
		BiNode<T> *Search(BiNode<T> *p,T e);
		BiNode<T> *SearchParent(BiNode<T> *p,BiNode<T> *child);  //查找父节点 
public:
	BiTree(){root=NULL;}
	BiTree(vector<T>&pre); 
	BiTree(vector<T>&pre,vector<T>&mid);
	BiTree(BiTree<T>&tree); 
	void preorder();
	void inorder();
	void postorder();
	void levelorder();
	int Count();
	int Height();
	BiNode<T>* Search(T e);
	BiNode<T>* SearchParent(BiNode<T> *child);
};
template<class T>
BiNode<T>* BiTree<T>::CreateByPre(vector<T>&pre,int &i)
{
	T e=pre[i];
	i++;
	if(e=='*')
	return NULL;
	BiNode<T> *p=new BiNode<T>;
	p->data=e;
	p->lchild=CreateByPre(pre,i);
	p->rchild=CreateByPre(pre,i);
	return p; 
}

template <class T>
BiTree<T>::BiTree(vector<T> &pre)
{
	int i=0;
	root=CreateByPre(pre,i);
}
template<class T>
BiNode<T>* BiTree<T>::CreateByPreMid(vector<T> &pre,vector<T> &mid,int ipre,int imid,int n)
{
	int i;
	if(n==0)
	return NULL;
	BiNode<T> *p=new BiNode<T>;
	p->data=pre[ipre];
	for( i=0;i<n;i++)
	if(pre[ipre]==mid[imid+i])
	break;
	p->lchild=CreateByPreMid(pre,mid,ipre+1,imid,i);
	p->rchild=CreateByPreMid(pre,mid,ipre+i+1,imid+i+1,n-i-1);
	return p;
 } 
 template<class T>
BiTree<T>::BiTree(vector<T> &pre,vector<T> &mid)
{
	int n=pre.size();
	root=CreateByPreMid(pre,mid,0,0,n);
}
template<class T>
BiNode<T>* BiTree<T>::Copy(BiNode<T> *p)
{
	if(p==NULL)
	return NULL;
	BiNode<T> *newp=new BiNode<T>;
	newp->data=p->data;
	newp->lchild=Copy(p->lchild);
	newp->rchild=Copy(p->rchild);
	return newp;
}
template<class T>
BiTree<T>::BiTree(BiTree<T>&tree)
{
	root=tree.root;
}

template<class T>
void BiTree<T>::preorder(BiNode<T> *p)
{
	if(p==NULL)
	return ;
	cout<<p->data;
	preorder(p->lchild);
	preorder(p->rchild);
}
template<class T>
void BiTree<T>::preorder()
{
	preorder(root);
 } 
 template<class T>
 void BiTree<T>::inorder(BiNode<T> *p)
 {
 	if(p==NULL)
 	return ;
 	inorder(p->lchild);
 	cout<<p->data;
 	inorder(p->rchild);
 }
 template<class T>
 void BiTree<T>::inorder()
 {
 	inorder(root);
 }
 template<class T>
 void BiTree<T>::postorder(BiNode<T> *p)
 {
 	if(p==NULL)
 	return ;
 	postorder(p->lchild);
 	postorder(p->rchild);
 	cout<<p->data;
  } 
  template<class T>
  void BiTree<T>::postorder()
  {
  	postorder(root);
  }
 template<class T>
 void BiTree<T>::levelorder(BiNode<T> *p)
 {
 	if(p==NULL)
 	return ;
 	queue<BiNode<T> *> s;
 	s.push(p);
 	while(!s.empty())
 	{
 		BiNode<T> *q=s.front();
 		s.pop();
 		cout<<q->data<<" ";
 		if(q->lchild!=NULL)
 		s.push(q->lchild);
 		if(q->rchild!=NULL)
 		s.push(q->rchild);
	 }
 }
 template<class T>
 void BiTree<T>::levelorder()
 {
 	levelorder(root);
 }
 
 template<class T>
int BiTree<T>::Count(BiNode<T> *p)
{
	int left=0,right=0;
 	if(p==NULL)
 	return 0;
 	left=Count(p->lchild);
 	right=Count(p->rchild);
 	return left+right+1;
 }
 template<class T>
int BiTree<T>::Count()
 {
 	return Count(root);
 }
 template<class T>
int BiTree<T>::Height(BiNode<T> *p)
 {
 	int left=0,right=0;
 	if(p==NULL)
 	return 0;
 	left=Height(p->lchild);
 	right=Height(p->rchild);
 	if(left>right)
 	return left+1;
 	else
 	return right+1;
  } 
template<class T>
int BiTree<T>::Height()
{
	return Height(root);
}
template<class T>
BiNode<T>* BiTree<T>::Search(BiNode<T> *p,T e)
{
	if(p==NULL)
	return NULL;
	if(p->data==e)
	return p;
	BiNode<T> *q=Search(p->lchild,e);
	if(q!=NULL)
	return q;
	return Search(p->rchild,e);
}
template<class T>
BiNode<T>* BiTree<T>::Search(T e)
{
	return Search(root,e);
}
template<class T>
BiNode<T>* BiTree<T>::SearchParent(BiNode<T> *p,BiNode<T> *child)
{
	if(p==NULL || child==NULL)
	return NULL;
		if(p->lchild==child || p->rchild==child)
		return p;
		BiNode<T> *q=SearchParent(p,child);
		if(q!=NULL)
		return q;
		return SearchParent(p->rchild,child);
}
template<class T>
BiNode<T>* BiTree<T>::SearchParent(BiNode<T> *child)
{
	return SearchParent(root,child);
}

int main()
{
	char b[]={'a','b','d','*','*','e','*','*','c','f','*','*','*'};
	vector<char> a(b,b+13);
	BiTree <char>tree(a);
	cout<<"根据先序创建树,先序遍历树:";
	tree.preorder();
	cout<<endl;
	cout<<"树中节点的数目:"<<tree.Count()<<endl;
	cout<<"树的高度:"<<tree.Height()<<endl;
	char c[]={'A','B','E','C','D','F','G','H','I','J'};
	char d[]={'E','B','C','D','A','F','H','I','G','J'};
	vector<char> n(c,c+10);
	vector<char> m(d,d+10);
	BiTree <char>tree2(n,m);
	cout<<"根据前序和中序创建树,先序遍历树:";
	tree2.preorder();
	cout<<"\n中序遍历树:";
	tree2.inorder();
	cout<<"\n后序遍历树:";
	tree2.postorder();
	cout<<"\n层次遍历:";
	tree2.levelorder();
	cout<<endl;
	cout<<"树中节点的数目:"<<tree2.Count()<<endl;
	cout<<"树的高度:"<<tree2.Height()<<endl;
	char p;
	cout<<"请输入要查找结点的关键值:";
	cin>>p;
	BiNode<char> *q=tree2.Search(p);
	cout<<q->data<<endl;
	cout<<tree2.Search(p)<<endl;
	cout<<"查找结点的父节点:";
	cin>>p;
	q=tree2.Search(p);
	BiNode<char> *z=tree2.SearchParent(q);
	cout<<z->data<<endl;
	return 0;
 } 

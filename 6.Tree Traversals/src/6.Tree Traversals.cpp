//============================================================================
// Name        : Tree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//    段错误
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
const int maxn=50;
using namespace std;
struct node{
	int data;
	node * lchild;
	node * rchild;
};
int pre[maxn],post[maxn],in[maxn];  // 将元素装入数组中
int n;

node* creat(int postL,int postR,int inL,int inR){    //1-----.?node* creat(node *postL,node *postR,node*inL,node*inR){
	if(postL > postR){
		return NULL;       // 2----????if(postL > postR)  没有写出来!!!!!
	}
	node *root = new node;
	root->data = post[postR];
	int k;
	for(k = inL;k <= inR;k++){
		if(in[k] == post[postR]){
			break;
		}
	}
	int numleft = k - inL;
	root->lchild = creat(postL,postL + numleft - 1,inL,k - 1);
	root->rchild = creat(postL + numleft,postR - 1,k + 1,inR);   //3-----postR - 1
	return root;
}
int num = 0;              //8-----为什么????
void layerOrder(node*root){
	queue <node*>q;
	q.push(root);
	while(!q.empty()){
		node *now = q.front();
		q.pop();
		printf("%d",now->data);
		num++;
		if(num < n ) printf(" ");
		if(now->lchild!= NULL) q.push(now->lchild);   // 4---root->Lchildif(num < n ) printf(" ");
		//		if(root->lchild!= NULL) q.push(now->lchild);   // 4---root->Lchild
		//		if(root->rchild != NULL) q.push(now->rchild);
		if(now->rchild != NULL) q.push(now->rchild);   /////
	}//////////////////段错误    这里花了我两个小时!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

}

int main() {
	scanf("%d",&n);
	// 后序遍历的输入
	for(int i = 0;i < n;i++){
		scanf("%d",&post[i]);     //5----scanf("%d",post[i]);
	}
	//中序遍历的输入
	for(int i = 0;i < n;i++){    // 6----漏写了,主要还是没理解;
		scanf("%d",&in[i]);
	}

	node *p = creat(0,n - 1, 0, n-1);  //7 ---- 括号内容怎么理解;
	layerOrder(p);
	return 0;
}

//段错误应该就是访问了不可访问的内存，这个内存区要么是不存在的，要么是受到系统保护的，
//还有可能是缺少文件或者文件损坏。

//序运行在内存中;
//系统在程序运行之前会在内存中先给程序画出一个空间
//这个空间有些来存放代码的;有些来存放运行时的变量,还有些....
//这个空间有一个区间使用来存放运行时的变量什么的
//段错误 就是 程序运行时,变量访问越界一类的问题...
//可能出现的原因是:
//数组下标越界
//动态分配内存的指针被double free了(释放两次了)

//段错误应该就是访问了不可访问的内存，这个内存区要么是不存在的，要么是受到系统保护的，还有可能是缺少文件或者文件损坏。

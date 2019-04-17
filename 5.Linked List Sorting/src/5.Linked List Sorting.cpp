//============================================================================
// Name        : Linked.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <algorithm>
#define maxn 100010     ///???
using namespace std;

struct Node{
	int data,address,next;
	bool flag;
}node[maxn];

bool cmp(Node a,Node b){
	if(a.flag == false || b.flag == false)  //if(a.flag != false || b.flag != false)
		return a.flag > b.flag;
	else return a.data < b.data;
}

int main() {
	for(int i = 0;i < maxn;i++){
		node[i].flag = false;
	}
	int n,begin;
	int address;
	scanf("%d %d",&n,&begin);
	for(int i = 0;i < n;i++){
		scanf("%d ",&address );  // scanf("%d %d",&node[address].address,&data );
		scanf("%d %d",&node[address].data,&node[address].next);//	scanf("%d %d",node[address].data,node[address].next);
		node[address].address = address;     ///???
	}
	int count = 0;                     //	int p,count;   ???
	int p = begin;
	while(p != -1){
		node[p].flag = true;
		count++;
		p = node[p].next;
	}
	sort(node,node + maxn,cmp);
	printf("%d %05d\n",count,node[0].address);
	for(int i = 0;i < count ;i++){
		if(i < count - 1)
			printf("%05d %d %05d\n",node[i].address,node[i].data,node[i + 1].address);   //node[i].next
		else
			printf("%05d %d -1\n",node[i].address,node[i].data);
	}
	return 0;
}
//5 00001
//11111 100 -1
//00001 0 22222
//33333 100000 11111
//12345 -1 33333
//22222 1000 12345

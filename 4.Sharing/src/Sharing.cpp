//============================================================================
// Name        : Sharing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define max 100010
using namespace std;
int main() {
	struct Node{
		int data;
		int next;
		bool flag;
	}node[max];
	for(int i = 0;i < max;i++){
		node[i].flag = false;
	}
	int s1,s2,next;
	int address,n;
	char data;
	scanf("%d %d %d",&s1,&s2,&n);

	for(int i = 0;i < n;i++){
		scanf("%d %c %d",&address,&data,&next);
		node[address].data = data;
		node[address].next = next;
//		node[address] = scanf("%d",&address);
//		node[address].data = scanf("%c",&data);
//		node[address].next = scanf("%d",&next);
	}
	//遍历第一个链表,并将标识为true

	   int p;// 这里的P有什么意义   全局变量中的P与循环中的K
		for(  p = s1;p != -1; p = node[p].next){
			node[p].flag = true;
		}

		for( p = s2;p != -1; p = node[p].next){
				if(node[p].flag == true){   //P == -1时   出循环 p的值不能赋给k

					break;
				}
			}
		if( p != -1) printf("%05d\n",p);
//	for( int p = s1;p != -1; p = node[p].next){
//		node[p].flag = true;
//	}
//	int k = 1;
//	for(int p = s2;p != -1; p = node[p].next){
//			if(node[p].flag == true){   //P == -1时   出循环 p的值不能赋给k
//				k = p;
//				break;
//			}
//		}
//	if( k != -1) printf("%05d\n",k);
	else printf("-1\n");
	return 0;
}

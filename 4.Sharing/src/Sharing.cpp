//============================================================================
// Name        : Sharing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//Output Specification:

//For each case, simply output the 5-digit starting position of the common suffix.
//If the two words have no common suffix, output -1 instead.
//
//Sample Input 1:
//
//11111 22222 9
//67890 i 00002
//00010 a 12345
//00003 g -1
//12345 D 67890
//00002 n 00003
//22222 B 23456
//11111 L 00001
//23456 e 67890
//00001 o 00010
//Sample Output 1:
//
//67890
//Sample Input 2:
//
//00001 00002 4
//00001 a 10001
//10001 s -1
//00002 a 10002
//10002 t -1
//Sample Output 2:
//-1
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
//00001 00002 4
//00001 a 10001
//10001 s -1
//00002 a 10002
//10002 t -1

//============================================================================
// Name        : 计算器.cpp
// Author      : 周文涛
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <map>
using namespace std;
struct Node{
    double num;
    char op;
    bool flag;
};
string Str;
stack <Node> s;
queue <Node> q;
map <char,int> op;

void change(){            //void
    Node temp;

    for(int i = 0;i < Str.length();){   //Str.length()
        if(Str[i] >= '0' && Str[i] <= '9'){
            temp.flag = true;
            temp.num = Str[i++] - '0';         //什么意思?????
                                        //为什么会有循环?

/////////////////////////////////////////////// 循环内容不会写????!!
            while(i < Str.length() && Str[i] >= '0' && Str[i] <= '9'){
                temp.num = temp.num * 10 + (Str[i] - '0');
                i++;
        }
        q.push(temp);
/////////////////////////////////////////////////////////////
        }

        else{
            temp.flag = false;
            while(!s.empty() &&  op[Str[i]] <= op[s.top().op] ){
                q.push(s.top());
                s.pop();        ///////s.top()
            }
            temp.op = Str[i];
            s.push(temp);
            i++;
        }
    }
//循环位置?
    while(!s.empty()){         ///!s.top()  !s.empty()
            q.push(s.top());
            s.pop();
    }
}
//。计算后缀表达式的值
double Cal(){
    double temp1,temp2;
    Node cur,temp;
    while(!q.empty()){           ///!s.top()  !s.empty()  !q.empty()
        cur = q.front();
        q.pop();                 //s.push(cur);

        if(cur.flag == true){
            s.push(cur);
        }
        else{
            temp2 = s.top().num;//temp1 = s.top().num;排在前的元素后出栈先做计算
            s.pop();
            temp1 = s.top().num;
            s.pop();
            temp.flag = true;

            if(cur.op == '+')
                temp.num = temp1 + temp2;
            else if(cur.op == '-')
                temp.num = temp1 - temp2;
            else if(cur.op == '*')
                temp.num = temp1 * temp2;
            else
                temp.num = temp1 / temp2;
            s.push(temp);                     ///z直接压入栈中
        }
    //    return s.push(temp);           该写法错误,返回类型因该是  “int”  类型

    }
    return s.top().num;                 //   返回栈顶数字
}

int main(){
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;    // Str.end(); it != Str.begin()
    while(getline(cin,Str)){
        if(Str == "0"){       /////
            break;
        }
        for(string::iterator it = Str.begin(); it != Str.end(); ++it){
            if(*it == ' ')     //*it = " "
                Str.erase(it); //string.erase(it)
        }
        change();
        printf("%.2f\n",Cal());
    }
    return 0;
}

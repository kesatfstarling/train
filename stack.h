#pragma once
#include <iostream>
#include<ctime>
#include<cstdlib>

using namespace std;
template<class T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};
template<class T>
class linkstack {
private:
    Node<T>* top;//栈顶指针
public:
    linkstack() :top(nullptr) {}//构造函数
    ~linkstack() { empty(); }//析构函数
    //进栈
    void push(const T& x) {
        Node<T>* newnode = new Node<T>(x);
        newnode->next = top;
        top = newnode;
    }
    //退栈
    void pop() {
        if (!isempty()) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
        else {
         std::cerr << "Stack underflow" << std::endl;
        }
        
    }
    //栈顶元素
    T gettop() const{
        if (!isempty()){
            return top->data;
        }
        else{
            std::cerr << "Stack is empty" << std::endl;
            return T(); // 返回默认值
        }
    }
    //得到大小
    int getsize() {
        if (!isempty()) {
            Node<T>* temp = top;
            int size=0;
            while (top != nullptr) { top = top->next; size++; }
            return size;
        }
    }
    //删去栈
    void empty() {
        Node<T>* p;
        while (top!=nullptr) {
            p = top;
            top = top->next;
            delete p;
        }
    }
    bool isempty ()const { return (top == nullptr) ? true : false; }//判断是否为栈空
    //数组转栈
    linkstack(const T*list,int size) {
        top = nullptr;
        //将数组从底部压入
        for (int i = size - 1; i >= 0;--i) {
            push(list[i]);
        }
    }

};

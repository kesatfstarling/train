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
    Node<T>* top;//ջ��ָ��
public:
    linkstack() :top(nullptr) {}//���캯��
    ~linkstack() { empty(); }//��������
    //��ջ
    void push(const T& x) {
        Node<T>* newnode = new Node<T>(x);
        newnode->next = top;
        top = newnode;
    }
    //��ջ
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
    //ջ��Ԫ��
    T gettop() const{
        if (!isempty()){
            return top->data;
        }
        else{
            std::cerr << "Stack is empty" << std::endl;
            return T(); // ����Ĭ��ֵ
        }
    }
    //�õ���С
    int getsize() {
        if (!isempty()) {
            Node<T>* temp = top;
            int size=0;
            while (top != nullptr) { top = top->next; size++; }
            return size;
        }
    }
    //ɾȥջ
    void empty() {
        Node<T>* p;
        while (top!=nullptr) {
            p = top;
            top = top->next;
            delete p;
        }
    }
    bool isempty ()const { return (top == nullptr) ? true : false; }//�ж��Ƿ�Ϊջ��
    //����תջ
    linkstack(const T*list,int size) {
        top = nullptr;
        //������ӵײ�ѹ��
        for (int i = size - 1; i >= 0;--i) {
            push(list[i]);
        }
    }

};

#include<iostream>
#include<list>
#include"func.h"

struct q_node {
    int value;
    int priority;
};

extern "C" __declspec(dllexport) int* initList() {
    std::list<q_node>* pq = new std::list<q_node>();
    return (int*)pq;
}


extern "C" __declspec(dllexport)void deleteList(int* pq) {
    delete pq;
}



extern "C" __declspec(dllexport) void push_el(int* pq, int v, int p)
{
    std::list<q_node>* queue = (std::list<q_node>*)pq;
    queue->push_back({ v, p });

}



extern "C" __declspec(dllexport) int pop_el(int* pq)
{
    std::list<q_node>* queue = (std::list<q_node>*)pq;
    int max_priority = queue->front().priority;
    int value_to_return;
    for (auto iter = queue->begin(); iter != queue->end(); iter++) {

        if ((*iter).priority > max_priority) {
            max_priority = (*iter).priority;
        }
    }

    for (auto iter = queue->begin(); iter != queue->end(); iter++) {
        if ((*iter).priority == max_priority) {
            value_to_return = (*iter).value;
            queue->erase(iter);
            return value_to_return;
        }

    }

}

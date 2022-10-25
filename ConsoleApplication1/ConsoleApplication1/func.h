#pragma once

extern "C" __declspec(dllexport) int* initList();
extern "C" __declspec(dllexport) void deleteList(int* pq);
extern "C" __declspec(dllexport) void push_el(int* pq, int v, int p);
extern "C" __declspec(dllexport) int pop_el(int* pq);
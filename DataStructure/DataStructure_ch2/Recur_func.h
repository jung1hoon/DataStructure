#pragma once
#include <iostream>

//배열 합 (재귀 함수 버전)
int RecurSum(int* arr, int size);

//피보나치 수열
int Fibo_Recur(int n); // 재귀 버전
int Fibo_da(int n); // 동적배열 활용
int Fibo_itr(int n); //일반 반복문 활용

//이진탐색 - 재귀함수 활용
int Recur_BinarySearch(int* arr, int left_index, int right_index, int n);

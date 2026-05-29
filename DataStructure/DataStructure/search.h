#pragma once
#include <iostream>

// n을 count하는 함수
int count(int arr[], int size, int n);

// c라는 문자 개수 반환
int char_count(char* arr, char c);

// n을 찾는 함수
int linearsearch(int arr[], int size, int n);

// 정렬된 배열에서 n 개수
int sorted_count(int arr[], int size, int n);

// 문자와 그 문자 개수 출력 ex) a3b4d6...
void char_n_number(int table[], int size);
// 테스트용 함수
void search_test1(char arr[], int count_table[]);

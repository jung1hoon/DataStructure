#pragma once
#include <iostream>

void Print(int arr[], int n);
void swap(int a, int b);

void InsertionSort(int arr[], int n);
void InsertionSort(int arr[], int n, int gap);
void ShellSort(int arr[], int n);

void Merge(int arr[], int merged[], int left, int mid, int right);
void Merge2(int arr[], int left, int mid, int right);
void MergeSort(int arr[], int merged[], int left, int right);
void MergeSort2(int arr[], int left, int right);


#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n;
int A[N];
void merge (int array[], int const left, int const mid, int const right){
    int const n1 = mid - left + 1;
    int const n2 = right - mid;

    auto *leftArray = new int[n1];
    auto *rightArray = new int[n2];

    for (auto i = 0 ; i < n1; i++){
        leftArray[i] = array[left + i];
    }
    for (auto i = 0 ; i < n2 ;i++){
        rightArray[i] = array[mid + i + 1];
    }

    auto indexofn1 = 0, indexofn2 = 0; 
    int indexMerge = left;

    while (indexofn1 < n1 && indexofn2 < n2){
        if (leftArray[indexofn1] <= rightArray[indexofn2]){
            array[indexMerge] = leftArray[indexofn1];
            indexofn1++;
        }
        else {
            array[indexMerge] = rightArray[indexofn2];
            indexofn2 ++;
        }
        indexMerge++;
    }

    while (indexofn1 < n1 ){
        array[indexMerge] = leftArray[indexofn1];
        indexofn1++;
        indexMerge++;
    }

    while (indexofn2 < n2){
        array[indexMerge] = rightArray[indexofn2];
        indexofn2++;
        indexMerge++;
    }

    delete[] leftArray;
    delete[] rightArray;

}


void mergeSort(int array[], int const begin, int const end){
    if ( begin >= end){
        return;
    }

    int mid = begin + (end - begin) /2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid , end);
}

void printArray(int A[], int size){
    for (int i = 0 ; i < size ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void input (){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> A[i];
    }
}

int main(){
    input();
    mergeSort(A, 0, n - 1);
    cout << "After sort : ";
    printArray(A, n);
    return 0;
}
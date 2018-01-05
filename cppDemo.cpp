#include <iostream>

typedef int Int6[6];

//交换两个值。升序
void swapValue(int& a, int& b) {
  if (a > b) {
    a = a + b;
    b = a - b;
    a = a - b;
  }
}

// 冒泡排序.
// 接受数组的引用作为其参数的函数
// 是否必须传递引用的数组的个数6.
void bubbleSort(int (&array)[6], int size) {

  for (int i = 0; i < size; i++) {
    for (int j = i + 1;  j < size; j++) {
        swapValue(array[i],array[j]);
    }
  }
}

// 插入排序
// typedef
void insertionSort(Int6& array, int size) {
  int valueToInsert;
  int holePosition;
  for (int i = 0; i < size; i++) {
    valueToInsert = array[i];
    holePosition = i;

    while (holePosition > 0 && array[holePosition - 1] > valueToInsert) {
      array[holePosition] = array[holePosition - 1];
      holePosition--;
    }

    if (holePosition != i) {
      array[holePosition] = valueToInsert;
    }
  }
}

// 选择排序
// 依次选出数组中最小的数，放在最左边。
void selectionSort(Int6& array, int size) {
    int indexMin;
    for (int i = 0; i < size - 1; i++) {
      indexMin = i;
      for (int j = i + 1; j < size; j++) {
          if ( array[j] < array[indexMin] ) {
             indexMin = j;
          }
      }
      if (indexMin != i) {
        swapValue(array[i],array[indexMin]);
      }
    }
}

// 快速排序
void quickSort(Int6& array,int start, int end) {
  if (start >= end) {
    return;
  }
    int left = start;
    int right = end - 1;
    int midValue = array[end];
    while (left < right) {
        while (array[left] < midValue && left < right) {
          left++;
        }
        while (array[right] > midValue && left < right) {
          right--;
        }
        swapValue(array[left],array[right]);
    }
    if (array[left] >= array[end]) {
      swapValue(array[left], array[end]);
    } else {
      left++;
    }
    if (left) {
      quickSort(array,start,left-1);
    }
    quickSort(array,left + 1 ,end);
}

int main(int argc, char const *argv[]) {

  int a[6] = {3,6,2,9,1,5};
  // bubbleSort(a, 6);
  // insertionSort(a,6);
  // selectionSort(a,6);
  quickSort(a,0,5);
  for (int i = 0; i < 6; i++) {
    std::cout << a[i] << ',';
  }
  std::cout << '\n';
  return 0;
}

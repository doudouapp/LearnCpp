#include <iostream>

template <class T>
class MaxHeap {
private:
    T* mHeap;
    int mCapacity; // 总容量
    int mSize;     // 实际容量

    // 最大堆的向下调整算法
    void fileterDown(int start, int end);

    // 最大堆的向上调整算法
    void filterUp(int start);

public:
    MaxHeap();
    ~MaxHeap();
    MaxHeap(int capacity);

    int getIndex(T data);

    int remove(T data);

    int insert(T data);

    void print();

};

// 构造函数
template <class T>
MaxHeap<T>::MaxHeap() {
    new (this)MaxHeap(30);
}

template <class T> 
MaxHeap<T>::MaxHeap(int capacity) {
    mSize = 0;
    mCapacity = capacity;
    mHeap = new T[mCapacity];
}

template <class T>
MaxHeap<T>::~MaxHeap() {
    mSize = 0;
    mCapacity = 0;
    delete[] mHeap;
}

template <class T> 
int MaxHeap<T>::getIndex (T data) {
    for (int i = 0; i < mSize; i++) {
        if (data == mHeap[i]) {
            return i;
        }
    }
    return -1;
}

template <class T>
void MaxHeap<T>::print() {
    for (int i=0; i<mSize; i++)
        std:: cout << mHeap[i] << " ";
 }

template <class T> 
void MaxHeap<T>::filterUp(int start) {
    int cur = start;
    int par = (cur -1) / 2;
    T temp = mHeap[cur];
    while (cur > 0) {
        if (mHeap[par] >= temp) {
            break;
        } else {
            mHeap[cur] = mHeap[par];
            cur = par;
            par = (cur - 1) / 2;
        }
    }
    mHeap[cur] = temp;
}

template <class T> 
int MaxHeap<T>::insert(T data) {
    if (mSize == mCapacity) {
        return -1;
    }
    mHeap[mSize] = data;
    filterUp(mSize);
    mSize++;
    return 0;
}

template <class T> 
int MaxHeap<T>::remove(T data) {

    int idx;
    if (mSize == 0) {
        return -1;
    }
    idx = getIndex(data);
    if (idx == -1) {
        return -1;
    }
    

    return 0;
}

int main () {

    int a[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
    int len =(sizeof(a)) / (sizeof(a[0]));
    MaxHeap<int>* tree = new MaxHeap<int>();
    std::cout << "===Add one by one : ";
    for (int i = 0; i < len; i++) {
        tree->insert(a[i]);
    }
    std::cout << "\n==Heap: ";
    tree->print();

    return 0;
}
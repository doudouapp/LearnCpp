#include <iostream>
#include <vector>

using namespace std;

#define Max_Stack 100


// 
// Start 用数组实现 栈
// 
class Stack {
    int top;
public:
    int a[Max_Stack];

    Stack() { top = -1; };

    int pop();
    bool push(int x);
    bool isEmpty();
};

bool Stack::push(int x) {
    if ( top >= Max_Stack - 1 ) {
        cout << "Stack is overflow" << endl;
        return false;
    } else {
        a[++top] = x;
        return true;
    }
}

int Stack::pop() {
    if (top < 0) {
        cout << "Statck is under" << endl;
        return 0;
    } else {
        cout << "top == " << top << endl; 
        int x = a[top--];
        return x;
    }
}

bool Stack::isEmpty() {
    return top < 0;
}

void demo_stack() {
    struct Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    
    while(!s.isEmpty()){
        cout << s.pop() << " popped from the stack" << endl;
    }
    cout << "end end" << endl;
}
// 
// End 用数组实现 栈
// 

// 
// Start  虚函数 
// 

class Animal {
    public:
    virtual void eat() {
        cout << "I eat like a generic animal" << endl;
    }
    virtual ~Animal(){}
};

class Wolf : public Animal {
    public:
    void eat() {
        cout << "I eat like a wolf" << endl;
    }
};

class Fish : public Animal {
    public:
    void eat() {
        cout << "I eat like a fish" << endl;
    }
};

class OtherAni : public Animal {

};

void demo_virtual_function() {
    vector <Animal *>animals;
        animals.push_back( new Animal() );
        animals.push_back( new Wolf() );
        animals.push_back( new Fish() );
        animals.push_back( new OtherAni() );
        for (vector<Animal *>::iterator  it = animals.begin() ; it != animals.end(); ++it) {
            (*it) -> eat();
            delete *it;
        }        
}
// 
// End  虚函数 
// 

void demo_scan_list(int *a, int length, std::function<void(int)> cb){
    for(int i = 0; i < length; i++) {   
        cb(a[i]);
    }
}

void demo_lambda_function() {
    vector<int>lists;
    
    for(int i = 1; i < 4; i++) {
        lists.push_back(i);
    }
    int total = 0;
    // 此处 [&]  <====> [&total]
    for_each(lists.begin(),lists.end(),[&](int &x){
       total += x;
    });

    cout << "total == " << total << endl;

    int a[3] = {1,2,3};
    demo_scan_list(a,3,[](int x) {
        cout << x << endl;
    });
}



int main() {
    printf("Hello Wrold! \n");

// 虚函数
    // demo_virtual_function();

// 栈
    // demo_stack();

// 闭包
    demo_lambda_function();

    return 0;
}
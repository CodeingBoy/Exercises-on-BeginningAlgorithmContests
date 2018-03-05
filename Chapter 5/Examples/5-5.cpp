// Example 5-5 The SetStack Computer
// UVa 12096
// Language: C++ 11

#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef set<int> InnerSet;
typedef stack<int> Stack;

vector<InnerSet> set_cache;

InnerSet get_stack(int index){
    return set_cache[index];
}

int get_set_id(InnerSet &set){
    for(int i = 0;i < set_cache.size();i++){
        if(set_cache[i] == set){
            return i;
        }
    }
    set_cache.push_back(set);
    return set_cache.size() - 1;
}

int stack_pop(Stack &stack){
    int top = stack.top();
    stack.pop();
    return top;
}

void push(Stack &stack){
    InnerSet inner_set;
    int id = get_set_id(inner_set);
    stack.push(id);
}

void duplicate(Stack &stack){
    stack.push(stack.top());
}

void union_stack(Stack &stack){
    InnerSet first = get_stack(stack_pop(stack)),
             second = get_stack(stack_pop(stack));

    InnerSet result;
    set_union(first.begin(), first.end(),
            second.begin(), second.end(),
            inserter(result, result.begin()));

    stack.push(get_set_id(result));
}

void intersect(Stack &stack){
    InnerSet first = get_stack(stack_pop(stack)),
             second = get_stack(stack_pop(stack));

    InnerSet result;
    set_intersection(first.begin(), first.end(),
            second.begin(), second.end(),
            inserter(result, result.begin()));

    stack.push(get_set_id(result));
}

void add(Stack &stack){
    InnerSet first = get_stack(stack_pop(stack)),
             second = get_stack(stack_pop(stack));

    second.insert(get_set_id(first));

    stack.push(get_set_id(second));
}

void interpret(Stack &stack, string &command){
    switch(command[0]){
        case 'P': push(stack); break;
        case 'D': duplicate(stack); break;
        case 'U': union_stack(stack); break;
        case 'I': intersect(stack); break;
        case 'A': add(stack); break;
    }
    cout << get_stack(stack.top()).size() << endl;
}

int main(){
    int kase;
    cin >> kase;

    while(kase--){
        int commands_count;
        cin >> commands_count;

        Stack stack;

        for(int i = 0;i < commands_count;i++){
            string command;
            cin >> command;

            interpret(stack, command);
        }

        cout << "***" << endl;
    }

    return 0;
}

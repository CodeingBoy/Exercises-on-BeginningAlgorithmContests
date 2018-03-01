// Example 5-2 The Blocks Problem
// UVa 101
// Language: C++

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void print_blocks(const vector<int> blocks[], const int size){
    for(int i = 0;i < size;i++){
        cout << i << ":";
        const vector<int> &block = blocks[i];
        for(int j = 0;j < block.size();j++){
            cout << " " << block[j];
        }
        cout << endl;
    }
}

void return_above(vector<int> blocks[], vector<int> &stack, int pos_start = 0){
    for(int i = stack.size() - 1;i >= pos_start;i--){
        int index = stack[i];
#ifdef DEBUG
        cout << "Returning " << index << endl;
#endif
        vector<int> &block = blocks[index];
        if(block != stack){
            block.push_back(index);
        }

        stack.pop_back();
    }
}

void move(vector<int> &src, vector<int> &dest){
    for(int i = 0;i < src.size();i++){
        dest.push_back(src[i]);
    }
    src.clear();
}

int search(vector<int> &block, int num){
    for(int i = 0;i < block.size();i++){
        if(block[i] == num){
            return i;
        }
    }
    return -1;
}

void search_num(vector<int> blocks[], int block_count, int num, int &index, int &pos){
    index = -1, pos = -1;
    for(int i = 0;i < block_count;i++){
        vector<int> &current_block = blocks[i];
        pos = search(current_block, num);
        if(pos != -1){
            index = i;
            return;
        }
    }
}

void move_onto(vector<int> blocks[], int index_a, int pos_a, int index_b, int pos_b){
    vector<int> &block_a = blocks[index_a], &block_b = blocks[index_b];
    int a = block_a[pos_a];
    int b = block_b[pos_b];
    return_above(blocks, block_a, pos_a + 1);
    return_above(blocks, block_b, pos_b + 1);

    block_a.pop_back();
    block_b.push_back(a);
}

void move_over(vector<int> blocks[], int index_a, int pos_a, int index_b, int pos_b){
    vector<int> &block_a = blocks[index_a], &block_b = blocks[index_b];
    int a = block_a[pos_a];
    int b = block_b[pos_b];
    return_above(blocks, block_a, pos_a + 1);

    block_a.pop_back();
    block_b.push_back(a);
}

void pile_onto(vector<int> blocks[], int index_a, int pos_a, int index_b, int pos_b){
    vector<int> &block_a = blocks[index_a], &block_b = blocks[index_b];
    int b = block_b[pos_b];
    return_above(blocks, block_b, pos_b + 1);

    move(block_a, block_b);
}

void pile_over(vector<int> blocks[], int index_a, int pos_a, int index_b, int pos_b){
    vector<int> &block_a = blocks[index_a], &block_b = blocks[index_b];
    for(int i = pos_a;i < block_a.size();i++){
        block_b.push_back(block_a[i]);
    }
    while(block_a.size() > pos_a){
        block_a.pop_back();
    }
}

bool parse_command(vector<int> blocks[], int block_count){
    string line;
    getline(cin, line);
    if(line[0] == 'q'){
        return false;
    }
    if(line.empty()){
        return true;
    }

    if(line == "print"){
        print_blocks(blocks, block_count);
        return true;
    }

    stringstream ss;
    ss << line;
    string operation, direction;
    int src, dest;
    ss >> operation >> src >> direction >> dest;

    if(src == dest){
        return true;
    }
    int index_a = -1, index_b = -1;
    int pos_a = -1, pos_b = -1;
    search_num(blocks, block_count, src, index_a, pos_a);
    search_num(blocks, block_count, dest, index_b, pos_b);

#ifdef DEBUG
    cout << "Src: " << index_a << ", " << pos_a << endl;
    cout << "Dest: " << index_b << ", " << pos_b << endl;
#endif

    if(index_a == index_b){
        return true;
    }

    if(operation == "move"){
        if(direction == "onto"){
            move_onto(blocks, index_a, pos_a, index_b, pos_b);
        }else{
            move_over(blocks, index_a, pos_a, index_b, pos_b);
        }
    }else{
        if(direction == "onto"){
            pile_onto(blocks, index_a, pos_a, index_b, pos_b);
        }else{
            pile_over(blocks, index_a, pos_a, index_b, pos_b);
        }
    }

    return true;
}

int main(){
    int block_count;
    cin >> block_count;

    vector<int> *blocks = new vector<int>[block_count];
    for(int i = 0;i < block_count;i++){
        blocks[i].push_back(i);
    }

    while(parse_command(blocks, block_count))
        ;
    print_blocks(blocks, block_count);

    return 0;
}

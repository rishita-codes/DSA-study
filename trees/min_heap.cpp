#include<iostream>
#include<vector>

using namespace std;

void minHeapifyUp(vector<int>& heap, int cur){
    int parent;
    while(cur>0){
        parent=(cur-1)/2;
        if(heap[cur]<heap[parent]){
            swap(heap[cur], heap[parent]);
            cur=parent;
        }
        else
            break;
    }
}

void insertInMinheap(vector<int>& heap, int& size, int data){
    if(size==heap.size()){
        cout<< "heap is full\n";
        return;
    }
    heap[size]=data;
    size++;
    if(size>0){
        minHeapifyUp(heap, size-1);
    }
}

void minHeapifyDown(vector<int>& heap, int size, int cur){
    int childR, childL, smallest;
    while(true){
        childL= 2*cur+1;
        childR= 2*cur+2;
        smallest= cur;
        if(childL<size && heap[childL]< heap[smallest])
            smallest= childL;
        if(childR<size && heap[childR]< heap[smallest])
            smallest= childR;
        if(smallest!=cur){
            swap(heap[cur], heap[smallest]);
            cur= smallest;
        }
        else
            break;
    }
}

void deleteRootMinheap(vector<int>& heap, int& size){
    if(size==0){
        cout<< "heap is empty\n";
        return;
    }
    heap[0]=heap[size-1];
    size--;
    minHeapifyDown(heap, size, 0);
}

void levelOrder(vector<int>& heap, int size){
    for(int i=0;i<size;i++)
        cout<< heap[i]<< " ";
    cout<< endl;
}

int main(){
    int ch, n=100, data, size=0;
    vector<int> heap(n,-1);
    cout<< "Enter 1-insert 2-delete 3-levelorder 0-exit\n";
    while(true){
        cin>> ch;
        switch(ch){
            case 1:
                cin>> data;
                insertInMinheap(heap, size, data);
                break;
            case 2:
                deleteRootMinheap(heap, size);
                break;
            case 3:
                levelOrder(heap, size);
                break;
            case 0:
                exit(0);
            default:
                cout<< "Invalid choice\n";
        }
    }
    

    return 0;
}
//
//  main.cpp
//  MinHeap
//
//  Created by adeeb mohammed on 22/03/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <vector>

class MinHeap {
public:
  std::vector<int> heap;

  MinHeap(std::vector<int> vector) { heap = buildHeap(&vector); }

  std::vector<int> buildHeap(std::vector<int> *vector) {
      int firstParentIndex = (int)((vector->size() - 2) / 2);
      for(int currentIdx = firstParentIndex; currentIdx >= 0; currentIdx--){
          siftDown(currentIdx, (int)vector->size()-1, vector);
      }
      return *vector;
  }

    // shift down	method will take o(logn)
    void siftDown(int currentIdx, int endIdx, std::vector<int> *heap) {
        int childOneIdx = (currentIdx*2) +1;
        while (childOneIdx <= endIdx) {
            // find out which child to be swapped with the parent node
            int idxToSwap = childOneIdx;
            int childTwoIdx = (childOneIdx+ 1) <= endIdx ? childOneIdx + 1 : -1;
            if(childTwoIdx != -1 && heap->at(childTwoIdx) < heap->at(childOneIdx)){
                idxToSwap = childTwoIdx;
            }
            if(heap->at(idxToSwap) < heap->at(currentIdx)){
                swap(currentIdx, idxToSwap, heap);
                currentIdx  = idxToSwap;
                childOneIdx = (currentIdx*2) + 1;
            }else{
                return;
            }
        }
    }

    void siftUp(int currentIdx, std::vector<int> *heap) {
        int parentIdx = (currentIdx-1)/2;
        while (currentIdx > 0 && heap->at(currentIdx) < heap->at(parentIdx)) {
            swap(currentIdx, parentIdx, heap);
            currentIdx = parentIdx;
            parentIdx = (currentIdx-1) /2;
        }
    }

    int peek() {
      
        return heap.at(0);
    }

    int remove() {
      swap(0, (int)heap.size() - 1, &heap);
        int valueToRemove = heap.back();
        heap.pop_back();
        siftDown(0, (int)heap.size()-1, &heap);
        return valueToRemove;
    }

    void insert(int value) {
        heap.push_back(value);
        siftUp((int)heap.size()-1, &heap);
    }
    
    void swap(int pos_1, int pos_2, std::vector<int> *heap){
        int temp = heap->at(pos_1);
        heap->at(pos_1) = heap->at(pos_2);
        heap->at(pos_2) = temp;
    }
};


int main(int argc, const char * argv[]) {
    std::cout << "Program for constructig a min Heap" << std::endl;
    MinHeap oMinHeap({35,26,1,-10,24,8});
    oMinHeap.insert(-243);
    oMinHeap.remove();
    oMinHeap.insert(8);
    for(auto num : oMinHeap.heap){
        std::cout << num << std::endl;
    }
    return 0;
}

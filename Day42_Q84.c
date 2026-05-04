/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *maxHeap;
    int *minHeap;
    int maxSize;
    int minSize;
    int capacity;
} MedianFinder;

void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void maxHeapifyUp(int *heap,int index){
    while(index>0){
        int parent=(index-1)/2;
        if(heap[parent] < heap[index]){
            swap(&heap[parent],&heap[index]);
            index=parent;
        } else break;
    }
}

void minHeapifyUp(int *heap,int index){
    while(index>0){
        int parent=(index-1)/2;
        if(heap[parent] > heap[index]){
            swap(&heap[parent],&heap[index]);
            index=parent;
        } else break;
    }
}

void maxHeapifyDown(int *heap,int size,int index){
    while(1){
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;

        if(left<size && heap[left]>heap[largest]) largest=left;
        if(right<size && heap[right]>heap[largest]) largest=right;

        if(largest!=index){
            swap(&heap[largest],&heap[index]);
            index=largest;
        } else break;
    }
}

void minHeapifyDown(int *heap,int size,int index){
    while(1){
        int smallest=index;
        int left=2*index+1;
        int right=2*index+2;

        if(left<size && heap[left]<heap[smallest]) smallest=left;
        if(right<size && heap[right]<heap[smallest]) smallest=right;

        if(smallest!=index){
            swap(&heap[smallest],&heap[index]);
            index=smallest;
        } else break;
    }
}

MedianFinder* medianFinderCreate() {
    MedianFinder* obj=(MedianFinder*)malloc(sizeof(MedianFinder));
    obj->capacity=50000;
    obj->maxHeap=(int*)malloc(sizeof(int)*obj->capacity);
    obj->minHeap=(int*)malloc(sizeof(int)*obj->capacity);
    obj->maxSize=0;
    obj->minSize=0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {

    if(obj->maxSize==0 || num <= obj->maxHeap[0]){
        obj->maxHeap[obj->maxSize]=num;
        maxHeapifyUp(obj->maxHeap,obj->maxSize);
        obj->maxSize++;
    } 
    else{
        obj->minHeap[obj->minSize]=num;
        minHeapifyUp(obj->minHeap,obj->minSize);
        obj->minSize++;
    }

    if(obj->maxSize > obj->minSize + 1){
        int val=obj->maxHeap[0];
        obj->maxHeap[0]=obj->maxHeap[obj->maxSize-1];
        obj->maxSize--;
        maxHeapifyDown(obj->maxHeap,obj->maxSize,0);

        obj->minHeap[obj->minSize]=val;
        minHeapifyUp(obj->minHeap,obj->minSize);
        obj->minSize++;
    }

    if(obj->minSize > obj->maxSize){
        int val=obj->minHeap[0];
        obj->minHeap[0]=obj->minHeap[obj->minSize-1];
        obj->minSize--;
        minHeapifyDown(obj->minHeap,obj->minSize,0);

        obj->maxHeap[obj->maxSize]=val;
        maxHeapifyUp(obj->maxHeap,obj->maxSize);
        obj->maxSize++;
    }
}

double medianFinderFindMedian(MedianFinder* obj) {

    if(obj->maxSize > obj->minSize)
        return obj->maxHeap[0];

    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}
int main() {
    MedianFinder* medianFinder = medianFinderCreate();
    medianFinderAddNum(medianFinder, 1);
    medianFinderAddNum(medianFinder, 2);
    printf("Median: %.1f\n", medianFinderFindMedian(medianFinder)); // Should print 1.5
    medianFinderAddNum(medianFinder, 3);
    printf("Median: %.1f\n", medianFinderFindMedian(medianFinder)); // Should print 2.0
    medianFinderFree(medianFinder);
    return 0;
}
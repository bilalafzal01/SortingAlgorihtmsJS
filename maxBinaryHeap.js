class MaxBinaryHeap{
    constructor(){
        this.values = [];
    }
    swap(a, b){
        let temp = a;
        a = b;
        b = temp;
        return;
    }
    insert(val){
        this.values.push(val);
        this.bubbleUp();
    }
    bubbleUp(){
        let idx = this.values.length - 1;
        const element = this.values[idx];
        while(idx > 0){
            let parentIdx = Math.floor((idx - 1)/2);
            let parent = this.values[parentIdx];
            if(element <= parent) break;
            this.values[parentIdx] = element;
            this.values[idx] = parent;
            idx = parentIdx;
        }
    }
    extractMax(){
        const max = this.values[0];
        const end = this.values.pop();
        this.values[0] = end;
        this.sinkDown(0);
        return max;
    }
    sinkDown(index){
        let   left = 2*index+1,
              right = 2*index+2,
              largest = index;
        const length = this.values.length
   
   
           // if left child is greater than parent
         if(left <= length &&  this.values[left]>this.values[largest] ){
            largest = left
          }
         // if right child is greater than parent
         if(right <= length && this.values[right]>this.values[largest]) {
           largest = right
         }
        // swap
        if(largest !== index){
           [this.values[largest],this.values[index]] =   [this.values[index],this.values[largest]]
           this.sinkDown(largest)
        }
   
     }
}

var heap = new MaxBinaryHeap();
heap.insert(10);
heap.insert(20);
heap.insert(50);
heap.insert(23);
heap.insert(5);

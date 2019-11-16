// swap function
function swap(arr, i, j){
    var temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Bubble sort
    // Big O is n-square. Best case is: O(n)
    function bubbleSort(arr){
        var noSwaps;
        for(var i = arr.length; i > 0; i--){
            noSwaps = true;
            for(var j = 0; j < i - 1; j++){
                if(arr[j] > arr[j+1]){
                var temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                noSwaps = false;         
                }
            }
            if(noSwaps) break;
        }
        return arr;
    }
    bubbleSort([8,1,2,3,4,5,6,7]);


// selection sort
    // Selection sort is similar to bubble sort, but instead of placing larger values at the sorted position, you sort smaller values first
        // start at the first element, go through the remaining and find the minimum value
        // and put that at the front i.e swap the minimum element in each iteration with whatever you started with.
        function selectionSort(arr){
            for(var i = 0; i < arr.length; i++){
                var lowest = i;
                for(var j = i+1; j < arr.length; j++){
                    if(arr[j] < arr[lowest]){
                        lowest = j;
                    }
                }
                if(i !== lowest){
                    //SWAP!
                    var temp = arr[i];
                    arr[i] = arr[lowest];
                    arr[lowest] = temp;
                }
            }
            return arr;
        }
        // Big O is of n-square

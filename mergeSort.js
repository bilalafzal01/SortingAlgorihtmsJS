// merge sort implementation
    // combination of splitting up, merging and sorting
    // exploits the fact that arrays of 0 or 1 elements are always sorted
    // works by decomposing an array into smaller array of 0 or 1 elements, then builds up the newly sorted array (divide and conquer)
    // O(n + m) => space and time both

    // merge function
    function merge(arr1, arr2){
        let results = [];
        let i = 0;
        let j = 0;
        while(i < arr1.length && j < arr2.length){
            if(arr2[j] > arr1[i]){
                results.push(arr1[i]);
                i++;
            } else {
                results.push(arr2[j])
                j++;
            }
        }
        while(i < arr1.length) {
            results.push(arr1[i])
            i++;
        }
        while(j < arr2.length) {
            results.push(arr2[j])
            j++;
        }
        return results;
    }
    // merge([100,200], [1,2,3,5,6])
    

    // mergeSort function now
    function mergeSort(arr){
        if(arr.length <=1 ) return arr;

        let mid = Math.floor(arr.length/2), left = mergeSort(arr.slice(0, mid)), right = mergeSort(arr.slice(mid, arr.length));
        return merge(left, right);
    }

    

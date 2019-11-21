function partition(arr, p, r){
    var i = p - 1;
    for(var j = p; j < r; j++){
        if(arr[j]<=arr[r]){
            i++;
            var temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } 
    var temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;

    return i+1;
}

function quickSort(arr,p,r){
    if(p<r){
        var q = partition(arr, p, r);
        quickSort(arr, p, q);
        quickSort(arr, q+1, r);
    }
}
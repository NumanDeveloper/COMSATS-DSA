// Bubble sort function
const bubbleSort = arr => {
    let swapped = false;
    const a = [...arr];
    // outer loop is for passes
    // # of passes is always equal to size-1
    for (let i = 0; i < a.length-1; i++) {
        swapped = false;
        // inner loop is for sorting
        for (let j = 0; j < a.length - i; j++) {
            if (a[j + 1] < a[j]) {
                // swapping
                [a[j], a[j + 1]] = [a[j + 1], a[j]];
                swapped = true;
            }
        }
        if (!swapped) return a;
    }
    return a;
};

// function call
console.log(bubbleSort([3,1,4,2]))
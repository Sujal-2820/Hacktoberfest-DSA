class MergeSort {
    public static void main(String[] args) {
        int[] arr = { 2, 7, 8, 9, 1, 3, 4, 5 };
        int low = 0;
        int high = arr.length - 1;

        // Call the mergeSort function to sort the array
        mergeSort(arr, low, high);

        // Print the sorted array
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    static void mergeSort(int arr[], int low, int high) {
        // Check if the array can be divided into smaller arrays
        if (low < high) {
            int mid = (low + high) / 2;

            // Recursively sort the left and right halves of the array
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);

            // Merge the sorted halves
            mergefunc(arr, low, mid, high);
        }
    }

    static void mergefunc(int[] arr, int low, int mid, int high) {
        int n1 = mid - low + 1; // Size of the left subarray
        int n2 = high - mid;    // Size of the right subarray
        int[] left = new int[n1];
        int[] right = new int[n2];

        // Copy data to temporary arrays left[] and right[]
        for (int i = 0; i < n1; i++) {
            left[i] = arr[low + i];
        }
        for (int i = 0; i < n2; i++) {
            right[i] = arr[mid + 1 + i];
        }

        int i = 0, j = 0, k = low;

        // Merge the two subarrays back into the original array
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        // Copy any remaining elements from left[] and right[] if there are any
        while (i < n1) {
            arr[k] = left[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
}
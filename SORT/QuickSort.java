import java.util.*;
public class QuickSort {
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }
   private static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
       System.out.print("enter number of elements:");
       int n=in.nextInt();
       int[] arr = new int[n];
       for(int i=0;i<arr.length;i++){
          System.out.print("enter array element:"+(i+1)+":");
          arr[i]=in.nextInt();
        }
        System.out.println("Original array:");
        System.out.println(Arrays.toString(arr));
        quickSort(arr, 0, arr.length - 1);
        System.out.println("Sorted array:");
        System.out.println(Arrays.toString(arr));
    }
}

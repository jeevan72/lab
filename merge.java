import java.util.*;
public class prg1{
    static int mcount=0;
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter n");
        int n=s.nextInt();
        System.out.println("Enter the elements:");
        int A[]=new int[n];
        for(int i=0;i<n;i++){
            A[i]=s.nextInt();
        }
        mergesort(A);
        System.out.println("Number of basic operations:"+mcount++);
        System.out.println("sorted elements:");
        
        for(int i=0;i<n;i++){
            System.out.println(A[i]);
        }
    }
    public static void mergesort(int[] A) {
        if (A.length > 1) {
            int mid = A.length / 2;
            int B[] = new int[mid];
            int C[] = new int[A.length - mid];

            for (int i = 0; i < mid; i++) {
                B[i] = A[i];
            }
            for (int i = mid; i < A.length; i++) {
                C[i - mid] = A[i];
            }

            mergesort(B);
            mergesort(C);
            merge(B, C, A);
        }
    }
    public static void merge(int[] B,int[] C,int []A) {
        int i=0,j=0,k=0;
        while(i<B.length && j<C.length){
            mcount++;
            if(B[i]<=C[j]){
                
                A[k++]=B[i++];
            }
            else{
                
                A[k++]=C[j++];
            }
        }
        while(i<B.length){
            mcount++;
            A[k++]=B[i++];
        }
        while(j<C.length){
            mcount++;
            A[k++]=C[j++];
        }   

    }
}
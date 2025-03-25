import java.util.*;
public class prg1{
    
    static int searchcount=0,sortcount=0;
    public static void main(String[]  args){
        Scanner s =new Scanner(System.in);
        System.out.println("Enter the size of elements:");
        int n=s.nextInt();
        int a[]=new int[n];
        System.out.println("Enter the elements: ");
        for(int i=0;i<n;i++){
            a[i]=s.nextInt();
        }
        System.out.println("Enter key");
        int key=s.nextInt();
        int index=sequentialsearch(a,key);
        if(index!=-1){
            System.out.println("Key found at index:"+(index+1));
        }
        else{
            System.out.println("Key  not found");
        }
      
        selectionsort(a);
        System.out.println("The sorted elements are:");
        for(int i=0;i<n;i++){
            System.out.println(a[i]);
        }
        System.out.println("The number of basic operations of sequential search are:"+searchcount);
        System.out.println("The number of basic operations of selection sort are:"+sortcount);
    }
    public static void selectionsort(int[] a){
            int n=a.length;
            for(int i=0;i<n-1;i++){
                int min=i;
                for(int j=i+1;j<n;j++){
                    if(a[j]<a[min]){
                        sortcount++;
                        min=j;
                    }
                }
                int temp=a[min];
                a[min]=a[i];
                a[i]=temp;
            }
    }
    public static int sequentialsearch(int []a,int key){
        int n=a.length;
        for(int i=0;i<n;i++){
            searchcount++;
            if(a[i]==key){
                return i;
            }
            
        }
        return -1;
    }
}
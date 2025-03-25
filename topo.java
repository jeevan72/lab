import java.util.*;
public class topologicalsort{
    static int n;
    static int[][] adj=new int[10][10];
    static int[] indegree=new int[10];
    static int[] removed=new int[10];
    public static void main(String[] args){
        Scanner s= new Scanner(System.in);
        System.out.println("enter the number of vertices");
        n=s.nextInt();
        System.out.println("enter the cost matrix");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adj[i][j]=s.nextInt();

            }
        }
        
        sremoval();
    }
    public static void icalc(){
        Arrays.fill(indegree,0);
        for(int j=0;j<n;j++){
            
            for(int i=0;i<n;i++){
                indegree[j]+=adj[i][j];
            }
        }
    }
    public static void sremoval(){
            System.out.println("Topological sort");
            
            for(int i=0;i<n;i++){
                icalc();
                int j;
                for(j=0;j<n;j++){
                    if(removed[j]==0&&indegree[j]==0){
                        break;
                    }
                }                
                if(j==n){
                    System.out.println("Graph is cyclic");
                    return;
                }
                System.out.print(j+" ");
                removed[j]=1;
            
            for(int k=0;k<n;k++){
                adj[j][k]=0;
            }
        } 
    }
}
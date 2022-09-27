import java.util.*;
public class Adjacency_Matrix{
    public static void main(String[] args) {
        Scanner S=new Scanner(System.in);
        int v,e;
        System.out.print("Enter Total Vertices In Your Graph\n->");
        v=S.nextInt();
        System.out.print("Enter Total Edges In Your Graph\n->");
        e=S.nextInt();
        int AdjacencyMatrix[][]=new int[v+1][v+1];
        for(int i=0;i<e;i++){
            System.out.print("Enter Source And Destination of your "+(i+1)+"st edge \n->");
            int source=S.nextInt();
            // System.out.print("Enter Destination of your "+(i+1)+"th edge \n->");
            int destination=S.nextInt();
            System.out.print("Enter weight of Edge between "+source+" And "+destination+" \n->");
            int weight=S.nextInt();
            add(destination, source, weight,AdjacencyMatrix);
        }
        display(AdjacencyMatrix,v);

    }
    static void add(int destination,int source,int weight,int AdjacencyMatrix[][]){
        AdjacencyMatrix[destination][source]=weight;
        AdjacencyMatrix[source][destination]=weight;
    }
   static void display(int adj[][],int v){
        for(int i=1;i<(v+1);i++){
            for(int j=1;j<(v+1);j++){
                System.out.print(adj[i][j]+" ");
            }
            System.out.println();
        }
    }
}
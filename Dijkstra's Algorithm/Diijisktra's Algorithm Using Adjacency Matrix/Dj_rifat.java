import java.util.Scanner;
public class Dj_rifat {
    public static void dijkstraAlgo(int[][] adjacencyMatrix) {
        int v = adjacencyMatrix.length;
        boolean[] visited = new boolean[v];
        int[] distance = new int[v];
        distance[0] = 0;
        for (int i = 1; i < v; i++) {
            distance[i] = Integer.MAX_VALUE;
            visited[i] = false;
        }
        for (int i = 0; i < v - 1; i++) {
            int u = MinimumVertex(distance, visited);// finds the unvisited vertex with minimum distance
            visited[u] = true;
            for (int j = 0; j < v; j++) {
                if (adjacencyMatrix[u][j] != 0 && !visited[j] && distance[u] != Integer.MAX_VALUE) {
                    int currDistance = distance[u] + adjacencyMatrix[u][j];
                    if (currDistance < distance[j]) { // relaxation 
                        distance[j] = currDistance;
                    }
                }
            }
            System.out.println( i+1 +" iteration");
            printShortestDistance( distance);
        }
    
    }

    public static int MinimumVertex(int[] distance, boolean[] visited) {
        int minVertex = -1;
        for (int i = 0; i < distance.length; i++) {
            if (visited[i]==false && (minVertex == -1 || distance[i] < distance[minVertex])) {
                minVertex = i;
            }
        }
        return minVertex;
    }

    public static void printShortestDistance( int distance[])
    {
    for(int i=0;i<distance.length;i++)
    {
    System.out.println("THE SHORTEST DISTANCE OF VERTEX " + i +" FROM SOURCE IS "+ distance[i] );
    }
    }
    public static void printAdjacencyMatrix(int[][] adjacencyMatrix) {
        for (int i = 0; i < adjacencyMatrix.length; i++) {
            for (int j = 0; j < adjacencyMatrix.length; j++) {
                System.out.print(adjacencyMatrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String args[]) {
        int vertices;
        int edges;
         Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of vertices");
        vertices = sc.nextInt();
        System.out.println("Enter number of edges");
        edges = sc.nextInt();
        // int  AdjecencyMatrix[][]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        //                            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        //                            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        //                            { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        //                            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        //                            { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        //                            { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        //                            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        //                            { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
         int[][] adjacencyMatrix = new int[vertices][vertices];
        for (int i = 0; i < edges; i++) {
            System.out.println("Enter edge number "+i);
            System.out.print("Source :");
            int source = sc.nextInt();
            System.out.print("Destination :");
            int destination = sc.nextInt();
            System.out.print("Weight :");
            int weight = sc.nextInt();
            adjacencyMatrix[source][destination] = weight;
            }
         System.out.println("The adjacency matrix of the given graph is :");
        printAdjacencyMatrix(adjacencyMatrix);
        System.out.println("Enter the source from where distance is measured :");
       int SOURCE = sc.nextInt();
       dijkstraAlgo(adjacencyMatrix);
    //    dijkstraAlgo(AdjecencyMatrix);
        sc.close();
    }   
    
}

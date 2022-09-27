import java.util.Scanner;
public class Dijikstra {
    public static void dj(int Adj[][], int src) {
        int v = Adj.length;
        boolean[] visited = new boolean[Adj.length];
        int[] distance = new int[Adj.length];
        // distance[0]=0;
        for (int i = 0; i < v; i++) {
            visited[i] = false;
            distance[i] = Integer.MAX_VALUE;
        }
        distance[src] = 0;
        // disp(distance);
        for (int i = 0; i < v - 1; i++) {
            System.out.println();
            int minV = minmumver(visited, distance);
            System.out.println("Position of Minimum Element is : " + minV);
            visited[minV] = true;
            for (int j = 0; j < v; j++) {
                if (Adj[minV][j] != 0 && visited[j] == false) {
                    int newdis = distance[minV] + Adj[minV][j];
                    if (newdis < distance[j]) {
                        System.out.println(
                                "Value is Updated at " + j + " Position From " + distance[j] + " to " + newdis);
                        distance[j] = newdis;
                    }
                }
            }
            disp(distance);
        }
        System.out.println();
        System.err.println("Your Final result is ................");
        disp(distance);

    }

    public static void disp(int dist[]) {
        for (int i = 0; i < dist.length; i++) {
            if (dist[i] == Integer.MAX_VALUE) {
                System.out.print("_ ");
            } else {
                System.out.print(dist[i] + " ");
            }
        }
        System.out.println();
    }

    public static int minmumver(boolean[] visit, int[] distance) {
        int minVertex = -1;
        for (int i = 0; i < distance.length; i++) {
            if (visit[i] == false && ( minVertex==-1 ||distance[i] < distance[minVertex])) {
                minVertex = i;
                // minValue = distance[i];
            }
        }
        return minVertex;
    }

    public static void main(String[] args) {
        Scanner S = new Scanner(System.in);
        int v, e;
        System.out.print("Enter Total Vertices In Your Graph\n->");
        v = S.nextInt();
        System.out.print("Enter Total Edges In Your Graph\n->");
        e = S.nextInt();
        int AdjacencyMatrix[][] = new int[v][v];
        // int AdjacencyMatrix[][]={{0,1,0,0,5,2},{1, 0 ,1, 0, 3, 2},{0 ,1, 0, 1, 1,0},{0 ,0, 1, 0, 5, 0},{5 ,3 ,1 ,5 ,0 ,3},{2 ,2, 0, 0, 3, 0}};
        for (int i = 0; i < e; i++) {
            System.out.println();
            System.out.print("Enter Source And Destination of your " + (i + 1) + "th edge \n->");
            int source = S.nextInt();
            int destination = S.nextInt();
            System.out.print("Enter weight of Edge between " + source + " And " + destination + " \n->");
            int weight = S.nextInt();
            add(source,destination, weight, AdjacencyMatrix);
            // add(destination , source , weight, AdjacencyMatrix);
        }
        int src;
        System.out.print("Enter Your Source Vertex\n->");
        src=S.nextInt();
        display(AdjacencyMatrix);
        dj(AdjacencyMatrix, src);
        S.close();

    }

    static void add(int destination, int source, int weight, int AdjacencyMatrix[][]) {
        AdjacencyMatrix[destination][source] = weight;
        // AdjacencyMatrix[source][destination] = weight;// For Undirected Graph Only
    }

    static void display(int adj[][]) {

        System.err.println("\nYour Adjacency Matrix is As Follows ..............");
        System.out.println();
        for (int i = 0; i < adj.length; i++) {
            for (int j = 0; j < adj.length; j++) {
                System.out.print(adj[i][j] + " ");
            }
            System.out.println();
        }
    }
}
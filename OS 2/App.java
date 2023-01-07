import java.util.*;

public class App{
    static int remain;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n,m,demandExceed,deadlock=1,i,j;
        System.out.println("Processes \n->");
        n = sc.nextInt();
        System.out.println("\nResources \n->");
        m = sc.nextInt();
        remain = n;
        int[][] alloc = new int[n][m];
        int[][] maxNeed = new int[n][m];
        int[] currAvail = new int[m];
        int[] safeSeq = new int[n];

        System.out.println("Enter the total no of each resource in the system:");
        for(j=0;j<m;j++)
        {
            currAvail[j] = sc.nextInt(); 
        }

        System.out.println("Enter the allocation followed by max need, for each process:");
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                alloc[i][j] = sc.nextInt(); 
                currAvail[j] = currAvail[j] - alloc[i][j];
            }
            for(j=0;j<m;j++)
            {
                maxNeed[i][j] = sc.nextInt();
            }
        }
        sc.close();
        System.out.print("\n");
        while(remain!=0)
        {
            deadlock = 1;
            for(i=0;i<n;i++)
            {

                //for each process
                demandExceed = 0;

                for(j=0;j<m;j++) 
                {
                    if(currAvail[j] < maxNeed[i][j]-alloc[i][j] )
                    {
                        demandExceed=1; 
                        break;
                    }
                }

                if(demandExceed==0)
                {
                    System.out.println("P"+i+": EXECUTED");
                    deadlock=0;
                    safeSeq[(n-remain)] = i;
                    remain--;
                    for(j=0;j<m;j++)
                    {
                        currAvail[j] += alloc[i][j];
                    }
                    maxNeed[i][0] = Integer.MAX_VALUE;
                }
                else
                {
                    System.out.println("----P"+i+" :NOT selected, demand exceed on recource: "+(j+1));
                }
                if(remain==0)break;

            }

            if(deadlock==1)
            {
                System.out.print("THE DEADLOCK CANNOT BE AVOIDED BY ANY SEQUENCE!!!");
                break;
            }
        }


        if(deadlock==0)
        {
            System.out.println("\nThe safe sequence is:");
            for(i=0;i<n;i++)
            {
                System.out.printf("P%d ",safeSeq[i]);
            }
        }
    }
}
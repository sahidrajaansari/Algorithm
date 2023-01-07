import java.util.Scanner;

final class Bankers {

    public static boolean isSafe(int allocatedResources[][], int maxResources[][], int neededResources[][],
            int availiable[], boolean isCompleted[], int process, int resources) {

        int tempAvaliable[] = new int[resources];

        for (int i = 0; i < resources; i++) {
            tempAvaliable[i] = availiable[i];
        }

        int safeSequence[] = new int[process];
        int count = 0, completedprocesss = 0, flag = 0;

        System.out.println("\n\nAvailiable resources  ");
        for (int i = 0; i < resources; i++) {
            System.out.print(tempAvaliable[i] + "\t");
        }

        System.out.println("\n\nAmount of resources allocated to each process");
        for (int i = 0; i < process; i++) {
            for (int j = 0; j < resources; j++) {
                System.out.print(allocatedResources[i][j] + "\t");
            }
            System.out.println();
        }

        System.out.println("\n\nAmount of resources needed to each process");
        for (int i = 0; i < process; i++) {
            for (int j = 0; j < resources; j++) {
                System.out.print(neededResources[i][j] + "\t");
            }
            System.out.println();
        }
        System.out.println();

        while (completedprocesss != process) {
            int index = -1;
            for (int i = 0; i < process; i++) {
                if (isCompleted[i] == false) {

                    index = i;
                    for (int j = 0; j < resources; j++) {
                        if (neededResources[i][j] > tempAvaliable[j]) {
                            index = -1;
                            break;
                        }
                    }
                    if (index != -1) {
                        safeSequence[count] = index;
                        count++;
                        isCompleted[index] = true;
                        completedprocesss++;
                        for (int k = 0; k < resources; k++) {
                            tempAvaliable[k] = tempAvaliable[k] + allocatedResources[index][k];
                        }
                        System.out.println("Resources allocated to process " + i + "\n");
                        System.out.println("Availiable resources after process " + i + " is completed");
                        for (int k = 0; k < resources; k++)
                            System.out.print(tempAvaliable[k] + "\t");
                        System.out.println("\n\n");
                    }
                }
            }

            if (index == -1) {
                flag = 1;
                break;
            }

        }

        if (flag == 1) {
            System.out.println("System is Unsafe\n\n");
            return false;
        } else {
            System.out.println("Safe Sequence is  ");
            for (int i = 0; i < count; i++) {
                System.out.print("Process " + (safeSequence[i]) + " \t ");
            }
            System.out.println("\n\n");
            return true;
        }

    }

    public static void resourseRequest(int allocatedResources[][], int maxResources[][], int neededResources[][],
            int availiable[], boolean isCompleted[], int process, int resources, Scanner Sc) {
        int pindex;
        int requestedResource[] = new int[resources];

        System.out.println("\nEnter proces id for which request is made");
        pindex = Sc.nextInt();

        System.out.println("\nEnter amount of request of each resource");
        for (int i = 0; i < resources; i++) {
            requestedResource[i] = Sc.nextInt();
        }

        for (int i = 0; i < resources; i++) {
            if (requestedResource[i] > neededResources[pindex][i]) {
                System.out.println("Error occurred");
                return;
            }
        }

        for (int i = 0; i < resources; i++) {
            if (requestedResource[i] > availiable[i]) {
                System.out.println("System must wait");
                return;
            }
        }

        for (int i = 0; i < resources; i++) {
            availiable[i] -= requestedResource[i];
            allocatedResources[pindex][i] += requestedResource[i];
            neededResources[pindex][i] -= requestedResource[i];
        }

        System.out.println("After request has been completed availiable resources are");
        for (int j = 0; j < resources; j++) {
            System.out.print(availiable[j] + "\t");
        }
        System.out.println();

        System.out.println("\n\nAfter resource have been allocated amount of resources allocated to each process");
        for (int i = 0; i < process; i++) {
            for (int j = 0; j < resources; j++) {
                System.out.print(allocatedResources[i][j] + "\t");
            }
            System.out.println();
        }

        System.out.println("\n\nAfter resource have been allocated amount of resources needed to each process");
        for (int i = 0; i < process; i++) {
            for (int j = 0; j < resources; j++) {
                System.out.print(neededResources[i][j] + "\t");
            }
            System.out.println();
        }
        System.out.println();

        isSafe(allocatedResources, maxResources, neededResources, availiable, isCompleted, process, resources);

    }

    public static void main(String[] args) {
        int process, resources;
        Scanner Sc = new Scanner(System.in);
        System.out.println("Enter number of processes.");
        process = Sc.nextInt();
        System.out.println("\nEnter number of unique resources availiable.");
        resources = Sc.nextInt();

        int allocatedResources[][] = new int[process][resources];
        int maxResources[][] = new int[process][resources];
        int neededResources[][] = new int[process][resources];
        int availiable[] = new int[process];

        for (int i = 0; i < process; i++) {
            System.out.println(
                    "\nEnter amount of maximum resources that need to be allocated for process " + (i) + " .");
            for (int j = 0; j < resources; j++) {
                maxResources[i][j] = Sc.nextInt();
            }
        }

        for (int i = 0; i < process; i++) {
            System.out.println("\nEnter amount of resources that have already been allocated to process " + (i));
            for (int j = 0; j < resources; j++) {
                allocatedResources[i][j] = Sc.nextInt();
            }
        }

        
        System.out.println("\nAmount of resource availiable:    ");
        for (int i = 0; i < resources; i++) {
            availiable[i] = Sc.nextInt();
        }

        for (int i = 0; i < process; i++) {
            for (int j = 0; j < resources; j++) {
                neededResources[i][j] = maxResources[i][j] - allocatedResources[i][j];
            }
        }

        boolean isCompleted[] = new boolean[process];
        for (int i = 0; i < process; i++) {
            isCompleted[i] = false;
        }

        boolean f;

        f = isSafe(allocatedResources, maxResources, neededResources, availiable, isCompleted, process, resources);

        if (f) {
            char ch = 'y';
            System.out.println("Enter 'y' to make request   ");
            ch = Sc.next().charAt(0);
            while (ch == 'y' || ch == 'Y') {
                for (int i = 0; i < process; i++) {
                    isCompleted[i] = false;
                }
                resourseRequest(allocatedResources, maxResources, neededResources, availiable, isCompleted, process,
                        resources, Sc);
                System.out.println("Enter 'y' to  make request   ");
                ch = Sc.next().charAt(0);
            }
        }

        Sc.close();
    }
}

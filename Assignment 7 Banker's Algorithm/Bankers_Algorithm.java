import java.util.Scanner;

class Bankers_Algorithm {
    public static void print(int allocated_resources[][], int max_resorces[][], int neededResources[][],
            int total_number_of_process, int total_number_of_resources, int result[][]) {
        System.out.print("\nPrc\t");
        System.out.print("Alloc\t\t");
        System.out.print("Max\t\t");
        System.out.print("Need\t\t");
        System.out.print("Avlbl\t\t\n");

        char ch = 'A';
        System.out.print("\t");
        for (int j = 0; j < total_number_of_resources; j++) {
            System.out.print((char) (ch + j) + "  ");
        }
        System.out.print("\t");
        for (int j = 0; j < total_number_of_resources; j++) {
            System.out.print((char) (ch + j) + "  ");
        }
        System.out.print("\t");
        for (int j = 0; j < total_number_of_resources; j++) {
            System.out.print((char) (ch + j) + "  ");
        }
        System.out.print("\t");
        for (int j = 0; j < total_number_of_resources; j++) {
            System.out.print((char) (ch + j) + " ");
        }
        for (int i = 0; i < total_number_of_process; i++) {
            System.out.print("\nP" + i + '\t');
            for (int j = 0; j < total_number_of_resources; j++) {
                System.out.print(allocated_resources[i][j] + "  ");
            }
            System.out.print("\t");
            for (int j = 0; j < total_number_of_resources; j++) {
                System.out.print(max_resorces[i][j] + "  ");
            }
            System.out.print("\t");
            for (int j = 0; j < total_number_of_resources; j++) {
                System.out.print(neededResources[i][j] + "  ");
            }
            System.out.print("\t");
            for (int j = 0; j < total_number_of_resources; j++) {
                System.out.print(result[i][j] + " ");
            }
        }
    }

    public static boolean deadlockcheck(int allocated_resources[][], int max_resorces[][], int neededResources[][],
            int total[], int total_number_of_process, int total_number_of_resources) {
        char ch = 'A';
        Boolean isvisted[] = new Boolean[total_number_of_process];
        int Sequence[] = new int[total_number_of_process];
        int totalAllocated[] = new int[total_number_of_resources];
        int availiable[] = new int[total_number_of_resources];
        int result[][] = new int[total_number_of_process][total_number_of_resources];
        int count = 0;
        for (int i = 0; i < total_number_of_process; i++) {
            isvisted[i] = false;
            Sequence[i] = 0;
        }
        for (int i = 0; i < total_number_of_resources; i++) {
            totalAllocated[i] = 0;
            availiable[i] = total[i];
        }
        // for (int i = 0; i < total_number_of_resources; i++) {
        // for (int j = 0; j < total_number_of_process; j++) {
        // totalAllocated[i] = totalAllocated[i] + allocated_resources[j][i];
        // }
        // }
        // for (int i = 0; i < total_number_of_resources; i++) {
        // availiable[i] = total[i] - totalAllocated[i];
        // }
        System.out.println("\nCurrent Resource ");
        for (int j = 0; j < total_number_of_resources; j++) {
            System.out.print((char) (ch + j) + "  ");
        }
        System.out.println();
        for (int i = 0; i < total_number_of_resources; i++) {
            System.out.print(availiable[i] + "  ");
        }

        int completedproces = 0, flag = 0;
        // System.out.println();
        while (completedproces != total_number_of_process) {
            int index = -1;
            for (int i = 0; i < total_number_of_process; i++) {
                if (isvisted[i] == false) {
                    index = i;
                    for (int j = 0; j < total_number_of_resources; j++) {
                        if (neededResources[i][j] > availiable[j] && isvisted[i] == false) {
                            index = -1;
                            break;
                        }
                    }
                    if (index != -1) {
                        System.out.println("\nProcess P" + index + " is Selected ");
                        System.out.println(
                                "------------------------------------------------------------------------------------------");
                        System.out.println("Current Avilable Resource is ");
                        for (int j = 0; j < total_number_of_resources; j++) {
                            result[count][j] = availiable[j];
                            System.out.print(availiable[j] + " ");
                        }
                        System.out.println("\nResource Required By the Process P" + index);
                        for (int j = 0; j < total_number_of_resources; j++) {
                            System.out.print(neededResources[index][j] + " ");
                        }
                        for (int k = 0; k < total_number_of_resources; k++) {
                            availiable[k] += allocated_resources[index][k];
                        }
                        System.out.println("\nAllocated Resource P" + index);
                        for (int j = 0; j < total_number_of_resources; j++) {
                            System.out.print(allocated_resources[index][j] + " ");
                        }

                        System.out.println("\nAfter Completion of Process Avilable Resource is ");
                        for (int j = 0; j < total_number_of_resources; j++) {
                            // availiable[j]+=allocated_resources[index][j];
                            result[count][j] = availiable[j];
                            System.out.print(availiable[j] + " ");
                        }
                        isvisted[index] = true;
                        Sequence[count] = index;
                        completedproces++;
                        count++;
                        System.out.println(
                                "\n------------------------------------------------------------------------------------------");
                        System.out.println("Process\t" + "Status");
                        for (int j = 0; j < total_number_of_process; j++) {
                            System.out.print("P" + j + "\t");
                            if (isvisted[j] == true)
                                System.out.println("Completed");
                            else {
                                System.out.println("Not Completed");
                            }
                        }
                        break;
                    }
                }
            }
            if (index == -1) {
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            System.out.println("\n\nSystem is Unsafe \n\n");
            return false;
        } else {
            System.out.println("\n\nSystem is Safe ");
            print(allocated_resources, max_resorces, neededResources, total_number_of_process,
                    total_number_of_resources, result);
            System.out.println("\n\nSafe Sequence is--^");
            for (int i = 0; i < total_number_of_process; i++) {
                System.out.print("P" + (Sequence[i]));
                if (i != total_number_of_process - 1) {
                    System.out.print("-->");
                }
            }
            System.out.println();
            return true;
        }

    }

    public static void resource_request(int allocated_resources[][], int max_resorces[][], int neededResources[][],
            int total[], int total_number_of_process, int total_number_of_resources) {
        Scanner sc = new Scanner(System.in);
        char ch = 'A';
        System.out.print("Enter Process Number \n->");
        int process_number;
        int newresource[] = new int[total_number_of_resources];
        process_number = sc.nextInt();
        if (process_number < total_number_of_process) {
            System.out.println("Enter Amount Of Resource Required");
            for (int j = 0; j < total_number_of_resources; j++) {
                System.out.print((char) (ch + j) + "->");
                newresource[j] = sc.nextInt();
                // max_resorces[process_number][j] += newresource[j];
            }
            for (int j = 0; j < total_number_of_resources; j++) {
                if (newresource[j] > neededResources[process_number][j]) {
                    System.out.println("Resource Can't be Allocated");
                    System.out.println("Exceeds Needed Resources");
                    return;
                }
                if (newresource[j] > total[j]) {
                    System.out.println("Resource Can't be Allocated");
                    System.out.println("Exeeds Avilable Resources");
                    return;
                }
            }
            for (int j = 0; j < total_number_of_resources; j++) {
                total[j] -= newresource[j];
                allocated_resources[process_number][j] += newresource[j];
                neededResources[process_number][j] -= newresource[j];
                // max_resorces[process_number][j] += newresource[j];
            }
            // print(allocated_resources, max_resorces, neededResources,
            // total_number_of_process,
            // total_number_of_resources);
            System.out.print("\nPrc\t");
            System.out.print("Alloc\t\t");
            System.out.print("Max\t\n");
            System.out.print("\t");
            for (int j = 0; j < total_number_of_resources; j++) {
                System.out.print((char) (ch + j) + "  ");
            }
            System.out.print("\t");
            for (int j = 0; j < total_number_of_resources; j++) {
                System.out.print((char) (ch + j) + "  ");
            }
            for (int i = 0; i < total_number_of_process; i++) {
                System.out.print("\nP" + i + '\t');
                for (int j = 0; j < total_number_of_resources; j++) {
                    System.out.print(allocated_resources[i][j] + "  ");
                }
                System.out.print("\t");
                for (int j = 0; j < total_number_of_resources; j++) {
                    System.out.print(max_resorces[i][j] + "  ");
                }
            }
            Boolean crosscheck;
            crosscheck = deadlockcheck(allocated_resources, max_resorces, neededResources, total,
                    total_number_of_process,
                    total_number_of_resources);
            if (crosscheck == true) {
                System.out.println("Resources Allocated");
            } else {
                System.out.println("Resource Can't be Allocated");
            }
            sc.close();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char ch = 'A';
        // System.out.println("\n------------------------------------------------------------------------------------------");
        // System.out.println("\n\n\n\t\t\tBanker's Algorithm\n");

        int total_number_of_process, total_number_of_resources;
        System.out.print("Total Number Of Process \n->");
        total_number_of_process = sc.nextInt();
        System.out.print("Total Number Of Resource \n->");
        total_number_of_resources = sc.nextInt();

        int total[] = new int[total_number_of_resources];
        int allocated_resources[][] = new int[total_number_of_process][total_number_of_resources];
        int max_resorces[][] = new int[total_number_of_process][total_number_of_resources];

        for (int i = 0; i < total_number_of_process; i++) {
            System.out.println("Enter Allocated Resources for Process :" + (i + 1));
            for (int j = 0; j < total_number_of_resources; j++) {
                System.out.print((char) (ch + j) + "->");
                allocated_resources[i][j] = sc.nextInt();
            }
            System.out.println("Enter Maximum Resources for Process :" + (i + 1));
            for (int j = 0; j < total_number_of_resources; j++) {
                System.out.print((char) (ch + j) + "->");
                max_resorces[i][j] = sc.nextInt();
            }
        }

        System.out.println("Total Resources :");
        for (int i = 0; i < total_number_of_resources; i++) {
            System.out.print((char) (ch + i) + "->");
            total[i] = sc.nextInt();
        }

        // final int total_number_of_process = 5, total_number_of_resources = 3;
        // final int total[] = new int[] { 3, 3, 2 };
        // final int allocated_resources[][] = new int[][] { { 0, 1, 0 }, // P0
        // { 2, 0, 0 }, // P1
        // { 3, 0, 2 }, // P2
        // { 2, 1, 1 }, // P3
        // { 0, 0, 2 } }; // P4

        // final int max_resorces[][] = new int[][] { { 7, 5, 3 }, // P0
        // { 3, 2, 2 }, // P1
        // { 9, 0, 2 }, // P2
        // { 2, 2, 2 }, // P3
        // { 4, 3, 3 } }; // P4

        int neededResources[][] = new int[total_number_of_process][total_number_of_resources];
        for (int i = 0; i < total_number_of_process; i++) {
            for (int j = 0; j < total_number_of_resources; j++) {
                neededResources[i][j] = max_resorces[i][j] - allocated_resources[i][j];
            }
        }
        System.out.print("\nPrc\t");
        System.out.print("Alloc\t\t");
        System.out.print("Max\t\n");
        System.out.print("\t");
        for (int j = 0; j < total_number_of_resources; j++) {
            System.out.print((char) (ch + j) + "  ");
        }
        System.out.print("\t");
        for (int j = 0; j < total_number_of_resources; j++) {
            System.out.print((char) (ch + j) + "  ");
        }
        for (int i = 0; i < total_number_of_process; i++) {
            System.out.print("\nP" + i + '\t');
            for (int j = 0; j < total_number_of_resources; j++) {
                System.out.print(allocated_resources[i][j] + "  ");
            }
            System.out.print("\t");
            for (int j = 0; j < total_number_of_resources; j++) {
                System.out.print(max_resorces[i][j] + "  ");
            }
        }

        boolean result;
        // Algorithm a;
        // System.out.println("\n\n\n\t\t\tResults\n");
        System.out.println(
                "\n------------------------------------------------------------------------------------------");
        System.out.println("Banker's Algorithm\n");
        result = deadlockcheck(allocated_resources, max_resorces, neededResources, total, total_number_of_process,
                total_number_of_resources);
        int choice;
        if (result) {
            // print(allocated_resources, max_resorces, neededResources,
            // total_number_of_process,
            // total_number_of_resources);
            System.out.print("\n\n\nEnter 1 to request resource and 2 to terminate\n->");
            choice = sc.nextInt();
            if (choice == 1) {
                resource_request(allocated_resources, max_resorces, neededResources, total, total_number_of_process,
                        total_number_of_resources);
            } else {
                System.out.println("Thank You ended with exit(0)");
            }
        } else {
            System.out.println("Thank You");
        }
        sc.close();
    }
}
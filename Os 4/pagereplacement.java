import java.util.Scanner;

public class pagereplacement {
    public static void fifo(int pages, int frames, int Allpages[], int framecontents[]) {
        int totalhit = 0, totalfault = 0, currentindex = 0;
        boolean flag = true;
        int sol[][] = new int[frames][pages];
        for (int i = 0; i < frames; i++) {
            framecontents[i] = -1;
        }
        for (int i = 0; i < pages; i++) {
            flag = true;
            for (int j = 0; j < frames; j++) {
                if (Allpages[i] == framecontents[j]) {
                    totalhit++;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                totalfault++;
                framecontents[currentindex] = Allpages[i];
                currentindex++;
                if (currentindex == frames)
                    currentindex = 0;
            }
            for (int j = 0; j < frames; j++)
                sol[j][i] = framecontents[j];
        }
        for (int i = 0; i < frames; i++) {
            System.out.print("Frame "+(i+1)+"  |\t");
            for (int j = 0; j < pages; j++) {
                if (sol[i][j] != -1)
                    System.out.print(sol[i][j] + "  |\t");
                else {
                        System.out.print("N/A|\t");
                    }
            }
            System.out.println();
        }
        System.out.println("\nHits - " + totalhit + " faults - " + totalfault);
    }

    public static void optimalpagereplacement(int pages, int frames, int Allpages[], int framecontents[]) {
        int i, j, k, check, totalfault = 0, totalhit = 0, currentindex = 0, position = 0;
        boolean flagf, FrameisFull = false, flag = true;
        int sol[][] = new int[frames][pages];
        for (i = 0; i < frames; i++) {
            framecontents[i] = -1;
        }
        for (i = 0; i < pages; i++) {
            flagf = true;
            for (j = 0; j < frames; j++) {
                if (Allpages[i] == framecontents[j]) {
                    totalhit++;
                    flagf = false;
                    break;
                }
            }
            if (flagf) {
                totalfault++;
                if (FrameisFull) {
                    check = 0;
                    position = 0;
                    for (j = 0; j < frames; j++) {
                        for (k = (i + 1); k < pages; k++) {
                            flag = true;
                            if (framecontents[j] == Allpages[k]) {
                                if (k > check) {
                                    check = k;
                                    position = j;
                                }
                                flag = false;
                                break;
                            }
                        }
                        if (flag == true) {
                            position = j;
                            check = pages;
                            break;
                        }
                    }
                    framecontents[position] = Allpages[i];
                } else {
                    framecontents[currentindex] = Allpages[i];
                    currentindex++;
                    if (currentindex == frames) {
                        currentindex = 0;
                        FrameisFull = true;
                    }
                }
            }
            for (j = 0; j < frames; j++)
                sol[j][i] = framecontents[j];
        }
        for (i = 0; i < frames; i++) {
            System.out.print("Frame "+(i+1)+"  |\t");
            for (j = 0; j < pages; j++) {
                if (sol[i][j] != -1)
                    System.out.print(sol[i][j] + "  |\t");
                else {
                        System.out.print("N/A|\t");
                    }
            }
            System.out.println();
        }
        System.out.println("\nHits - " + totalhit + " Faults - " + totalfault);
    }

    public static void leastrecentlyused(int pages, int frames, int Allpages[], int framecontents[]) {
        int i, j, k, check, totalfault = 0, totalhit = 0, currentindex = 0, position = 0;
        boolean flagf, FrameisFull = false, flag = true;
        int sol[][] = new int[frames][pages];
        for (i = 0; i < frames; i++) {
            framecontents[i] = -1;
        }
        for (i = 0; i < pages; i++) {
            flagf = true;
            for (j = 0; j < frames; j++) {
                if (Allpages[i] == framecontents[j]) {
                    totalhit++;
                    flagf = false;
                    break;
                }
            }
            if (flagf) {
                totalfault++;
                if (FrameisFull) {
                    check = pages;
                    position = 0;
                    for (j = 0; j < frames; j++) {
                        for (k = (i - 1); k >= 0; k--) {
                            flag = true;
                            if (framecontents[j] == Allpages[k]) {
                                if (k < check) {
                                    check = k;
                                    position = j;
                                }
                                flag = false;
                                break;
                            }
                        }
                        if (flag == true) {
                            position = j;
                            check = pages;
                            break;
                        }
                    }
                    framecontents[position] = Allpages[i];
                } else {
                    framecontents[currentindex] = Allpages[i];
                    currentindex++;
                    if (currentindex == frames) {
                        currentindex = 0;
                        FrameisFull = true;
                    }
                }
            }
            for (j = 0; j < frames; j++)
                sol[j][i] = framecontents[j];
        }
        for (i = 0; i < frames; i++) {
            System.out.print("Frame "+(i+1)+"  |\t");
            for (j = 0; j < pages; j++) {
                if (sol[i][j] != -1)
                    System.out.print(sol[i][j] + "  |\t");
                else {
                        System.out.print("N/A|\t");
                    }
            }
            System.out.println();
        }
        System.out.println("\nTotal Hits - " + totalhit + " Total Faults - " + totalfault);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Number Of Frames \n->");
        int frames = sc.nextInt();
        System.out.print("Length of pages \n->");
        int pages = sc.nextInt();
        int Allpages[] = new int[pages];
        int framecontents[] = new int[frames];
        System.out.println("\nEnter the pages:\n");
        for (int i = 0; i < pages; i++) {
            System.out.print("Page :" + (i + 1) + "\n");
            Allpages[i] = sc.nextInt();
        }
        int choice = 0;
        while (choice != 4) {
            System.out.println("\n1.Fifo\n2.Least recently used\n3.Optimal page erplacement\n4.Exit");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    fifo(pages, frames, Allpages, framecontents);
                    break;
                case 2:
                    leastrecentlyused(pages, frames, Allpages, framecontents);
                    break;
                case 3:
                    optimalpagereplacement(pages, frames, Allpages, framecontents);
                    break;

                default:
                    System.out.println("Wrong Choice Enter Again");
                    break;
            }
        }
        sc.close();
    }
}

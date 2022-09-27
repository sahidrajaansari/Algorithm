public class Linked_list_3 {
    public static class Node {
        int data;
        Node Next;
    }

    public static class Linked_list {
        Node head;
        public void insert(int a) {
            Node node = new Node();
            node.data = a;
            node.Next = null;
            if (head == null) {
                this.head = node;
                return;
            }
            Node temp = head;
            this.head = node;
            node.Next = temp;
        }

        public void show() {
            Node temp = head;
            while (temp != null) {
                System.out.println("Data is " + temp.data);
                temp=temp.Next;
            }
        }
    }
    public static void main(String[] args) {
        // Linked_list l1=new Linked_list();
        // l1.insert(1);
        // l1.insert(2);
        // l1.insert(3);
        // l1.insert(4);
        // Linked_list l2=new Linked_list();
        // l2.insert(5);
        // l2.insert(6);
        // l2.insert(7);
        // l2.insert(8);
        // l1.insert(9);
        // l1.show();
        // l2.show();
        Linked_list [] l=new Linked_list[2];
        for(int i=0;i<2;i++){
            l[i]=new Linked_list();
        }
        l[0].insert(1);
        l[0].insert(2);
        l[0].insert(3);
        l[0].insert(4);
        l[0].insert(5);
        l[0].show();
        l[1].insert(5);
        l[1].insert(6);
        l[1].insert(7);
        l[1].insert(8);
        l[0].insert(9);
        l[0].show();
        l[1].show();

    }
}

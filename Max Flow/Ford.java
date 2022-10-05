class Node {
    int vertices;
    int weight;
    Node next;

    public Node(int val, int w) {
        vertices = val;
        weight = w;
        next = null;
    }
}
class Linked_l {
    Node head;

    public Linked_l() {
        head = null;
    }

    public void Push(int val, int w) {
        Node temp = head;
        Node newNode = new Node(val, w);
        if (head == null) {
            head = new Node(val, w);
            return;
        }
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
        return;
    }

    public void display() {
        Node temp = head;
        while (temp != null) {
            System.out.print("(" + temp.vertices + "," + temp.weight + ")" + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}

class QNode{
    int val;
    QNode next;
    public QNode(int val){
        this.val=val;
        next=null;
    }
}
public class Ford {
    
}

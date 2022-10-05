class QNode{
    int v1;
    int v2;
    int weight;
    QNode next;
    public QNode(int v1,int v2,int weight){
        this.v1=v1;
        this.v2=v2;
        this.weight=weight;
        next=null;
    }
}
class Qu{
    QNode head;
    QNode tail;
    public Qu(){
        head=null;
        tail=null;
    }
    boolean isempty()
    {
        if(head==null && tail==null){
            return true;
        }
        return false;
    }
    public void enque(int v1,int v2,int weight){
        QNode temp=new QNode(v1,v2,weight);
        if(head==null){
            this.head=this.tail= temp;
            return;
        }
            System.out.println("Hello");
            this.tail.next= temp;
            this.tail=temp;
            return;
    }
    public int deque(){
        if(isempty()){
            return -1;
        }
        else{
            int n=head.weight;
            head=head.next;
            return n;
        }
    }
    public void display(){
        QNode temp=head;
        while(temp!=null){
            System.out.print("(" + temp.v1 + "," + temp.weight + ")" + " ");
            temp=temp.next;
        }
    }
}
public class Queue {
    public static void main(String[] args) {
        Qu q=new Qu();
        q.enque(0,0,1);
        q.enque(0,0,2);
        q.enque(0,0,3);
        q.enque(0,0,4);
        q.enque(0,0,5);
        q.display();
        System.out.println();
        System.out.print(q.deque());
    }
}

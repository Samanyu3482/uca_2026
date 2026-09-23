
import java.util.*;

class Reverse {
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }

    public Node reverse(Node head) {
        // Base case
        if (head == null || head.next == null) {
            return head;
        }

        Node newHead = reverse(head.next);

        head.next.next = head;
        head.next = null;

        return newHead;
    }

    public static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {

   
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(5);

        System.out.println("Original List:");
        printList(head);

        Reverse obj = new Reverse();

    
        head = obj.reverse(head);

        System.out.println("Reversed List:");
        printList(head);
    }
}

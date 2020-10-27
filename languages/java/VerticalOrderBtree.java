package hashing;
import java.util.TreeMap;
import java.util.Vector;
import java.util.Map.Entry;
public class VerticalOrderBtree {
	static class Node{
		int key;
		Node left;
		Node right;
		
		Node (int data){
			key=data;
			left=null;
			right=null;
		}
	}
	
	static void getVerticalOrder(Node root,int hd,TreeMap<Integer,Vector<Integer>>m) {
		if (root==null) // base case
			return;
		
		Vector<Integer>get = m.get(hd);  // get vector list as hd
		
		if(get==null) {
			get = new Vector<>();
			get.add(root.key);
		}
		else
			get.add(root.key);
		
		m.put(hd,get); // passing key,value pair to TreeMap m
		
		getVerticalOrder(root.left,hd-1,m);  //stores nodes in left subtree
		getVerticalOrder(root.right,hd+1,m);  //stores nodes in right subtree
	}
	
	static void printVerticalOrder(Node root) {
		TreeMap<Integer,Vector<Integer>>m = new TreeMap<>();
		int hd=0;
		getVerticalOrder(root,hd,m);
		
		for(Entry<Integer,Vector<Integer>> entry : m.entrySet())
		System.out.println(entry.getValue());
	}
	
	public static void main(String[] args) {
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		root.right.left = new Node(6);
		root.right.right = new Node(7);
		root.right.right.left = new Node(8);
		root.right.right.right = new Node(9);
		System.out.println("VERTICAL ORDER:");
		printVerticalOrder(root);
	}
}

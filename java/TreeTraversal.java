package com.abc.edf;

import java.util.*;

public class TreeTraversal {
  public static void main(String[] args) {
    // construct tree
    //          1
    //        /   \
    //       2     3
    //        \   / \
    //         4 5   6
    Node root = new Node(1);
    root.left = new Node(2);
    root.right = new Node(3);
    root.left.right = new Node(4);
    root.right.left = new Node(5);
    root.right.right = new Node(6);

    TreeTraversal t = new TreeTraversal();

    System.out.println(t.preOrder(root));
    System.out.println(t.preOrderStackApproach(root));

    System.out.println(t.inOrder(root));
    System.out.println(t.inOrderStackApproach(root));

    System.out.println(t.postOrder(root));
    System.out.println(t.postOrderReversePreOrder(root));
    System.out.println(t.postOrderStackApproach(root));
  }

  /* ---------------             pre order        ----------------- */
  private List<Integer> preOrder(Node root) {
    List<Integer> result = new ArrayList<>();
    preOrderHelper(root, result);
    return result;
  }

  private void preOrderHelper(Node root, List<Integer> result) {
    if (root == null) return;
    result.add(root.val);
    preOrderHelper(root.left, result);
    preOrderHelper(root.right, result);
  }

  private List<Integer> preOrderStackApproach(Node root) {
    List<Integer> result = new ArrayList<>();
    if (root == null) return result;

    Deque<Node> stack = new LinkedList<>();
    stack.offerLast(root);
    while (!stack.isEmpty()) {
      Node node = stack.pollLast();
      result.add(node.val);
      if (node.right != null) stack.offerLast(node.right);
      if (node.left != null) stack.offerLast(node.left);
    }

    return result;
  }

  /* ---------------             in order        ----------------- */
  private List<Integer> inOrder(Node root) {
    List<Integer> result = new ArrayList<>();
    inOrderHelper(root, result);
    return result;
  }

  private void inOrderHelper(Node root, List<Integer> result) {
    if (root == null) return;
    inOrderHelper(root.left, result);
    result.add(root.val);
    inOrderHelper(root.right, result);
  }

  /**
   * The basic idea is to use a current node to keep track of the next movement.
   * After each outer loop, current node can either be
   * 1) null
   * 2) right node of the last left node
   * The inner loop should check (curr != null) such that in the first case we would not go down the
   * left pass again.
   */
  private List<Integer> inOrderStackApproach(Node root) {
    List<Integer> result = new ArrayList<>();

    Deque<Node> stack = new LinkedList<>();
    Node curr = root;
    while (!stack.isEmpty() || curr != null) {
      while (curr != null) { // After loop, curr will points to null
        stack.offerLast(curr);
        curr = curr.left;
      }
      Node tmp = stack.pollLast();
      result.add(tmp.val);
      curr = tmp.right;
    }

    return result;
  }

  /* ---------------             post order        ----------------- */
  private List<Integer> postOrder(Node root) {
    List<Integer> result = new ArrayList<>();
    postOrderHelper(root, result);
    return result;
  }

  private void postOrderHelper(Node root, List<Integer> result) {
    if (root == null) return;
    postOrderHelper(root.left, result);
    postOrderHelper(root.right, result);
    result.add(root.val);
  }

  private List<Integer> postOrderReversePreOrder(Node root) {
    List<Integer> result = new ArrayList<>();
    if (root == null) return result;

    Deque<Node> stack = new LinkedList<>();
    stack.offerLast(root);
    while (!stack.isEmpty()) {
      Node node = stack.pollLast();
      result.add(node.val);
      if (node.left != null) stack.offerLast(node.left);
      if (node.right != null) stack.offerLast(node.right);
    }

    Collections.reverse(result);
    return result;
  }

  private List<Integer> postOrderStackApproach(Node root) {
    List<Integer> result = new ArrayList<>();
    if (root == null) return result;

    Deque<Node> stack = new LinkedList<>();
    stack.offerLast(root);
    Node curr, prev = null;
    while (!stack.isEmpty()) {
      curr = stack.peekLast();
      if ((curr.left == null && curr.right == null) || (prev != null && (prev == curr.left || prev == curr.right))) {
        curr = stack.pollLast();
        result.add(curr.val);
        prev = curr;
      } else {
        if (curr.right != null) stack.offerLast(curr.right);
        if (curr.left != null) stack.offerLast(curr.left);
      }
    }
    return result;
  }


  static class Node {
    int val;
    Node left, right;

    Node(int val) {
      this.val = val;
    }
  }
}

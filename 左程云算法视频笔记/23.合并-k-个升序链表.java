/*
 * @lc app=leetcode.cn id=23 lang=java
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] arr) {
        // 小根堆
        PriorityQueue<ListNode> heap = new PriorityQueue<>((a, b) -> a.val - b.val);
        for (ListNode h : arr) {
            if (h != null)
                heap.add(h);
        }
        if (heap.isEmpty())
            return null;
        // 先弹出一个节点作为头部，一个变量作为链表末尾
        ListNode h = heap.poll();
        ListNode pre = h;
        if (pre.next != null) {
            heap.add(pre.next);
        }
        while (!heap.isEmpty()) {
            ListNode cur = heap.poll();
            pre.next = cur;
            pre = pre.next;
            if (cur.next != null) {
                heap.add(cur.next);
            }
        }
        return h;
    }
}
// @lc code=end

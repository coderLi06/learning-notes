// setAll功能的哈希表
// 测试链接 : https://www.nowcoder.com/practice/7c4559f138e74ceb9ba57d76fd169967
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.HashMap;

public class Code01_SetAllHashMap {

	public static HashMap<Integer, int[]> map = new HashMap<>();
	public static int setAllValue;
	public static int setAllTime;
	public static int cnt;

	public static void put(int k, int v) {
		if (map.containsKey(k)) {
			int[] value = map.get(k);
			value[0] = v;
			value[1] = cnt++;
		} else {
			map.put(k, new int[] { v, cnt++ });
		}
	}

	public static void setAll(int v) {
		setAllValue = v;
		setAllTime = cnt++;
	}

	public static int get(int k) {
		if (!map.containsKey(k)) {
			return -1;
		}
		int[] value = map.get(k);
		if (value[1] > setAllTime) {
			return value[0];
		} else {
			return setAllValue;
		}
	}

	public static int n, op, a, b;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer in = new StreamTokenizer(br);
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		while (in.nextToken() != StreamTokenizer.TT_EOF) {
			map.clear();
			setAllValue = 0;
			setAllTime = -1;
			cnt = 0;
			n = (int) in.nval;
			for (int i = 0; i < n; i++) {
				in.nextToken();
				op = (int) in.nval;
				if (op == 1) {
					in.nextToken();
					a = (int) in.nval;
					in.nextToken();
					b = (int) in.nval;
					put(a, b);
				} else if (op == 2) {
					in.nextToken();
					a = (int) in.nval;
					out.println(get(a));
				} else {
					in.nextToken();
					a = (int) in.nval;
					setAll(a);
				}
			}
		}
		out.flush();
		out.close();
		br.close();
	}

}

// 实现LRU结构
public class Code02_LRU {

	// 测试链接 : https://leetcode.cn/problems/lru-cache/
	class LRUCache {
    //双向链表加HashMap的结构方便频繁删除
		class DoubleNode {
			public int key;
			public int val;
			public DoubleNode last;
			public DoubleNode next;

			public DoubleNode(int k, int v) {
				key = k;
				val = v;
			}
		}

		class DoubleList {
			private DoubleNode head;
			private DoubleNode tail;

			public DoubleList() {
				head = null;
				tail = null;
			}

			public void addNode(DoubleNode newNode) {
				if (newNode == null) {
					return;
				}
				if (head == null) {
					head = newNode;
					tail = newNode;
				} else {
					tail.next = newNode;
					newNode.last = tail;
					tail = newNode;
				}
			}

			public void moveNodeToTail(DoubleNode node) {
				if (tail == node) {
					return;
				}
				if (head == node) {
					head = node.next;
					head.last = null;
				} else {
					node.last.next = node.next;
					node.next.last = node.last;
				}
				node.last = tail;
				node.next = null;
				tail.next = node;
				tail = node;
			}

			public DoubleNode removeHead() {
				if (head == null) {
					return null;
				}
				DoubleNode ans = head;
				if (head == tail) {
					head = null;
					tail = null;
				} else {
					head = ans.next;
					ans.next = null;
					head.last = null;
				}
				return ans;
			}

		}

		private HashMap<Integer, DoubleNode> keyNodeMap;

		private DoubleList nodeList;

		private final int capacity;

		public LRUCache(int cap) {
			keyNodeMap = new HashMap<>();
			nodeList = new DoubleList();
			capacity = cap;
		}

		public int get(int key) {
			if (keyNodeMap.containsKey(key)) {
				DoubleNode ans = keyNodeMap.get(key);
				nodeList.moveNodeToTail(ans);
				return ans.val;
			}
			return -1;
		}

		public void put(int key, int value) {
			if (keyNodeMap.containsKey(key)) {
				DoubleNode node = keyNodeMap.get(key);
				node.val = value;
				nodeList.moveNodeToTail(node);
			} else {
				if (keyNodeMap.size() == capacity) {
					keyNodeMap.remove(nodeList.removeHead().key);
				}
				DoubleNode newNode = new DoubleNode(key, value);
				keyNodeMap.put(key, newNode);
				nodeList.addNode(newNode);
			}
		}

	}

}

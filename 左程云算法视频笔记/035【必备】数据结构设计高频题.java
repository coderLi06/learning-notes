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
import java.util.ArrayList;
import java.util.HashSet;
import java.util.PriorityQueue;

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
public class Code02_LRU {//(least recently used)缓存结构

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

		class DoubleList {//双向链表存(k,v)节点，其内存地址作为map的value
			private DoubleNode head;//头表示最早
			private DoubleNode tail;//尾表示最晚

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
			//移动本身存在的节点到尾部
			public void moveNodeToTail(DoubleNode node) {
				if (tail == node) {
					return;
				}
				if (head == node) {
					head = node.next;
					head.last = null;
				} else {
					node.last.next = node.next;//前面连后面
					node.next.last = node.last;//后面连前面
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
			//更新操作
			if (keyNodeMap.containsKey(key)) {
				DoubleNode node = keyNodeMap.get(key);
				node.val = value;
				nodeList.moveNodeToTail(node);
			}//新增操作，需要讨论DoubleList是否已满 
			else {
				if (keyNodeMap.size() == capacity) {
					//nodeList.removeHead()返回节点，
					//找到它的key作为HashMap的key删除
					keyNodeMap.remove(nodeList.removeHead().key);
				}
				DoubleNode newNode = new DoubleNode(key, value);
				keyNodeMap.put(key, newNode);
				nodeList.addNode(newNode);
			}
		}

	}

}

// 插入、删除和获取随机元素O(1)时间的结构
public class Code03_InsertDeleteRandom {

	// 测试链接 : https://leetcode.cn/problems/insert-delete-getrandom-o1/
	class RandomizedSet {

		public HashMap<Integer, Integer> map;//查表可得数据在动态数组的下标

		public ArrayList<Integer> arr;//动态数组，数据与下标对应

		public RandomizedSet() {
			map = new HashMap<>();
			arr = new ArrayList<>();
		}

		public boolean insert(int val) {
			if (map.containsKey(val)) {
				return false;
			}
			map.put(val, arr.size());
			arr.add(val);
			return true;
		}

		//删除的问题在于，动态数组中会留空，随机获取行为可能获取到不存在的值
		//解决：用最后一个填补洞
		public boolean remove(int val) {
			if (!map.containsKey(val)) {
				return false;
			}
			int valIndex = map.get(val);
			int endValue = arr.get(arr.size() - 1);
			map.put(endValue, valIndex);//hashMap.put(k,v)插入键值对
			arr.set(valIndex, endValue);//arrayList.set(i,v)将下标i的值改为v
			map.remove(val);
			arr.remove(arr.size() - 1);
			return true;
		}

		public int getRandom() {
			return arr.get((int) (Math.random() * arr.size()));
		}

	}

}



// 插入、删除和获取随机元素O(1)时间且允许有重复数字的结构
public class Code04_InsertDeleteRandomDuplicatesAllowed {

	// 测试链接 :
	// https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/
	class RandomizedCollection {

		public HashMap<Integer, HashSet<Integer>> map;

		public ArrayList<Integer> arr;

		public RandomizedCollection() {
			map = new HashMap<>();
			arr = new ArrayList<>();
		}

		public boolean insert(int val) {
			arr.add(val);
			HashSet<Integer> set = map.getOrDefault(val, new HashSet<Integer>());
			set.add(arr.size() - 1);
			map.put(val, set);
			return set.size() == 1;
		}

		public boolean remove(int val) {
			if (!map.containsKey(val)) {
				return false;
			}
			HashSet<Integer> valSet = map.get(val);
			int valAnyIndex = valSet.iterator().next();
			int endValue = arr.get(arr.size() - 1);
			if (val == endValue) {
				valSet.remove(arr.size() - 1);
			} else {
				HashSet<Integer> endValueSet = map.get(endValue);
				endValueSet.add(valAnyIndex);
				arr.set(valAnyIndex, endValue);
				endValueSet.remove(arr.size() - 1);
				valSet.remove(valAnyIndex);
			}
			arr.remove(arr.size() - 1);
			if (valSet.isEmpty()) {
				map.remove(val);
			}
			return true;
		}

		public int getRandom() {
			return arr.get((int) (Math.random() * arr.size()));
		}
	}

}

// 快速获得数据流的中位数的结构
public class Code05_MedianFinder {

	// 测试链接 : https://leetcode.cn/problems/find-median-from-data-stream/
	class MedianFinder {
//大根堆存小的一半数据，小根堆存大的一半数据
		private PriorityQueue<Integer> maxHeap;

		private PriorityQueue<Integer> minHeap;

		public MedianFinder() {
			maxHeap = new PriorityQueue<>((a, b) -> b - a);//快速建立大根堆
			minHeap = new PriorityQueue<>((a, b) -> a - b);//快速建立小根堆
		}//默认小根堆，通过b-a调整优先级，所有比较器默认返回-1则a优先级高

		public void addNum(int num) {
			if (maxHeap.isEmpty() || maxHeap.peek() >= num) {
				maxHeap.add(num);//进大根堆的情况：大根堆为空，或者大根堆的堆顶元素大于等于num
			} else {
				minHeap.add(num);
			}
			balance();//每次添加完，对两个堆容量进行平衡，保证两个堆的容量差不超过1
		}

		public double findMedian() {
			if (maxHeap.size() == minHeap.size()) {
				return (double) (maxHeap.peek() + minHeap.peek()) / 2;
			} else {
				return maxHeap.size() > minHeap.size() ? maxHeap.peek() : minHeap.peek();
			}
		}

		private void balance() {
			if (Math.abs(maxHeap.size() - minHeap.size()) == 2) {//两个堆的大小差为2时，进行平衡
				if (maxHeap.size() > minHeap.size()) {//大根堆个数较多，将其堆顶最大元素放入小根堆顶
					minHeap.add(maxHeap.poll());//poll()方法返回堆顶元素并删除
				} else {
					maxHeap.add(minHeap.poll());
				}
			}
		}

	}

}
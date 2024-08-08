# 题目一：是否为环形链表

## 面试问题
为什么一定会相遇，有没有可能追不上，请证明？如果 slow 每次走 1 步，fast 走 3、4、5、n 步呢，请证明？

看似在基本情况下（fast 走 2，slow 走 1），如果进入环形时的距离差 N 为奇数，环形总长 C 为偶数，永远无法追上。

<img src="D:\code\113-issues-master\113-issues-master\24年-04月28日--链表OJ讲解\4-28.png" />

## 变量定义
- **L**: 从 head 到环形入口的距离
- **x**: slow 进圈之前 fast 在环内走的圈数
- **N**: slow 进入环形时的距离差
- **C**: 环形的总长

## 证明
在 fast 走 3 步，slow 走 1 步的情况下：
\[ 3L = x*C + C - N \]、
\[ 2L = x*C + C - N \]、
**所以不可能出现C为偶数，N为奇数的情况，也就是一定会相遇**

# 题目二：环形链表的入口

## 变量定义
- **L**: 从 head 到环形入口的距离
- **x**: slow 进圈之前 fast 在环内走的圈数
- **N**: slow 进入环形时的距离差
- **C**: 环形的总长

## 证明
在 fast 走 2 步，slow 走 1 步的情况下：
- **fast**: \( \text{fast} = L + x \cdot C + N \)（注意此时的 x 不可能为 0，fast 和 slow 的距离不可能相同）
- **slow**: \( \text{slow} = L + N \)

因此：
\[ L = x \cdot C - N = (x - 1) \cdot C + (C - N) \]

# 题目三：复制带随机指针的链表

## 方法一
1. 复制每个节点，插入到原节点的后面
2. 将复制节点的随机指针指向原节点 random 的下一个节点

```cpp
cur = head;
while (cur) {
    Node* copy = cur->next;
    if (!cur->random)
        copy->random = nullptr;
    else
        copy->random = cur->random->next;
    cur = copy->next;
}
```
3.将复制的链表拆分出来，注意原链表的next指针可以恢复（其实不查）

## 方法二：c++ librery
```
#include <unordered_map>

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    // Step 1: Create a copy of each node and store them in a map
    std::unordered_map<Node*, Node*> nodeMap;
    Node* current = head;
    while (current) {
        nodeMap[current] = new Node(current->val);
        current = current->next;
    }

    // Step 2: Set up next and random pointers for the copied nodes
    current = head;
    while (current) {
        nodeMap[current]->next = nodeMap[current->next];
        nodeMap[current]->random = nodeMap[current->random];
        current = current->next;
    }

    // Return the head of the copied list
    return nodeMap[head];
}
```
<img src = D:\code\113-issues-master\113_issues_master\24年-05月12日--二叉树\5-12-上午.png/>

leetcode题目：
第一题：232 用栈实现队列
思路：用两个栈pushstack和popstack，pushstack负责入队，popstack负责出队，当popstack为空时，将pushstack中的元素全部倒入popstack中（栈后进先出的特性使得数据前后颠倒），这样popstack的栈顶元素就是队列的队头元素，popstack的栈底元素就是队列的队尾元素。
在原本的pushstack中的栈顶其实是模拟队列的队尾（添加数据），此时删除就删错了，通过将数据倒入另一个popstack实现颠倒，从而popstack的栈顶变为模拟队列的队头，这样就可以实现删除操作。 

树：
注意：
1. 树的层数是从1开始的，数组之所以从0开始，是由于 a[i] 等价于 *(a+i) ，所以a[0]等价于a+0,是无奈之举，若下标从1开始，那么 a[2]{第二个元素} 等价于 *(a+2){第三个元素}
2. 节点的degree是节点的子树个数（而非子节点个数）
3. 树的degree和树的height注意区分

二叉树：
注意：
1. 满二叉树和完全二叉树区分
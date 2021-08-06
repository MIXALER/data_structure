# 必读文章

## 1 学习算法和刷题的思路指南

### 1.1 数据结构的存储方式

数据结构的存储方式只有两种：数组（顺序存储）和链表（链式存储）、

### 1.2 数据结构的基本操作

数据结构种类很多，但它们存在的目的都是在不同的应用场景，尽可能高效地增删改查。

## 2 动态规划详解

首先，动态规划问题的一般形式就是求最值。其核心问题时穷举。但是动态规划的穷举有点特别，因为这类问题存在**重叠子问题**，如果暴力穷举会效率低下，所以需要备忘录来优化穷举过程，避免不必要的计算（空间换时间）。而且，动态规划问题会具备最优子结构，可以通过子问题的最值得到原问题的最值。

虽然动态规划的核心思想就时穷举求最值，但是问题千变万化，穷举所有可行解不是一件容易的事，只有列出正确的**状态转移方程**才能正确的穷举。

写出状态转移方程式最困难的。其思维框架如下：

明确 base case -》明确状态 -》 明确选择 -》定义 dp 数组/函数的含义

```python
# 初始化 base case
dp[0][0][...] = base
# 进行状态转移
for 状态1 in 状态1的所有取值
	for 状态2 in 状态2的所有取值
		for ...
			dp[状态1][状态2][...] = 求最值(选择1, 选择2,...)
```

## 3 回溯算法详解

回溯算法就是我们常说的 DFS 算法，本质上是一种暴力穷举算法

解决一个回溯问题，实际上就式一个决策树的遍历过程。只需要思考三个问题：

1.  路径：也就是已经做出的选择。
2.  选择列表：也就是你当前可以做的选择
3.  结束条件：也就是到达决策树底层，无法再做选择的条件

其框架如下：

```python
result = []
def backtrace(路径，选择列表):
	if 满足结束条件:
		result.add(路径)
		return
		
	for 选择 in 选择列表:
		做选择
		backtrace(路径，选择列表)
		撤销选择
```

其核心就是 for 循环里面的递归，在递归调用之前做选择，递归调用之后撤销选择

## 4 BFS 算法框架套路详解

BFS 相对于 DFS 的最主要的区别就是：BFS 找到的路径一定是最短的，但代价就是空间复杂度要比 DFS 大很多。

框架：

```c++
int BFS(Node start, Node target)
{
	queue<Node> q;
	set<Node> visited;
    
	q.add(start);
	visited.add(start);
    int step = 0;
    
    while(!q.empty)
    {
        int size = q.size();
        for(int i = 0, i< size; i++)
        {
            Node cur = q.front();
            if	(cur == target)
                return step;
            for	(Node x : cur.adj())
            {
                if (x is not in visited)
                {
                    q.add(x);
                    visited.add(x);
                }
            }
        }
        st
    }
}
```

## 5 二分查找详解

二分查找场景：寻找一个数，寻找左侧边界，寻找右侧边界。

框架：

```c++
int binarySearch(vector<int> nums, int target)
{
	int left = 0, right = ...;
    while(...)
    {
        int mid = left + (right - left) / 2;
        if	(nums[mid] == target)
        {
            ...
        }
        else if(nums[mid] < target)
        {
            left = ...
        }
       	else if(nums[mid] > target)
        {
            right = ...
        }
    }
    return ...;
}
```

上面 ... 部分是可能出现细节问题的地方。计算 mid 的时候需要防止溢出。left + (right - left)/2 和 (left + right)/2 的结果相同，但是前一种方式防止了相加导致的整数溢出。

## 6 滑动窗口算法框架

算法逻辑如下：

```c++
woid slidingWindow(string s, string t)
{
    unordered_map(char, int) need, window;
    for (char c: t) need[c]++;
    
    int left = 0, right = 0;
    int valid = 0;
	while(right < s.size())
	{
    	// c 是将移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一系列更新
        ...
        
  
    	// 判断左侧窗口是否需要收缩
    	while(window needs shrink)
    	{
        	// d 是将移出窗口的字符
            char d = s[left];
            // 左移窗口
       	 	left++;
            // 进行窗口内数据的一系列更新
            ...
    	}
	}
}

```

算法时间复杂度为 O(N)，比暴力算法高效得多

### 7 双指针技巧解题框架

# 动态规划系列

## 1 动态规划设计：最长递增子序列



# 数据结构系列

# 算法思维系列

# 高频面试系列






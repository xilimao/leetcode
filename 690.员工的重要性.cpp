/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start

// Definition for Employee.
// class Employee {
// public:
//     int id;
//     int importance;
//     vector<int> subordinates;
// };


class Solution {
public:
    //递归 / DFS / 深度优先搜索
    // unordered_map<int, Employee*> mp;

    // int dfs(int id){
    //     Employee* employee = mp[id];
    //     int total = employee->importance;

    //     for(int subId : employee->subordinates)
    //     {
    //         total +=  dfs(subId);
    //     }

    //     return total;
    // } 

    // int getImportance(vector<Employee*> employees, int id) {

    //     for (auto &employee : employees)
    //     {
    //         mp[employee->id] = employee;
    //     }
        
    //     return dfs(id);
    // }

    //迭代 / BFS / 广度优先搜索
    int getImportance(vector<Employee*> employees, int id) 
    {
        //将每个员工的ID 以及其对应的数据结构放入到map表中-便于查找
        unordered_map<int, Employee*> mp;
        //使用引用,能大幅节省时间
        for (auto &employee : employees)
        {
            mp[employee->id] = employee;
        }
        
        //使用栈来存储ID,每次弹出进行操作
        queue<int> qId;
        qId.push(id);

        int total = 0;
        while (!qId.empty())
        {
            //弹出获取当前ID
            int curId = qId.front();
            qId.pop();
            //将总数添加
            total += mp[curId]->importance;
            //将ID压栈(如果有的话)
            for (auto i : mp[curId]->subordinates)
            {
                qId.push(i);
            }
        }
        return total;
    }
};
// @lc code=end


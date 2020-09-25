// unothelinkedlist.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define BP (cout<<endl)

#define DOCK() do{                       \
                                  int dock;     \
                                  cin >> dock;    \
}while(0)

class Graph
{
public:
    void BFS(int n, vector<vector<int>>& e)
    {
        vector<vector<pair<int, int>>> g(n);
        queue<int> v;
        vector<int> seen(n, 0);

        // covert edge to adjacency list
        for (auto ei : e)
        {
            g[ei[0]].push_back({ei[1], ei[2]});
            g[ei[1]].push_back({ei[0], ei[2]});
        }

        cout << "BFS: ";

        for (int i = 0; i < n; ++i)
        {
            if (seen[i])
                continue;

            v.push(i);

            while (v.size())
            {
                int vi = v.front();
                v.pop();

                seen[vi]++;
                cout << vi << " ";

                for (auto vw : g[vi])
                {
                    if (!seen[vw.first])
                        v.push(vw.first);
                }
            }
        }

        cout << endl;
    }

    void DFS(int n, vector<vector<int>>& e)
    {
        vector<vector<pair<int, int>>> g(n);
        stack<int> v;
        vector<int> seen(n, 0);

        for (auto ei : e)
        {
            g[ei[0]].push_back({ei[1], ei[2]});
            g[ei[1]].push_back({ei[0], ei[2]});
        }

        cout << "DFS: ";

        for (int i = 0; i < n; ++i)
        {
            if (seen[i])
                continue;

            v.push(i);

            while (v.size())
            {
                int vi = v.top();
                v.pop();

                if (!seen[vi])
                {
                    cout << vi << " ";
                }

                seen[vi]++;

                for (auto vw : g[vi])
                {
                    if (!seen[vw.first])
                        v.push(vw.first);
                }
            }
        }

        cout << endl;
    }

    void prim(int n, vector<vector<int>>& e)
    {
        vector<vector<pair<int, int>>> g(n);

        for (auto ei : e)
        {
            g[ei[0]].push_back({ei[1], ei[2]});
            g[ei[1]].push_back({ei[0], ei[2]});
        }

        priority_queue<pair<int, int>> q;
        vector<int> seen(n, 0);
        int min_cost = 0;

        seen[0]++;
        q.push({0, 0});

        while (q.size())
        {
            int vi = q.top().second;
        }



        cout << endl;
        cout << "Min cost: " << min_cost << endl;
    }
};

class Solution
{
public:
    // 997. Find the Town Judge
    // int findJudge(int N, vector<vector<int>>& trust)
    // {
    //     vector<int> in_edges(N + 1, 0);
    //     vector<int> out_edges(N + 1, 0);

    //     for (auto t : trust)
    //     {
    //         ++in_edges[t[1]];
    //         ++out_edges[t[0]];
    //     }

    //     for (int i = 1; i <= N; ++i)
    //     {
    //         if (in_edges[i] - out_edges[i] == N - 1)
    //             return i;
    //     }

    //     return -1;
    // }

    int findJudge(int N, vector<vector<int>>& trust)
    {
        vector<int> trusts(N + 1, 0);

        for (auto t : trust)
        {
            ++trusts[t[1]];
            --trusts[t[0]];
        }

        for (int i = 1; i <= N; ++i)
        {
            if (trusts[i] == N - 1)
                return i;
        }

        return -1;
    }

};

int main()
{
    // adjacency matrix
    // vector<vector<int>> m;
    /*
            0   1   2   3   4   5
        0   \   3   -1  2   -1  -1
        1   
        2
        3
        4
        5
    */

    // adjacency list
    // vector<vector<pair<int, int>>> g; 
    /*
        {
          0:  {<1, 3>, <3, 4>, <5, 2>}
          1:  {<0, 3>, <2, 1>}
          2:  ...
          .
          .
        }
    */

    // edge list
    vector<vector<int>> e = {{0, 1, 4}, {1, 2, 2}, {1, 3, 2}, {2, 4, 1}, {2, 6, 2}, {3, 5, 3}};


    Graph graph;
    Solution solu;

    graph.BFS(7, e);
    graph.DFS(7, e);
    graph.prim();

    // 997. Find the Town Judge
    // vector<vector<int>> trust = { {1,3}, {1,4}, {2,3}, {2,4}, {4,3} };
    // cout << "The label of the Town Judge is: " << solu.findJudge(4, trust) << endl << endl;

    DOCK();

    return 0;
}


#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
        {
            return NULL;
        }
        stack<UndirectedGraphNode*> st;
        set<UndirectedGraphNode*> visited;
        map<UndirectedGraphNode*, UndirectedGraphNode*> nodes;
        st.push(node);
        visited.insert(node);
        while (!st.empty())
        {
            auto p = st.top();
            st.pop();
            nodes[p] = new UndirectedGraphNode(p->label);
            for (auto it = p->neighbors.begin(); it != p->neighbors.end(); it++)
            {
                if (visited.find(*it) == visited.end())
                {
                    st.push(*it);
                    visited.insert(*it);
                }
            }
        }
        for (auto it = visited.begin(); it != visited.end(); it++)
        {
            auto p = *it;
            auto np = nodes[p];
            for (auto it2 = p->neighbors.begin(); it2 != p->neighbors.end(); it2++)
            {
                np->neighbors.push_back(nodes[*it2]);
            }
        }
        return nodes[node];
    }
};

int main()
{
    return 0;
}
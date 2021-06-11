#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int a, c, i;
    Node* parent;
    set<Node> children;
    Segment* segment;
    Node(int a, int c, int i) {
        this->a = a;
        this->c = c;
        this->i = i;
    }
};

struct Segment
{
    queue<Node> nodes;
    Segment* parent;
    set<Segment> children;
};

int main() {
    int Q;
    cin >> Q;
    int tln1, tln2; cin >> tln1 >> tln2;
    Node root(tln1, tln2, 0);
    map<int, Node> mp;
    mp.insert({0, root});
    Segment sR;
    sR.nodes.push(root);
    root.segment = &sR;
    for (int q = 0; q < Q; q++)
    {
        int t1n3; cin >> t1n3;
        if (t1n3 == 1)
        {
            int t1n4; cin >> t1n4;
            Node parent = mp[t1n4];
            int valn, valn2; cin >> valn >> valn2;
            Node n(valn, valn2, q + 1);
            n.parent = &parent;
            parent.children.insert(n);
            mp.insert({q + 1, n});
            if (parent.children.size() == 1)
            {
                parent.segment->nodes.push(n);
                n.segment = parent.segment;
            }
            else
            {
                Segment sN;
                sN.nodes.push(n);
                n.segment = &sN;
                Segment sM;
                sM.parent = parent.segment->parent;
                while (&parent.segment->nodes.front() != &parent)
                {
                    auto up = parent.segment->nodes.front();
                    parent.segment->nodes.pop();
                    sM.nodes.push(up);
                }
                auto up = parent.segment->nodes.front();
                parent.segment->nodes.pop();
                sM.nodes.push(up);
                parent.segment = &sM;
                sN.parent = &sM;
            }
        }
        else
        {  
            int v; cin >> v;
            Segment current = *mp[v].segment;
            stack<Segment> stack;
            while (&current != root.segment && !current.nodes.empty())
            {
                stack.push(current);
                current = *current.parent;
            }
            stack.push(current);
            int K, res = 0, gold = 0; cin >> K;
            while (!stack.empty())
            {
                Segment s = stack.top(); stack.pop();
                int i = 0;
                while (!s.nodes.empty() && K > 0)
                {
                    Node n = s.nodes.front();
                    int remove = min(n.a, K);
                    res += n.c * remove;
                    n.a -= remove;
                    gold += remove;
                    K -= remove;
                    if (n.a == 0)
                    {
                        s.nodes.pop();
                    }
                    if (n.i == v)
                    {
                        break;
                    }
                }
            }
            cout << (gold) << " " << res;
            fflush(stdout);
        }
    }
}
    
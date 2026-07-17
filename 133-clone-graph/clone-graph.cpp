/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        std::map<Node*, Node*> node_map;
        std::queue<Node*> q;
        std::set<Node*> visited;

        visited.insert(node);
        q.push(node);
        Node* top_node = nullptr;

        while(!q.empty()) {
            top_node = q.front();
            q.pop();
            if (!node_map.contains(top_node)) {
                Node* top_copy = new Node(top_node->val);;
                node_map.insert({top_node, top_copy}); 
            }

            std::vector<Node*> current_neighbor_copy = {};
            for (Node* neighbor : top_node->neighbors) {
                if (!visited.contains(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
                
                if (!node_map.contains(neighbor)) {
                   Node* neighbor_copy = new Node(neighbor->val);;
                   node_map.insert({neighbor, neighbor_copy}); 
                }
                current_neighbor_copy.push_back(node_map[neighbor]);
            }

            node_map[top_node]->neighbors = current_neighbor_copy;
        }

        return node_map[node];
        
    }
};
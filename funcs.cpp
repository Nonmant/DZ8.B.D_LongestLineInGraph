//https://contest.yandex.ru/contest/29403/problems/D/

#include "funcs.h"
#include <bits/stdc++.h>

struct TreeNode{
    //! @brief index - sum in this direction
    std::vector<std::pair<int,int>> connectedNodes;
};

int getLength(std::vector<TreeNode> & nodes,
              int index,
              int excludeIndex){
    TreeNode & node = nodes[index];
    int maxLen = 0;
    for(auto & connectedNode : node.connectedNodes){
        if(connectedNode.first == excludeIndex)
            continue;
        if(connectedNode.second == 0)
            connectedNode.second = getLength(nodes,
                                             connectedNode.first,
                                             index);
        if(connectedNode.second > maxLen)
            maxLen = connectedNode.second;
    }
    return maxLen+1;
}

int longestLine(std::vector<TreeNode> & nodes){
    int maxLen = 0;
    for(int i = 1; i<nodes.size(); ++i){
        //Check only corners
        if(nodes[i].connectedNodes.size() > 1)
            continue;
        for(auto & connectedNode : nodes[i].connectedNodes){
            if(connectedNode.second == 0)
                connectedNode.second = getLength(nodes,connectedNode.first,i);

            if(connectedNode.second > maxLen)
                maxLen = connectedNode.second;
        }
    }

    return maxLen+1;
}

void parseFile(std::istream & input, std::ostream & output){
    std::vector<TreeNode> nodes;

    int n;
    input >> n;
    nodes.resize(n+1);
    int firstNode, secondNode;
    for(int i = 1; i<n; ++i){
        input >> firstNode >> secondNode;
        nodes[firstNode].connectedNodes.emplace_back(secondNode,0);
        nodes[secondNode].connectedNodes.emplace_back(firstNode,0);
    }
    output << longestLine(nodes)<<std::endl;
}

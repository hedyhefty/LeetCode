#pragma once

struct Node {
    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* next = nullptr;

    Node(int _val) : val(_val) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
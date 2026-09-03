/*
    직접 구현한 이진 탐색 트리(Binary Search Tree)

    각 노드는 왼쪽과 오른쪽 자식을 최대 하나씩 가진다.
    현재 노드보다 작은 값은 왼쪽, 큰 값은 오른쪽에 저장한다.
*/

#include <iostream>

template<typename T>
class BinarySearchTree
{
private:
    struct Node
    {
        T mValue;
        Node* mLeft = nullptr;
        Node* mRight = nullptr;

        Node(const T& value)
            : mValue(value)
        {
        }
    };

    Node* mRoot = nullptr;

public:
    BinarySearchTree() = default;

    ~BinarySearchTree()
    {
        DeleteNodes(mRoot);
    }

    BinarySearchTree(const BinarySearchTree&) = delete;
    BinarySearchTree& operator=(const BinarySearchTree&) = delete;

    void Insert(const T& value)
    {
        if (mRoot == nullptr)
        {
            mRoot = new Node(value);
            return;
        }

        Node* current = mRoot;

        while (true)
        {
            if (value < current->mValue)
            {
                if (current->mLeft == nullptr)
                {
                    current->mLeft = new Node(value);
                    return;
                }

                current = current->mLeft;
            }
            else if (current->mValue < value)
            {
                if (current->mRight == nullptr)
                {
                    current->mRight = new Node(value);
                    return;
                }

                current = current->mRight;
            }
            else
            {
                return; // 같은 값은 넣지 않는다.
            }
        }
    }

    bool Contains(const T& value) const
    {
        const Node* current = mRoot;

        while (current != nullptr)
        {
            if (value < current->mValue)
            {
                current = current->mLeft;
            }
            else if (current->mValue < value)
            {
                current = current->mRight;
            }
            else
            {
                return true;
            }
        }

        return false;
    }

    void PrintInOrder() const
    {
        PrintInOrder(mRoot);
        std::cout << '\n';
    }

private:
    void PrintInOrder(const Node* node) const
    {
        if (node == nullptr)
        {
            return;
        }

        // 왼쪽 → 현재 → 오른쪽 순서의 중위 순회다.
        PrintInOrder(node->mLeft);
        std::cout << node->mValue << ' ';
        PrintInOrder(node->mRight);
    }

    void DeleteNodes(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }

        DeleteNodes(node->mLeft);
        DeleteNodes(node->mRight);
        delete node;
    }
};

int main()
{
    BinarySearchTree<int> scores;

    scores.Insert(50);
    scores.Insert(30);
    scores.Insert(70);
    scores.Insert(20);
    scores.Insert(40);
    scores.Insert(60);
    scores.Insert(80);

    std::cout << "중위 순회: ";
    scores.PrintInOrder();
    std::cout << "60이 있는가? " << scores.Contains(60) << '\n';
    std::cout << "25가 있는가? " << scores.Contains(25) << '\n';

    return 0;
}

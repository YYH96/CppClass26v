/*
    직접 구현한 양방향 연결 리스트

    각 노드는 값과 이전·다음 노드의 주소를 함께 가진다.
    mBegin과 mEnd는 실제 데이터를 저장하지 않는 더미 노드(sentinel node)다.
    더미 노드가 있으면 맨 앞·맨 뒤에 원소를 추가하거나 제거할 때도 같은 연결 규칙을 사용할 수 있다.
*/

#include <cassert>
#include <iostream>
#include <string>

template<typename T>
class ListNode
{
    template<typename U>
    friend class ListIterator;

    template<typename U>
    friend class MyLinkedList;

private:
    T mData{};
    ListNode<T>* mNext = nullptr;
    ListNode<T>* mPrev = nullptr;
};

template<typename T>
class ListIterator
{
    template<typename U>
    friend class MyLinkedList;

private:
    ListNode<T>* mNode = nullptr;

public:
    // 두 반복자가 같은 노드를 가리키는지 확인한다.
    bool operator==(const ListIterator& other) const
    {
        return mNode == other.mNode;
    }

    bool operator!=(const ListIterator& other) const
    {
        return mNode != other.mNode;
    }

    // ++iterator: 다음 노드로 이동한 뒤, 이동한 자기 자신을 반환한다.
    ListIterator& operator++()
    {
        assert(mNode != nullptr && mNode->mNext != nullptr);
        mNode = mNode->mNext;
        return *this;
    }

    // iterator++: 현재 위치를 복사해 반환한 뒤, 자기 자신은 다음 노드로 이동한다.
    ListIterator operator++(int)
    {
        ListIterator previous = *this;
        ++(*this);
        return previous;
    }

    ListIterator& operator--()
    {
        assert(mNode != nullptr && mNode->mPrev != nullptr);
        mNode = mNode->mPrev;
        return *this;
    }

    // *iterator: 반복자가 가리키는 노드의 실제 데이터에 접근한다.
    T& operator*() const
    {
        // begin 앞의 더미 노드와 end 더미 노드는 역참조하면 안 된다.
        assert(mNode != nullptr && mNode->mPrev != nullptr && mNode->mNext != nullptr);
        return mNode->mData;
    }
};

template<typename T>
class MyLinkedList
{
private:
    using Node = ListNode<T>;

public:
    using iterator = ListIterator<T>;

    MyLinkedList()
    {
        mBegin = new Node;
        mEnd = new Node;
        mBegin->mNext = mEnd;
        mEnd->mPrev = mBegin;
    }

    ~MyLinkedList()
    {
        Clear();
        delete mBegin;
        delete mEnd;
    }

    // 포인터만 복사하면 두 리스트가 같은 노드를 delete하는 얕은 복사가 된다.
    MyLinkedList(const MyLinkedList&) = delete;
    MyLinkedList& operator=(const MyLinkedList&) = delete;

    void PushBack(const T& data)
    {
        Insert(end(), data);
    }

    void PushFront(const T& data)
    {
        Insert(begin(), data);
    }

    void PopBack()
    {
        assert(!Empty());
        iterator last = end();
        --last;
        Erase(last);
    }

    void PopFront()
    {
        assert(!Empty());
        Erase(begin());
    }

    // position 바로 앞에 새 노드를 연결하고, 새 노드를 가리키는 반복자를 반환한다.
    iterator Insert(iterator position, const T& data)
    {
        assert(position.mNode != nullptr);

        Node* next = position.mNode;
        Node* previous = next->mPrev;
        Node* newNode = new Node;
        newNode->mData = data;

        previous->mNext = newNode;
        newNode->mPrev = previous;
        newNode->mNext = next;
        next->mPrev = newNode;
        ++mSize;

        iterator result;
        result.mNode = newNode;
        return result;
    }

    // position의 노드를 제거하고, 제거된 노드의 다음 위치를 반환한다.
    iterator Erase(iterator position)
    {
        assert(position.mNode != nullptr && position.mNode != mEnd);

        Node* deleteNode = position.mNode;
        Node* previous = deleteNode->mPrev;
        Node* next = deleteNode->mNext;

        previous->mNext = next;
        next->mPrev = previous;
        delete deleteNode;
        --mSize;

        iterator result;
        result.mNode = next;
        return result;
    }

    void Clear()
    {
        Node* current = mBegin->mNext;

        while (current != mEnd)
        {
            Node* next = current->mNext;
            delete current;
            current = next;
        }

        mBegin->mNext = mEnd;
        mEnd->mPrev = mBegin;
        mSize = 0;
    }

    bool Empty() const
    {
        return mSize == 0;
    }

    int Size() const
    {
        return mSize;
    }

    iterator begin()
    {
        iterator result;
        result.mNode = mBegin->mNext;
        return result;
    }

    iterator end()
    {
        iterator result;
        result.mNode = mEnd;
        return result;
    }

private:
    Node* mBegin = nullptr;
    Node* mEnd = nullptr;
    int mSize = 0;
};

template<typename T>
void PrintList(MyLinkedList<T>& values)
{
    // begin()부터 end() 전까지 ++iterator로 한 칸씩 이동하며 순회한다.
    for (typename MyLinkedList<T>::iterator iterator = values.begin(); iterator != values.end(); ++iterator)
    {
        std::cout << *iterator << ' ';
    }

    std::cout << "(size: " << values.Size() << ")\n";
}

int main()
{
    MyLinkedList<std::string> quests;

    quests.PushBack("슬라임 처치");
    quests.PushBack("포션 구매");
    quests.PushFront("마을 방문");
    PrintList(quests);

    // 반복자는 배열의 인덱스가 아니라 특정 노드의 위치를 기억한다.
    MyLinkedList<std::string>::iterator potionQuest = quests.begin();
    ++potionQuest;
    ++potionQuest;
    quests.Insert(potionQuest, "대장장이 방문");
    PrintList(quests);

    // Erase는 삭제한 자리의 다음 노드를 반환하므로, 순회 중 삭제할 때도 활용할 수 있다.
    MyLinkedList<std::string>::iterator current = quests.begin();
    ++current;
    quests.Erase(current);
    PrintList(quests);

    quests.PopFront();
    quests.PopBack();
    PrintList(quests);

    return 0;
}

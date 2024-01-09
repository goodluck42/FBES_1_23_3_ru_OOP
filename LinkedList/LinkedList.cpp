#include <iostream>
#include <list>
#include <vector>


template <typename T>
class Greater
{
public:
    bool operator()(const T& ALeft, const T& ARight)
    {
        return ALeft > ARight;
    }
};

template <typename T>
class Less
{
public:
    bool operator()(const T& ALeft, const T& ARight)
    {
        return ALeft < ARight;
    }
};

template <typename T, template <typename> typename TComparer>
class PriorityQueue
{
public:
    PriorityQueue()
    {
        std::cout << MComparer(1, 2);
    }

private:
    TComparer<T> MComparer;
};

template <typename T>
class LinkedList
{
public:
    class Node
    {
    public:
        Node(const T& AValue) : Value(AValue), Next(), Prev()
        {
        }

        T Value;
        Node* Next;
        Node* Prev;
    };

    ~LinkedList()
    {
        //// Variant 1

        Node* LCurrent = MHead;

        while (LCurrent != nullptr)
        {
            auto* LTemp = LCurrent->Next;

            delete LCurrent;

            LCurrent = LTemp;
        }

        //// Varinat 2
        // std::vector<Node*> LNodes;
        //
        // Node* LCurrent = MHead;
        //
        // while (LCurrent != nullptr)
        // {
        //     LNodes.push_back(LCurrent);
        //
        //     LCurrent = LCurrent->Next;
        // }
        //
        // for (auto& LNode : LNodes)
        // {
        //     delete LNode;
        // }
    }

    LinkedList() : MHead(), MTail(), MSize()
    {
    }

    Node* PushBack(const T& AElement)
    {
        auto LNode = new Node{AElement};

        if (MSize == 0)
        {
            MHead = MTail = LNode;

            ++MSize;

            return LNode;
        }

        // LNode - is a newly created node
        MTail->Next = LNode;
        LNode->Prev = MTail;
        MTail = LNode;
        ++MSize;

        return LNode;
    }

    Node* InsertAfter(const T& AElement, Node* APosition)
    {
        return nullptr;
    }
private:
    Node* MHead;
    Node* MTail;
    int MSize;
};


int main(int argc, char* argv[])
{
    LinkedList<int> LList;

    LList.PushBack(10);
    LList.PushBack(20);
    LList.PushBack(30);


    return 0;
}

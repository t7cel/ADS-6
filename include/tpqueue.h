// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
    struct Node {
        T data;
        Node* next;
        explicit Node(const T& data, Node* next = nullptr)
            : data(data), next(next) {}
    };

    Node* head;

 public:
    TPQueue() : head(nullptr) {}
    ~TPQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const T& item) {
        if (!head || item.prior > head->data.prior) {
            head = new Node(item, head);
            return;
        }

        Node* cur = head;
        while (cur->next &&
               cur->next->data.prior >= item.prior) {
            cur = cur->next;
        }
        cur->next = new Node(item, cur->next);
    }

    T pop() {
        if (!head) {
            throw std::string("Empty");
        }

        T res = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return res;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    TPQueue(const TPQueue&) = delete;
    TPQueue& operator=(const TPQueue&) = delete;
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_

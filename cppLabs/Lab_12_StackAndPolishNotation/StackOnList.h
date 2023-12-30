#ifndef TRAINING_STACKONLIST_H
#define TRAINING_STACKONLIST_H

#include <iostream>

template<class T>
class StackOnList {
public:
    struct Node {
        T data = NULL;
        Node *next = nullptr;
    };
private:
    Node *top_ = nullptr;

    void Delete() {
        while (top_) {
            Node *tmp = top_->next;
            delete top_;
            top_ = tmp;
        }
    }

public:
    void Swap(StackOnList& other) {
        std::swap(top_, other.top_);
    }

    StackOnList() = default;

    StackOnList(const StackOnList& other) : StackOnList() {
        StackOnList tmp;
        Node *tmpTop = other.top_;
        while (tmpTop) {
            tmp.Push(tmpTop->data);
            tmpTop = tmpTop->next;
        }
        tmpTop = tmp.top_;
        while (tmpTop) {
            this->Push(tmpTop->data);
            tmpTop = tmpTop->next;
        }
    }

    StackOnList(StackOnList&& other) noexcept: StackOnList() {
        Swap(other);
    }

    StackOnList& operator=(const StackOnList& other) {
        if (this != &other) {
            StackOnList tmp(other);
            Swap(tmp);
        }
        return *this;
    }

    StackOnList& operator=(StackOnList&& other) noexcept {
        if (this != &other) {
            Swap(other);
        }
        return *this;
    }

    ~StackOnList() {
        Delete();
    }

    void Push(T x) {
        auto tmp = new Node{x, top_};
        top_ = tmp;
    }

    T Pop() {
        if (top_ == nullptr) {
            throw std::runtime_error("Top is nullptr.");
        }
        Node *temp = top_;
        T value = temp->data;
        top_ = top_->next;
        delete temp;
        return value;
    }

    T& Top() {
        if (!top_) {
            throw std::runtime_error("Top is nullptr");
        }
        return top_->data;
    }

    [[nodiscard]] T Top() const {
        if (!top_) {
            throw std::runtime_error("Top is nullptr");
        }
        return top_->data;
    }

    [[nodiscard]] bool isEmpty() const {
        return top_ == nullptr;
    }
};


#endif //TRAINING_STACKONLIST_H

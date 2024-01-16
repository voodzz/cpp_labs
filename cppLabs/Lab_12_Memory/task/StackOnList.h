#ifndef TASK_STACKONLIST_H
#define TASK_STACKONLIST_H

#include <stdexcept>

template<typename T>
class StackOnList {
    class Node;

public:
    StackOnList(Node* top = nullptr) : top_(top) {
        if (top != nullptr) {
            size_ = 1;
        }
    }

    StackOnList(std::initializer_list<T>);
    StackOnList(const StackOnList<T>&);
    StackOnList(StackOnList<T>&&) noexcept ;
    bool isEmpty() const;
    size_t size() const;
    void push(const T& element);
    const T& top() const;
    T& top();
    T pop();

    StackOnList& operator=(const StackOnList<T>&);
    StackOnList& operator=(StackOnList<T>&&) noexcept ;

private:
    class Node {
    public:
        T value;
        Node() : next_(nullptr) {}
        Node(T newValue, Node* nextNode = nullptr) : value(newValue), next_(nextNode) {}
        ~Node() = default;
        void setNextNode(Node* nextNode) { next_ = nextNode; }
        Node* getNextNode() const { return next_; }
    private:
        Node* next_;
    };

    void clearStack();
    Node* top_ = nullptr;
    size_t size_ = 0;
};

template<typename T>
StackOnList<T>::StackOnList(const std::initializer_list<T> initializerList) {
    for (const auto& element : initializerList) {
        push(element);
    }
}

template<typename T>
bool StackOnList<T>::isEmpty() const {
    return top_ == nullptr;
}

template<typename T>
void StackOnList<T>::push(const T& element) {
    top_ = new StackOnList<T>::Node(element, top_); // !
    ++size_;
}

template<typename T>
size_t StackOnList<T>::size() const {
    return size_;
}

template<typename T> // !
const T& StackOnList<T>::top() const {
    if (this->isEmpty()) {
        throw std::runtime_error("Empty stack!");
    }
    return top_->value;
}

template<typename T>
T& StackOnList<T>::top() {
    if (this->isEmpty()) {
        throw std::runtime_error("Empty stack!");
    }
    return top_->value;
}

template<typename T>
T StackOnList<T>::pop() {
    if (this->isEmpty()) {
        throw std::runtime_error("Empty stack!");
    }
    auto* temp = top_;
    T poppedValue = temp->value;
    top_ = temp->getNextNode();
    delete temp;
    --size_;
    return poppedValue;
}

template<typename T>
StackOnList<T>::StackOnList(const StackOnList<T>& other) {
    auto* current = other.top_;
    top_ = new Node(current->value, nullptr);
    auto* prev = top_;
    while (current->getNextNode() != nullptr) {
        current = current->getNextNode();
        auto* temp = new Node(current->value, nullptr);
        prev->setNextNode(temp);
        prev = temp;
    }
    size_ = other.size_;
}

template<typename T>
StackOnList<T>& StackOnList<T>::operator=(const StackOnList<T>& other) {
    if (other.top_ != top_) {
        return *this;
    }
    if (!(this->isEmpty())) {
        clearStack();
    }
    size_ = other.size_;
    auto* current = other.top_;
    top_ = new Node(current->value, nullptr);
    auto* prev = top_;
    while (current->getNextNode() != nullptr) {
        current = current->getNextNode();
        auto* temp = new Node(current->value, nullptr);
        prev->setNextNode(temp);
        prev = temp;
    }
    return *this;
}

template<typename T>
void StackOnList<T>::clearStack() {
    while (!(this->isEmpty())) {
        auto* temp = top_;
        top_ = temp->getNextNode();
        delete temp;
    }
}

template<typename T>
StackOnList<T>::StackOnList(StackOnList<T>&& other) noexcept {
    top_ = other.top_;
    size_ = other.size_;
    other.top_ = nullptr;
    other.size_ = 0;
}

template<typename T>
StackOnList<T>& StackOnList<T>::operator=(StackOnList<T>&& other) noexcept {
    if (other.top_ == top_) {
        return *this;
    }
    if (!(this->isEmpty())) {
        clearStack();
    }
    top_ = other.top_;
    size_ = other.size_;
    other.top_ = nullptr;
    other.size_ = 0;
    return *this;
}

#endif //TASK_STACKONLIST_H

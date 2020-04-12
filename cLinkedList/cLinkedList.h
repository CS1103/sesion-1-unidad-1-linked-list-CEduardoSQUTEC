//
// Created by ceduardosq on 4/12/20.
//

#ifndef CLINKEDLIST_CLINKEDLIST_H
#define CLINKEDLIST_CLINKEDLIST_H

#include <cstddef>

namespace utec {
    template<typename T>
    struct node_t {
        T value_{};
        node_t<T> *next_ = nullptr;
    };

    inline namespace first {
        template<typename T>
        class cLinkedList {
        private:
            node_t<T> *head_ = nullptr;
            node_t<T> *tail_ = nullptr;
            size_t size_ = 0;
        public:
            // Constructors
            cLinkedList() = default;

            cLinkedList(const cLinkedList &other) : size_(other.size_), head_(nullptr), tail_(nullptr) {
                for (auto i = other.head_; i != nullptr; i = i->next_)
                    this->push_back(i->value_);
            }

            cLinkedList<T> &operator=(const cLinkedList<T> &other) {
                for (auto i = other.head_; i != nullptr; i = i->next_)
                    this->push_back(i->value_);
                return *this;
            }

            cLinkedList(cLinkedList<T> &&other) noexcept {
                for (auto i = other.head_; i != nullptr; i = i->next_)
                    this->push_back(i->value_);
            }

            cLinkedList<T> &operator=(cLinkedList &&other) noexcept {
                for (auto i = other.head_; i != nullptr; i = i->next_)
                    this->push_back(i->value_);
            }

            // Destroyer
            ~cLinkedList() {
                while (size_)
                    pop_front();
            }

            // Add
            void push_front(T value) {
                head_ = new node_t<T>{value, head_};
                if (tail_ == nullptr)
                    tail_ = head_;
                size_++;
            }

            void push_back(T value) {
                tail_->next_ = new node_t<T>{value, nullptr};
                tail_ = tail_->next_;
                ++size_;
            }

            void insert(size_t index, T value) {
                if (index == 0)
                    push_front(value);
                else {
                    auto i = head_;
                    index -= 1;
                    while (index--)
                        i = i->next_;
                    i->next_ = new node_t<T>{value, i->next_};
                    ++size_;
                }
            }

            //  remove
            void pop_front() {
                if (head_ == tail_) {
                    delete[] head_;
                    head_ = tail_ = nullptr;
                    size_ = 0;
                } else {
                    auto next = head_->next_;
                    delete head_;
                    head_ = next;
                    size_--;
                }
            }

            void pop_back() {
                if (tail_ == head_) {
                    delete[] tail_;
                    tail_ = head_ = nullptr;
                    size_ = 0;
                } else {
                    auto i = head_;
                    while (i->next_ != tail_)
                        i = i->next_;
                    delete[] tail_;
                    tail_ = i;
                    --size_;
                }
            }

            void erase(size_t index) {
                if (index == 0)
                    pop_front();
                else if (index == size_ - 1) {
                    pop_back();
                } else {
                    auto i = head_;
                    index -= 1;
                    while (index--)
                        i = i->next_;
                    auto next = i->next_->next_;
                    delete[] i->next_;
                    i->next_ = next;
                    --size_;
                }
            }

            // traversal
            T &item(size_t index) {
                auto actual = head_;
                while (index--)
                    actual = actual->next_;
                return actual->value_;
            }

            const T &item(size_t index) const {
                auto actual = head_;
                while (index--)
                    actual = actual->next_;
                return actual->value_;
            }

            // get size of the list
            size_t size() const {
                return size_;
            }
        };
    }
}

#endif //CLINKEDLIST_CLINKEDLIST_H

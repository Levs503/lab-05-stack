//
// Created by Лев on 12.11.2020.
//

#ifndef TEMPLATE_STACK1_H
#define TEMPLATE_STACK1_H
#include <cstddef>
#include <stdexcept>
#include <type_traits>
#include <utility>

#include "Node.h"

template <typename T>
class Stack1 {
 private:
  Node<T>* lastNode;

 public:
  Stack1();
  void push(T&& value);
  void push(const T& value);
  void pop();
  const T& head() const;
  Stack1(Stack1&) = delete;
  Stack1& operator=(Stack1&) = delete;
  Stack1(Stack1&& original);
  Stack1& operator=(Stack1&& original);
  template <typename... Args>
  void push_emplace(Args&&... args);
  ~Stack1();
};

template <typename T>
Stack1<T>::Stack1() {
  lastNode = nullptr;
}

template <typename T>
void Stack1<T>::push(const T& value) {
  static_assert(std::is_constructible_v<T>, "no copy constructor");

  lastNode = new Node<T>(value, lastNode);
}

template <typename T>
void Stack1<T>::push(T&& value) {
  static_assert(std::is_move_constructible_v<T>, "no move constructor");
  lastNode = new Node<T>(std::move(value), lastNode);
}

template <typename T>
void Stack1<T>::pop() {
  if (lastNode == nullptr) throw std::out_of_range("out of range");

  Node<T>* nextNode = lastNode->getNode();
  delete lastNode;
  lastNode = nextNode;
}

template <typename T>
const T& Stack1<T>::head() const {
  if (lastNode == nullptr) throw std::out_of_range("request by nullptr");
  return lastNode->get();
}

template <typename T>
Stack1<T>::~Stack1() {
  Node<T>* topNode = lastNode;
  while (topNode) {
    Node<T>* next = topNode->getNode();
    delete topNode;
    topNode = next;
  }
}

template <typename T>
Stack1<T>::Stack1(Stack1&& original) {
  lastNode = original.lastNode;
  original.lastNode = nullptr;
}

template <typename T>
Stack1<T>& Stack1<T>::operator=(Stack1&& original) {
  if (&original != this) {
    std::swap(original.lastNode, lastNode);
  }
  return *this;
}

template <typename T>
template <typename... Args>
void Stack1<T>::push_emplace(Args&&... value) {
  lastNode = new Node<T>(T(std::forward<Args>(value)...), lastNode);
}

#endif  // TEMPLATE_STACK1_H

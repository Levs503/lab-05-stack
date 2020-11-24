//
// Created by Лев on 12.11.2020.
//

#ifndef LAB_05_STACK_NODE_H
#define LAB_05_STACK_NODE_H

template <typename T>
class Node {
 private:
  Node* prevNode;
  T object;

 public:
  Node();
  Node(const Node*);
  Node(T&& obj, Node<T>* prev_node);
  Node(const T& obj, Node<T>* prev_node);
  const T& get() const;
  Node<T>* getNode() const;
};

template <typename T>
Node<T>::Node() : prevNode(nullptr), object(T()) {}

template <typename T>
Node<T>::Node(const Node* a) : prevNode(a), object(T()) {}
template <typename T>
const T& Node<T>::get() const {
  return object;
}
template <typename T>
Node<T>::Node(T&& obj, Node<T>* prev_node)
    : prevNode(prev_node), object(std::move(obj)) {}

template <typename T>
Node<T>::Node(const T& obj, Node<T>* prev_node)
    : prevNode(prev_node), object(obj) {}
template <typename T>
Node<T>* Node<T>::getNode() const {
  return prevNode;
}

#endif  // LAB_05_STACK_NODE_H

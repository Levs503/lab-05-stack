//
// Created by Лев on 12.11.2020.
//

#ifndef LAB_05_STACK_NODE_H
#define LAB_05_STACK_NODE_H

template <typename T>
class Node{
 private:
  Node* prevNode;
  T object;
 public:
  Node();
  Node(const Node*);
  Node(T&& obj, Node<T>* prev_node);
  Node(T& obj, Node<T>* prev_node);
  const T& get() const;
  const Node<T>* getNode() const;
};

template <typename T>
Node<T>::Node(): prevNode(nullptr), object(T()){

}

template <typename T>
Node<T>::Node(const Node * a):prevNode(a), object(T()) {}
template <typename T>
const T& Node<T>::get() const {
  return object;
}
template <typename T>
Node<T>::Node(T&& obj, Node<T>* prev_node): object(move(obj)), prevNode(prev_node) {}

template <typename T>
Node<T>::Node(T& obj, Node<T>* prev_node): object(obj), prevNode(prev_node) {}
template <typename T>
const Node<T>* Node<T>::getNode() const {
  return prevNode;
}

#endif  // LAB_05_STACK_NODE_H

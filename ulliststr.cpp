#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (empty()) {
    return NULL;
  }

  if (loc > size_) {
    return nullptr;
  }
  
  Item* curr = head_;
  size_t index = loc;

  while(curr != nullptr) {
    size_t nodeSize = curr->last - curr->first;
    if (index < nodeSize) {
      return &curr->val[curr->first + index];
    }
    
    index = index - nodeSize;
    curr = curr->next;
  }

  return nullptr;
}

void ULListStr::push_back(const std::string& val) {
  if (empty()) { 
    Item* newItem = new Item(); 
    head_ = newItem;
    tail_ = newItem; 

    newItem->val[0] = val;
    newItem->first = 0; 
    newItem->last = 1;
    size_ = 1;
    return;
  }

  if (tail_->last < ARRSIZE) { 
    tail_->val[tail_->last] = val;
    tail_->last = tail_->last + 1;
    size_++; 
    return;
  }

  if (tail_->last >= ARRSIZE) { //if no room 
    Item* newItem = new Item();
    newItem->prev = tail_;
    tail_->next = newItem;
    tail_ = newItem;

    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
    size_++;
    return;
  }
}

void ULListStr::push_front(const std::string& val) {
  if (empty()) { 
    Item* newItem = new Item(); 
    head_ = newItem;
    tail_ = newItem; 

    newItem->val[0] = val;
    newItem->first = 0; 
    newItem->last = 1;
    size_ = 1;
    return;
  }

  if (head_->first > 0) {
    head_->first = head_->first - 1;
    head_->val[head_->first] = val;
    size_++;
    return;
  }

  if (head_->first <= 0) {
    Item* newItem = new Item();
    newItem->next = head_;
    head_->prev = newItem;
    head_ = newItem;

    newItem->val[9] = val;
    newItem->first = 9;
    newItem->last = 10;
    size_++;
    return;

  }
}

void ULListStr::pop_back() {
  if (empty()) {
    return;
  }

  if (tail_->last - tail_->first == 1) {
    Item* temp = tail_;

    if (head_ == tail_) {
      head_ = nullptr;
      tail_ = nullptr;
    }
    else {
      tail_ = tail_->prev;
      tail_->next = nullptr;
    }

    delete temp;
    --size_;
    return;
  }

  if (tail_->last - tail_->first > 1) {
    tail_->last--;
  }

  size_--;
}

void ULListStr::pop_front() {
  if (empty()) {
    return;
  }

  if (head_->last - head_->first == 1) {
    Item* temp = head_;

    if (head_ == tail_) {
      head_ = nullptr;
      tail_ = nullptr;
    }
    else {
      head_ = head_->next;
      head_->prev = nullptr;
    }

    delete temp;
    --size_;
    return;
  }

  if (head_->last - head_->first > 1) {
    head_->first++;
  }

  size_--;
}

std::string const & ULListStr::back() const {
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

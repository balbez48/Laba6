//#include "UnorderedList.h"
//
////Конструкторы + деструктор
//template<typename T>
//UnorderedList<T>::UnorderedList() : UnorderedList(10) {}
//
//template<typename T>
//UnorderedList<T>::UnorderedList(int capacity) : count_(0), capacity_(capacity)
//{
//	if (capacity <= 0) {
//	  throw std::invalid_argument("Размер списка должен быть > 0");
//	}
//	items_ = new T[capacity_];
//}
//
//template<typename T>
//UnorderedList<T>::UnorderedList(const UnorderedList& list) : count_(list.count_), capacity_(list.capacity_)
//{
//	items_ = new T[capacity_];
//	for (int i = 0; i < count_; i++) {
//		items_[i] = list.items_[i];
//	}
//}
//
//template<typename T>
//UnorderedList<T>::~UnorderedList()
//{
//	delete[] items_;
//}
//
//
////приватные методы
//template<typename T>
//void UnorderedList<T>::AddCapacity()
//{
//	if (count_ >= capacity_) {
//	  int new_cap = capacity_ * 2;
//	  T* new_items = new T[new_cap];
//
//	  for (int i = 0; i < count_; i++) {
//		  new_items[i] = items_[i];
//	  }
//
//	  delete[] items_;
//
//	  items_ = new_items; 
//	  capacity_ = new_cap;
//	}
//}
//
//
////основные методы
//template<typename T>
//void UnorderedList<T>::Add(const T& item)
//{
//	if (Contains(item)) {
//	  return;
//	}
//
//	AddCapacity();
//	items_[count_] = item;
//	count_++;
//}
//
//template<typename T>
//bool UnorderedList<T>::Remove(const T& item)
//{
//	for (int i = 0; i < count_; i++) {
//	  if (items_[i] == item) {
//	    for (int j = i; j < count_ - 1; j++) {
//		  items_[j] = items_[j + 1];  
//		}
//		count_--;
//		return true;
//	  }
//	}
//	return false;
//}
//
//template<typename T>
//bool UnorderedList<T>::Contains(const T& item) const
//{
//	for (int i = 0; i < count_; i++) {
//		if (items_[i] == item) {
//			return true;
//		}
//	}
//	return false;
//}
//
//template<typename T>
//UnorderedList<T> UnorderedList<T>::Union(const UnorderedList<T>& list) const
//{
//	UnorderedList<T> res(count_ + list.count_);
//
//	for (int i = 0; i < count_; i++) {
//		res.Add(items_[i]);
//	}
//
//	for (int i = 0; i < list.count_; i++) {
//		res.Add(list.items_[i]);
//	}
//
//	return res;
//}
//
//template<typename T>
//UnorderedList<T> UnorderedList<T>::Except(const UnorderedList<T>& list) const
//{
//	UnorderedList<T> res(count_);
//
//	for (int i = 0; i < count_; i++) {
//		if (!list.Contains(items_[i])) {
//			res.Add(items_[i]);
//		}
//	}
//	return res;
//}
//
//template<typename T>
//UnorderedList<T> UnorderedList<T>::Intersect(const UnorderedList<T>& list) const
//{
//	UnorderedList<T> res(std::min(count_, list.count_));
//
//	for (int i = 0; i < count_; ++i) {
//	  if (list.Contains(items_[i])) {
//	    res.Add(items_[i]);
//	  }
//	}
//	return res;
//}
//
//template<typename T>
//void UnorderedList<T>::Print() const {
//	std::cout << "UnorderedList [";
//	for (int i = 0; i < count_; i++) {
//		std::cout << items_[i];
//		if (i < count_ - 1) {
//			std::cout << ", ";
//		}
//	}
//	std::cout << "]" << std::endl;
//}
//


//Vector.h
#pragma once
#include <initializer_list>

template<typename T>//generic data type

class Vector {
private:

	T* data;
	size_t size;
	size_t capacity;

public:

	//constructors

	Vector() :data(nullptr), size(0), capacity(0) {};
	Vector(size_t count, T value);
	Vector(std::initializer_list<T> initList);
	Vector(const Vector& vector_obj);

	//destructor

	~Vector() { delete[]data; };

	//main functions

	size_t getSize() const { return size; };
	size_t getCapacity() const { return capacity; };
	bool isempty();
	void reserve(size_t new_cap);
	void clear();
	void push_back(const T& value);
	void pop_back();
	void resize(size_t new_size);
	bool at(size_t index);


	//operators;

	Vector<T>& operator=(const Vector<T>& vector_obj2);
	bool operator==(const Vector<T>& vector) const;
	T& operator[](size_t index);
};


//constructor that create vector with number of values(if wanna string value use " " to intialize
template <typename T>
inline Vector<T>::Vector(size_t count, T value) {
	size = count;
	capacity = count;
	data = new T[capacity];

	for (size_t i = 0; i < size; i++) {
		data[i] = value;
	}
}

//a constructor with {} initialization
template <typename T>
inline Vector<T>::Vector(std::initializer_list<T> initList) {
	size = initList.size();
	capacity = size;

	data = new T[capacity];

	size_t index = 0;
	for (const T& element : initList) {
		data[index] = element;
		index++;
	}
}

//a constructor that copy taked vector in new

template<typename T>
inline Vector<T>::Vector(const Vector& vector_obj)
{
	size = vector_obj.getSize();
	capacity = vector_obj.getCapacity();

	data = new T[capacity];

	for (size_t i = 0; i < size; i++) {
		data[i] = vector_obj.data[i];
	}
}



//assignment operator "vector_obj1=vector_obj2"
template<typename T>
inline Vector<T>& Vector<T>::operator =(const Vector<T>& vector_obj2) {

	if (this != &vector_obj2) {
		size = vector_obj2.size;
		capacity = vector_obj2.capacity;

		delete[] data;

		if (capacity > 0) {
			data = new T[capacity];
			for (size_t i = 0; i < size; i++) {
				data[i] = vector_obj2.data[i];
			}
		}
	}
	else {
		data = nullptr;
	}
	return *this;
}

//operator to compare vectors;
template<typename T>
bool Vector<T>:: operator ==(const Vector<T>& vector) const {

	size_t size1 = this->getSize();
	size_t size2 = vector.getSize();

	if (size1 != size2) {
		return false;
	}

	for (int i = 0; i < size1; i++) {
		if (data[i] != vector.data[i]) {
			return false;
		}
	}

	return true;
}


//operator for indexing value

template<typename T>
inline T& Vector<T>::operator[](size_t index)
{
	if (!at(index)) {
		return *reinterpret_cast<T*>(nullptr);
	}
	return data[index];
}

//func for checking bounds

template<typename T>
inline bool Vector<T>::at(size_t index)
{
	return index < size;
}


//isempty function
template<typename T>
inline bool Vector<T>::isempty() {
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

//reserve func

template<typename T>
inline void Vector<T>::reserve(size_t new_cap) {
	if (new_cap > capacity) {

		T* new_data = new T[new_cap];

		for (size_t i = 0; i < this->getSize(); i++) {
			new_data[i] = data[i];
		}

		delete[] data;

		data = new_data;
		capacity = new_cap;
	}
}

//clear vector function

template<typename T>
inline void Vector<T>::clear()
{
	delete[] data;
	size = 0;
	data = nullptr;

}

//push_back func

template<typename T>
inline void Vector<T>::push_back(const T& value)
{
	if (size == capacity) {
		size_t new_cap = (capacity == 0) ? 1 : capacity * 2;

		T* new_data = new T[new_cap];

		for (size_t i = 0; i < size; i++) {
			new_data[i] = data[i];
		}

		delete[] data;

		data = new_data;
		capacity = new_cap;

	}

	data[size] = value;
	++size;

}

//pop_back func

template<typename T>
inline void Vector<T>::pop_back()
{

	if (size == 0) {
		std::cout << "EROR, you cannot delete an element of an empty vector";
	}
	else if (size) {
		size--;
	}
}

//resize func

template<typename T>
inline void Vector<T>::resize(size_t new_size)
{
	if (size > new_size) {
		size = new_size;
	}
	else if (size < new_size) {
		reserve(new_size);

		for (size_t i = size; i < new_size; i++) {
			data[i] = T();
		}

		size = new_size;
	}
}





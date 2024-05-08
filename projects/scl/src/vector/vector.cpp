#include <iostream>

#include "vector.hpp"

namespace KLikhosherstova {

    template<typename T>
    Vector<T>::Vector() noexcept {
        arr = new T[capacity];
	vec_size = 0;
    }

    template<typename T>
    Vector<T>::~Vector() noexcept {
        delete[] arr;
    }

    template<typename T>
    void Vector<T>::push_back(const T& value) noexcept {
        if (vec_size == capacity) {
            capacity *= 2;

            T* copy_arr = new T[capacity];

            for (std::size_t i = 0; i < vec_size; i++) {
                copy_arr[i] = arr[i];
            }

            delete[] arr;

            arr = copy_arr;
       }

        arr[vec_size] = value;
        vec_size++;
    }

    template<typename T>
    bool Vector<T>::has_item(const T& value) const noexcept {
        if (size() == 0) {return false;}
        for (size_t i = 0; i < vec_size; i++) {
            if (arr[i] == value) {
                return true;
            }
        }
        return false;
    }

    template<typename T>
    bool Vector<T>::insert(const int position, const T& value) {
        if (position == vec_size + 1) {
            push_back(value);
            return true;
        }

        if ((position < 0) || (position > vec_size + 1)) {
            return false;
        }

        if (vec_size == capacity) {
            capacity *= 2;
            T* copy_arr = new T[capacity];
            
            for(std::size_t i = 0; i < position; i++) {
                copy_arr[i] = arr[i];
            }

            for(std::size_t i = 0; i < vec_size; i++) {
                copy_arr[i + 1] = arr[i]; 
            }
            delete[] arr;
            arr = copy_arr;
        }
        else {
            for(std::size_t i = vec_size; i > position; i--) {
                arr[i] = arr[i - 1];
            }
        }
        arr[position] = value;
        vec_size++;
        return true;
    }

    template<typename T>
    void Vector<T>::print() const noexcept {
        for (std::size_t i = 0; i < vec_size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    template<typename T>
    bool Vector<T>::remove_first(const T& value) noexcept {

        if(has_item(value) == false) {
            return false;
        }

        else {
            std::size_t position = 0;
            for (std::size_t i = 0; i < vec_size; i++) {
                if (arr[i] == value) {
                    position = i;
                    break;
                }
            }

            for (std::size_t i = position; i < vec_size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            vec_size--;
            return true;
        } 
    }


    template<typename T>
    std::size_t Vector<T>::size() const noexcept {
        return vec_size;
    }
}

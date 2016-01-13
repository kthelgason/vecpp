#pragma once
#include <cstdlib>
#include <cstdint>
#include <stdexcept>
#include <functional>

template <typename T, size_t i>
class Vec {
public:
    Vec() {
        memset(data, 0, i * sizeof(T));
    }
    Vec(const Vec<T, i>& other) {
        for(uint32_t a = 0; a < i; a++) {
            data[a] = other.data[a];
        }
    }
    Vec(const std::initializer_list<T>& init) {
        int32_t s = 0;
        for(auto it = init.begin(); it != init.end() && s < i; s++, it++) {
            data[s] = *it;
        }
    }
    template <size_t j>
    Vec<T, (i + j)> append(Vec<T, j>& other) {
        Vec<T, i+j> ret;
        for(uint32_t a = 0; a < i; a++) { ret[a] = data[a]; }
        for(uint32_t a = i; a < i+j; a++) { ret[a] = other[a-i]; }
        return ret;
    }
    T& operator[](size_t idx) {
        if(idx > i) throw std::out_of_range("idx");
        return data[idx];
    }
    template <size_t idx>
    void set(T val) {
        static_assert(idx < i, "Out of bounds access");
        data[idx] = val;
    }
    template <size_t idx>
    T at(void) {
        static_assert(idx < i, "Out of bounds access");
        return data[idx];
    }
    template <typename R>
    Vec<R, i> map(std::function<R(T)> fn) {
        Vec<R, i> ret;
        for(uint32_t a = 0; a < i; a++) { ret.data[a] = fn(data[a]); }
        return ret;
    }
    Vec<T, i> operator+(Vec<T, i>& other) {
        Vec<T, i> ret;
        for(uint32_t a = 0; a < i; a++) { ret.data[a] = other[a] + data[a]; }
        return ret;
    }
private:
    T data[i];
};


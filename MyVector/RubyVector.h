/* 
 * File:   MyVector.h
 * Author: Lukas Elmer
 *
 * Created on 14. Mai 2010, 12:01
 */

#ifndef _MYVECTOR_H
#define	_MYVECTOR_H


#include <vector>

#include <bits/stl_iterator_base_funcs.h>

using namespace std;

template <typename _Tp, typename _Alloc = allocator<_Tp> >
        class RubyVector {
public:

    __glibcxx_class_requires(_Tp, _SGIAssignableConcept)

    typedef _Vector_base<_Tp, _Alloc> _Base;
    typedef vector<_Tp, _Alloc> vector_type;

    typedef _Tp value_type;
    typedef size_t size_type;
    typedef typename _Alloc::pointer pointer;
    typedef typename _Alloc::const_pointer const_pointer;
    typedef typename _Alloc::reference reference;
    typedef typename _Alloc::const_reference const_reference;
    typedef __gnu_cxx::__normal_iterator<pointer, vector_type> iterator;
    typedef __gnu_cxx::__normal_iterator<const_pointer, vector_type>
    const_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef ptrdiff_t difference_type;
    typedef typename _Base::allocator_type allocator_type;

    explicit
    RubyVector(const allocator_type& __a = allocator_type()) {
        vec = std::vector<_Tp > (__a);
    }

    RubyVector(size_type __n, const value_type& __value, const allocator_type& __a = allocator_type()) {
        vec = std::vector<_Tp > (__n, __value, __a);
    }

    explicit
    RubyVector(size_type __n) {
        vec = std::vector<_Tp > (__n);
    }

    RubyVector(const RubyVector& __x) {
        vec = std::vector<_Tp > (__x.vec);
    }

    template<typename _InputIterator>
    RubyVector(_InputIterator __first, _InputIterator __last, const allocator_type& __a = allocator_type()) {
        vec = std::vector<_Tp > (__first, __last, __a);
    }

    //virtual ~RubyVector() {
    //}

    void
    assign(size_type __n, const value_type& __val) {
        vec.assign(__n, __val);
    }

    template<typename _InputIterator>
    void
    assign(_InputIterator __first, _InputIterator __last) {
        vec.assign(__first, __last);
    }

    iterator
    begin() {
        return vec.begin();
    }

    const_iterator
    begin() const {
        return vec.begin();
    }

    iterator
    end() {
        return vec.end();
    }

    const_iterator
    end() const {
        return vec.end();
    }

    reverse_iterator
    rbegin() {
        return vec.rbegin();
    }

    const_reverse_iterator
    rbegin() const {
        return vec.rbegin();
    }

    reverse_iterator
    rend() {
        return vec.rend();
    }

    const_reverse_iterator
    rend() const {
        return vec.rend();
    }

    size_type
    size() const {
        return vec.size();
    }

    size_type
    max_size() const {
        return vec.max_size();
    }

    void
    resize(size_type __new_size, const value_type& __x) {
        return vec.resize(__new_size, __x);
    }

    void
    resize(size_type __new_size) {
        return vec.resize(__new_size);
    }

    size_type
    capacity() const {
        return vec.capacity();
    }

    bool
    empty() const {
        return vec.empty();
    }

    void
    reserve(size_type __n) {
        vec.reserve(__n);
    }

    reference
    operator[](long __n) {
        if (__n < 0) __n += size();
        return vec.at(__n);
    }

    const_reference
    operator[](long __n) const {
        if (__n < 0) __n += size();
        return vec.at(__n);
    }

    reference
    at(long __n) {
        if (__n < 0) __n += size();
        return vec.at(__n);
    }

    const_reference
    at(long __n) const {
        if (__n < 0) __n += size();
        return vec.at(__n);
    }

    reference
    front() {
        return vec.front();
    }

    const_reference
    front() const {
        return vec.front();
    }

    reference
    back() {
        return vec.back();
    }

    const_reference
    back() const {
        return vec.back();
    }

    void
    push_back(const value_type& __x) {
        return vec.push_back(__x);
    }

    void
    pop_back() {
        return vec.pop_back();
    }

    iterator
    insert(iterator __position, const value_type& __x) {
        return vec.insert(__position, __x);
    }

    void
    insert(iterator __position, size_type __n, const value_type& __x) {
        return vec.insert(__position, __n, __x);
    }

    template<typename _InputIterator>
    void
    insert(iterator __position, _InputIterator __first,
            _InputIterator __last) {
        return vec.insert(__position, __first, __last);
    }

    iterator
    erase(iterator __position) {
        return vec.erase(__position);
    }

    iterator
    erase(iterator __first, iterator __last) {
        return vec.erase(__first, __last);
    }

    void
    swap(RubyVector& __x) {
        return vec.swap(__x);
    }

    void
    clear() {
        return vec.clear();
    }

private:
    std::vector<_Tp> vec;
};



#endif	/* _MYVECTOR_H */


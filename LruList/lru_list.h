#ifndef LRU_LIST_H
#define	LRU_LIST_H

#include <vector>
#include <algorithm>

template <typename T>
class lru_list {
    typedef typename std::vector<T> container_type;
    typedef typename container_type::iterator iterator;
    container_type vec;
public:
    typedef typename container_type::value_type value_type;
    typedef typename container_type::const_reference const_reference;
    typedef typename container_type::const_iterator const_iterator;
    typedef typename container_type::reference reference;
    typedef typename container_type::size_type size_type;

    bool empty() const {
        return vec.empty();
    }

    size_type size() const {
        return vec.size();
    }

    void insert(const_reference e) {
        iterator it = std::find(vec.begin(), vec.end(), e);
        if (it != vec.end()) {
            vec.erase(it);
        }
        vec.insert(vec.begin(), e);
    }

    value_type front() const {
        return *vec.begin();
    }

    const_iterator begin() const {
        return vec.begin();
    }

    const_iterator end() const {
        return vec.end();
    }

    bool contains(const_reference e) {
        return std::find(vec.begin(), vec.end(), e) != vec.end();
    }

    template <typename vector_type>
    std::vector<vector_type> asVector() const {
        std::vector <vector_type> ret_vec(begin(), end());
        return ret_vec;
    }

private:

};

#endif	/* LRU_LIST_H */


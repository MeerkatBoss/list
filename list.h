/**
 * @file list.h
 * @author MeerkatBoss (solodovnikov.ia@phystech.edu)
 * @brief List data structure
 * @version 0.1
 * @date 2022-10-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef COMPACT_LIST_H
#define COMPACT_LIST_H

#include <stddef.h>

#ifndef REDEFINE_ELEMENT
typedef void* element_t;
const element_t POISON     = NULL;
#endif

/**
 * @brief 
 * Iterator over `compact_list` elements
 */
typedef size_t list_iterator;

struct compact_list;

/**
 * @brief 
 * Linked list node
 */
struct node
{
    element_t     value;
    list_iterator next;
    list_iterator prev;
    int           is_free;
};

/**
 * @brief 
 * Linked list
 */
struct compact_list
{
    node*         nodes;
    list_iterator free;
    size_t        size;
    size_t        capacity;
    int           is_linear;
};

/**
 * @brief Construct `compact_list` instance
 * @return Constructed instance
 */
[[nodiscard]]
compact_list list_ctor(void);

/**
 * @brief Destroy `compact_list` instance. Free associated resources
 * 
 * @param[inout] list `compact_list` instance to be freed
 */
void list_dtor(compact_list* list);

/**
 * @brief Check list integrity
 * 
 * @param[in] list `compact_list` instance
 * @return 1 upon successful check, 0 otherwise
 */
int list_check(compact_list* list);

/**
 * @brief Get iterator to first list element
 * 
 * @param[in] list `compact_list` instance
 * @return `list_iterator` or 0 if list is empty
 */
list_iterator list_begin(const compact_list* list);

/**
 * @brief Get iterator to last list element
 * 
 * @param[in] list `compact_list` instance
 * @return `list_iterator` or 0 if list is empty
 */
list_iterator list_end(const compact_list* list);

/**
 * @brief Get iterator to next list element
 * 
 * @param[in] list `compact_list` instance
 * @param[in] iterator Iterator to current list element
 * @return `list_iterator` or 0 if iterator pointed to last
 * list element
 */
list_iterator next_element(const compact_list* list, const list_iterator iterator);

/**
 * @brief Get iterator to previous list element
 * 
 * @param[in] list `compact_list` instance
 * @param[in] iterator Iterator to current list element
 * @return `list_iterator` or 0 if iterator pointed to first
 * list element
 */
list_iterator prev_element(const compact_list* list, const list_iterator iterator);

/**
 * @brief Add element after current
 * 
 * @param[in] list `compact_list` instance
 * @param[in] iterator Iterator to current list element
 * @param[in] value Added value
 * @return Iterator to added list element
 */
list_iterator insert_after(compact_list* list, list_iterator iterator, element_t value);

/**
 * @brief Add element before current
 * 
 * @param[in] list `compact_list` instance
 * @param[in] iterator Iterator to current list element
 * @param[in] value Added value
 * @return Iterator to added list element
 */
list_iterator insert_before(compact_list* list, list_iterator iterator, element_t value);

/**
 * @brief Add element after last
 * 
 * @param[in] list `compact_list` instance
 * @param[in] value Added value
 * @return Iterator to added list element
 */
list_iterator push_back(compact_list* list, element_t value);

/**
 * @brief Add element before first
 * 
 * @param[in] list `compact_list` instance
 * @param[in] value Added value
 * @return Iterator to added list element
 */
list_iterator push_front(compact_list* list, element_t value);

/**
 * @brief Get element value by iterator
 * 
 * @param[in] list `compact_list` instance
 * @param[in] iterator Iterator to list element
 * @return Element value
 */
element_t get_element(const compact_list* list, const list_iterator iterator);

/**
 * @brief Erase element from list
 * 
 * @param[in] list `compact_list` instance
 * @param[in] iterator Iterator to deleted element
 * 
 * @warning Call to this function invalidates `iterator`
 */
void erase_element(compact_list* list, list_iterator iterator);

/**
 * @brief Erase last element from list
 * 
 * @param[in] list `compact_list` instance
 * 
 * @warning Call to this function invalidates all iterators,
 * pointing to list end
 */
void pop_back(compact_list* list);

/**
 * @brief Erase first element from list
 * 
 * @param[in] list `compact_list` instance
 * 
 * @warning Call to this function invalidates all iterators,
 * pointing to list start
 */
void pop_front(compact_list* list);

/**
 * @brief Sort list by element order.
 * 
 * @param[in] list `compact_list` instance
 */
void linearize(compact_list* list);

/**
 * @brief Get element by its number in list
 * 
 * @param[in] list `compact_list` instance
 * @param[in] num Element number in list
 * @return Iterator to element
 * 
 * @warning This function can be called only on linearized lists
 */
list_iterator element_by_number(const compact_list* list, size_t num);

#endif
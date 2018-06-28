#pragma once
#include "Song.h"
#include <iostream>
#include <memory>

/**
 * @brief The SmartPointers class
 *
 * Smart pointers needs to include memory library
 *
 * There are 3 kind of smart pointers:
 *
 * The std::unique_ptr for exclusive-ownership resourse manager
 * This kind of smart pointer:
 *    - Keeps the object ownership through a pointer
 *    - Disposes of the object when the unique_ptr goes out of
 *      scope.
 *    - Is initialized with std::make_unique rather than new
 *
 * The std::shared_ptr for shared-ownership resourse manager
 * This kind of smart pointer:
 *    - Retains shared ownership of an object through a pointer
 *    - Disposes of the object when the last remaining shared_ptr
 *      owning the object is destroyed;
 *    - Also it disposes of the object when the last remaining
 *      shared_ptr owning the object is assigned another pointer
 *      via operator= or reset().
 *    - Is initialized with std::make_unique rather than new
 *
 * The std::weak_ptr is a special-case smart pointer for use
 * in conjunction with shared_ptr (shared_ptr must have done
 * before in any place of our code). A weak_ptr provides access
 * to an object that is owned by one or more shared_ptr
 * instances, but does not participate in reference counting.
 * Use when you want to observe an object, but do not require
 * it to remain alive. Required in some cases to break circular
 * references between shared_ptr instances.
 *
 * is a smart pointer that holds a non-owning ("weak") reference
 * to an object that is managed by std::shared_ptr. It must be
 * converted to std::shared_ptr in order to access the referenced
 * object.
 *
 * The std::weak_ptr is an augmentation of std::shared_ptr
 */
class SmartPointers
{
private:
    std::string* m_ObjectWithoutDeleting;
    std::string* m_ObjectWithDeleting;

    bool WeakPtrHasExpired (std::weak_ptr<Song> weakSongPointer);

public:
    SmartPointers();
    ~SmartPointers();

    void UniquePtrExample ();
    void SharedPtrExample ();
    void WeakPtrExample ();
};

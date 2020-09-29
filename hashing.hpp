#ifndef OPEN_ADRESS__HASHING_HPP_
#define OPEN_ADRESS__HASHING_HPP_

namespace kuroda {

class HashTableInterface {
 public:
  virtual int get(int key) const = 0;
  virtual void set(int key, int value) = 0;
};

/*
 * Unstored value needs to be -1
 */
class HashTable : HashTableInterface {
// TODO: Needs implementation by yourself.

};

}

#endif //OPEN_ADRESS__HASHING_HPP_

## iterators

* if you modify container while iterator then behavior "may be" undefined
  * if you insert into a vector while iterating it, then the iterator may become invalid due to relocation depending on where it is relative to the insert
  * when erasing you can get the next iterator from erase call
  * same thing with linked list may not be an issue
  * check specific docs

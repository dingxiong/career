## packages

###  container initialization
- raw array
  - Ref: https://en.cppreference.com/w/c/language/array_initialization
  - Examples:
  ```
    int const A::test[10][10];           // uninitialized
    int const A::test[10][10] = { {0} }; // all elements initialized to 0.
    int const A::test[10][10] = {1,2};   // test[0][0] ==1, test[0][1]==2, rest==0
    std::fill(std::begin(A[0]), std::end(A[0]), -1); // fill out the first row with -1
  ```
- vector
  - Example: `std::vector<std::vector<int>> x(rows, std::vector<int>(cols, num));`.
- 

### container
- `unordered_set<K, Hash, KeyEqual, Allocator>`
  - erase, insert
- `std::map<K, V, Compare, Allocator>`: 
  - erase, insert,
  - upper_bound(k): greater than k
  - lower_bound(k): greater or equal than k
- vector: 
  - push_back, pop_back
  - front, back,
- stack:
  - push, pop, top
- std::deque
  - front, back, push_back, pop_back, push_front(emplace_front), push_back(emplace_back), begin, end,
- queue, priority_queue:
  - front, back, push(emplace), pop: push element at back, pop element from front
  - priority_queue is by default a max heap
  - both queue and priority_queue do not define `begin`, `end`, so in order to view the elements 
    it, you should pop out the elements and reconstruct the queue.
    For queue, the default underlying container is `std::deque`, and queue constructor only accepts a new container. For priority_queue, the constructer accepts begin and end iterators.
- `std::list<T, Allocator>`
  - push_back, emplace_back, pop_back, push_front, emplace_front, pop_front, front, back
  - insert/emplace, erase
- std::string:
  - `find` and `find_first_of` are two different functions
  - `std::string::npos`

### <iterator>
- std::back_insert_iterator, std::front_insert_iterator, std::insert_iterator : class
  - back/front_insert_interator and insert_iterator have different constructor signature. The latter requires an iterator as second param.
- std::back_inserter, std::front_inserter, std::inserter : function
- std::ostream_iterator, std::istream_iterator : class
  - Note, the template param cannot be omitted, and the second parameter is a string not a char. 
  - Ex: std::ostream_iterator<int>(std::cout, ",")
- Most container's iterator class only defines `++`, `--` operator. In order to increased/decrease  
  iterator, use `std::advance(iter, n)`.

### <algorithm>
- std::reverse, std::reverse_copy
- std::sort vs std::stable_sort
- std::accumulate
- std::count, std::count_if
- std::min_element, std::max_element
  - Can be used for raw array
- `std::lower_bound`, `std::upper_bound`, `std::binary_search`

### functional
- std::greater, std::less

### <cctypes>
- std::isalpha, std::isdigit, std::isalnum
- std::tolower, std::toupper
  - Note, the signature is `int tolower( int ch );` so we should be careful with two things.
    - 1. We should convert input as `unsigned char` : `static_cast<unsigned char>()`
    - 2. It is passed by value. It cannot change the value in place.
- 

### Mics
  - swap: 
    - swap elements of a vector: `std::swap(v[i], v[j])`
  - nullptr:
    - It has type `std::nullptr_t`. It does not overwrite `operator bool` function, so `!nullptr` is always true. use `ptr == nullptr` to check if `ptr` is null or not, not use `!ptr`.

### Util functions
1. string split
  ```
  ```
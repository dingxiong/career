## Tips
### Binary search
Suppose the search range is `[from, to]`, and `mid` is the middle index as `(from + to) / 2`. It is better to make the left/right recursive search range as `[from, mid]` and `[mid+1, to]`. If you draw the cases for two-element and three-element cases on a paper, you will find the benefits. The reasoning behind is that for all possible cases, `mid >= from` and `mid < to`. You see `mid` is strictly less than `to`.

### Median number
`(a[(n-1)/2] + a[n/2]) / 2` no matter array has odd or even number of elements.

### C++ specific
1. Use `std::deque` for use cases of `std::stack`, `std::queue`. So I do not need to remember the subtle differences of their APIs. Also, std::deque provide iterator features for constructions and iteration, which is easier for me to construct it and print the content of it.
2.
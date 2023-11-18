## templates

* template functions look like

```cpp
template <typename T>
T maxof ( const T & a, const T & b ) {
    return ( a > b ? a : b );
}
```
now you can invoke this with `maxof<int>( a, b )`

* C++14 also allows specialization of variables

```cpp
template<typename T>
T pi = T(3.1415926535897932385L);

// you can now get a specialized version of this value
cout.precision(20);
cout << pi<double> << endl;

```


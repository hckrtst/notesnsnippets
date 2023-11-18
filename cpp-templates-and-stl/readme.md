<!-- vscode-markdown-toc -->
* 1. [templates](#templates)
	* 1.1. [implementing a stack using templates](#implementingastackusingtemplates)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->##  1. <a name='templates'></a>templates

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
constexpr T pi = T(3.1415926535897932385L);

// you can now get a specialized version of this value
cout.precision(20);
cout << pi<double> << endl; // will truncate
cout << pi<float> << endl; // will truncate
cout << pi<long double> << endl; // the one that prints it entirely
```

###  1.1. <a name='implementingastackusingtemplates'></a>implementing a stack using templates






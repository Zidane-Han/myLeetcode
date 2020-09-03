**vector**

```c++
// initialization
vector<int> v;
vector<int> v = {0,1,2,3,4,5};
vector<int> v(7);  // 7 elements are 0 by default
vector<int> v(7, 1); // 7 elements are one

// min value
iterator min_pos = min_element(v.begin(), v.end());
int min_val = *min_pos;

// relative distance
int idx = distance(v.begin(), v.begin() + 5);
```

**stack**

```c++
st.push(element);  // insert the element
st.top();  // access the top element
st.pop();  // remove the top element
```

**unordered_map**

```cpp
// delete by key
u.erase(key)
```

**string**

```cpp
// find
// return 1st char of the first match; otherwise returns string::npos
s.find(substring);
s.find(substring, start_index);
s.find(substring, start_index, len); // length of subtring to match
// substring
s.substr(start_index, length=optional);

// conversion
stoi(str);  // string to int
to_string(num); // any type of values to string 
```


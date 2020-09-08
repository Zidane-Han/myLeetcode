**vector**

```c++
// initialize array
int arrary[length];
int arrary[] = {1, 2, 3, 4};
int arrary[length] = {1, 2, 3, 4};
int array[lengthA][lengthB];

// initialization
vector<int> v;
vector<int> v = {0,1,2,3,4,5};
vector<int> v(7);  // 7 elements are 0 by default
vector<int> v(7, 1); // 7 elements are one

// resize
v.resize(n);   // only change the capacity
v.resize(n, val);   // change the capacity and initialize new elements

// access and add element
v.front();  // access the first element
v.back();   // access the last element
v.push_back();
v.pop_back();   // remove the last element

// insert
v.insert(it_pos, ele);
v.insert(it_pos, count, ele);
v.insert(it_pos, eles.begin(), eles.end());

// min value
iterator min_pos = min_element(v.begin(), v.end());
int min_val = *min_pos;

// relative distance
int idx = distance(v.begin(), v.begin() + 5);

// sort
sort(v.begin(), v.end());
// count element frequency
count(v.begin(), v.end(), element);
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

// add char(s)
s.push_back(char);
s += char;
s.append(string);
s.append(times, char);

// conversion
stoi(str);  // string to int
to_string(num); // any type of values to string 
```


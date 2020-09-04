#pragma once

#include <random>

#define cti(x) (static_cast<int>((x)))
#define sz static_cast<int>(arr.size())

using namespace std;
using namespace utils;

using List = vector<int>;
using Row = vector<int>;
using Table = vector<Row>;

constexpr int INF = INT_MAX - 10;

inline void newsymbol(const int n, const char symbol) {
    if (n == 1) cout << symbol;
    else cout << string(n, symbol);
}

inline void newspace(const int n = 1) {
    newsymbol(n, ' ');
}

inline void newline(const int n = 1) {
    newsymbol(n, '\n');
}

inline vector<string> splitline(istream& is = cin, const char delimiter = ' ') {
    vector<string> result;
    string token;
    while (getline(is, token, delimiter)) result.emplace_back(move(token));
    return result;
}

inline vector<string> splitline(const char* s, const char delimiter = ' ') {
    stringstream ss(s);
    return splitline(ss, delimiter);
}

inline vector<string> splitline(const string& s, const char delimiter = ' ') {
    return splitline(s.c_str(), delimiter);
}

inline string readline(istream& is = cin) {
    string s;
    getline(is, s);
    return s;
}

inline vector<string> readlines(istream& is = cin) {
    vector<string> result;
    string token;
    while (getline(is, token)) result.push_back(move(token));
    return result;
}

inline vector<string> readlines(const char* s) {
    stringstream ss(s);
    return readlines(ss);
}

inline vector<string> readlines(const string& s) {
    return readlines(s.c_str());
}

// template<class T>
// inline void bits_print(const T n) noexcept
// {
//     for (T i = 1 << ((sizeof(n) * 8) - 1); i > 0; i >>= 1) {
//         printf((n & i) ? "1" : "0");
//     }
// }

template<class T>
inline void bits_print(const T n) noexcept
{
    if (n == 1) {
        cout << '1';
    }
    else {
        bits_print(n / 2);
        cout << n % 2;
    }
}

template<class T>
inline T bits_reverse(const T n) noexcept
{
    T res{};
    for (T i = 1 << ((sizeof(n) * 8) - 1); i > 0; i >>= 1) {
        if (!(n & i)) {
            res |= i;
        }
    }
    return res;
}

template<class T>
inline size_t bits_count(const T n) noexcept
{
    return log2(n) + 1;
}

template<class T>
inline size_t digits_count(const T n) noexcept
{
    return log10(n) + 1;
}

inline uint32_t ip_to_integer(const uint8_t ip[]) noexcept
{
    return
        ip[0] * (1 << 24) +
        ip[1] * (1 << 16) +
        ip[2] * (1 <<  8) +
        ip[3] * (1 <<  0);
}

template<class T>
inline bool is_even(const T n) noexcept
{
    return !(n & 1);
}

template<class T>
inline bool is_odd(const T n) noexcept
{
    return n & 1;
}

inline int ArraySum(const vector<int>& arr, int a, int b, int acc = INT_MIN) noexcept
{
    if (a > b) return acc;
    return ArraySum(arr, a + 1, b, acc == INT_MIN ? arr[a] : acc + arr[a]);
}

inline int ArraySum(const vector<int>& arr) noexcept
{
    return ArraySum(arr, 0, arr.size() - 1);
}

inline int TableSum(const vector<vector<int>>& table, int rows, int cols, int top, int left) noexcept
{
    int sum{INT_MIN};
    for (int i = top; i < rows; ++i) {
        const auto local_sum = ArraySum(table[i], left, cols);
        sum = sum == INT_MIN ? local_sum : sum + local_sum;
    }
    return sum;
}

inline int TableSum(const vector<vector<int>>& table) noexcept
{
    return TableSum(table, table.size(), table[0].size(), 0, 0);
}

/* D. J. Bernstein hash function */
template<class T>
inline size_t djb_hash(const T* cp) noexcept
{
    size_t hash = 5381;
    while (*cp) {
        hash = 33 * hash ^ static_cast<size_t>(*cp++);
    }
    return hash;
}

template<class T>
inline size_t djb_hash(const T& param) noexcept
{
    return djb_hash(param.data());
}

/* Fowler/Noll/Vo (FNV) hash function, variant 1a */
template<class T>
inline size_t fnv1a_hash(const T* cp) noexcept
{
    size_t hash = 0x811c9dc5;
    while (*cp) {
        hash ^= static_cast<size_t>(*cp++);
        hash *= 0x01000193;
    }
    return hash;
}

template<class T>
inline size_t fnv1a_hash(const T& param) noexcept
{
    return fnv1a_hash(param.data());
}

// Say the compiler that this assembler code has significant impact on runtime performance
// So, we can turn off optimizations for this data pointer
inline void escape(void* p) noexcept
{
    asm volatile ("" : : "g"(p) : "memory");
}

// This code magically writes to all memory without any instructions
// We can use after some pushing memory operations like vector.push_back(),
// to eliminate compilier optimizations on write operations
inline void clobber()
{
    asm volatile ("" : : : "memory");
}

#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)


inline void GetRandomString(char *s, size_t len) noexcept
{
    static constexpr char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937_64 generator(random_device());
    std::uniform_int_distribution<int> distribution{0, sizeof(alphanum) / sizeof(alphanum[0]) - 1};

    for (size_t i = 0; i < len; ++i) {
        s[i] = alphanum[distribution(generator)];
    }

    s[len] = 0;
}

inline string GetRandomString(size_t len) noexcept
{
    std::string s(len, ' ');
    GetRandomString(s.data(), len);
    return s;
}

inline vector<string> GetRandomStrings(size_t len, size_t string_len) noexcept
{
    static constexpr char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937_64 generator(random_device());
    std::uniform_int_distribution<int> distribution{0, sizeof(alphanum) / sizeof(alphanum[0])};

    vector<string> strings(len, string(string_len, ' '));
    for (size_t i = 0; i < len; ++i) {
        for (size_t j = 0; j < string_len; ++j) {
            strings[i][j] = alphanum[distribution(generator)];
        }
        strings[i][string_len] = '\0';
    }
    return strings;
}

inline int GetRandomNumber(int from, int to) noexcept
{
    std::random_device random_device;
    std::mt19937_64 generator(random_device());
    std::uniform_int_distribution<int> distribution{from, to};

    return distribution(generator);
}

inline int GetRandomNumber(int diapason) noexcept
{
    std::random_device random_device;
    std::mt19937_64 generator(random_device());
    std::uniform_int_distribution<int> distribution{0, diapason};

    return distribution(generator);
}

inline int GetRandomNumber() noexcept
{
    std::random_device random_device;
    std::mt19937_64 generator(random_device());
    std::uniform_int_distribution<int> distribution{0, INT_MAX};

    return distribution(generator);
}

inline vector<int> GetRandomNumbers(int n, int from, int to) noexcept
{
    std::random_device random_device;
    std::mt19937_64 generator(random_device());
    std::uniform_int_distribution<int> distribution{from, to};

    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) {
        arr[i] = distribution(generator);
    }
    return arr;
}

inline vector<int> GetRandomNumbers(int n) noexcept
{
    return GetRandomNumbers(n, -99, 99);
}

inline vector<vector<int>> GetRandomTable(int a, int b, int from, int to) noexcept
{
    std::random_device random_device;
    std::mt19937_64 generator(random_device());
    std::uniform_int_distribution<int> distribution{from, to};

    vector<vector<int>> table(a, vector<int>(b, 0));
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            table[i][j] = distribution(generator);
        }
    }
    return table;
}

inline vector<vector<int>> GetRandomTable(int a, int b) noexcept
{
    return GetRandomTable(a, b, -99, 99);
}

template<class T, class U>
inline bool IsArrayContains(const T& arr, const U& param) noexcept
{
    for (const auto& elem : arr) {
        if (elem == param) {
            return true;
        }
    }
    return false;
}

template<class T, class U>
inline bool IsTableContains(const T& table, const U& param) noexcept
{
    for (const auto& row : table) {
        if (IsArrayContains(row, param)) {
            return true;
        }
    }
    return false;
}

template<class Fn, class ... Args>
inline auto TestOnRandomString(Fn fn, int string_size, int times, Args&&... args) noexcept ->
    std::enable_if_t<
        decltype(fn("", std::forward<Args>(args)...), true){true},
        void
    >

{
    for (int i = 0; i < times; ++i) {
        const auto s = GetRandomString(string_size);
        fn(s, std::forward<Args>(args)...);
        cout << "Test #" << i << " passed :)\n";
    }
    cout << "All tests passed :)\n";
}

template<class Fn, class ... Args>
inline auto TestOnRandomString(Fn fn, Fn fn2, int string_size, int times, Args&&... args) noexcept ->
    std::enable_if_t<
        decltype(fn("", std::forward<Args>(args)...), true){true},
        void
    >

{
    for (int i = 0; i < times; ++i) {
        const auto arr = GetRandomString(string_size);
        const auto a = fn1(arr, std::forward<Args>(args)...);
        const auto b = fn2(arr, std::forward<Args>(args)...);
        if (a != b) {
            cout << "Test #" << i << " failed :(\n"
                 << "String: \n";
            cout << arr;
            cout << "\nFirst result: " << a << '\n'
                 << "Second result: " << b << '\n' << '\n';
            print(std::forward<Args>(args)...);
            abort();
        }
        else {
            cout << "Test #" << i << " passed :)\n";
        }
    }
    cout << "All tests passed :)\n";
}

template<class Fn, class ... Args>
inline auto TestOnRandomStrings(Fn fn, int string_size1, int string_size2, int times, Args&&... args) noexcept ->
    std::enable_if_t<
        decltype(fn("", "", std::forward<Args>(args)...), true){true},
        void
    >

{
    for (int i = 0; i < times; ++i) {
        const auto s1 = GetRandomString(string_size1);
        const auto s2 = GetRandomString(string_size2);
        fn(s1, s2, std::forward<Args>(args)...);
        cout << "Test #" << i << " passed :)\n";
    }
    cout << "All tests passed :)\n";
}

template<class Fn, class ... Args>
inline auto TestOnRandomStrings(Fn fn, Fn fn2, int string_size1, int string_size2, int times, Args&&... args) noexcept ->
    std::enable_if_t<
        decltype(fn("", "", std::forward<Args>(args)...), true){true},
        void
    >

{
    for (int i = 0; i < times; ++i) {
        const auto arr = GetRandomString(string_size1);
        const auto arr2 = GetRandomString(string_size2);
        const auto a = fn(arr, arr2, std::forward<Args>(args)...);
        const auto b = fn2(arr, arr2, std::forward<Args>(args)...);
        if (a != b) {
            cout << "Test #" << i << " failed :(\n"
                 << "String1: \n";
            cout << arr;
            cout << "String2: \n";
            cout << arr2;
            cout << "\nFirst result: " << a << '\n'
                 << "Second result: " << b << '\n' << '\n';
            print(std::forward<Args>(args)...);
            abort();
        }
        else {
            cout << "Test #" << i << " passed :)\n";
        }
    }
    cout << "All tests passed :)\n";
}

template<class Fn, class ... Args>
inline auto TestOnRandomArray(Fn fn, int size, int times, Args&&... args) noexcept ->
    std::enable_if_t<
        decltype(fn({}, std::forward<Args>(args)...), true){true},
        void
    >

{
    for (int i = 0; i < times; ++i) {
        const auto arr = GetRandomNumbers(size);
        fn(arr, std::forward<Args>(args)...);
        cout << "Test #" << i << " passed :)\n";
    }
    cout << "All tests passed :)\n";
}

template<class Fn, class ... Args>
inline auto TestOnRandomPositiveArray(Fn fn, int size, int times, Args&&... args) noexcept ->
    std::enable_if_t<
        decltype(fn({}, std::forward<Args>(args)...), true){true},
        void
    >

{
    for (int i = 0; i < times; ++i) {
        const auto arr = GetRandomNumbers(size, 1, 99);
        fn(arr, std::forward<Args>(args)...);
        cout << "Test #" << i << " passed :)\n";
    }
    cout << "All tests passed :)\n";
}

template<class Fn, class ... Args>
inline auto TestOnRandomArrays(Fn fn, int size1, int size2, int times, Args&&... args) noexcept ->
    std::enable_if_t<
        decltype(fn({}, {}, std::forward<Args>(args)...), true){true},
        void
    >

{
    for (int i = 0; i < times; ++i) {
        const auto arr1 = GetRandomNumbers(size1);
        const auto arr2 = GetRandomNumbers(size2);
        fn(arr1, arr2, std::forward<Args>(args)...);
        cout << "Test #" << i << " passed :)\n";
    }
    cout << "All tests passed :)\n";
}


template<class Fn, class ... Args>
inline auto TestOnRandomArray(Fn fn1, Fn fn2, int size, int times, Args&& ... args) noexcept -> void
{
    for (int i = 0; i < times; ++i) {
        const auto arr = GetRandomNumbers(size);
        const auto a = fn1(arr, std::forward<Args>(args)...);
        const auto b = fn2(arr, std::forward<Args>(args)...);
        if (a != b) {
            cout << "Test #" << i << " failed :(\n"
                 << "Array: \n";
            print(arr, size);
            cout << "\nFirst result: " << a << '\n'
                 << "Second result: " << b << '\n' << '\n';
            print(std::forward<Args>(args)...);
            abort();
        }
        else {
            cout << "Test #" << i << " passed :)\n";
        }
    }
    cout << "All tests passed :)\n";
}

template<class Fn, class ... Args>
inline auto TestOnRandomPositiveArray(Fn fn1, Fn fn2, int size, int times, Args&& ... args) noexcept -> void
{
    for (int i = 0; i < times; ++i) {
        const auto arr = GetRandomNumbers(size, 1, 99);
        const auto a = fn1(arr, std::forward<Args>(args)...);
        const auto b = fn2(arr, std::forward<Args>(args)...);
        if (a != b) {
            cout << "Test #" << i << " failed :(\n"
                 << "Array: \n";
            print(arr, size);
            cout << "\nFirst result: " << a << '\n'
                 << "Second result: " << b << '\n' << '\n';
            print(std::forward<Args>(args)...);
            abort();
        }
        else {
            cout << "Test #" << i << " passed :)\n";
        }
    }
    cout << "All tests passed :)\n";
}

template<class Fn, class ... Args>
inline auto TestOnRandomArray(Fn fn1, Fn fn2, int size, int size2, int times, Args&& ... args) noexcept -> void
{
    for (int i = 0; i < times; ++i) {
        const auto arr = GetRandomNumbers(size);
        const auto arr2 = GetRandomNumbers(size2);
        const auto a = fn1(arr, std::forward<Args>(args)...);
        const auto b = fn2(arr2, std::forward<Args>(args)...);
        if (a != b) {
            cout << "Test #" << i << " failed :(\n"
                 << "Array1: \n";
            print(arr, size);
            cout << "Array2: \n";
            print(arr2, size2);
            cout << "\nFirst result: " << a << '\n'
                 << "Second result: " << b << '\n' << '\n';
            if (sizeof...(args) != 0) print(std::forward<Args>(args)...);
            abort();
        }
        else {
            cout << "Test #" << i << " passed :)\n";
        }
    }
    cout << "All tests passed :)\n";
}

template<class Fn, class ... Args>
inline auto TestFunction(Fn fn, Args&& ... args) noexcept ->
    std::enable_if_t<
        decltype(fn(std::forward<Args>(args)...), true){true},
        void
    >
{
    const auto t1 = std::chrono::high_resolution_clock::now();
    fn(std::forward<Args>(args)...);
    const auto t2 = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    cout << "Test passed :) [" << duration << " mcsec]\n";
}

template<class Fn, class ... Args>
inline auto TestFunctionTime(int times, Fn fn, Args&& ... args) noexcept ->
    std::enable_if_t<
        decltype(fn(std::forward<Args>(args)...), true){true},
        void
    >
{
    const auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < times; ++i) {
        fn(std::forward<Args>(args)...);
    }
    const auto t2 = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    cout << "Total time: [" << duration << " mcsec], Function time: " << static_cast<double>(duration) / times << "\n";
}

template<class ResultT, class Fn, class ... Args>
inline auto TestFunction(ResultT result, Fn fn, Args&& ... args) noexcept ->
    std::enable_if_t<
        decltype(fn(std::forward<Args>(args)...), true){true},
        void
    >
{
    const auto t1 = std::chrono::high_resolution_clock::now();
    const auto res = fn(std::forward<Args>(args)...);
    const auto t2 = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    if (res != result) {
        cout << "Test failed :( [" << duration << " mcsec]\n"
             << "Args: \n";
        print(std::forward<Args>(args)...);
        cout << "\nExpected: \n";
        print(result);
        cout << "\nResult: \n";
        print(res);
        cout << endl;
        abort();
    }
    else {
        cout << "Test passed :) [" << duration << " mcsec]\n";
    }
}

template<class ResultT, class Fn, class ... Args>
inline auto TestFunction(ResultT result, Fn fn, const vector<int>& arr, Args&& ... args) noexcept ->
    std::enable_if_t<
        decltype(fn(std::forward<Args>(args)...), true){true},
        void
    >
{
    const auto t1 = std::chrono::high_resolution_clock::now();
    const auto res = fn(arr, std::forward<Args>(args)...);
    const auto t2 = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    if (res != result) {
        cout << "Test failed :( [" << duration << " mcsec]\n"
             << "Result: " << res << '\n'
             << "Array: \n";
        print(arr, arr.size());
        print(std::forward<Args>(args)...);
        cout << '\n';
        abort();
    }
    else {
        cout << "Test passed :) [" << duration << " mcsec]\n";
    }
}

template<class ResultT, class Fn, class ... Args>
inline auto TestFunction(ResultT result, Fn fn, const vector<int>& arr1, const vector<int>& arr2, Args&& ... args) noexcept ->
    std::enable_if_t<
        decltype(fn(std::forward<Args>(args)...), true){true},
        void
    >
{
    const auto t1 = std::chrono::high_resolution_clock::now();
    const auto res = fn(arr1, arr2, std::forward<Args>(args)...);
    const auto t2 = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    if (res != result) {
        cout << "Test failed :( [" << duration << " mcsec]\n"
             << "Result: " << res << '\n'
             << "Array1: \n";
        print(arr1, arr1.size());
        cout << "Array2: \n";
        print(arr2, arr2.size());
        print(std::forward<Args>(args)...);
        cout << "\n";
        abort();
    }
    else {
        cout << "Test passed :) [" << duration << " mcsec]\n";
    }
}

template<class T>
T max(T&& param1, T&& param2) {
    return param1 > param2 ? param1 : param2;
}

template<class T, class ... Args>
T max(T&& param1, T&& param2, Args&& ... args) {
    return max(max(param1, param2), max(std::forward<Args>(args)...));
}

template<
    class T,
    class = enable_if_t<
        decltype(declval<T>().begin(), true){true},
        void
    >
>
decltype(auto) max(T&& param) {
    decay_t<decltype(*param.begin())> result{};
    for (const auto& elem : param) {
        if (result < elem) {
            result = elem;
        }
    }
    return result;
}


template<class T>
T min(T&& param1, T&& param2) {
    return param1 < param2 ? param1 : param2;
}

template<class T, class ... Args>
T min(T&& param1, T&& param2, Args&& ... args) {
    return min(min(param1, param2), min(std::forward<Args>(args)...));
}

template<
    class T,
    class = enable_if_t<
        decltype(declval<T>().begin(), true){true},
        void
    >
>
decltype(auto) min(T&& param) {
    decay_t<decltype(*param.begin())> result{};
    for (const auto& elem : param) {
        if (result > elem) {
            result = elem;
        }
    }
    return result;
}

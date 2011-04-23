#include "../src/javascript_start.h"

var f = function (var x, var y) {
    std::cout << "this: " << This << std::endl;
    This["x"] = x;
    This["y"] = y;

    return This;
};

// New creates a new object this
var a = New(f)(1, 2); // this: <function 0x005240d0>
var b = New(f)(3, 4); // this: <function 0x005248e0>

// Unbound call, 
var c = f(5, 6); // this: undefined

// Bound call
var obj = {42};
obj["f"] = f;

var d = obj["f"](1, 2); // this: [42]

// Call
var e = f["call"](obj, 1, 2); // this: [42]

#include "../src/javascript_end.h"

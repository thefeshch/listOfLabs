#include <cassert>
#include "Vector2.hpp"

int main() {
    Vector2 v1{5.5f, 1.0f};
    Vector2 v2{2.7f, 9.0f};

    assert(((v1 * 2.0f) == Vector2{11.0f, 2.0f}));
    assert(((2.0f * v1) == Vector2{11.0f, 2.0f}));
	
	v1 += v2;
    assert((v1 == Vector2{8.2f, 10.0f}));
    v1 -= v2;
    assert((v1 == Vector2{2.8f, -8.0f}));
	
    v1 *= 3.0f;
    assert((v == Vector2{6.5f, 3.0f}));
    v1 /= 2.0f;
    assert((v1 == Vector2{2.75f, 0.5f}));
	
    assert(((v1 + v2) == Vector2{8.2f, 10.0f}));
    assert(((v1 - v2) == Vector2{2.8f, -8.0f}));
    
    assert(v1[0] == 5.5f);
    assert(v1[1] == 1.0f);

    v1[0] = 6.3f;
    std::cout << v1 << std::endl;

    return 0;
}
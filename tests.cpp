// enum Test
// {
//     a = 1,
//     b = 2, // 2
// };

// enum Test
// {
//     a = 1,
//     b, // 2
// };

// enum Test
// {
//     a, 
//     b, // 1
// };

// enum Test
// {
//     a = -1,
//     b, // 0
// };

// enum Test
// {
//     a = (5 + 10 * 5) / 5, // 11
//     b, 					// 12
// };

// enum Test
// {
//     other = 5,
//     a = other + 6, 	// 11
//     b, 				// 12
// };

// enum Test
// {
//     a = '5',
//     b = '7', 	// 55
// };

// enum Test
// {
//     a = '5',
//     b, // '6'= 54
// };

// enum Test
// {
//     a = 'b',
//     b, 		// 'c'= 99
// };

// enum Test
// {
//     a = 'a' + '1',
//     b, 		// 147
// };


//Почему enum class лучше чем enum? Перечислите. 
//- Потому что enum class делает проверку типа


#include <iostream>
#include <cassert>

enum class Portrait { Lenin, Washington, Hitler };
enum class WireColor { None = -1, Red, Yellow, Green };
enum class LampColor { Blue, White, Red };

WireColor WhatToCut(Portrait portrait, LampColor lampColor, bool switchOn, int dialValue) {
    if (portrait == Portrait::Lenin) {
        return WireColor::None; 
    }

    WireColor wireToCut;
    int lampValue;
    switch (lampColor) {
        case LampColor::Blue: lampValue = 11; break;  
        case LampColor::White: lampValue = 15; break;
        case LampColor::Red: lampValue = 35; break;
    }

    if (portrait == Portrait::Hitler) {
        lampValue = (lampValue == 11) ? 15 : (lampValue == 15) ? 35 : 11;  
    }

    if (dialValue == lampValue) {
        wireToCut = WireColor::Green;
    } else if (dialValue < lampValue) {
        wireToCut = WireColor::Red;
	} else {
        wireToCut = WireColor::Yellow;
    }

    if (switchOn) {
        wireToCut = static_cast<WireColor>((static_cast<int>(wireToCut) + 2) % 3);
    }

    if (dialValue % 4 == 0) {
        wireToCut = static_cast<WireColor>((static_cast<int>(wireToCut) + dialValue) % 3);
    }

    return wireToCut;
}

int main() {
    assert(WhatToCut(Portrait::Lenin, LampColor::Blue, false, 100) == WireColor::None);
    assert(WhatToCut(Portrait::Washington, LampColor::Blue, false, 37) == WireColor::Yellow);
    assert(WhatToCut(Portrait::Washington, LampColor::Blue, true, 11) == WireColor::Yellow);
    assert(WhatToCut(Portrait::Hitler, LampColor::Red, true, 40) == WireColor::Yellow);
    assert(WhatToCut(Portrait::Hitler, LampColor::Blue, false, 15) == WireColor::Green);
    assert(WhatToCut(Portrait::Washington, LampColor::White, false, 8) == WireColor::Green);
	std::cout << "All good" << std::endl;
}

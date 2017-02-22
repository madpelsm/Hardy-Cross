#include <iomanip>
#include <iostream>
#include "Pipe.hpp"
#include "loop.hpp"

int main() {
    Pipe one = Pipe(700, 0.18, 0.00009, 0.0203290791, "1");
    Pipe two = Pipe(630, 0.12, 0.00009, 0.0088697458, "2");
    Pipe three = Pipe(340, 0.12, 0.00009, -0.00980733754803, "3");

    Pipe four = Pipe(250, 0.06, 0.00009, -0.002474004214702, "4");

    // since we want 4 to be shared in between we need to adjust to rotation in
    // the next loop, a better solution should be sought!
    Pipe seven = Pipe(760, 0.06, 0.00009, 0.001604166666667, "7");
    Pipe eight = Pipe(600, 0.06, 0.00009, -0.001604166666667, "8");

    Pipe nine = Pipe(530, 0.15, 0.00009, -0.0145, "9");
    Pipe ten = Pipe(450, 0.08, 0.00009, -0.0045, "10");
    Pipe eleven = Pipe(640, 0.08, 0.00009, 0.0045, "11");

    std::vector<Pipe*> pipes_loop1 = {&one, &two, &three, &four};
    std::vector<Pipe*> pipes_loop2 = {&four, &seven, &eight};
    std::vector<Pipe*> pipes_loop3 = {&nine, &ten, &eleven};

    loop loop1 = loop(pipes_loop1);
    loop loop2 = loop(pipes_loop2);
    loop loop3 = loop(pipes_loop3);
    size_t n =1000;
    for (size_t i = 0; i <n; i++) {
        loop1.iterate();
        loop2.iterate();
        loop3.iterate();
    }

    std::cout << std::setprecision(6) << "flows after " << n << " iterations"
              << std::endl;

    loop1.showResults();
    loop2.showResults();
    loop3.showResults();

    return 0;
}

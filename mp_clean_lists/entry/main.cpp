<<<<<<< HEAD
// #include "List.h"

// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <vector>

// #include "cs225/PNG.h"
// #include "cs225/HSLAPixel.h"

// #include <catch2/catch_test_macros.hpp>
#include "../tests/tests_helper.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <random>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include "List.h"

using namespace cs225;
int main() {

  // PNG in;        in.readFromFile("../tests/alma.png");
  // List<HSLAPixel> list = imageToList(in);
  // list.tripleRotate();
  // PNG out = listToImage(list, in.width(), in.height());
  // out.writeToFile("actual-reverse.png");
  //INFO("Output image `out` saved as actual-reverse.png");







  List<int> list;

  list.insertBack(1);

  list.insertBack(2);
  
  list.insertBack(3);


  list.insertBack(4);

  list.insertBack(5);

  list.insertBack(6);

  // list.insertBack(8);

  // List<int> list2;

  
  // list.insertBack(6);
  //List<int> slist = list.split(4);
  //stringstream s1, s2;

  // std::cout << "List 1 Before Size: " << list.size() << std::endl;
  list.tripleRotate();
  stringstream s1;


  //TEST TRIPLE ROTATE IN REVERSE
  
  // 1-> 2-> 3-> 4-> 5-> 6
  // Triple Rotate Forward: 2- -> 3 -> 1 -> 5 -> 6 -> 4
  // Triple Rotate Reverse: 6 -> 5 -> 1 -> 3 -> 2    (Missing 4)
  list.print(s1);
  // // list2.print(s2);

  // // std::cout << "List 1 After Size: " << list.size() << std::endl;
  std::cout << "List 1: " << s1.str() << std::endl;
  // std::cout << "List 2: " << s2.str() << std::endl;
=======
#include "List.h"

int main() {
  return 0;
>>>>>>> release/main
}

/*
 Achtung!: Keine Gewähr auf korrekten Codingstandard/Stil/Korrektheit!
*/

#include <iostream>
#include <vector>
#include <algorithm>  
#include <fstream>


int main()
{
  std::cout << "Hallo Welt!" << std::endl;
  
  std::vector<int> int_list;
  int input = 0;
  
  std::cin >> input;
  
  
  while(input != -1)
  {
    int_list.push_back(input);
    std::cin >> input;    
      
  }
  
  std::cout << "Pre sorting" << std::endl;
  
  for(auto it = int_list.begin(); it != int_list.end(); it++)
  {
    std::cout << *it << std::endl;
  }
  
  // using default comparison (operator <):
  std::sort (int_list.begin(), int_list.end()); 
  
  std::cout << "After sorting" << std::endl;
  for(auto it = int_list.begin(); it != int_list.end(); it++)
  {
    std::cout << *it << std::endl;
  }
  
   std::ofstream file("demo.bin",
    std::ios::out | std::ios::trunc | std::ios::binary);
    
  if (!file.is_open())
  {
    std::cout << "cannot open file" << std::endl;
  } 

  for(auto it = int_list.begin(); it != int_list.end(); it++)
  {
   // file.write(reinterpret_cast<char*>(&*it), sizeof(int));
    file << *it;
  }
  
  
  
  
  return 0;
}

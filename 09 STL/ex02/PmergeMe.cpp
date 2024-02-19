#include "PmergeMe.hpp"

int *calc_order_insertions(int argc) {
  int nb_insertions = (argc - 3) / 2;
  int *order = new int[nb_insertions];
  int size_group = 0;
  int k = 1;
  for(int i = 0; i < nb_insertions;) {
    size_group = pow(2, k++) - size_group;
    int where_to_stop = i + size_group;
    int v = i + size_group - 1;
    if(where_to_stop >= argc - 1) {
      v -= (where_to_stop - argc + 1);
      where_to_stop -= (where_to_stop - argc + 1);
    }
    for(; i < where_to_stop && i < nb_insertions; v--, i++) 
      order[i] = v;
  }
  return order;
}

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {
  delete order;
}

PmergeMe::PmergeMe(const PmergeMe& o) { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::PmergeMe(int argc, char *argv[]) {
  for(int i = 1; i < argc; i++)
    if(i % 2 == 1 && argv[i + 1] != NULL)
      map.insert(std::pair<unsigned int, unsigned int>(std::strtoul(argv[i + 1], NULL, 10), std::strtoul(argv[i], NULL, 10)));
    else if (i % 2 == 1 && argv[i + 1] == NULL)
      map.insert(std::pair<unsigned int, unsigned int>(std::strtoul(argv[i], NULL, 10), 0)); // 0 ?
  order = calc_order_insertions(argc);
}

map_iterator insert_after_(map_iterator begin, map_iterator end, unsigned int a) { // искать середину
  while(1) {
    map_iterator middle = begin;
    std::advance(middle, std::distance(begin, end) / 2);
    if(a == middle->first)
      return middle ;
    else if(a < middle->first)
      end = middle;
    else if(a > middle->first)
      begin = middle;
    std::cout << " distance = " << std::distance(begin, end) << std::endl;
    if (std::distance(begin, end) <= 1)
      return begin;
  }
  return end;
}

void PmergeMe::run(std::map<unsigned int, unsigned int> map) {
  // sort recursively
  for (map_iterator it = map.begin(); it != map.end(); it++)
    std::cout << "[" << it->first << "," << it->second << "] ";
  std::cout << std::endl;
  //std::cout << "where_insert = " << it_where_insert(map.begin(), map.end(), 3)->first << std::endl; // end !
  //if(a <= map.begin()->first);
  map_iterator insert_after = insert_after_(map.begin(), map.end(), 13);
  std::cout << "insert_after " << insert_after->first << std::endl;
}

void PmergeMe::run() {
  run(map);
}

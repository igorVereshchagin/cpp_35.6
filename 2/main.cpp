#include <iostream>
#include <vector>
#include <unordered_set>

int main()
{
  auto makeUniqVector = [](std::vector<int> &vec)
  {
    std::unordered_set<int> set;
    for (auto &a : vec)
      if (set.find(a) == set.end())
        set.insert(a);
    std::vector<int> retVec;
    for (auto &s : set)
      retVec.push_back(s);
    return std::make_unique<std::vector<int>>(retVec);
  };

  std::vector<int> vec{1, 2, 3, 1, 4, 5, 2, 6, 7, 1, 8, 9, 2, 1};
  std::unique_ptr<std::vector<int>> result = makeUniqVector(vec);

  for (auto &a : *result)
    std::cout << a << std::endl;
  return 0;
}

#include <iostream>
#include <filesystem>
#include <string>

int main()
{
  auto searchFileByExtension = [](const std::filesystem::path &path, const std::string &extension)
  {
    std::vector<std::string> retVec;
    for(auto& p: std::filesystem::recursive_directory_iterator(path))
      if (is_regular_file(p.path()))
        if (!p.path().extension().compare(extension))
          retVec.push_back(p.path().string());
    return retVec;
  };
  auto result = searchFileByExtension(".", ".exe");
  for (auto &s : result)
    std::cout << s << std::endl;
  return 0;
}

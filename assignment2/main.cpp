/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>
std::string kYourName = "Aerry Bones"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::ifstream ifile;
  ifile.open(filename);
  std::string line;
  std::set<std::string> result;
  while(std::getline(ifile, line)){
    result.insert(line);
  }
  return result;
}

std::string initialName(std::string a){
  if(a == ""){
    return "";
  }
  std::stringstream ss(a);
  std::string sub;
  std::string sub1;
  while (std::getline(ss, sub, ' '))
  {
    if(sub != "" && sub[0] >= 'A' && sub[0] <= 'Z'){
      sub1.push_back(sub[0]);
    }
  }
  return sub1;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  // 返回首字母相同的名字队列
  std::string target = initialName(name);
  std::queue<const std::string*> myque;
  for(auto& student : students){
    std::string cur = initialName(student);
    if(cur != "" && cur == target){
      // 如果传入的是临时副本的地址，循环结束，地址就失效了，所以遍历要用引用
      // 容器本身保存的就是const string， 也就不需要const_cast 了
      myque.push(&student);
    }
  }
  return myque;
}
/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  if(matches.empty()){
    return "NO MATCHES FOUND.";
  }else{
    // std::cout << *matches.front();
    std::string result = *matches.front();
    matches.pop();
    return result;
  }
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"

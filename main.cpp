#include <iostream>
#include <cstdlib>
#include <ctime>

// Project 3 — Andrew Bennett
// CIS 5 Week 12 · Fifty students
// Do not edit the boilerplate. It randomly generates 50 scores.
// Do not type scores or names into this file.

void countGrades(const int scores[], int n, int& a, int& b, int& c, int& d, int& failing) {
  a = 0;
  b = 0;
  c = 0;
  d = 0;
  failing = 0;
  if (n <= 0 || scores == nullptr) return;
  
// iterate thrpugh array and increment each grade to the relevant letter grade or failing
  for(int i = 0; i < n; i++)
  {
    if(scores[i] >= 90)
    {
      a += 1;
    }
    else if (scores[i] < 90 && scores[i] >= 80)
    {
      b += 1;
    }
    else if (scores[i] < 80 && scores[i] >= 70)
    {
      c += 1;
    }
    else if (scores[i] < 70 && scores[i] >= 60)
    {
      b += 1;
    }
    else
    {
      failing += 1;
    }    
  }
}

double average(const int scores[], int n) {
  if (n <= 0 || scores == nullptr) return 0.0;
  
  int sum = 0;
// calculate sum of all grades
  for(int i = 0; i < n; i++)
  {
    sum += scores[i];
  }
//calculate mean, use * 1.0 to turn result into a double for decimal accuracey
  return sum * 1.0 / n;
}

void officeHours(const int scores[], int n, int* failingCount) {
  if (failingCount != nullptr) *failingCount = 0;
  if (n <= 0 || scores == nullptr) return;

  while (true)
  {
    for(int i = 0; i < n; i++)
    {
      // print out a notice to students with failing grades
      if(scores[i] < 60)
      {
        std::cout << "Student at index " << scores[i] << " needs to come to office hours." << std::endl;
        // if counter isn't empty then increment counter for every failed grade
        if(failingCount != nullptr)
        {
          *failingCount += 1;
        }
      }
    }
    // end while loop when finished
    break;

  }
  
}

int main() {
  const int N = 50;
  int scores[N];

  // Do not edit this boilerplate. It randomly generates 50 scores.
  srand(static_cast<unsigned>(time(nullptr)));
  for (int i = 0; i < N; ++i) {
    scores[i] = rand() % 100;
  }

  for (int i = 0; i < N; ++i) {
    std::cout << "[" << i << "] " << scores[i] << "\n";
  }

  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int failing = 0;
  countGrades(scores, N, a, b, c, d, failing);

  std::cout << "A: " << a << "\n";
  std::cout << "B: " << b << "\n";
  std::cout << "C: " << c << "\n";
  std::cout << "D: " << d << "\n";
  std::cout << "Failing: " << failing << "\n";
  std::cout << "Average: " << average(scores, N) << "\n";

  int lines = 0;
  officeHours(scores, N, &lines);
  std::cout << "Office hours: " << lines << "\n";

  return 0;
}

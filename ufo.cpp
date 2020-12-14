/*
 * ufo.cpp
 * 
 * Copyright 2020 Sarvesh-SP <sarveshsp@pop-os>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <iostream>
#include "ufo_foo.hpp"
#include <vector>
using namespace std;

int main()
{
  vector<char> incorrect;
  bool guess = false;
  string codeword = "monolith", answer = "__________";
  int misses = 0;
  greet();
  char letter;
  while (answer != codeword && misses < 7)
  {
    display_misses(misses);
    display_status(incorrect, answer);
    cout << "\n\nPlease enter your guess:";
    cin >> letter;
    for (int i = 0; i < (int)codeword.length(); i++)
    {
      if (letter == codeword[i])
      {
        answer[i] = letter;
        guess = true;
      }
    }
    if (guess)
    {
      cout << "Correct!\n";
    }
    else
    {
      cout << "Incorrect! The tractor beam pulls the person in further.";
      incorrect.push_back(letter);
      misses++;
    }
    guess = false;
  }
  end_game(answer, codeword);
}

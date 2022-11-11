/**
 * @file cartalk_puzzle.cpp
 * Declares the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#pragma once

#include <string>
#include <tuple>
#include <algorithm>
#include "pronounce_dict.h"
#include <iostream>
std::vector<std::tuple<std::string, std::string, std::string> > cartalk_puzzle(PronounceDict d,
                                         const std::string& word_list_fname);

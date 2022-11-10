/*
We have a catalog of song titles (and their lengths) that we play at a local radio station.  We have been asked to play two of those songs in a row, and they must add up to exactly seven minutes long.  

Given a list of songs and their durations, write a function that returns the names of any two distinct songs that add up to exactly seven minutes.  If there is no such pair, return an empty collection. 

Example:
song_times_1 = [
    ("Stairway to Heaven", "8:05"), ("Immigrant Song", "2:27"),
    ("Rock and Roll", "3:41"), ("Communication Breakdown", "2:29"),
    ("Good Times Bad Times", "2:48"), ("Hot Dog", "3:19"),
    ("The Crunge", "3:18"), ("Achilles Last Stand", "10:26"),
    ("Black Dog", "4:55")
]
find_pair(song_times_1) => ["Rock and Roll", "Hot Dog"] (3:41 + 3:19 = 7:00)

Additional Input:
song_times_2 = [
    ("Stairway to Heaven", "8:05"), ("Immigrant Song", "2:27"),
    ("Rock and Roll", "3:41"), ("Communication Breakdown", "2:29"),
    ("Good Times Bad Times", "2:48"), ("Black Dog", "4:55"),
    ("The Crunge", "3:18"), ("Achilles Last Stand", "10:26"),
    ("The Ocean", "4:31"), ("Hot Dog", "3:19"),
]
song_times_3 = [
    ("Stairway to Heaven", "8:05"), ("Immigrant Song", "2:27"),
    ("Rock and Roll", "3:41"), ("Communication Breakdown", "2:29"),
    ("Hey Hey What Can I Do", "4:00"), ("Poor Tom", "3:00"),
    ("Black Dog", "4:55")
]
song_times_4 = [
    ("Hey Hey What Can I Do", "4:00"), ("Rock and Roll", "3:41"),
    ("Communication Breakdown", "2:29"), ("Going to California", "3:30"),
    ("Black Mountain Side", "2:00"), ("Black Dog", "4:55")
]
song_times_5 = [("Celebration Day", "3:30"), ("Going to California", "3:30")]


Complexity Variable:
n = number of song/time pairs

All Test Cases - snake_case:
find_pair(song_times_1) => ["Rock and Roll", "Hot Dog"]
find_pair(song_times_2) => ["Rock and Roll", "Hot Dog"] or ["Communication Breakdown", "The Ocean"]
find_pair(song_times_3) => ["Hey Hey What Can I Do", "Poor Tom"]
find_pair(song_times_4) => []
find_pair(song_times_5) => ["Celebration Day", "Going to California"]

All Test Cases - camelCase:
findPair(songTimes1) => ["Rock and Roll", "Hot Dog"]
findPair(songTimes2) => ["Rock and Roll", "Hot Dog"] or ["Communication Breakdown", "The Ocean"]
findPair(songTimes3) => ["Hey Hey What Can I Do", "Poor Tom"]
findPair(songTimes4) => []
findPair(songTimes5) => ["Celebration Day", "Going to California"]


*/



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

pair<string, string> solve(vector<pair<string, string>> songs) {
  unordered_map<float, string> mp;
  pair<string, string> ans;
  for(pair<string, string> song: songs) { 
    //cout<<song.first<<" "<<song.second<<endl;
    float duration = stof(song.second);
    string decimal1 = song.second.substr(song.second.find(':')+1, 2);
    //cout<<decimal1;
    int decimal = stoi(decimal1);
    int value = stoi(song.second);
    //cout<<value<<" "<<(decimal)<<endl;
    double finalnum = (double)(value*100 + decimal)/100.00;
    cout<<finalnum<<endl;
    if(finalnum >= 7.00)
      continue;
      //cout<<duration<<" "<<7.00 - duration<<endl;
      cout<<song.first<<" "<<420.00 - finalnum*60<<endl;
      int diff = 7 - finalnum;
      int decimaldiff = 60 - decimal;
      
    if(mp.find((double)(diff*100 + decimaldiff)/100.00) != mp.end()) {
      //cout<<song.first<<" "<<song.second<<endl;
      ans = {song.first, mp[(diff*100 + decimaldiff)/100.00]};
      return ans;
    }
    //cout<<song.first<<" "<<finalnum<<endl;
    mp.insert({finalnum, song.first});
  }
  return ans;
  
}
int main() {
  
  const vector<pair<string, string>> songTimes1 = {
    {"Stairway to Heaven", "8:05"}, {"Immigrant Song", "2:27"},
    {"Rock and Roll", "3:41"}, {"Communication Breakdown", "2:29"},
    {"Good Times Bad Times", "2:48"}, {"Hot Dog", "3:19"},
    {"The Crunge", "3:18"}, {"Achilles Last Stand", "10:26"},
    {"Black Dog", "4:55"}
  };
  const vector<pair<string, string>> songTimes2 = {
    {"Stairway to Heaven", "8:05"}, {"Immigrant Song", "2:27"},
    {"Rock and Roll", "3:41"}, {"Communication Breakdown", "2:29"},
    {"Good Times Bad Times", "2:48"}, {"Black Dog", "4:55"},
    {"The Crunge", "3:18"}, {"Achilles Last Stand", "10:26"},
    {"The Ocean", "4:31"}, {"Hot Dog", "3:19"}
  };
  const vector<pair<string, string>> songTimes3 = {
    {"Stairway to Heaven", "8:05"}, {"Immigrant Song", "2:27"},
    {"Rock and Roll", "3:41"}, {"Communication Breakdown", "2:29"},
    {"Hey Hey What Can I Do", "4:00"}, {"Poor Tom", "3:00"},
    {"Black Dog", "4:55"}
  };
  const vector<pair<string, string>> songTimes4 = {
    {"Hey Hey What Can I Do", "4:00"}, {"Rock and Roll", "3:41"}, 
    {"Communication Breakdown", "2:29"}, {"Going to California", "3:30"}, 
    {"Black Mountain Side", "2:00"}, {"Black Dog", "4:55"}
  };  
  const vector<pair<string, string>> songTimes5 = {{"Celebration Day", "3:30"}, {"Going to California", "3:30"}};
  pair<string, string> ansPair = solve(songTimes1);
  
  cout<<ansPair.first<<" "<<ansPair.second<<endl;
  pair<string, string> ansPair1 = solve(songTimes2);
  
  cout<<ansPair1.first<<" "<<ansPair1.second<<endl;
  pair<string, string> ansPair2 = solve(songTimes3);
  
  cout<<ansPair2.first<<" "<<ansPair2.second<<endl;
  pair<string, string> ansPair3 = solve(songTimes4);
  
  cout<<ansPair3.first<<" "<<ansPair3.second<<endl;
  pair<string, string> ansPair4 = solve(songTimes5);
  
  cout<<ansPair4.first<<" "<<ansPair4.second<<endl;
  
  return 0;
}

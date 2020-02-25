#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(int argc, char **argv){
  ifstream infs;
  ofstream outfs;
  string fName = argv[1];
  int answer = 0;
  string strAnswer = "";

  string line = "";
  int lengthLine = 0;
  int sum = 0;
  int numLines = 0;
  double mean = 0;
  double variance = 0;
  double topVar;
  double totalTopVar;
  double stddev = 0;

  int a = 0;
  int c = 0;
  int t = 0;
  int g = 0;

  double probA = 0;
  double probC = 0;
  double probT = 0;
  double probG = 0;
  int totalLetters = 0;

  double aa = 0;
  double ac = 0;
  double at = 0;
  double ag = 0;
  double ca = 0;
  double cc = 0;
  double ct = 0;
  double cg = 0;
  double ta = 0;
  double tc = 0;
  double tt = 0;
  double tg = 0;
  double ga = 0;
  double gc = 0;
  double gt = 0;
  double gg = 0;

  double aaProb = 0;
  double acProb = 0;
  double atProb = 0;
  double agProb = 0;
  double caProb = 0;
  double ccProb = 0;
  double ctProb = 0;
  double cgProb = 0;
  double taProb = 0;
  double tcProb = 0;
  double ttProb = 0;
  double tgProb = 0;
  double gaProb = 0;
  double gcProb = 0;
  double gtProb = 0;
  double ggProb = 0;


  //outputting to a new file
  outfs.open("andyAnguiano.out");

  outfs << "Andy Anguiano" << endl;
  outfs << "2316199" << endl;
  outfs << "aanguiano@chapman.edu" << endl;
  outfs << endl;
  outfs << endl;

  while(answer == 0){
    //opens file and reads argument
    infs.open(fName);
    cout << "1";

    //error checking
    if(!infs.is_open()){
      cout << "Could not open file" << endl;
      return 1;
    }

    //while loop calculating mean
    while(getline(infs, line)){
      cout << "2";
      // for loop iterating through char in line
      for(int i = 0; i < line.size(); ++i){
        sum += 1;
        totalLetters += 1;
        cout << "3";

        if(tolower(line.at(i)) == 'a'){
          cout << "4";
          a += 1;
        }else if(tolower(line.at(i)) == 'g'){
          c += 1;
        }else if(tolower(line.at(i)) == 'g'){
          g += 1;
        }else if(tolower(line.at(i)) == 't'){
          t += 1;
        }
      }

      for(int i = 0; i < line.size(); i+=2){
        cout << "5";
        if(tolower(line.at(i)) == 'a' && tolower(line.at(i+1)) == 'a'){
          aa += 1;
        }else if(tolower(line.at(i)) == 'a' && tolower(line.at(i+1)) == 'c'){
          ac += 1;
        }else if(tolower(line.at(i)) == 'a' && tolower(line.at(i+1)) == 't'){
          at += 1;
        }else if(tolower(line.at(i)) == 'a' && tolower(line.at(i+1)) == 'g'){
          ag += 1;
        }else if(tolower(line.at(i)) == 'c' && tolower(line.at(i+1)) == 'a'){
          ca += 1;
        }else if(tolower(line.at(i)) == 'c' && tolower(line.at(i+1)) == 'c'){
          cc += 1;
        }else if(tolower(line.at(i)) == 'c' && tolower(line.at(i+1)) == 't'){
          ct += 1;
        }else if(tolower(line.at(i)) == 'c' && tolower(line.at(i+1)) == 'g'){
          cg += 1;
        }else if(tolower(line.at(i)) == 'g' && tolower(line.at(i+1)) == 'a'){
          ga += 1;
        }else if(tolower(line.at(i)) == 'g' && tolower(line.at(i+1)) == 'c'){
          gc += 1;
        }else if(tolower(line.at(i)) == 'g' && tolower(line.at(i+1)) == 't'){
          gt += 1;
        }else if(tolower(line.at(i)) == 'g' && tolower(line.at(i+1)) == 'g'){
          gg += 1;
        }else if(tolower(line.at(i)) == 't' && tolower(line.at(i+1)) == 'a'){
          ta += 1;
        }else if(tolower(line.at(i)) == 't' && tolower(line.at(i+1)) == 'c'){
          tc += 1;
        }else if(tolower(line.at(i)) == 't' && tolower(line.at(i+1)) == 't'){
          tt += 1;
        }else if(tolower(line.at(i)) == 't' && tolower(line.at(i+1)) == 'g'){
          tg += 1;
        }
      }


      cout << "6";
      numLines += 1;
      mean = sum/numLines;
      //calculating variance and stadard deviation
      topVar = pow(sum - mean, 2);
      totalTopVar += topVar;
    }
    cout << "7";
    variance = totalTopVar/(numLines - 1);
    stddev = sqrt(variance);
    infs.close();

    cout << "Would you like to process another file? (yes/no)" << endl;
    cin >> strAnswer;
    if(strAnswer == "yes"){
      cout << "What is the file name?" << endl;
      cin >> fName;
      continue;
    }else if(strAnswer == "no"){
      cout << "Exiting...";
      answer = 1;
    }else{
      cout << "That was not an option";
      break;
    }
  }


    probA = a/totalLetters;
    probC = c/totalLetters;
    probG = g/totalLetters;
    probT = t/totalLetters;
    aaProb = aa/totalLetters;
    acProb = ac/totalLetters;
    atProb = at/totalLetters;
    agProb = ag/totalLetters;
    caProb = ca/totalLetters;
    ccProb = cc/totalLetters;
    ctProb = ct/totalLetters;
    cgProb = cg/totalLetters;
    gaProb = ga/totalLetters;
    gcProb = gc/totalLetters;
    ggProb = gg/totalLetters;
    gtProb = gt/totalLetters;
    taProb = ta/totalLetters;
    tcProb = tc/totalLetters;
    tgProb = tg/totalLetters;
    ttProb = tt/totalLetters;


    outfs << "Sum of lines: " << numLines << endl;
    outfs << "Mean of line length: " << mean << endl;
    outfs << "Variance of line length: " << variance;
    outfs << "Standard Deviation of line length: " << stddev << endl;

    outfs << endl;

    outfs << "The probabilites of the following items:" << endl;
    outfs << "A: " << probA << endl;
    outfs << "C: " << probC << endl;
    outfs << "T: " << probT << endl;
    outfs << "G: " << probG << endl;
    outfs << "AA: " << aaProb << endl;
    outfs << "AC: " << acProb << endl;
    outfs << "AT: " << atProb << endl;
    outfs << "AG: " << agProb << endl;
    outfs << "CA: " << caProb << endl;
    outfs << "CC: " << ccProb << endl;
    outfs << "CT: " << ctProb << endl;
    outfs << "CG: " << cgProb << endl;
    outfs << "GA: " << gaProb << endl;
    outfs << "GC: " << gcProb << endl;
    outfs << "GT: " << gtProb << endl;
    outfs << "GG: " << ggProb << endl;
    outfs << "TA: " << taProb << endl;
    outfs << "TC: " << tcProb << endl;
    outfs << "TT: " << ttProb << endl;
    outfs << "TG: " << tgProb << endl;


  //closes the file
  outfs.close();



  return 0;
}

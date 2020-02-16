#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(int argc, char **charv){
  ifstream infs;
  ofstream outfs;

  //opens file and reads argument
  infs.open(charv[0]);
  //error checking
  if(!infs.is_open()){
    cout << "Could not open file" << endl;
    return 1;
  }

  string line = "";
  int lengthLine = 0;
  int sum = 0;
  int numLines = 0;
  double mean = 0;
  int variance = 0;
  double topVar;
  int totalTopVar;
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
  doubel ga = 0;
  double gc = 0;
  double gt = 0;
  double gg = 0;



  //while loop calculating mean
  while(getline(infs, line) != ""){
    // for loop iterating through char in line
    for(int i = 0; i < line.length(); ++i){
      sum += 1;
    }
    numLine += 1;
    mean = sum/numLines;
  }

  //compute standard dev and variance
  while(getline(infs, line) != ""){
    // for loop getting length of line
    for(int i = 0; i < line.length(); ++i){
        sum += 1;
    }
    //calculating variance and stadard deviation
    topVar = pow(sum - mean, 2);
    totalTopVar += topVar;
  }
  varience = totalTopVar/(numLines - 1);
  stddev = sqrt(variance);



  //while loop calculating probability
  while(getline(infs, line) != ""){
    //converts all to lowercase
    line.tolower();
    // for loop iterating through char in line
    for(int i = 0; i < line.length(); ++i){
      totalLetters += 1;

      if(line[i] = "a"){
        a += 1;
        //what if it is 0

        if(line[i-1] = "a"){
          aa += 1;
        }else if(line[i-1] = "c"){
          ac += 1;
        }else if(line[i-1] = "t"){
          at += 1;
        }else if(line[i-1] = "g"){
          ag += 1;
        }
      }else if(line[i] = "c"){
        c += 1;
        if(line[i-1] = "a"){
          ca += 1;
        }else if(line[i-1] = "c"){
          cc += 1;
        }else if(line[i-1] = "t"){
          ct += 1;
        }else if(line[i-1] = "g"){
          cg += 1;
        }
      }else if(line[i] = "g"){
        g += 1;
        if(line[i-1] = "a"){
          ga += 1;
        }else if(line[i-1] = "c"){
          gc += 1;
        }else if(line[i-1] = "t"){
          gt += 1;
        }else if(line[i-1] = "g"){
          gg += 1;
        }
      }else if(line[i] = "t"){
        t += 1;
        if(line[i-1] = "a"){
          ta += 1;
        }else if(line[i-1] = "c"){
          tc += 1;
        }else if(line[i-1] = "t"){
          tt += 1;
        }else if(line[i-1] = "g"){
          tg += 1;
        }
      }
    }
  }
  probA = a/totalLetters;
  probC = c/totalLetters;
  probG = g/totalLetters;
  probT = t/totalLetters;
  aa = aa/totalLetters;
  ac = ac/totalLetters;
  at = at/totalLetters;
  ag = ag/totalLetters;
  ca = ca/totalLetters;
  cc = cc/totalLetters;
  ct = ct/totalLetters;
  cg = cg/totalLetters;
  ga = ga/totalLetters;
  gc = gc/totalLetters;
  gg = gg/totalLetters;
  gt = gt/totalLetters;
  ta = ta/totalLetters;
  tc = tc/totalLetters;
  tg = tg/totalLetters;
  tt = tt/totalLetters;


  //outputting to a new file
  outfs.open(andyAnguiano.out);

  outfs << "Andy Anguiano" << endl;
  outfs << "2316199" << endl;
  outfs << endl;
  outfs << endl;

  outfs << "Mean of line length: " << mean << endl;
  outfs << "Variance of line length: " << variance;
  outfs << "Standard Deviation of line length: " << stddev << endl;

  outfs << endl;

  outfs << "The probabilites of the following items:" << endl;
  outfs << "A: " << probA << endl;
  outfs << "C: " << probC << endl;
  outfs << "T: " << progT << endl;
  outfs << "G: " << probG << endl;
  outfs << "AA: " << aa << endl;
  outfs << "AC: " << ac << endl;
  outfs << "AT: " << at << endl;
  outfs << "AG: " << ag << endl;
  outfs << "CA: " << ca << endl;
  outfs << "CC: " << cc << endl;
  outfs << "CT: " << ct << endl;
  outfs << "CG: " << cg << endl;
  outfs << "GA: " << ga << endl;
  outfs << "GC: " << gc << endl;
  outfs << "GT: " << gt << endl;
  outfs << "GG: " << gg << endl;
  outfs << "TA: " << ta << endl;
  outfs << "TC: " << tc << endl;
  outfs << "TT: " << tt << endl;
  outfs << "TG: " << tg << endl;


  //closes the file
  infs.close();
  outfs.close();



  return 0;
}

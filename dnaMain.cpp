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
  double lengthLine = 0;
  double numLines = 0;
  double mean = 0.0;
  double variance = 0;
  double topVar;
  double totalTopVar;
  double stddev = 0;

  double a = 0;
  double c = 0;
  double t = 0;
  double g = 0;

  double probA = 0;
  double probC = 0;
  double probT = 0;
  double probG = 0;
  double totalLetters = 0;
  double bigramTotalLetters = 0;

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

//while user is not parsing another file
  while(answer == 0){
    //opens file and reads argument
    infs.open(fName);

    //error checking
    if(!infs.is_open()){
      cout << "Could not open file" << endl;
      return 1;
    }

    //while loop calculating mean and totals
    while(getline(infs, line)){
      //total letters
      totalLetters += line.size();
      //number of lines
      numLines += 1;
      // for loop iterating through char in line
      for(int i = 0; i < line.size(); ++i){
        //counts evertime an instance of a, c, g, t come up
        if(tolower(line.at(i)) == 'a'){
          a += 1;
        }else if(tolower(line.at(i)) == 'c'){
          c += 1;
        }else if(tolower(line.at(i)) == 'g'){
          g += 1;
        }else if(tolower(line.at(i)) == 't'){
          t += 1;
        }
      }
      // iterates over every 2 nucleotides to see whether nucleotide bigrams are formed
      for(int i = 0; i < line.size(); i+=2){
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
      //calculates mean
      mean = totalLetters/numLines;
    }
    //closes file
    infs.close();

    //calculating standard deviation and variance now that mean is set
    infs.open(fName);
    while(getline(infs, line)){
      int lineSum = line.size();
      //calculating variance and stadard deviation
      topVar = pow(lineSum - mean, 2);
      totalTopVar += topVar;
    }
    variance = totalTopVar/(numLines - 1);
    stddev = sqrt(variance);
    //closes file
    infs.close();

    //calculates probabilites
    probA = a/totalLetters;
    probC = c/totalLetters;
    probG = g/totalLetters;
    probT = t/totalLetters;

    //change totalLetters since every two nucleotides were looked over
    bigramTotalLetters = totalLetters / 2;
    aaProb = aa/bigramTotalLetters;
    acProb = ac/bigramTotalLetters;
    atProb = at/bigramTotalLetters;
    agProb = ag/bigramTotalLetters;
    caProb = ca/bigramTotalLetters;
    ccProb = cc/bigramTotalLetters;
    ctProb = ct/bigramTotalLetters;
    cgProb = cg/bigramTotalLetters;
    gaProb = ga/bigramTotalLetters;
    gcProb = gc/bigramTotalLetters;
    ggProb = gg/bigramTotalLetters;
    gtProb = gt/bigramTotalLetters;
    taProb = ta/bigramTotalLetters;
    tcProb = tc/bigramTotalLetters;
    tgProb = tg/bigramTotalLetters;
    ttProb = tt/bigramTotalLetters;

    // begins outputting results to new file
    outfs << "Sum of the length of the DNA strings: " << totalLetters << endl;
    outfs << "Mean of line length: " << mean << endl;
    outfs << "Variance of line length: " << variance << endl;
    outfs << "Standard Deviation of line length: " << stddev << endl;

    outfs << endl;

    outfs << "The relative probabilities of each nucleotide and nucleotide bigram:" << endl;
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
    outfs << endl;

    //Gaussian Distribution
    //for loop for 100 lines
    string dnaOutput = "";
    for(int i = 0; i < 1000; ++i){
      //creates random numbers
      double rand1 = (rand()) / (double)(RAND_MAX);
      double rand2 = (rand()) / (double)(RAND_MAX);
      //begins calculations
      double isC = (sqrt(-2 * log(rand1)) * (cos(2 * M_PI * rand2)));
      double isD = stddev * isC + mean;
      isD = round(isD);
      //writing each nucleotide line
      for(int j = 0; j < isD; ++j){
        double rand3 = (rand()) / (double)(RAND_MAX);
        if(rand3 <= probA){
          dnaOutput += "a";
        }else if(rand3 <= probA + probC){
          dnaOutput += "c";
        }else if(rand3 <= probA + probC + probG){
          dnaOutput += "g";
        }else if(rand3 <= probA + probC + probG + probT){
          dnaOutput += "t";
        }
      }
      //outputs each line to new file
      outfs << dnaOutput << endl;
      //resets string to begin new line
      dnaOutput = "";
    }

    //checks to see if user would like to parse another file
    cout << "Would you like to process another file? (yes/no)" << endl;
    cin >> strAnswer;
    if(strAnswer == "yes"){
      cout << "What is the file name?" << endl;
      cin >> fName;
      continue;
    }else if(strAnswer == "no"){
      cout << "Exiting..." << endl;
      //closes file and exits while loop
      outfs.close();
      answer = 1;
    }else{
      cout << "That was not an option";
      break;
    }
  }

  return 0;
}

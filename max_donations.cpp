#include <iostream>
#include <sstream>
#include <fstream>
using std::cin, std::cout, std::endl, std::string, std::getline,
    std::ifstream, std::istringstream;

int main()
{
  string filename;
  cout << "Enter donation filename: ";
  cin >> filename;
  ifstream ifs(filename);
  if (!ifs.is_open())
  {
    cout << "Failed to open file " << filename << "." << endl;
    return 1;
  }

  double maxTotalDonation = 0;
  int maxTotalCollector = 0;
  int donationCount;
  // read data
  string line;
  // read the lines from the file
  while (getline(ifs, line))
  {
    double donation = 0;
    donationCount = 0;
    int uin;
    string tmp;
    // breaking line into words using string stream
    istringstream ss(line);
    // read collector
    ss >> uin;
    // calculate total donation
    while (ss >> tmp)
    {
      // convert from string to float
      donation += stod(tmp);
      donationCount++;
    }
    // check if donation is greater than maxTotalDonation
    if (maxTotalDonation < donation && donationCount > 1)
    {
      maxTotalDonation = donation;
      maxTotalCollector = uin;
    }
  }

  if(donationCount > 1){
    cout << "Highest donation total: " << maxTotalDonation << endl;
    cout << "-- collected by id: " << maxTotalCollector << endl;
  }
  else
    cout << "No donations." << endl;

  
}

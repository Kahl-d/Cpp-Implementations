#include <iostream>
#include <random>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <utility>


std::vector <std::pair<double, int>> generateNormalDistributionRandomNumbers();
std::vector <std::pair<double, int>> generateUniformDistributionRandomNumbers();
std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> classifyStudents(const std::vector<std::tuple<std::string,int,int>> &students, int groupSize, int numSections);
std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> groupingStudents(std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> &groups, int groupSize);
void printClass(const std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> &objectGroups);
double roundToTwo(double num);
void makeHistogram(std::vector <std::pair<double, int>> &points);



int main(){

    std::cout << "CSC 340 Small Group Project | Group 2" << std::endl;
    int userInput{1};

    while(userInput){

        std::cout<< "1) Generate a histogram of randomly generated floating-point numbers according to a normal distribution with a user-specified mean and standard deviation." <<std::endl;
        std::cout<< "2) Generate a histogram of randomly generated floating-point numbers according to a uniform distribution with a user-specified minimum and maximum." <<std::endl;
        std::cout<< "3) There are x learners who haven't found a small group yet. Please design and implement an algorithm to randomly assign them to an existing group or a newly created group if all existing groups are full. Constraints: (1) Each group will be limited to 3 members; and (2) students in the same group must be enrolled in the same section." <<std::endl;

        std::cout<< "0) Exit" <<std::endl;

        std::cout<< "Please enter a number: ";
        std::cin >> userInput;

        switch (userInput) {

            case 1:{
                std::cout << "You chose Q1" << std::endl;
                auto points = generateNormalDistributionRandomNumbers();
                makeHistogram(points);
                std::cout<<std::endl;
                std::cout<<std::endl;

                break;
            }
            case 2:{
                std::cout << "You chose 2" << std::endl;
                auto points = generateUniformDistributionRandomNumbers();
                makeHistogram(points);
                std::cout<<std::endl;
                std::cout<<std::endl;
                break;
            }
            case 3:{
                std::cout << "You chose 3" << std::endl;
//                std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> objectGroups;
                std::vector<std::tuple<std::string,int,int>> classOfStudents{
                        {"Khalid", 1, 1},
                        {"Jaylene", 1, 1},
                        {"Diya", 1, 1},
                        {"Hilary", 1, 2},
                        {"Khaliesi", 1, 2},
                        {"Dat", 1, 3},
                        {"Sam", 1, 4},
                        {"Elena", 1, 4},
                        {"Miguel", 1, 4},
                        {"Leo", 1, 5},
                        {"Zack", 1, 5},
                        {"Rene", 2, 1},
                        {"Emma", 2, 1},
                        {"Oliver", 2, 1},
                        {"Liam", 2, 2},
                        {"Ava", 2, 2},
                        {"Benjamin", 2, 3},
                        {"Charlotte", 2, 4},
                        {"Amelia", 2, 4},
                        {"Elijah", 2, 5},
                        {"Harper", 2, 5},
                        {"James", 2, 5},
                        {"Sara", 1, 2},
                        {"Lucas", 1, 0},
                        {"Marie", 1, 0},
                        {"Mia", 1, 0},
                        {"Sophia", 2, 3},
                        {"Noah", 2, 0},
                        {"Isabella", 2, 0},
                        {"William", 2, 0},
                        {"Alice",1,0},
                        {"Bob",1,0},
                        {"Charlie",1,0},
                        {"Daisy",1,0},
                        {"Edward",1,0},
                        {"Fiona",2,0},
                        {"George",2,0},
                        {"Hannah",2,0}
                };

                int max_width = 0;
                for (const auto& student : classOfStudents) {
                    int name_length = std::get<0>(student).length();
                    max_width = std::max(max_width, name_length);
                }
                std::cout<< "Group number 0 means student is not in any group yet." << std::endl;
                std::cout<< std::left << std::setw(max_width + 2) << "Student" << "  " << "Sec" << "  " << "Group" << std::endl;

                // Print the classOfStudents in a tabulated format
                for (const auto& student : classOfStudents) {
                    std::cout << std::left << std::setw(max_width + 2) << std::get<0>(student) << "  "
                              << std::get<1>(student) << "      "
                              << std::get<2>(student) << std::endl;
                }

                std::cout<<"Enter number of Sections: "<<std::endl;
                int numSections;
                std::cin>>numSections;
                std::cout<<"Enter number of members per group: "<<std::endl;
                int numMembers;
                std::cin>>numMembers;

                auto objectGroups = classifyStudents(classOfStudents, numMembers, numSections);

                printClass(objectGroups);

                objectGroups = groupingStudents(objectGroups, numMembers);
                printClass(objectGroups);

                break;
            }
            case 0:{
                std::cout << "Exiting..." << std::endl;
                break;
            }
        }

    }

    return 0;


}

double roundToTwo(double num)
{
    return round(num*10)/10;
}

std::vector <std::pair<double, int>> generateNormalDistributionRandomNumbers()
{
    std::vector <std::pair<double, int>> points;
    std::cout<< "Enter Mean" << std::endl;
    double mean;
    std::cin >> mean;
    std::cout<< "Enter Standard Deviation (Standard deviation should be greater than or equal to 1)" << std::endl;
    double standardDeviation;
    std::cin >> standardDeviation;
    std::cout<< "Enter Number of Samples" << std::endl;
    int numSamples;
    std::cin >> numSamples;
    std::cout<<"Enter Number of Bins" << std::endl;
    int numBins;
    std::cin >> numBins;

    //Preparing the vector for bins according to user specified bins, mean and standard deviation

    int startingPoint{0};
    int endingPoint{0};
    if(numBins%2 == 0)
    {
        startingPoint = -1*(numBins/2) + 1;
        endingPoint = startingPoint + numBins-1;
    }
    else
    {
        startingPoint = -1*((numBins-1)/2);
        endingPoint = startingPoint + numBins -1;
    }

    for(int i = startingPoint; i<=endingPoint;i++)
    {
        points.push_back(std::make_pair(round(mean+(i*standardDeviation)),0));
    }

    std::random_device rd{};
    std::mt19937 gen{rd()};

    std::normal_distribution d{mean, standardDeviation};
    int currRandom{0};
    for(int n = 0; n < numSamples; ++n) {

        currRandom = round(d(gen));
        auto p = std::find_if(points.begin(), points.end(), [currRandom](std::pair<double,int> a){return a.first == currRandom;});
        p->second++;
    }

    for(auto a : points)
    {
        std::cout << a.first << "  " << a.second<<std::endl;
    }


    return points;

}

std::vector <std::pair<double, int>> generateUniformDistributionRandomNumbers()
{
    std::cout<<"Enter range of numbers: "<<std::endl;
    double  a, b;
    std::cin>>a>>b;
    std::cout<< "Enter Number of Samples" << std::endl;
    int samples;
    std::cin >> samples;
    std::cout<<"Enter Number of Bins" << std::endl;
    int bins;
    std::cin >> bins;

    std::vector <std::pair<double, int>> points;

    double binCenter = (b-a)*1.0/(bins-1);

    for(int i = 0; i < bins; i++)
    {
        points.push_back(std::make_pair(roundToTwo(a+ i*binCenter) , 0));
    }

    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(a, b);
    double currRandom{0};
    for (int n = 0; n < samples; ++n) {

        currRandom = roundToTwo(dis(gen));
        auto p = std::find_if(points.begin(), points.end(),[currRandom](std::pair<double, int> a) { return a.first == currRandom; });
        p->second++;
    }

    return points;

}

void makeHistogram(std::vector <std::pair<double, int>> &points)
{

    int maxBarLength{0};
    for(auto a : points)
    {
        if(a.second > maxBarLength)
        {
            maxBarLength = a.second;
        }
    }

    int unitLength = maxBarLength/5;

    for(auto &a : points)
    {
        a.second = a.second/unitLength;
    }

    for(int i = unitLength; i >=0; i--)
    {
        for(auto a : points)
        {
            if(a.second >= i)
            {
                std::cout << std::setw(8) << "*" ;
            }
            else
            {
                std::cout <<std::setw(8)<< " ";
            }
        }
        std::cout << std::endl;
    }

    for(auto a : points)
    {
        std::cout << std::setw(8) << a.first;
    }


}

std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> classifyStudents(const std::vector<std::tuple<std::string,int,int>> &students, int groupSize = 3, int numSections = 2){

    std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> tempGroups(numSections);
    for(auto &a : tempGroups){
        a.resize(10);
    }

    for(auto a : students){
        int temp1 = std::get<1>(a);
        int temp2 = std::get<2>(a);
        tempGroups[temp1-1][temp2].push_back(a);
    }

    for(auto &a : tempGroups){
        while(a.at(a.size()-1).size() ==0){
            a.pop_back();
        }
    }


    return tempGroups;

}

std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> groupingStudents(std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> &groups, int groupSize = 3)
{


    for(auto &a : groups){


        int x = a.at(0).size();
        std::vector<std::pair<int,int>> freeGroups;
        int freeSpaces{0};

        for(int i = 1; i < a.size(); i++){
            if(groupSize - a.at(i).size() > 0){
                freeGroups.push_back({i, groupSize - a.at(i).size()});
                freeSpaces += groupSize - a.at(i).size();
            }
        }

        if(freeSpaces >=x ){
            std::cout<<"There are enough free spaces to accomodate all students"<<std::endl;
            while(freeSpaces > 0 && !a.at(0).empty()){
                std::tuple<std::string,int, int> temp = a.at(0).back(); // Access the last element directly with back()
                int temp1 = rand() % freeGroups.size();
                a.at(freeGroups.at(temp1).first).push_back(temp);
                a.at(0).pop_back();
                freeGroups.at(temp1).second--;
                if(freeGroups.at(temp1).second == 0){
                    freeGroups.erase(freeGroups.begin() + temp1);
                }
                freeSpaces--;
                x--;
            }
        }
        else{
            if(x%groupSize < freeSpaces)
            {
                int y  = x%groupSize;
                for(int i =0; i < y; i++){
                    std::tuple<std::string,int, int> temp = a.at(0).back(); // Access the last element directly with back()
                    int temp1 = rand() % freeGroups.size();
                    a.at(freeGroups.at(temp1).first).push_back(temp);
                    a.at(0).pop_back();
                    freeGroups.at(temp1).second--;
                    if(freeGroups.at(temp1).second == 0){
                        freeGroups.erase(freeGroups.begin() + temp1);
                    }
                    freeSpaces--;
                    x--;
                }

                while(!a.at(0).empty()){
                    int  temp1 = rand() % a.at(0).size();
                    std::tuple<std::string,int, int> tempS1 = a.at(0).at(temp1);
                    a.at(0).erase(a.at(0).begin() + temp1);
                    int  temp2 = rand() % a.at(0).size();
                    std::tuple<std::string,int, int> tempS2 = a.at(0).at(temp2);
                    a.at(0).erase(a.at(0).begin() + temp2);
                    int  temp3 = rand() % a.at(0).size();
                    std::tuple<std::string,int, int> tempS3 = a.at(0).at(temp3);
                    a.at(0).erase(a.at(0).begin() + temp3);

                    a.push_back({tempS1, tempS2, tempS3});




                }




            }
        }


    }


    return groups;

}
void printClass(const std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> &objectGroups)
{
    int max_width = 0;
    for (const auto& section : objectGroups) {
        for (const auto& group : section) {
            for (const auto& student : group) {
                int name_length = std::get<0>(student).length();
                max_width = std::max(max_width, name_length);
            }
        }
    }

    // Print the classOfStudents in a tabulated format
    for (int section = 0; section < objectGroups.size(); section++) {
        std::cout << "Section " << section + 1 << std::endl;
        for (int group = 0; group < objectGroups[section].size(); group++) {
            std::cout << "Group " << group  << std::endl;
            for (const auto& student : objectGroups[section][group]) {
                std::cout << std::left << std::setw(max_width + 2) << std::get<0>(student);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
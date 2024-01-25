#include <iostream>
#include <random>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <utility>

// Function declarations
std::vector <std::pair<double, int>> generateNormalDistributionRandomNumbers();
std::vector <std::pair<double, int>> generateUniformDistributionRandomNumbers();
std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> classifyStudents(const std::vector<std::tuple<std::string,int,int>> &students, int groupSize, int numSections);
std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> groupingStudents(std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> &groups, int groupSize);
void printClass(const std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> &objectGroups);
double roundToTwo(double num);
void makeHistogram(std::vector <std::pair<double, int>> &points);

// Unit test declarations
void testGenerateNormalDistributionRandomNumbers();
void testGenerateUniformDistributionRandomNumbers();
void testStudentGrouping();



int main(){
    // Initial menu display
    std::cout << "CSC 340 Small Group Project | Group 2" << std::endl;
    int keepRunning{true};
    int userInput{0};
    // Main application loop
    while(keepRunning) {
        // Displaying the user options menu
        std::cout<< "1) Generate a histogram of randomly generated floating-point numbers according to a normal distribution with a user-specified mean and standard deviation." <<std::endl;
        std::cout<< "2) Generate a histogram of randomly generated floating-point numbers according to a uniform distribution with a user-specified minimum and maximum." <<std::endl;
        std::cout<< "3) There are x learners who haven't found a small group yet. Please design and implement an algorithm to randomly assign them to an existing group or a newly created group if all existing groups are full. Constraints: (1) Each group will be limited to 3 members; and (2) students in the same group must be enrolled in the same section." <<std::endl;

        std::cout<< "0) Exit" <<std::endl;

        std::cout<< "Please enter a number: ";
        std::cin >> userInput;


        // Switch-case to handle user input
        switch (userInput) {

            case 1:{
                // Generating a histogram for a normal distribution
                std::cout << "You chose Q1" << std::endl;
                auto points = generateNormalDistributionRandomNumbers();
                makeHistogram(points);
                std::cout<<std::endl;
                std::cout<<std::endl;

                break;
            }
            case 2:{
                // Generating a histogram for a uniform distribution
                std::cout << "You chose 2" << std::endl;
                auto points = generateUniformDistributionRandomNumbers();
                makeHistogram(points);
                std::cout<<std::endl;
                std::cout<<std::endl;
                break;
            }
            case 3:{
                // Assigning students to groups
                std::cout << "You chose 3" << std::endl;

                // Sample student data with name, section, and group info
                // Note: A group number of '0' indicates no group assignment
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

                // Calculate maximum name length for formatting
                int max_width = 0;
                for (const auto& student : classOfStudents) {
                    int nameLength = std::get<0>(student).length();
                    max_width = std::max(max_width, nameLength);
                }


                std::cout<< "Group number 0 means student is not in any group yet." << std::endl;
                std::cout<< std::left << std::setw(max_width + 2) << "Student" << "  " << "Sec" << "  " << "Group" << std::endl;

                // Print the classOfStudents in a tabulated format
                for (const auto& student : classOfStudents) {
                    std::cout << std::left << std::setw(max_width + 2) << std::get<0>(student) << "  "
                              << std::get<1>(student) << "      "
                              << std::get<2>(student) << std::endl;
                }

                // Take user input for number of sections and group members
                std::cout<<"Enter number of Sections: "<<std::endl;
                int numSections;
                std::cin>>numSections;
                std::cout<<"Enter number of members per group: "<<std::endl;
                int numMembers;
                std::cin>>numMembers;

                // Classify students into sections and groups
                auto objectGroups = classifyStudents(classOfStudents, numMembers, numSections);
                std::cout<<"Initial grouping of students: "<<std::endl;
                printClass(objectGroups);

                // Further group students
                objectGroups = groupingStudents(objectGroups, numMembers);
                std::cout<<"Final grouping of students: "<<std::endl;
                printClass(objectGroups);

                break;
            }
            case 0:{
                // Exit the program
                keepRunning = false;
                std::cout << "Exiting..." << std::endl;
                break;
            }

            default:{
                // Invalid input
                keepRunning = false;
                userInput = 0;
                break;
            }
        }

    }

    testGenerateNormalDistributionRandomNumbers();
    testGenerateUniformDistributionRandomNumbers();
    testStudentGrouping();

    return 0;


}

// Function to round a number to two decimal places
double roundToTwo(double num)
{
    return round(num*10)/10;
}


// Function to generate random numbers following a normal distribution.
// This function prompts the user for necessary parameters like mean, standard deviation,
// number of samples, and number of bins. It then generates random numbers based on the
// given parameters, categorizing them into specified bins.
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

    //Generating random numbers and categorizing them into bins

    std::random_device rd{};
    std::mt19937 gen{rd()};

    std::normal_distribution d{mean, standardDeviation};
    int currRandom{0};
    for(int n = 0; n < numSamples; ++n) {

        currRandom = round(d(gen));
        auto p = std::find_if(points.begin(), points.end(), [currRandom](std::pair<double,int> a){return a.first == currRandom;});
        p->second++;
    }

    //Returning the vector of bins
    return points;

}

// Function to generate random numbers following a uniform distribution.
// This function prompts the user for necessary parameters like minimum, maximum,
// number of samples, and number of bins. It then generates random numbers based on the
// given parameters, categorizing them into specified bins.

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

    //Preparing the vector for bins according to user specified bins and range
    std::vector <std::pair<double, int>> points;

    double binCenter = (b-a)*1.0/(bins-1);

    for(int i = 0; i < bins; i++)
    {
        points.push_back(std::make_pair(roundToTwo(a+ i*binCenter) , 0));
    }

    //Generating random numbers and categorizing them into bins
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(a, b);
    double currRandom{0};
    for (int n = 0; n < samples; ++n) {

        currRandom = roundToTwo(dis(gen));
        auto p = std::find_if(points.begin(), points.end(),[currRandom](std::pair<double, int> a) { return a.first == currRandom; });
        p->second++;
    }

    //Returning the vector of bins
    return points;

}

// Function to generate a histogram from a vector of bins
// This function takes a vector of bins as input and prints a histogram
// based on the number of samples in each bin, the functions scales the histogram to fit the screen
// and print the histogram upright

void makeHistogram(std::vector <std::pair<double, int>> &points)
{
        //Scaling the histogram to fit the screen
       int maxBarLength{0};
       for(auto a : points)
       {
           if(a.second > maxBarLength)
           {
               maxBarLength = a.second;
           }
       }


       int unitLength = maxBarLength/8;

         for(auto &a : points)
         {
              a.second = a.second/unitLength;
         }

         //Printing the histogram

    for(int i = 8; i >=0; i--)
    {
        for(auto a : points)
        {
            if(a.second > i)
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

    //Printing the x-axis

    for(auto a : points)
    {
        std::cout << std::setw(8) << a.first;
    }


}

// Function to classify students into sections and groups
std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> classifyStudents(const std::vector<std::tuple<std::string,int,int>> &students, int groupSize = 3, int numSections = 2){

    std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> tempGroups(numSections);
    for(auto &a : tempGroups){
        a.resize(10);
    }
    //Checking each student and assigning them to a section and group
    for(auto a : students){
        int temp1 = std::get<1>(a);
        int temp2 = std::get<2>(a);
        tempGroups[temp1-1][temp2].push_back(a);
    }

    //Removing empty groups
    for(auto &a : tempGroups){
        while(a.at(a.size()-1).size() ==0){
            a.pop_back();
        }
    }

    //returning the vector of groups
    return tempGroups;

}


// Function to further group students
// This function takes a vector of groups as input and further groups students
// based on the number of free spaces in each group

std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> groupingStudents(std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> &groups, int groupSize = 3)
{

    //Iterating through each section

    for(auto &a : groups){


        int x = a.at(0).size();                     //Number of students who are not in any group yet in the current section
        std::vector<std::pair<int,int>> freeGroups;
        int freeSpaces{0};

        for(int i = 1; i < a.size(); i++){
            if(groupSize - a.at(i).size() > 0){
                freeGroups.push_back({i, groupSize - a.at(i).size()});  //Pushing the index of the group and the number of free spaces in that group
                freeSpaces += groupSize - a.at(i).size();                       //Calculating the total number of free spaces
            }
        }

        //If there are enough free spaces to accommodate all students who are not in any group yet, then assign them to the free spaces
        if(freeSpaces >= x) {
            std::cout << "There are enough free spaces to accommodate all students" << std::endl;
            while(freeSpaces > 0 && !a.at(0).empty()) {

                //pick a random student from unassigned students of the section
                int randomStudentIndex = rand() % a.at(0).size();
                std::tuple<std::string, int, int> temp = a.at(0).at(randomStudentIndex);

                //pick a random group from the free groups
                int randomGroupIndex = rand() % freeGroups.size();
                a.at(freeGroups.at(randomGroupIndex).first).push_back(temp);

                //remove the student from unassigned students
                a.at(0).erase(a.at(0).begin() + randomStudentIndex);
                //reduce the number of free spaces in the group
                freeGroups.at(randomGroupIndex).second--;

                //if the group is full, remove it from the free groups
                if(freeGroups.at(randomGroupIndex).second == 0) {
                    freeGroups.erase(freeGroups.begin() + randomGroupIndex);
                }
                //reduce the total number of free spaces
                freeSpaces--;
                //reduce the number of students who are not in any group yet
                x--;
            }
        }
        //If there are not enough free spaces to accommodate all students who are not in any group yet, then create new groups
        else{
            //If there are no free groups, then create new groups
            while(x > freeSpaces) {
                std::vector<std::tuple<std::string, int, int>> newGroup;
                //creating groups of size groupSize of random students from unassigned students
                for(int i = 0; i < groupSize; i++) {
                    if(!a.at(0).empty()) {
                        int tempIndex = rand() % a.at(0).size();
                        std::tuple<std::string, int, int> tempStudent = a.at(0).at(tempIndex);
                        a.at(0).erase(a.at(0).begin() + tempIndex);
                        newGroup.push_back(tempStudent);
                        x--;
                    }
                }
                //adding the new group to the section
                a.push_back(newGroup);
            }

            //Assigning the remaining students to the free spaces
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



        } //else bracket


    }


    return groups;

}

// Function to print the class
void printClass(const std::vector<std::vector<std::vector<std::tuple<std::string, int , int>>>> &objectGroups)
{
    // Calculate maximum name length for formatting
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


//Unit tests for the functions
// Test for the function `generateNormalDistributionRandomNumbers`
void testGenerateNormalDistributionRandomNumbers() {
    auto points = generateNormalDistributionRandomNumbers();

    if (points.empty()) {
        std::cout << "Test for generateNormalDistributionRandomNumbers FAILED: Empty points." << std::endl;
    } else {
        std::cout << "Test for generateNormalDistributionRandomNumbers PASSED." << std::endl;
    }

    for (const auto& point : points) {
        if (point.second < 0) {
            std::cout << "Test for generateNormalDistributionRandomNumbers FAILED: Negative frequencies detected." << std::endl;
            return;
        }
    }
}

// Test for the function `generateUniformDistributionRandomNumbers
void testGenerateUniformDistributionRandomNumbers() {
    auto points = generateUniformDistributionRandomNumbers();

    if (points.empty()) {
        std::cout << "Test for generateUniformDistributionRandomNumbers FAILED: Empty points." << std::endl;
    } else {
        std::cout << "Test for generateUniformDistributionRandomNumbers PASSED." << std::endl;
    }

    for (const auto& point : points) {
        if (point.second < 0) {
            std::cout << "Test for generateUniformDistributionRandomNumbers FAILED: Negative frequencies detected." << std::endl;
            return;
        }
    }
}


// Test for the function `classifyStudents` and `groupingStudents` belonging to the grouping algorithm
void testStudentGrouping() {
    // Sample data for testing
    std::vector<std::tuple<std::string,int,int>> testStudents = {
            {"John", 1, 0},
            {"Jane", 1, 0},
            {"Doe", 1, 0},
            {"Alan", 2, 0},
            {"Amy", 2, 0},
            {"David", 2, 0},
    };

    // Given a group size of 3 and 2 sections, we process the student assignment
    auto groupedStudents = classifyStudents(testStudents, 3, 2);
    groupedStudents = groupingStudents(groupedStudents, 3);


    //Ensuring that no group exceeds its size limit.
    for (const auto &section : groupedStudents) {
        for (const auto &group : section) {
            if (group.size() > 3) {
                std::cout << "Test FAILED: Group size exceeded the limit." << std::endl;
                return;
            }
        }
    }

    //Making sure that students from different sections aren't mixed up in the same group.
    for (const auto &section : groupedStudents) {
        int sectionNum = std::get<1>(section[0][0]); // assuming at least one student in a group
        for (const auto &group : section) {
            for (const auto &student : group) {
                if (std::get<1>(student) != sectionNum) {
                    std::cout << "Test FAILED: Students from different sections are in the same group." << std::endl;
                    return;
                }
            }
        }
    }

    std::cout << "Test PASSED: Students correctly grouped." << std::endl;
}


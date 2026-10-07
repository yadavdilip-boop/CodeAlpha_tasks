#include <iostream>
using namespace std;

double getGradePoint(string grade) {

 
     if (grade == "A+") {
        return 10.0;
    }
    else if (grade == "A") {
        return 9.0;
    }
    else if (grade == "B+") {
        return 8.0;
    }
    else if (grade == "B") {
        return 7.0;
    }
    else if (grade == "C") {
        return 5.0;
    }
    else if (grade == "D") {
        return 4.0;
    }
     else if (grade == "C+") {
        return 6.0;
     }
    else if (grade == "F") {
        return 0.0;
    }
    else {
        return -1.0;
    }
}

    

int main() {
    int semesters;

    double overallGradePoints = 0;
    double overallCredits = 0;

    cout << "Enter number of semesters: ";
    cin >> semesters;

    for (int s = 1; s <= semesters; s++) {
        int courses;
        double totalCredits = 0;
        double totalGradePoints = 0;

        cout << "\nSemester " << s << endl;
        cout << "Enter number of courses: ";
        cin >> courses;

        for (int i = 1; i <= courses; i++) {
            string grade;
            double credits;

            cout << "\nCourse " << i << endl;

            cout << "Enter grade (A/B/C/D/E/F): ";
            cin >> grade;

            cout << "Enter credit hours: ";
            cin >> credits;

            double gradePoint = getGradePoint(grade);

            if (gradePoint == -1) {
                cout << "Invalid grade!" << endl;
                return 0;
            }

            totalGradePoints += gradePoint * credits;
            totalCredits += credits;
        }

        double GPA = totalGradePoints / totalCredits;


        cout << "\nSemester " << s << " GPA: "
             << GPA << endl;

          // Overall CGPA 
        overallGradePoints += totalGradePoints;
        overallCredits += totalCredits;
    }

    double CGPA = overallGradePoints / overallCredits;

    cout << endl;
    cout << "Overall CGPA: " << CGPA << endl;
    cout << endl;

    return 0;
}
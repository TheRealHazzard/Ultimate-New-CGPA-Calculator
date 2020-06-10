#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

void help()
{
    cout << "There are three modes in which you can use this application:\n# Mode 1 (Winter-Semester Internals Calculation):\nEnter marks scored in internals for current sem\nAs you finish input for each subject , a prediction will show for grade of current subject as well as the marks scored (outt of a possible 100).\nAfter typing the input for all the subjects , you will see the predicted gpa for the semester\nYou will be given an option as to whether you wish to calculate your new CGPA after adding the that has been predicted\nIf you wish to know your modified CGPA after the new additions , simply click on 1 and enter your past CGPA(up until your previous semester) as well as the number of credits your have finished so far.\nYou will now be able to see your modified CGPA.\n\n# Mode 2 (Calculate GPA for a semester):\n\nEnter the course credits followed by your predicted grade for the course\nReturns the GPA for the semester after you finish all the inputs.\nYou will be given an option as to whether you wish to calculate your new CGPA after adding the that has been predicted\nIf you wish to know your modified CGPA after the new additions , simply click on 1 and enter your past CGPA(up until your previous semester) as well as the number of credits your have finished so far.\nYou will now be able to see your modified CGPA.\n# Mode 3 (Calculate New CGPA):\n\nThis mode assumes that you have already calculated the GPA you are likely to receive in the current semester.\nEnter the number of credits finished , your current CGPA (Up until last semester) , number of credits taken this semester as well as your predicted cgpa for this semester.\nYou will see your modified CGPA.\n\n";
}
void calculate_cgpa()
{
    int credits_so_far, current_credits;
    int total_credits;
    float cgpa_so_far, current_cgpa, total_sum;
    cout << "Enter the number of credits completed: ";
    cin >> credits_so_far;
    cout << "Enter current CGPA: ";
    cin >> cgpa_so_far;
    cout << "Enter the number of credits taken in current semester: ";
    cin >> current_credits;
    cout << "Enter GPA expected this semester: ";
    cin >> current_cgpa;
    total_credits = credits_so_far + current_credits;
    total_sum = (credits_so_far * cgpa_so_far) + (current_credits * current_cgpa);
    total_sum = total_sum / total_credits;
    cout << "Your new CGPA is: " << total_sum;
}

void calculate_cgpa(int current_credits, float current_cgpa)
{
    int credits_so_far;
    int total_credits;
    float cgpa_so_far, total_sum;
    cout << "Enter the number of credits completed: ";
    cin >> credits_so_far;
    cout << "Enter current CGPA: ";
    cin >> cgpa_so_far;
    total_credits = credits_so_far + current_credits;
    total_sum = (credits_so_far * cgpa_so_far) + (current_credits * current_cgpa);
    total_sum = total_sum / total_credits;
    cout << "Your new CGPA is: " << total_sum;
}

int gradeScore(char a)
{
    switch (a)
    {
    case 's':
    case 'S':
        return 10;
    case 'A':
    case 'a':
        return 9;
    case 'B':
    case 'b':
        return 8;
    case 'C':
    case 'c':
        return 7;
    case 'd':
    case 'D':
        return 6;
    case 'e':
    case 'E':
        return 5;
    default:
        return 0;
    }
}

void calculate_gpa()
{
    int total_credits = 0;
    char grade;
    int credits, number, choice;
    float gpa = 0;
    cout << "Enter number of courses taken this semester: ";
    cin >> number;
    for (int i = 1; i <= number; i++)
    {
        cout << "Enter credits for course " << i << ": ";
        cin >> credits;
        total_credits += credits;
        cout << "Enter Grade: ";
        cin >> grade;
        gpa = gpa + (credits * gradeScore(grade));
    }
    cout << "Your GPA for this semester is: " << (gpa / total_credits);
    cout << "\nDo you wish to calculate your new overall CGPA after adding this semester's GPA? 1-Yes 0-No: ";
    cin >> choice;
    if (choice == 1)
    {
        calculate_cgpa(total_credits, gpa / total_credits);
    }
}

int predict_grade(int score)
{
    if (score < 50)
    {
        cout << "\nRe-registration Time\n";
        return 0;
    }
    else if (score >= 50 && score < 55)
    {
        cout << "\nYou got lucky. Most likely an E grade\n";
        return 5;
    }
    else if (score >= 55 && score < 60)
    {
        cout << "\nLooks like someone's probably getting the D\n";
        return 6;
    }
    else if (score >= 60 && score < 70)
    {
        cout << "\nC grade incoming. B if your class average is really really low (very unlikely)\n";
        return 7;
    }
    else if (score >= 70 && score < 80)
    {
        cout << "\nLooks like you're in the middle of the pack. Expect either a B or an A if your class average is really low. Might drop to C if class average is really high.\n";
        return 8;
    }
    else if (score >= 80 && score < 90)
    {
        cout << "\nYou're most likely getting an A. But if your class average is low , this might be an S. On the flip side , if class average is high then you might be getting a B\n";
        return 9;
    }

    else if (score >= 90 && score < 94)
    {

        cout << "\nYou're most likely getting an S. If your class average is insanely high then you might be getting an A\n";
        return 10;
    }
    else
    {

        cout << "\nYou're the reason your class average is so high. S grade on the charts . But don't quote me on this , stranger things have happened before. *cough* *French* *cough* *cough*\n";
        return 10;
    }
}

int predict_grade_absolute(int score)
{
    if (score < 50)
    {
        cout << "\nRe-registration Time\n";
        return 0;
    }
    else if (score >= 50 && score < 55)
    {
        cout << "\nYou got lucky. E grade\n";
        return 5;
    }
    else if (score >= 55 && score < 60)
    {
        cout << "\nLooks like someone's getting the D\n";
        return 6;
    }
    else if (score >= 60 && score < 70)
    {
        cout << "\nC grade incoming\n";
        return 7;
    }
    else if (score >= 70 && score < 80)
    {
        cout << "\nLooks like you're in the middle of the pack. B Grade\n";
        return 8;
    }
    else if (score >= 80 && score < 90)
    {
        cout << "\nYou're getting an A\n";
        return 9;
    }

    else
    {
        cout << "\nYou have achieved the impossible. S grade in an absolute graded course. People will construct statues in your honor\n";
        return 10;
    }
}
int calculate(int option)
{
    float DA1, DA2, DA3, CAT1, CAT2, ADD, sum, final_sum, quiz1, quiz2, pat1, pat2, pat3, pat4, bat;
    float lab_internals, proj_internals;
    if (option == 4)
    {
        cout << "Enter Predicted Project Review marks out of 100 (20+30+50): ";
        cin >> proj_internals;
        cout << "Enter marks scored in theory out of 100: ";
        cin >> final_sum;
        final_sum = (final_sum / 100) * 33.3334 + (proj_internals / 100) * 66.667;
        cout << "Final Score for this subject out of 100 is " << final_sum;
        return predict_grade(final_sum);
    }
    else if (option == 6)
    {
        cout << "Enter CAT1 Marks weightage (Out of 15): ";
        cin >> CAT1;
        cout << "Enter CAT2 Marks weightage (Out of 15): ";
        cin >> CAT2;
        cout << "Enter Quiz-1 Marks (Out of 15): ";
        cin >> quiz1;
        cout << "Enter Quiz-2 Marks (Out of 15): ";
        cin >> quiz2;
        sum = CAT1 + CAT2 + quiz1 + quiz2;
        final_sum = (sum / 60) * 100;
        cout << "Final Score for this subject out of 100 is " << final_sum;
        return predict_grade_absolute(final_sum);
    }
    else if (option == 8)
    {
        cout << "Enter Predicted Project Review marks out of 100 (20+30+50): ";
        cin >> proj_internals;
        final_sum = proj_internals;
        cout << "Final Score for this subject out of 100 is " << final_sum;
        return predict_grade_absolute(final_sum);
    }
    else if (option == 9)
    {
        cout << "Enter marks scored in internals for Theory Component(Out of 60): ";
        cin >> sum;
        cout << "Enter Predicted Project Review marks out of 100 (20+30+50): ";
        cin >> proj_internals;
        final_sum = (sum / 60) * 50 + (proj_internals / 100) * 50;
        cout << "Final Score for this subject out of 100 is " << final_sum;
        return predict_grade_absolute(final_sum);
    }
    else if (option == 12)
    {
        cout << "Enter marks scored in PAT-1 (Out of 8): ";
        cin >> pat1;
        cout << "Enter marks scored in PAT-2 (Out of 8): ";
        cin >> pat2;
        cout << "Enter marks scored in PAT-3 (Out of 8): ";
        cin >> pat3;
        cout << "Enter marks scored in PAT-4 (Out of 8): ";
        cin >> pat4;
        cout << "Enter CAT1 Marks weightage (Out of 14): ";
        cin >> CAT1;
        cout << "Enter CAT2 Marks weightage (Out of 14): ";
        cin >> CAT2;
        cout << "Enter marks scored in BAT (Out of 10): ";
        cin >> bat;
        final_sum = ((pat1 + pat2 + pat3 + pat4 + CAT1 + CAT2) / 60) * 100;
        final_sum+=bat;
        if (final_sum>100)
        final_sum=100;
        cout << "Final Score for this subject out of 100 is " << final_sum;
        return predict_grade_absolute(final_sum);
    }
    cout << "Enter CAT1 Marks weightage (Out of 15): ";
    cin >> CAT1;
    cout << "Enter CAT2 Marks weightage (Out of 15): ";
    cin >> CAT2;
    cout << "Enter DA1 Marks: ";
    cin >> DA1;
    cout << "Enter DA2 Marks: ";
    cin >> DA2;
    cout << "Enter DA3 Marks: ";
    cin >> DA3;
    cout << "Enter Additional Learning Marks (Enter 0 if not applicable): ";
    cin >> ADD;
    sum = DA1 + DA2 + DA3 + CAT1 + CAT2;
    final_sum = (sum / 60) * 40;
    sum += ADD;
    if (sum > 60)
        sum = 60;
    final_sum += sum;
    if (option == 1)
    {
        cout << "Final Score for this subject out of 100 is " << final_sum;
        return predict_grade(final_sum);
    }
    else if (option == 2)
    {
        cout << "Enter Lab internal marks out of 60: ";
        cin >> lab_internals;
        final_sum = (final_sum / 100) * 75 + (lab_internals / 60) * 25;
        cout << "Final Score for this subject out of 100 is " << final_sum;
        return predict_grade(final_sum);
    }
    else if (option == 3)
    {
        cout << "Enter Predicted Project Review marks out of 100 (20+30+50): ";
        cin >> proj_internals;
        final_sum = (final_sum / 100) * 75 + (proj_internals / 100) * 25;
        cout << "Final Score for this subject out of 100 is " << final_sum;
        return predict_grade(final_sum);
    }
    else if (option == 5)
    {
        cout << "Enter Lab internal marks out of 60: ";
        cin >> lab_internals;
        cout << "Enter Predicted Project Review marks out of 100 (20+30+50): ";
        cin >> proj_internals;
        final_sum = (final_sum / 100) * 50 + (proj_internals / 100) * 25 + (lab_internals / 60) * 25;
        cout << "Final Score for this subject out of 100 is " << final_sum;
        return predict_grade(final_sum);
    }
    else if (option == 7)
    {
        cout << "Enter Predicted Project Review marks out of 100 (20+30+50): ";
        cin >> proj_internals;
        final_sum = (final_sum / 100) * 50 + (proj_internals / 100) * 50;
        cout << "Final Score for this subject out of 100 is " << final_sum;
        return predict_grade(final_sum);
    }
    else if (option == 10)
    {
        cout << "Enter Predicted Project Review marks out of 100 (20+30+50): ";
        cin >> proj_internals;
        final_sum = (final_sum / 100) * 66.666 + (proj_internals / 100) * 33.3333;
        cout << "Final Score for this subject out of 100 is " << final_sum;
        return predict_grade(final_sum);
    }

    else if (option == 11)
    {
        cout << "Enter Lab internal marks out of 60: ";
        cin >> lab_internals;
        final_sum = (final_sum / 100) * 66.6666 + (lab_internals / 60) * 33.3333;
        cout << "Final Score for this subject out of 100 is " << final_sum;
        return predict_grade(final_sum);
    }
    else
    {
        cout << "ERROR , WRONG VALUE ENTERED. RESTART AND TRY AGAIN";
        exit(-1);
    }
}

void first_option()
{
    int number, option,choice,temp;
    int credits=0;
    float gpa=0;
    cout << "Enter number of courses taken this semester: ";
    cin >> number;
    for (int i = 1; i <= number; i++)
    {
    choice:
        cout << "\nEnter the type of course for course " << i << ":\n\n1) Theory Only (any no of credits) \n2) Theory + Lab (3 + 1 = 4 credits) \n3) Theory + Project (3 + 1 = 4 credits) \n4) TARP \n5) Theory + Lab + Project (2 + 1 + 1 = 4 credits)\n6) Soft Skills (1 credit)\n7) Theory + Project (1 + 1 = 2 credits)\n8) IIP (PHY1901) (1 credit)\n9) IIP (PHY1999) (2 credits)\n10) Theory + Project (2 + 1 = 3 credits) \n11) Theory + Lab (2 + 1 = 3 credits)\n12) OOPS (3 credits)\n";
        cout << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter number of credits for this course: ";
            cin >> temp;
            gpa += (calculate(1) * temp);
            credits+=temp;
            break;
        case 2:
            gpa += (calculate(2) * 4);
            credits+=4;
            break;
        case 3:
            gpa += (calculate(3) * 4);
            credits+=4;
            break;
        case 4:
            gpa += (calculate(4) * 3);
            credits+=3;
            break;
        case 5:
            gpa += (calculate(5) * 4);
            credits+=4;
            break;
        case 6:
            gpa += (calculate(6) * 1);
            credits+=1;
            break;
        case 7:
            gpa += (calculate(7) * 2);
            credits+=2;
            break;
        case 8:
            gpa += (calculate(8) * 1);
            credits+=1;
            break;
        case 9:
            gpa += (calculate(9) * 2);
            credits+=2;
            break;
        case 10:
            gpa += (calculate(10) * 3);
            credits+=3;
            break;
        case 11:
            gpa += (calculate(11) * 3);
            credits+=3;
            break;
        case 12:
            gpa += (calculate(12) * 3);
            credits+=3;
            break;
        default:
            cout << "Enter a valid option: " << endl;
            goto choice;
        }
    }
    gpa = gpa / credits;
    cout << "\nPredicted gpa is: " << gpa;
    cout << "\nDo you wish to calculate your new overall CGPA after adding this semester's GPA? 1-Yes 0-No: ";
    cin >> choice;
    if (choice == 1)
    {
        calculate_cgpa(credits, gpa);
    }
}

int main()
{
    cout << "Created By Robin Thomas From VIT Chennai\n";
    cout << "Grades shown here are rough estimates only. Final grades will differ based on class average\n\n";
    int option;
choice:
    cout << "1) Predict Grades for Winter Semester 2019-2020 based on Internal Marks scored\n2) Calculate GPA for current semester\n3) Calculate new CGPA: \n4) Need Help?\n";
    cin >> option;
    switch (option)
    {
    case 1:
        first_option();
        break;
    case 2:
        calculate_gpa();
        break;
    case 3:
        calculate_cgpa();
        break;
    case 4:
        help();
        goto choice;
    default:
        cout << "Check Input . Please try again.\n";
        goto choice;
    }
    return 0;
}
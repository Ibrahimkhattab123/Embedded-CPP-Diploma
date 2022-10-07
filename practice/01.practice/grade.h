namespace GRADE_EVALUATION 
{
    constexpr short int Low = 0;
    constexpr short int Failed = 50;
    constexpr short int Passed = 65;
    constexpr short int Good = 75;
    constexpr short int VeryGood = 85;
    constexpr short int High = 100;
    float grade;

    void askForGrade()
    {
        std::cout << "please enter your grade " << std::endl;
        std::cin >> grade;
    }
    void evaluate()
    {
        if (grade >= Low && grade < Failed)
        {
            std::cout << "failed" << std::endl;
        }
        else if (grade >= Failed && grade < Passed)
        {
            std::cout << "passed" << std::endl;
        }
        else if (grade >= Passed && grade < Good)
        {
            std::cout << "good" << std::endl;
        }
        else if (grade >= Good && grade < VeryGood)
        {
            std::cout << "very good" << std::endl;
        }
        else if (grade >= VeryGood && grade <= High)
        {
            std::cout << "excellent" << std::endl;
        }
        else
        {
            std::cout << "please enter a valid grade" << std::endl;
            std::cout << "value range: 0 - 100" << std::endl;
            askForGrade();
            evaluate();
        }
    }

    void RunGradeEvaluation(void)
    {
        askForGrade();
        evaluate();
    }
}
#include <iostream>

using namespace std;

int getNumberOfQuestions(){
    int numberOfQuestions;
    do {
        cout << "What is the number of Questions? ";
        cin >> numberOfQuestions;
    } while (numberOfQuestions <= 0);
    return numberOfQuestions;
}

int randomChoice(int from, int to){
    return rand()%(to-from+1)+from; 
}

enum questionLevels {easy = 1, medium = 2, hard = 3, mixLevel = 4};
enum questionTypes {addition = 1, substraction = 2, multiplication = 3, division = 4, mixType = 5};

struct finalResults {
    int numberOfQuestions;
    string questionLevelString;
    string questionTypeString;
    int rightAnswers = 0;
    int wrongAnswers = 0;
    string finalResult;
};

string questionLevelsToString (questionLevels questionLevel){
    switch(questionLevel){
        case questionLevels::easy: return "Easy";
        case questionLevels::medium: return "Medium";
        case questionLevels::hard: return "Hard";
        case questionLevels::mixLevel: return ""; 
    }
}

string questionTypesToString (questionTypes questionType){
    switch(questionType) {
        case questionTypes::addition: return "+";
        case questionTypes::substraction: return "-";
        case questionTypes::multiplication: return "x";
        case questionTypes::division: return "÷";
        case questionTypes::mixType: return "Mix";
    }
}

questionLevels getQuestionsLevel (){
    cout << "Enter Question Level: [1] Easy, [2] Medium, [3] Hard, [4] Mix: ";
    int questionLevel;
    cin >> questionLevel;
    return questionLevels(questionLevel);
}

questionTypes getQuestionsType() {
    cout << "Enter Question Type: [1] Addition, [2] Subtraction, [3] Multiplication, [4] Division, [5] Mix: ";
    int questionType;
    cin >> questionType;
    return questionTypes(questionType);
}

int generateNumbersBasedOnLevels(questionLevels questionLevel){
    switch(questionLevel){
        case questionLevels::easy: return randomChoice(1,10);
        case questionLevels::medium: return randomChoice(11, 20);
        case questionLevels::hard: return randomChoice(21, 100);
        case questionLevels::mixLevel: return randomChoice(1, 100);
    }
}

int operationCalculation(questionTypes questionType, int n1, int n2){
    switch(questionType){
        case questionTypes::addition: return n1+n2;
        case questionTypes::substraction: return n1-n2;
        case questionTypes::multiplication: return n1*n2;
        case questionTypes::division: return n1/n2;
        case questionTypes::mixType: return 0;
    }
}

void questionPrint(questionTypes questionType, int n1, int n2){
    cout << "\n  " << n1 << endl;
    switch (questionType){
        case questionTypes::addition: 
            cout << "+" << endl;
            break;
        case questionTypes::substraction: 
            cout << "-" << endl;
            break;
        case questionTypes::multiplication: 
            cout << "x" << endl;
            break;
        case questionTypes::division: 
            cout << "÷";
            break;
        case questionTypes::mixType: 
            break;
    }
    cout << "  " << n2 << endl << "_____\n";
}

void questionResultPrint(questionTypes questionType, int n1, int n2, int userResult){
    int correctAnswer = operationCalculation(questionType, n1, n2);
    if (userResult == correctAnswer) cout << "Correct Answer :)" << endl;
    else cout << "Wrong Answer :(" << endl << "The Correct Answer is " << correctAnswer << endl;
}

finalResults operationRun(int questionNumbers, questionLevels questionLevel, questionTypes questionType){
    int n1, n2, userResult;
    questionTypes questionTypeInput;
    finalResults finalResultsDetails;
    for (int questionNum = 1; questionNum <= questionNumbers; questionNum++){
        cout << "\nQuestion [" << questionNum << "/" << questionNumbers << "]\n"; 
        n1 = generateNumbersBasedOnLevels(questionLevel);
        n2 = generateNumbersBasedOnLevels(questionLevel);
        if (questionType == questionTypes::mixType){
            questionTypeInput = questionTypes(randomChoice(1, 4));
        }
        else questionTypeInput = questionType;
        questionPrint(questionTypeInput, n1, n2);
        cin >> userResult;
        if (userResult == operationCalculation(questionTypeInput, n1, n2)) finalResultsDetails.rightAnswers++;
        else finalResultsDetails.wrongAnswers++;
        questionResultPrint(questionTypeInput, n1, n2, userResult);
    }
    finalResultsDetails.numberOfQuestions = questionNumbers;
    finalResultsDetails.questionLevelString = questionLevelsToString(questionLevel);
    finalResultsDetails.questionTypeString = questionTypesToString(questionType);
    finalResultsDetails.finalResult = (finalResultsDetails.rightAnswers > finalResultsDetails.wrongAnswers)? "Pass :)": "Fail :(";
    return finalResultsDetails;
}

void finalResultsPrint(finalResults finalResultsDetails){
    cout << "\n-------------------------------------------\n";
    cout << " Final Results is " << finalResultsDetails.finalResult;
    cout << "\n-------------------------------------------\n";
    cout << "Number of Questions:     " << finalResultsDetails.numberOfQuestions << endl;
    cout << "Question Level:          " << finalResultsDetails.questionLevelString << endl;
    cout << "Question Type:           " << finalResultsDetails.questionTypeString << endl;
    cout << "Number of Right Answers: " << finalResultsDetails.rightAnswers << endl;
    cout << "Number of Wrong Answers: " << finalResultsDetails.wrongAnswers << endl;
    cout << "-------------------------------------------\n";

}

void startGame(){
    char playAgain;
    do {
        int numberOfQuestions = getNumberOfQuestions();
        questionLevels questionLevel = getQuestionsLevel();
        questionTypes questionType = getQuestionsType();
        finalResults finalResultsDetails = operationRun(numberOfQuestions, questionLevel, questionType);
        finalResultsPrint(finalResultsDetails);
        cout << "Do you want to play again (Y/N)? ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');
    
}

int main(){
    srand((unsigned)time(NULL));  
    startGame();
}
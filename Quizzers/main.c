#include <stdio.h>
#include <ctype.h>
#include <windows.h>

// Function to change text color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to display the question and return the correct answer choice.
int askQuestion(char question[], char options[][100], char correctAnswer) {
    char answer;
    setColor(15); // White text color
    printf("%s\n", question);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, options[i]);
    }
    setColor(14); // Yellow text color for prompt
    printf("Enter your choice (A-D): ");
    scanf(" %c", &answer);  // Note the space before %c to catch any leftover newline character
    answer = toupper(answer);  // Convert to uppercase if the user enters lowercase
    if (answer == correctAnswer) {
        setColor(10); // Green text color for correct answer
        printf("Correct! You earned 1 point.\n");
        return 1; // Correct answer
    }
    setColor(12); // Red text color for wrong answer
    printf("Incorrect! You earned 0 points.\n");
    return 0; // Incorrect answer
}

void printHeader(char *header) {
    setColor(11); // Light Cyan for header
    printf("\n============================================\n");
    printf("          %s\n", header);
    printf("============================================\n");
    setColor(15); // Reset text color to white
}

int main() {
    int totalScore = 0;
    char choice;

    // Level 1 (Easy - Sports Questions)
    char question1[] = "Which country won the 2018 FIFA World Cup?";
    char options1[4][100] = {"Brazil", "Germany", "France", "Argentina"};
    char correctAnswer1 = 'C'; // Correct answer is option C (France)

    char question2[] = "Which sport is played at Wimbledon?";
    char options2[4][100] = {"Football", "Cricket", "Tennis", "Rugby"};
    char correctAnswer2 = 'C'; // Correct answer is option C (Tennis)

    char question3[] = "Which country is known for the sport of cricket?";
    char options3[4][100] = {"USA", "India", "Germany", "Canada"};
    char correctAnswer3 = 'B'; // Correct answer is option B (India)

    char question4[] = "Who is known as 'The King of Football'?";
    char options4[4][100] = {"Pele", "Cristiano Ronaldo", "Lionel Messi", "David Beckham"};
    char correctAnswer4 = 'A'; // Correct answer is option A (Pele)

    char question5[] = "Which sport is associated with the Stanley Cup?";
    char options5[4][100] = {"Football", "Basketball", "Hockey", "Baseball"};
    char correctAnswer5 = 'C'; // Correct answer is option C (Hockey)

    // Level 2 (Medium - General Knowledge Questions)
    char question6[] = "Which city is known as the 'Big Apple'?";
    char options6[4][100] = {"Los Angeles", "New York", "Chicago", "San Francisco"};
    char correctAnswer6 = 'B'; // Correct answer is option B (New York)

    char question7[] = "Who is the author of 'Harry Potter'?";
    char options7[4][100] = {"J.R.R. Tolkien", "J.K. Rowling", "George R.R. Martin", "C.S. Lewis"};
    char correctAnswer7 = 'B'; // Correct answer is option B (J.K. Rowling)

    char question8[] = "Which is the largest ocean on Earth?";
    char options8[4][100] = {"Atlantic Ocean", "Indian Ocean", "Southern Ocean", "Pacific Ocean"};
    char correctAnswer8 = 'D'; // Correct answer is option D (Pacific Ocean)

    char question9[] = "What is the tallest mountain in the world?";
    char options9[4][100] = {"Mount Everest", "K2", "Kangchenjunga", "Mount Kilimanjaro"};
    char correctAnswer9 = 'A'; // Correct answer is option A (Mount Everest)

    char question10[] = "What is the chemical symbol for Gold?";
    char options10[4][100] = {"Au", "Ag", "Pb", "Fe"};
    char correctAnswer10 = 'A'; // Correct answer is option A (Au)

    // Level 3 (Hard - Technical Content Questions)
    char question11[] = "What does CSS stand for in web development?";
    char options11[4][100] = {"Cascading Style Sheets", "Creative Style Sheets", "Computer Style Sheets", "Coded Style Sheets"};
    char correctAnswer11 = 'A'; // Correct answer is option A (Cascading Style Sheets)

    char question12[] = "Which programming language is primarily used for iOS development?";
    char options12[4][100] = {"Swift", "Objective-C", "Java", "Python"};
    char correctAnswer12 = 'A'; // Correct answer is option A (Swift)

    char question13[] = "Which type of software is used to manage databases?";
    char options13[4][100] = {"Operating System", "Database Management System", "Application Software", "Utility Software"};
    char correctAnswer13 = 'B'; // Correct answer is option B (Database Management System)

    char question14[] = "What is the purpose of an IP address in networking?";
    char options14[4][100] = {"To identify a device", "To connect to the internet", "To manage network traffic", "To store website data"};
    char correctAnswer14 = 'A'; // Correct answer is option A (To identify a device)

    char question15[] = "Which technology is used for creating Android mobile apps?";
    char options15[4][100] = {"Swift", "Java", "Ruby", "C#"};
    char correctAnswer15 = 'B'; // Correct answer is option B (Java)

    // Start the game
    setColor(13); // Pink for welcome message
    printf("*******************************************\n");
    printf("*          Welcome to the Quiz Game!     *\n");
    printf("*******************************************\n");

    // Loop for each level
    for (int level = 1; level <= 3; level++) {
        int levelScore = 0;
        int replayLevel = 0;

        // Print level header with colorful design
        if (level == 1) {
            printHeader("Level 1: Easy - Sports");
        } else if (level == 2) {
            printHeader("Level 2: Medium - General Knowledge");
        } else {
            printHeader("Level 3: Hard - Technical Content");
        }

        // Ask 5 questions per level
        for (int i = 1; i <= 5; i++) {
            int correct = 0;

            if (level == 1) {  // Easy questions for Level 1 (Sports)
                if (i == 1) {
                    correct = askQuestion(question1, options1, correctAnswer1);
                } else if (i == 2) {
                    correct = askQuestion(question2, options2, correctAnswer2);
                } else if (i == 3) {
                    correct = askQuestion(question3, options3, correctAnswer3);
                } else if (i == 4) {
                    correct = askQuestion(question4, options4, correctAnswer4);
                } else {
                    correct = askQuestion(question5, options5, correctAnswer5);
                }
            } else if (level == 2) {  // Medium questions for Level 2 (General Knowledge)
                if (i == 1) {
                    correct = askQuestion(question6, options6, correctAnswer6);
                } else if (i == 2) {
                    correct = askQuestion(question7, options7, correctAnswer7);
                } else if (i == 3) {
                    correct = askQuestion(question8, options8, correctAnswer8);
                } else if (i == 4) {
                    correct = askQuestion(question9, options9, correctAnswer9);
                } else {
                    correct = askQuestion(question10, options10, correctAnswer10);
                }
            } else if (level == 3) {  // Hard questions for Level 3 (Technical Content)
                if (i == 1) {
                    correct = askQuestion(question11, options11, correctAnswer11);
                } else if (i == 2) {
                    correct = askQuestion(question12, options12, correctAnswer12);
                } else if (i == 3) {
                    correct = askQuestion(question13, options13, correctAnswer13);
                } else if (i == 4) {
                    correct = askQuestion(question14, options14, correctAnswer14);
                } else {
                    correct = askQuestion(question15, options15, correctAnswer15);
                }
            }

            if (correct) {
                levelScore++;
            }
        }

        // Check if the user scored at least 3 out of 5
        if (levelScore >= 3) {
            totalScore += levelScore;
            setColor(10); // Green for success
            printf("\nScore for Level %d: %d\n", level, levelScore);
        } else {
            // If the user scored less than 3, ask if they want to replay the level
            setColor(12); // Red for failure
            printf("\nYou scored %d out of 5 for Level %d.\n", levelScore, level);
            printf("Do you want to replay this level? (y/n): ");
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                replayLevel = 1;
            }
        }

        // If the user does not want to replay, move to the next level
        if (!replayLevel) {
            totalScore += levelScore;
        }

        // If user decides to replay, stay on the same level and try again
        if (replayLevel) {
            level--; // Do not increment level, so the player can replay the current level
        }
    }

    // Game Over: Display Total Score
    setColor(15); // White text for final score
    printf("\nGame Over! Your total score: %d\n", totalScore);

    return 0;
}

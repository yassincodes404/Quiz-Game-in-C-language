#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Question {
    char question[256];
    char options[4][20];
    int correctOption;
};


struct EasyQuestionList {
   struct Question questions[100];
   int currentFilledIndex;
};
struct MediumQuestionList {
    struct Question questions[100];
    int currentFilledIndex;
};
struct HardQuestionList {
    struct Question questions[100];
    int currentFilledIndex;
};



struct playerSettings {
    int durationMode;
    int difficultyMode;
    int questionNumber;
    int questionDuration;
};

struct Player {
    char name[50];
    int score;
    struct playerSettings settings;
};

struct Player createPlayer(char name[50], int score, struct playerSettings settings) {
    struct Player newPlayer;
    strcpy(newPlayer.name, name);
    newPlayer.score = score;
    newPlayer.settings = settings;
    return newPlayer;
}
void createEasyQuestion(struct EasyQuestionList *easyQuestions, char question[256], char options[4][20], int correctOption) {
    struct Question newQuestion;
    strcpy(newQuestion.question, question);
    for (int i = 0; i < 4; i++) {
        strcpy(newQuestion.options[i], options[i]);
    }
    newQuestion.correctOption = correctOption;
    easyQuestions->questions[easyQuestions->currentFilledIndex] = newQuestion;
    easyQuestions->currentFilledIndex++;
}

void createMediumQuestion(struct MediumQuestionList *mediumQuestions, char question[256], char options[4][20], int correctOption) {
    struct Question newQuestion;
    strcpy(newQuestion.question, question);
    for (int i = 0; i < 4; i++) {
        strcpy(newQuestion.options[i], options[i]);
    }
    newQuestion.correctOption = correctOption;
    mediumQuestions->questions[mediumQuestions->currentFilledIndex] = newQuestion;
    mediumQuestions->currentFilledIndex++;
}
void createHardQuestion(struct HardQuestionList *hardQuestions, char question[256], char options[4][20], int correctOption) {
    struct Question newQuestion;
    strcpy(newQuestion.question, question);
    for (int i = 0; i < 4; i++) {
        strcpy(newQuestion.options[i], options[i]);
    }
    newQuestion.correctOption = correctOption;
    hardQuestions->questions[hardQuestions->currentFilledIndex] = newQuestion;
    hardQuestions->currentFilledIndex++;
}
void generateEasyQuestions(struct EasyQuestionList *easyQuestions) {
    easyQuestions->currentFilledIndex = 0; // Initialize to 0

    // Example questions
    char options1[4][20] = {"3", "4", "5", "6"};
    createEasyQuestion(easyQuestions, "What is 2 + 2?", options1, 1);

    char options2[4][20] = {"Blue", "Green", "Red", "Yellow"};
    createEasyQuestion(easyQuestions, "What is the color of the sky?", options2, 0);

    char options3[4][20] = {"6", "8", "10", "12"};
    createEasyQuestion(easyQuestions, "How many legs does a spider have?", options3, 1);

    char options4[4][20] = {"London", "Paris", "Berlin", "Madrid"};
    createEasyQuestion(easyQuestions, "What is the capital of England?", options4, 0);

    char options5[4][20] = {"7", "8", "9", "10"};
    createEasyQuestion(easyQuestions, "What is 5 + 3?", options5, 1);
}


void generateMediumQuestions(struct MediumQuestionList *mediumQuestions) {
    mediumQuestions->currentFilledIndex = 0; // Initialize to 0

    // Example questions
    char options1[4][20] = {"Berlin", "Madrid", "Paris", "Rome"};
    createMediumQuestion(mediumQuestions, "What is the capital of France?", options1, 2);

    char options2[4][20] = {"Mercury", "Venus", "Earth", "Mars"};
    createMediumQuestion(mediumQuestions, "Which planet is known as the Red Planet?", options2, 3);

    char options3[4][20] = {"Shakespeare", "Hemingway", "Dickens", "Tolkien"};
    createMediumQuestion(mediumQuestions, "Who wrote 'Romeo and Juliet'?", options3, 0);
}

void generateHardQuestions(struct HardQuestionList *hardQuestions) {
    hardQuestions->currentFilledIndex = 0; // Initialize to 0

    // Example questions
    char options1[4][20] = {"10", "12", "14", "16"};
    createHardQuestion(hardQuestions, "What is the square root of 144?", options1, 1);

    char options2[4][20] = {"Einstein", "Newton", "Galileo", "Tesla"};
    createHardQuestion(hardQuestions, "Who developed the theory of relativity?", options2, 0);

    char options3[4][20] = {"Oxygen", "Hydrogen", "Carbon", "Nitrogen"};
    createHardQuestion(hardQuestions, "What is the most abundant gas in Earth's atmosphere?", options3, 3);
}


bool firstTimePlayer(struct Player *player) {
    FILE *file = fopen("player_data.txt", "r");
    if (file == NULL) {
        // File doesn't exist, create it
        file = fopen("player_data.txt", "w");
        if (file == NULL) {
            printf("Error: Could not create player data file.\n");
            return true; // Treat as first-time player if file creation fails
        }
        fclose(file);
        return true; // First-time player
    }
    fclose(file);
    return false; // Not a first-time player
}

void loadPlayerData(struct Player *player) {

    FILE *file = fopen("player_data.txt", "r");
    if (file == NULL) {
        // If the file doesn't exist, create it
        file = fopen("player_data.txt", "w");
        if (file == NULL) {
            printf("Error: Could not create player data file.\n");
            return;
        }
        fclose(file);
        printf("Player data file created successfully.\n");
        return;
    }

fscanf(file, "%49s", player->name);
fscanf(file, "%d", &player->score);
fscanf(file, "%d", &player->settings.durationMode);
fscanf(file, "%d", &player->settings.difficultyMode);
fscanf(file, "%d", &player->settings.questionNumber);
fscanf(file, "%d", &player->settings.questionDuration);

fclose(file);
}

void WelcomePage() {
    printf("Welcome to the Quiz Game!\n");
    printf("You will be asked a series of questions.\n");
    printf("Answer them correctly to score points.\n");
    printf("Good luck!\n");
}

void changePlayerSettings(struct Player *player) {
    printf("Change Settings:\n");
    printf("Enter Duration Mode (in minutes): ");
    scanf("%d", &player->settings.durationMode);
    printf("Enter Difficulty Mode (1-Easy, 2-Medium, 3-Hard): ");
    scanf("%d", &player->settings.difficultyMode);
    printf("Enter Number of Questions: ");
    scanf("%d", &player->settings.questionNumber);
    printf("Enter Question Duration (in seconds): ");
    scanf("%d", &player->settings.questionDuration);
}



void savePlayerData(struct Player *player) {
    FILE *file = fopen("player_data.txt", "w"); 
    if (file == NULL) {
        printf("Error: Could not open player data file for writing.\n");
        return;
    }
    fprintf(file, "%s\n", player->name);
    fprintf(file, "%d\n", player->score);
    fprintf(file, "%d\n", player->settings.durationMode);
    fprintf(file, "%d\n", player->settings.difficultyMode);
    fprintf(file, "%d\n", player->settings.questionNumber);
    fprintf(file, "%d\n", player->settings.questionDuration);
    fclose(file);
}


void displayPlayerData(struct Player *player) {
    printf("\n");
    printf("---------------------------------------------------\n"); 
    printf("Player Data:\n");
    printf("Player Name: %s\n", player->name);
    printf("Total Score: %d\n", player->score);
    printf("Duration Mode: %d minutes\n", player->settings.durationMode);
    printf("Difficulty Mode: %d\n", player->settings.difficultyMode);
    printf("Number of Questions: %d\n", player->settings.questionNumber);
    printf("Question Duration: %d seconds\n", player->settings.questionDuration);
    printf("---------------------------------------------------\n"); 
}

void updatePlayerScore(struct Player *player, int score) {
    player->score += score;
}   

void updatePlayerSettings(struct Player *player, struct playerSettings settings) {
    player->settings = settings;
}   
void updatePlayerData(struct Player *player, int score, struct playerSettings settings) {
    
    updatePlayerScore(player, score);
    updatePlayerSettings(player, settings);

    FILE *file = fopen("player_data.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open player data file for writing.\n");
        return;
    }

    fprintf(file, "%s\n", player->name);
    fprintf(file, "%d\n", player->score);
    fprintf(file, "%d\n", player->settings.durationMode);
    fprintf(file, "%d\n", player->settings.difficultyMode);
    fprintf(file, "%d\n", player->settings.questionNumber);
    fprintf(file, "%d\n", player->settings.questionDuration);

    fclose(file);

    printf("Player data updated successfully.\n");
}

void initUserAndGameSettings(struct Player *player) {
  if(firstTimePlayer(player)) {
        printf("Enter your name: ");
        scanf("%49s", player->name);
        player->score = 0;
        player->settings.durationMode = 1; // Default to 1 minute
        player->settings.difficultyMode = 1; // Default to easy
        player->settings.questionNumber = 5; // Default to 5 questions
        player->settings.questionDuration = 30; // Default to 30 seconds per question
    } else {
        loadPlayerData(player);
    }
    printf("Welcome, %s!\n", player->name);
    printf("Your current score is: %d\n", player->score);
    printf("Duration Mode: %d minutes\n", player->settings.durationMode);
    printf("Difficulty Mode: %d\n", player->settings.difficultyMode);
    printf("Number of Questions: %d\n", player->settings.questionNumber);
    printf("Question Duration: %d seconds\n", player->settings.questionDuration);
    printf("You can change your settings in the game menu.\n");
}


void mainPage(struct Player *player, struct EasyQuestionList easyQuestions, struct MediumQuestionList mediumQuestions, struct HardQuestionList hardQuestions);
void startQuizGame(struct Player *player, struct EasyQuestionList *easyQuestions, struct MediumQuestionList *mediumQuestions, struct HardQuestionList *hardQuestions);

int main() {
    // init player's data and games Questions 
    struct Player player;
    struct EasyQuestionList easyQuestions;
    struct MediumQuestionList mediumQuestions;
    struct HardQuestionList hardQuestions;

   generateEasyQuestions(&easyQuestions);
   generateMediumQuestions(&mediumQuestions);
   generateHardQuestions(&hardQuestions);

    
    initUserAndGameSettings(&player);
   
    mainPage(&player, easyQuestions, mediumQuestions, hardQuestions);

    savePlayerData(&player);
    return 0;
}

void changePlayerName(struct Player *player) {
    printf("Enter new player name: ");
    scanf("%49s", player->name);
    updatePlayerData(player, player->score, player->settings);
    printf("Player name changed to: %s\n", player->name);
}

void mainPage(struct Player *player, struct EasyQuestionList easyQuestions, struct MediumQuestionList mediumQuestions, struct HardQuestionList hardQuestions) {
    
    WelcomePage();
    int choice;
    do {
        printf("\nMain Menu:\n");
        printf("1. Start Quiz\n");
        printf("2. Change Settings\n");
        printf("3. Change Player Name\n");
        printf("4. View Player Data and Settings\n");
        printf("5. Close Game\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                startQuizGame(player, &easyQuestions, &mediumQuestions, &hardQuestions);
                break;
            case 2:
                changePlayerSettings(player);
                savePlayerData(player);
                break;
            case 3:
                changePlayerName(player);
                break;
            case 4:
                loadPlayerData(player);
                displayPlayerData(player);
                break;
            case 5:
                printf("Closing the game. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}



void startQuizGame(struct Player *player , struct EasyQuestionList *easyQuestions, struct MediumQuestionList *mediumQuestions, struct HardQuestionList *hardQuestions) {
    int score = 0;
    int questionCount = player->settings.questionNumber;
    int questionDuration = player->settings.questionDuration;

    struct Question *questions = NULL;
    int totalQuestions = 0;

    if (player->settings.difficultyMode == 1) {
        questions = easyQuestions->questions;
        totalQuestions = easyQuestions->currentFilledIndex;
    } else if (player->settings.difficultyMode == 2) {
        questions = mediumQuestions->questions;
        totalQuestions = mediumQuestions->currentFilledIndex;
    } else {
        questions = hardQuestions->questions;
        totalQuestions = hardQuestions->currentFilledIndex;
    }

    int correctAnswers = 0;

    for (int i = 0; i < questionCount && i < totalQuestions; i++) {
        struct Question currentQuestion = questions[i];

        printf("Question %d: %s\n", i + 1, currentQuestion.question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, currentQuestion.options[j]);
        }

        int answer;
        printf("Enter your answer (1-4) or 0 to quit: ");
        scanf("%d", &answer);

        if (answer == 0) {
            printf("You chose to quit the quiz.\n");
            break;
        }

        if (answer - 1 == currentQuestion.correctOption) {
            printf("Correct!\n");
            score++;
            correctAnswers++;
        } else {
            printf("Wrong! The correct answer is: %s\n", currentQuestion.options[currentQuestion.correctOption]);
        }
    }

    updatePlayerScore(&player, score);

    printf("You answered %d out of %d questions correctly.\n", correctAnswers, questionCount);
    printf("Your final score is: %d\n", score);

    updatePlayerData(player, score, player->settings);
}












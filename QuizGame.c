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
};
struct MediumQuestionList {
    struct Question questions[100];
 
};
struct HardQuestionList {
    struct Question questions[100];
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

void generateEasyQuestions(struct EasyQuestionList *easyQuestions) {
    // Example questions
    strcpy(easyQuestions->questions[0].question, "What is 2 + 2?");
    strcpy(easyQuestions->questions[0].options[0], "3");
    strcpy(easyQuestions->questions[0].options[1], "4");
    strcpy(easyQuestions->questions[0].options[2], "5");
    strcpy(easyQuestions->questions[0].options[3], "6");
    easyQuestions->questions[0].correctOption = 1; // Correct answer is option 1
}
void generateMediumQuestions(struct MediumQuestionList *mediumQuestions) {
    // Example questions
    strcpy(mediumQuestions->questions[0].question, "What is the capital of France?");
    strcpy(mediumQuestions->questions[0].options[0], "Berlin");
    strcpy(mediumQuestions->questions[0].options[1], "Madrid");
    strcpy(mediumQuestions->questions[0].options[2], "Paris");
    strcpy(mediumQuestions->questions[0].options[3], "Rome");
    mediumQuestions->questions[0].correctOption = 2; // Correct answer is option 2
}
void generateHardQuestions(struct HardQuestionList *hardQuestions) {
    // Example questions
    strcpy(hardQuestions->questions[0].question, "What is the square root of 144?");
    strcpy(hardQuestions->questions[0].options[0], "10");
    strcpy(hardQuestions->questions[0].options[1], "12");
    strcpy(hardQuestions->questions[0].options[2], "14");
    strcpy(hardQuestions->questions[0].options[3], "16");
    hardQuestions->questions[0].correctOption = 1; 
}


bool firstTimePlayer(struct Player *player) {
    FILE *file = fopen("player_data.txt", "r");
    if (file == NULL) {
        return true; 
    }
    fclose(file);
    return false; 
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


int main() {

    struct Player player;
    struct EasyQuestionList easyQuestions;
    struct MediumQuestionList mediumQuestions;
    struct HardQuestionList hardQuestions;

   generateEasyQuestions(&easyQuestions);
   generateMediumQuestions(&mediumQuestions);
   generateHardQuestions(&hardQuestions);
    WelcomePage();
    initUserAndGameSettings(&player);

  
    return 0;
}










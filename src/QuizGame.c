#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

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

bool nameValidation(char name[50]) {
    // Check if the name is valid (e.g., not empty, no special characters, no numbers, length constraints)
    int length = strlen(name);
    if (length < 4 || length > 10) {
        printf("Name must be between 4 and 10 characters long.\n");
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            printf("Name can only contain letters and spaces.\n");
            return false;
        }
        if (isdigit(name[i])) {
            printf("Name cannot contain numbers.\n");
            return false;
        }
    }
    return true; // Name is valid
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

    char options6[4][20] = {"Dog", "Cat", "Lion", "Elephant"};
    createEasyQuestion(easyQuestions, "Which animal barks?", options6, 0);

    char options7[4][20] = {"Banana", "Carrot", "Apple", "Grapes"};
    createEasyQuestion(easyQuestions, "Which of these is not a fruit?", options7, 1);

    char options8[4][20] = {"January", "February", "June", "December"};
    createEasyQuestion(easyQuestions, "Which month has Valentine's Day?", options8, 1);

    char options9[4][20] = {"Water", "Milk", "Juice", "Oil"};
    createEasyQuestion(easyQuestions, "What do humans need to survive?", options9, 0);

    char options10[4][20] = {"Square", "Circle", "Triangle", "Rectangle"};
    createEasyQuestion(easyQuestions, "Which shape has no corners?", options10, 1);

    char options11[4][20] = {"Sun", "Moon", "Star", "Cloud"};
    createEasyQuestion(easyQuestions, "What provides light during the day?", options11, 0);

    char options12[4][20] = {"1", "2", "3", "4"};
    createEasyQuestion(easyQuestions, "What comes after 2?", options12, 2);

    char options13[4][20] = {"Pink", "Black", "Orange", "Green"};
    createEasyQuestion(easyQuestions, "What color is a pumpkin?", options13, 2);

    char options14[4][20] = {"Earth", "Mars", "Jupiter", "Venus"};
    createEasyQuestion(easyQuestions, "Which planet do we live on?", options14, 0);

    char options15[4][20] = {"Leg", "Hand", "Eye", "Foot"};
    createEasyQuestion(easyQuestions, "What do we use to see?", options15, 2);

    char options16[4][20] = {"Pen", "Eraser", "Ruler", "Pencil"};
    createEasyQuestion(easyQuestions, "What is used for writing?", options16, 3);

    char options17[4][20] = {"Fish", "Bird", "Frog", "Elephant"};
    createEasyQuestion(easyQuestions, "Which of these can fly?", options17, 1);

    char options18[4][20] = {"India", "USA", "China", "Australia"};
    createEasyQuestion(easyQuestions, "Which country is known for the Great Wall?", options18, 2);

    char options19[4][20] = {"Green", "Red", "Blue", "White"};
    createEasyQuestion(easyQuestions, "What color is grass?", options19, 0);

    char options20[4][20] = {"2", "3", "4", "5"};
    createEasyQuestion(easyQuestions, "What is 2 * 2?", options20, 2);
}



void generateMediumQuestions(struct MediumQuestionList *mediumQuestions) {
    mediumQuestions->currentFilledIndex = 0; // Initialize to 0

    char options1[4][20] = {"Berlin", "Madrid", "Paris", "Rome"};
    createMediumQuestion(mediumQuestions, "What is the capital of France?", options1, 2);

    char options2[4][20] = {"Mercury", "Venus", "Earth", "Mars"};
    createMediumQuestion(mediumQuestions, "Which planet is known as the Red Planet?", options2, 3);

    char options3[4][20] = {"Shakespeare", "Hemingway", "Dickens", "Tolkien"};
    createMediumQuestion(mediumQuestions, "Who wrote 'Romeo and Juliet'?", options3, 0);

    char options4[4][20] = {"Oxygen", "Hydrogen", "Carbon", "Nitrogen"};
    createMediumQuestion(mediumQuestions, "What is the most abundant gas in the Earth's atmosphere?", options4, 3);

    char options5[4][20] = {"Nile", "Amazon", "Yangtze", "Mississippi"};
    createMediumQuestion(mediumQuestions, "Which is the longest river in the world?", options5, 0);

    char options6[4][20] = {"299,792 km/s", "150,000 km/s", "1,080 km/h", "3,000 km/s"};
    createMediumQuestion(mediumQuestions, "What is the speed of light?", options6, 0);

    char options7[4][20] = {"Leonardo da Vinci", "Michelangelo", "Raphael", "Van Gogh"};
    createMediumQuestion(mediumQuestions, "Who painted the Mona Lisa?", options7, 0);

    char options8[4][20] = {"Isaac Newton", "Galileo", "Einstein", "Tesla"};
    createMediumQuestion(mediumQuestions, "Who formulated the laws of motion and gravity?", options8, 0);

    char options9[4][20] = {"Atlantic", "Arctic", "Indian", "Pacific"};
    createMediumQuestion(mediumQuestions, "Which is the largest ocean on Earth?", options9, 3);

    char options10[4][20] = {"Photosynthesis", "Metabolism", "Digestion", "Respiration"};
    createMediumQuestion(mediumQuestions, "What process do plants use to make their food?", options10, 0);

    char options11[4][20] = {"Jupiter", "Saturn", "Earth", "Neptune"};
    createMediumQuestion(mediumQuestions, "Which planet has the most moons?", options11, 0);

    char options12[4][20] = {"Mandarin", "English", "Spanish", "Hindi"};
    createMediumQuestion(mediumQuestions, "What is the most spoken language in the world by native speakers?", options12, 0);

    char options13[4][20] = {"Copper", "Iron", "Aluminum", "Silver"};
    createMediumQuestion(mediumQuestions, "Which metal is the best conductor of electricity?", options13, 3);

    char options14[4][20] = {"Bacteria", "Virus", "Fungus", "Algae"};
    createMediumQuestion(mediumQuestions, "What causes the common cold?", options14, 1);

    char options15[4][20] = {"Asia", "Africa", "Europe", "Antarctica"};
    createMediumQuestion(mediumQuestions, "Which is the most populous continent?", options15, 0);

    char options16[4][20] = {"E = mc^2", "F = ma", "V = IR", "a^2 + b^2 = c^2"};
    createMediumQuestion(mediumQuestions, "Which formula represents Einstein's theory of relativity?", options16, 0);

    char options17[4][20] = {"Pacific", "Atlantic", "Arctic", "Southern"};
    createMediumQuestion(mediumQuestions, "Which ocean is located at the North Pole?", options17, 2);

    char options18[4][20] = {"Beijing", "Tokyo", "Seoul", "Bangkok"};
    createMediumQuestion(mediumQuestions, "What is the capital city of Japan?", options18, 1);

    char options19[4][20] = {"9", "10", "11", "12"};
    createMediumQuestion(mediumQuestions, "How many players are on a soccer team (on the field)?", options19, 0);

    char options20[4][20] = {"Asia", "Europe", "South America", "North America"};
    createMediumQuestion(mediumQuestions, "Which continent is Brazil located in?", options20, 2);
}

void generateHardQuestions(struct HardQuestionList *hardQuestions) {
    hardQuestions->currentFilledIndex = 0; // Initialize to 0

    char options1[4][20] = {"10", "12", "14", "16"};
    createHardQuestion(hardQuestions, "What is the square root of 144?", options1, 1);

    char options2[4][20] = {"Einstein", "Newton", "Galileo", "Tesla"};
    createHardQuestion(hardQuestions, "Who developed the theory of relativity?", options2, 0);

    char options3[4][20] = {"Oxygen", "Hydrogen", "Carbon", "Nitrogen"};
    createHardQuestion(hardQuestions, "What is the most abundant gas in Earth's atmosphere?", options3, 3);

    char options4[4][20] = {"H2O", "CO2", "O2", "CH4"};
    createHardQuestion(hardQuestions, "What is the chemical formula for methane?", options4, 3);

    char options5[4][20] = {"Euler", "Gauss", "Fermat", "Newton"};
    createHardQuestion(hardQuestions, "Who formulated the Last Theorem in mathematics?", options5, 2);

    char options6[4][20] = {"Hyperbola", "Circle", "Ellipse", "Parabola"};
    createHardQuestion(hardQuestions, "Which conic section has one focus and one directrix?", options6, 3);

    char options7[4][20] = {"Helium", "Hydrogen", "Lithium", "Oxygen"};
    createHardQuestion(hardQuestions, "What is the lightest element in the periodic table?", options7, 1);

    char options8[4][20] = {"Titan", "Europa", "Ganymede", "Io"};
    createHardQuestion(hardQuestions, "Which is the largest moon in the solar system?", options8, 2);

    char options9[4][20] = {"Heisenberg", "Bohr", "Feynman", "Dirac"};
    createHardQuestion(hardQuestions, "Who is known for the uncertainty principle?", options9, 0);

    char options10[4][20] = {"Planck", "Hertz", "Ampere", "Faraday"};
    createHardQuestion(hardQuestions, "Which scientist's name is used for the constant relating energy and frequency?", options10, 0);

    char options11[4][20] = {"10", "12", "15", "20"};
    createHardQuestion(hardQuestions, "How many edges does a dodecahedron have?", options11, 2);

    char options12[4][20] = {"Iron", "Lead", "Uranium", "Plutonium"};
    createHardQuestion(hardQuestions, "Which element has the highest atomic number naturally occurring on Earth?", options12, 2);

    char options13[4][20] = {"Venus", "Mercury", "Earth", "Mars"};
    createHardQuestion(hardQuestions, "Which planet has the longest day?", options13, 0);

    char options14[4][20] = {"Asia", "Africa", "Europe", "Australia"};
    createHardQuestion(hardQuestions, "Which continent has the most countries?", options14, 1);

    char options15[4][20] = {"1944", "1945", "1946", "1947"};
    createHardQuestion(hardQuestions, "In which year did World War II end?", options15, 1);

    char options16[4][20] = {"Copper", "Aluminum", "Silver", "Gold"};
    createHardQuestion(hardQuestions, "Which of these metals is the best electrical conductor?", options16, 2);

    char options17[4][20] = {"Canberra", "Sydney", "Melbourne", "Perth"};
    createHardQuestion(hardQuestions, "What is the capital city of Australia?", options17, 0);

    char options18[4][20] = {"7", "8", "9", "10"};
    createHardQuestion(hardQuestions, "How many electrons are in the outer shell of an oxygen atom?", options18, 1);

    char options19[4][20] = {"Canada", "Russia", "USA", "China"};
    createHardQuestion(hardQuestions, "Which country has the largest land area?", options19, 1);

    char options20[4][20] = {"Joule", "Watt", "Volt", "Newton"};
    createHardQuestion(hardQuestions, "What unit is used to measure energy?", options20, 0);
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

bool DurationModeValidation(int durationMode);
bool DifficultyModeValidation(int difficultyMode);
bool QuestionNumberValidation(int questionNumber);

void changePlayerSettings(struct Player *player) {
    printf("Change Settings:\n");

    bool validInput = false;
    while (!validInput) {
        printf("Enter Duration Mode (in minutes): ");
        scanf("%d", &player->settings.durationMode);
        if (DurationModeValidation(player->settings.durationMode)) {
            validInput = true;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    validInput = false;
    while (!validInput) {
        printf("Enter Difficulty Mode (1-Easy, 2-Medium, 3-Hard): ");
        scanf("%d", &player->settings.difficultyMode);
        if (DifficultyModeValidation(player->settings.difficultyMode)) {
            validInput = true;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    validInput = false;
    while (!validInput) {
        printf("Enter Number of Questions: ");
        scanf("%d", &player->settings.questionNumber);
        if (QuestionNumberValidation(player->settings.questionNumber)) {
            validInput = true;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    validInput = false;
    while (!validInput) {
        printf("Enter Question Duration (in seconds): ");
        scanf("%d", &player->settings.questionDuration);
        if (DurationModeValidation(player->settings.questionDuration)) {
            validInput = true;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
}
bool DurationModeValidation(int durationMode) {
    if (durationMode < 1 || durationMode > 60) {
        printf("Invalid Duration Mode. Please enter a value between 1 and 60.\n");
        return false;
    }
    return true;
}
bool DifficultyModeValidation(int difficultyMode) {
    if (difficultyMode < 1 || difficultyMode > 3) {
        printf("Invalid Difficulty Mode. Please enter a value between 1 and 3.\n");
        return false;
    }
    return true;
}
bool QuestionNumberValidation(int questionNumber) {
    if (questionNumber < 1 || questionNumber > 100) {
        printf("Invalid Number of Questions. Please enter a value between 1 and 100.\n");
        return false;
    }
    return true;
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

    printf("---------------------------------------------------\n");
    printf("Player Settings:\n");
    printf("  - Duration Mode: %d minutes\n", player->settings.durationMode);
    printf("  - Difficulty Mode: %d\n", player->settings.difficultyMode);
    printf("  - Number of Questions: %d\n", player->settings.questionNumber);
    printf("  - Question Duration: %d seconds\n", player->settings.questionDuration);
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
    if (firstTimePlayer(player)) {
        bool validName = false;
        while (!validName) {
            printf("Enter your name: ");
            scanf("%49s", player->name);
            if (nameValidation(player->name)) {
                validName = true; // Valid name, exit loop
            } else {
                printf("Invalid name. Please try again.\n");
            }
        }
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
    bool validName = false;
    while (!validName) {
        printf("Enter new player name: ");
        scanf("%49s", player->name);
        if (nameValidation(player->name)) {
            validName = true; // Valid name, exit loop
        } else {
            printf("Invalid name. Please try again.\n");
        }
    }
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

    updatePlayerScore(player, score);

    printf("You answered %d out of %d questions correctly.\n", correctAnswers, questionCount);
    printf("Your final score is: %d\n", score);

    updatePlayerData(player, score, player->settings);
}












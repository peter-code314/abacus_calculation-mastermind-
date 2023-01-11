#ifndef ABACUSCALCULATION_H_INCLUDED
#define ABACUSCALCULATION_H_INCLUDED

#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <string>
using namespace std;
class game_system {
public:
    void startGame() {
        PrintRules();
        RunGame();
    }
private:
    string guess, ans;
    int digit;
    void RunGame() {
        GetDigit();
        randomNumber();
        while (1) {
            int all = 0, half = 0;
            getInput();
            for (int i = 0; i < digit; ++i) {
                if (ans[i] == guess[i]) ++all;
                else {
                    for (auto j : guess) {
                        if (ans[i] == j) {
                            ++half;
                            break;
                        }
                    }
                }
            }
            if (all == digit)  {
                printf("Correct!");
                break;
            }
            else printf("%d%c%d\n", all, ' ', half);
        }
    }
    void PrintRules() {
        printf("                              MASTERMIND\n");
        printf("The rules of this game is:\n  1. The computer will randomly create a number.");
        printf("And every number in this number is different.\n");
        printf("  2. You will guess the number in each round, and the computer will give you two hints.\n");
        printf("The first number output is the number of numbers and positions guessed correctly");
        printf(", and the second number output is the number of numbers guessed correctly only.GoodLuck!\n");
    }
    void GetDigit() {
        printf("Please enter the digit of the number ");
        printf("that you want to challange in this round of 'MASTERMIND'(3 ¡ª 7):");
        while (1) {
            cin >> digit;
            if (digit <= 7 && digit >= 3) break;
            else printf("\nWrong input, please enter again\n");
        }
        printf("\n");
    }
    void randomNumber() {
        string choice = "123456789";
        srand(time(nullptr));
        int r = rand() % choice.size();
        ans += choice[r];
        choice.erase(r, 1);
        choice += '0';
        for (int i = 1; i < digit; ++i) {
            srand(time(nullptr));
            r = rand() % choice.size();
            ans += choice[r];
            choice.erase(r, 1);
        }
    }
    bool checkInput() {
        string comp = "";
        for (int i = 0; i < guess.size(); ++i) {
            if (count(comp.begin(), comp.end(), guess[i]) > 0) return false;
            else comp += guess[i];
        }
        return guess.size() == digit;
        return true;
    }
    void getInput() {
        while (1) {
            cin >> guess;
            if (checkInput()) break;
            else printf("Wrong input, please enter again:");
        }
    }
};

#endif // ABACUSCALCULATION_H_INCLUDED


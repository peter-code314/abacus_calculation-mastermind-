#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <string>
// you can use `#include <bits/stdc++.h>` insted
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
                puts("Correct!");
                break;
            }
            else printf("%d%c%d\n", all, ' ', half);
        }
    }
    void PrintRules() {
        puts("                              MASTERMIND");
        puts("The rules of this game is:\n  1. The computer will randomly create a number.");
        puts("And every number in this number is different.");
        puts("  2. You will guess the number in each round, and the computer will give you two hints.");
        puts("The first number output is the number of numbers and positions guessed correctly");
        puts(", and the second number output is the number of numbers guessed correctly only.GoodLuck!");
    }
    void GetDigit() {
        printf("Please enter the digit of the number that you want to challange in this round of 'MASTERMIND'(3 to 7):");
        while (1) {
            cin >> digit;
            if (digit <= 7 && digit >= 3) break;
            else puts("\nWrong input, please enter again");
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
            // you can uncomment the following line
            //srand(time(nullptr));
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

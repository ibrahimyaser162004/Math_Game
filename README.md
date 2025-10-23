# 🧮 Math Quiz Game

A console-based **Math Quiz Game** written in **C++**, where players can test their arithmetic skills through customizable quizzes.  
Choose your difficulty level and question type, then try to score as high as possible!  
At the end, you’ll receive a detailed performance summary with your results.

---

## 🧩 Features
- 🎯 **Customizable gameplay** — choose the number of questions, difficulty level, and type of arithmetic operation.  
- 🧠 **Four difficulty levels:** Easy, Medium, Hard, and Mix.  
- ➕➖✖️➗ **Five operation types:** Addition, Subtraction, Multiplication, Division, and Mix.  
- 💬 **Instant feedback** after each question.  
- 📊 **Final summary** showing total correct and wrong answers, question details, and overall result (Pass/Fail).  
- 🔁 **Replay option** — play again as many times as you like.  

---

## ⚙️ Technologies Used
- **Language:** C++
- **Libraries:** `<iostream>`, `<cstdlib>`, `<ctime>`
- **Concepts Used:** Enums, Structs, Randomization, Conditional Logic, Loops, Input Validation, and User Interaction.

---

## 🎮 Gameplay Overview

1. The program asks:
   - How many questions you want to answer  
   - The difficulty level: **Easy**, **Medium**, **Hard**, or **Mix**  
   - The question type: **Addition**, **Subtraction**, **Multiplication**, **Division**, or **Mix**

2. Each question is generated **randomly** based on your chosen difficulty and type.

3. The player inputs an answer and instantly receives feedback:
   - ✅ *Correct Answer :)*
   - ❌ *Wrong Answer :( The Correct Answer is X*

4. After completing all questions, the game displays:
   - Total number of questions  
   - Chosen difficulty level and operation type  
   - Count of correct and wrong answers  
   - Final result: **Pass** or **Fail**

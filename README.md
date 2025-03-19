
---

# 💣 **Text-Based Minesweeper Game in C**  

This project features a **text-based Minesweeper game** developed in **C** with a focus on efficient board generation, strategic mine placement, and an intuitive user interface. The game delivers a challenging yet fair experience by balancing randomness and playability.  

---

## 🎯 **Project Overview**  
🔹 Developed in **C** for optimized performance and low-level memory control.  
🔹 Focused on creating an engaging and challenging player experience through balanced mine distribution.  
🔹 Built with a clean and easy-to-use terminal interface for smooth gameplay.  

---

## 🛠️ **Core Features**
### 🧩 **Board Generation and Mine Placement**  
- Efficient algorithm for mine placement ensures a fair distribution of mines.  
- Dynamic board resizing supports various levels of difficulty.  

### 🖥️ **Game Display and Interface**  
- Clean terminal-based display for easy navigation.  
- Real-time updates when uncovering cells and marking mines.  

### ⚙️ **Game Mechanics**  
- Left-click to reveal a cell; right-click to mark a mine.  
- Automatically reveals adjacent empty cells for a smoother experience.  
- Game-over scenario upon revealing a mine.  

---

## 🌟 **Challenges and Solutions**  
✅ **Mine Placement:** Ensured balanced randomness without clustering mines together.  
✅ **Recursive Flood Fill:** Efficient handling of adjacent empty cell reveals using a recursive algorithm.  
✅ **UI Feedback:** Added clear indicators for flagged cells and mines to improve the user experience.  

---

## 📸 **Preview**  
Example gameplay:  
```  
   1 1 *  
   1 * 2  
   1 2 *  
```  

---

## 🚀 **Future Improvements**  
✅ Implement a timer to track game duration.  
✅ Add customizable board sizes and difficulty levels.  
✅ Include color-coded cells for improved visibility.  

---

## 🎮 **How to Play**  
1. Clone the repository:  
```bash
git clone https://github.com/yourusername/minesweeper.git
```
2. Compile the code:  
```bash
gcc -o minesweeper minesweeper.c
```
3. Run the game:  
```bash
./minesweeper
```

---

**Enjoy the game and feel free to contribute!**  

---

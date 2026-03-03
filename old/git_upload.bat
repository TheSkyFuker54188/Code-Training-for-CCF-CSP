@echo off
echo 正在上传实验目录到GitHub...

cd /d D:\

:: 1. 初始化Git仓库（如果还没有初始化）
if not exist ".git" (
  echo 初始化Git仓库...
  git init
)

:: 2. 添加要上传的文件（排除LabX_Flex&Yacc目录）
echo 添加文件到暂存区...
git add Lab1_git入门 Lab2_文法解读 Lab3_词法分析 Lab4_语法分析 Lab5_中间代码生成 Lab6_代码生成

:: 3. 提交更改
echo 提交更改...
git commit -m "上传编译原理实验文件"

:: 4. 检查远程仓库是否已连接，如果没有则添加
git remote -v | findstr "origin" > nul
if errorlevel 1 (
  echo 添加远程仓库...
  git remote add origin https://github.com/TheSkyFuker54188/Compilation-principle.git
)

:: 5. 推送到GitHub
echo 推送到GitHub...
git push -u origin master

echo 完成！
pause

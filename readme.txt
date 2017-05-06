该目录用于学习 C++
真正的程序员用的语言是C++，积极沉淀。
顺便学习 git 的命令行

Git 命令部分：
1. git init 用于新建一个仓库
2. git add  把文件添加到仓库
3. git commit 把文件提交到仓库  git commit -m “”  引号中是本次提交的描述，尽可能表达清晰
4. HEAD 指向的版本是当前版本，使用命令 git reset --hard commit_id
5. git log 查看提交历史， git reflog 查看命令历史，包括回退的命令。

Git 远程仓库

1. 先确保 已经生成了sshkey 放在主目录下 ~/.ssh 即可
2. 查看 公钥和私钥 ： cat ~/.ssh/id_rsa  cat ~/.ssh/id_rsa.pub
3. 将公钥放入github的账户中
4. 关联仓库 git remote add origin git@github.com:doudouapp/LearnCpp.git
5. 推送至仓库 git push -u origin master

Git 分支的创建和合并

1. 分支操作指令
   查看分支： git branch
   创建分支： git branch branchName
   切换分支： git checkout branchName
   创建并切换分支： git checkout -b branchName
   合并某分支到当前分支：git merge branchName
   删除分支：git branch -d branchName

2. 这是master上的修改

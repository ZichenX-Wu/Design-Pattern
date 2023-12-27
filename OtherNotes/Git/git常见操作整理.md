[toc]

# 1. branch

## 1.1 创建分支，并将该分支及其提交的代码推送至远程仓库

```bash

```



## 1.2 删除本地分支，同时删除远程仓库对应分支

```bash

```


## 1.3 合并分支




# 2. 保存修改 与 丢弃修改

## 2.1 




# 3. 版本回退(本地仓库/远程仓库)








# 4. merge



问题： git如何移动当前HEAD的位置到某一特定commit？如果我当前工作区已经有了一些修改，我在本次移动的过程中，这些修改是否会丢失?如果会丢失，我该怎么做才能不丢失?


要移动当前HEAD的位置到某一特定commit，可以使用git checkout命令加上commit的哈希值或分支名来实现。例如，要将HEAD移动到commit的哈希值为abc123的commit上，可以使用以下命令：

git checkout abc123
如果当前工作区有了一些修改，执行上述命令会导致这些修改丢失。为了不丢失这些修改，可以使用git stash命令将当前工作区的修改保存起来，然后再执行git checkout命令，最后再使用git stash apply命令将之前保存的修改恢复回来。

具体步骤如下：

执行git stash命令，将当前工作区的修改保存起来。

git stash
执行git checkout命令，将HEAD移动到目标commit上。

git checkout abc123
执行完成后，可以查看之前保存的修改，使用git stash list命令查看stash列表。

git stash list
如果需要将之前保存的修改恢复回来，可以使用git stash apply命令。

git stash apply
这样就可以在不丢失修改的情况下移动HEAD的位置到特定commit。


使用下面指令也可以完成HEAD的移动
git reset --hard <commit-ID>





# 实战操作

## 查看哪些commits在某一分支，但是不在另一个分支上

git log --no-merges dev_100 ^main

查看dev_100分支的没有merge的commits，同时这些commits并不在main分支上。


## 如何让




## 合并多个commit为1个commit的方法

[两种方法合并多个commit为一个_多个commit合成一个](https://blog.csdn.net/Spade_/article/details/108698036)


[Github PR 时合并多次提交的 git commits All In One](https://www.cnblogs.com/xgqfrms/p/16457911.html)


方法1：git reset --soft

1. 查看最早的commit之前的那个commit-ID (这个commit最终不会被合并的，也就是要合并的所有commits之外离它最近的，比它早的那个commit)

2. git reset --soft commit-ID

3. git add -u

4. git commit -m 'message'

5. git push --force [origin branchName]



方法2：git rebase

1. 查看要合并的所有commits中最早的commit (这个commit和方法1的commit不同哦！这个是合并的commit里最早的)

2. git rebase -i [commit-ID]
或者 git rebase -i HEAD~n
n是合并的commits的数量


此时会进入到commit信息的编辑页面，将除了第一个pick之外的所有pick改成fixup或者squash或者s。

可选步骤：git commit --amend --author="Zichen, Wu<zichenx.wu@intel.com>"
编辑一下合并的commit信息

3. git push --force [origin branchName]





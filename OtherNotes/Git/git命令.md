## git commit --amend

git commit --amend命令可以覆盖上一次的commit。它允许你修改上一次提交的提交信息或者修改文件，然后将这些修改追加到上一次的提交中，而不会增加新的提交。这样可以保持提交历史的整洁性，同时修改错误或者补充遗漏的内容。


## git cherry-pick

### cherry-pick的基本使用

git cherry-pick命令的作用，就是将指定的提交（commit）应用于其他分支。

```shell
git cherry-pick <commitHash>  # <commitHash> 就是每次commit时产生的Hash编号 (唯一性)
```

在执行完上面的命令后，就会将 `<commitHash>` 这一commit应用到当前分支。这会使得当前分支产生一个新的提交。*(需要注意的时，这次产生的新的提交的哈希值和 目标<commitHash>的值是不同的哦!)*


**• 举例**

代码仓库有master和feature两个分支。

```shell
    a - b - c - d   Master
         \
           e - f - g Feature
```

现在我们想**将提交f应用到master分支**。

```shell

git checkout master # 切换到master分支

git cherry-pick <f-Hash>    # 将f应用到master分支

```

在经过了上述的操作后，分支的状态变成如下:

```shell
    a - b - c - d - f   Master
         \
           e - f - g Feature
```

从上面可以看到，master分支的末尾增加了一个提交f。

git cherry-pick命令的参数，**不一定是提交的哈希值，分支名也是可以的**，表示转移该分支的**最新提交**。

```shell
git cherry-pick feature # 将feature分支的最近一次提交，转移到当前分支。
```

&emsp;

&emsp;

### cherry-pick转移多次提交










[git cherry-pick blog](https://ruanyifeng.com/blog/2020/04/git-cherry-pick.html)
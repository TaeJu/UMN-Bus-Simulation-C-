### Assessment for Lab 10

#### Total score: _100.0_ / _100_

Run on March 03, 14:54:12 PM.


### Necessary Files and Structure

+  _10_ / _10_ : Pass: Check that directory "labs" exists.

+  _10_ / _10_ : Pass: Check that directory "labs/lab10_advanced_git" exists.


### Git Usage

+  _10_ / _10_ : Pass: Run git ls-remote to check for existence of specific branch- Branch devel found

+ Pass: Checkout devel branch.



+ Pass: Run git ls-remote gather all branches in repo

		0570d484ef9997efea4fbd5e98b1959fb1b6ff0d	refs/heads/devel

		4847b10208da09cad5f8611f6ab9850704faaee3	refs/heads/fix/01-compilation-errors

		df1e8b8df2b952cadfa18f62b90ffddc4d9a8e79	refs/heads/fix/02-google-style-errors

		a51edef2da7bd294edaa585764cea171ab0fb515	refs/heads/master

		62a994c4c7337a8f6b3197d4b937f0d620ef7703	refs/heads/support-code



+  _10_ / _10_ : Pass: Checking for the correct number of branches

Sufficient branches found (found=2, required=2):

fix/01-compilation-errors

fix/02-google-style-errors


#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

		[TaeJu] 2020-03-02 (HEAD -> devel, origin/devel) updating 

		[TaeJu] 2020-03-02 updating 

		[TaeJu] 2020-03-02 updating 

		[TaeJu] 2020-03-02 updating 

		[TaeJu] 2020-03-02 updating 

		[TaeJu] 2020-03-02 (origin/fix/01-compilation-errors, fix/01-compilation-errors) updating 

		[TaeJu] 2020-03-02 Merge branch 'fix/02-google-style-errors' into devel 

		[TaeJu] 2020-03-02 (origin/fix/02-google-style-errors, fix/02-google-style-errors) uploading cpplint 

		[TaeJu] 2020-03-02 triggering feedback 

		[TaeJu] 2020-03-02 updating 

		[TaeJu] 2020-03-02 updating 

		[TaeJu] 2020-03-02 Merge branch 'support-code' 


		[TaeJu] 2020-03-02 Merge branch 'support-code' of github.umn.edu:umn-csci-3081-s20/csci3081-shared-upstream into support-code 


		[TaeJu] 2020-03-02 (origin/support-code) updating 

























		[TaeJu] 2020-02-27 updating 

		[TaeJu] 2020-02-27 updating 














		[TaeJu] 2020-02-24 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-s20/repo-leex9121 

		[TaeJu] 2020-02-24 adding lab8 



		[TaeJu] 2020-02-24 updating lab8 

		[TaeJu] 2020-02-24 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-s20/repo-leex9121 

		[TaeJu] 2020-02-24 updating lab8 




		[TaeJu] 2020-02-24 updating lab8 

		[TaeJu] 2020-02-24 Merge branch 'support-code' 

		[TaeJu] 2020-02-24 Merge branch 'support-code' of github.umn.edu:umn-csci-3081-s20/csci3081-shared-upstream into support-code 

		[TaeJu] 2020-02-24 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-s20/repo-leex9121 

































































































+  _5_ / _5_ : Pass: Check git commit history
Sufficient commits (found=25,required=4)


### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 2)

[OPEN issue #2] :  Google style errors [enhancement]

[OPEN issue #1] :  compilation error [bug]





+ Pass: Run ghi for total number of closed issues in Github repo (Found: 0)

+  _10.0_ / _10_ : Pass: Run ghi for total number of issues in Github repo (Found: 2, Expected: 2) 

 [OPEN issue #2] :  Google style errors [enhancement]

[OPEN issue #1] :  compilation error [bug]

[CLOSED issue #] : 

 




### Test that code on  devel compiles

+ Pass: Checkout devel branch.



+  _10_ / _10_ : Pass: Check that directory "project/src" exists.

+ Pass: Change into directory "project/src".

+  _5_ / _5_ : Pass: Check that file "makefile" exists.

+  _30_ / _30_ : Pass: Check that make compiles.



#### Total score: _100.0_ / _100_


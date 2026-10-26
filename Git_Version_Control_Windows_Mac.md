# Lab 00 — Git Version Control

## 1. What Is Version Control?

A **version control system (VCS)** tracks changes to files—usually source code—and helps developers combine work completed by different people at different times.

**Git** is a popular distributed version control system created by Linus Torvalds for development of the Linux kernel. With Git, a project can have a history of changes, and multiple copies of the project can be maintained and synchronized.

### Useful resources

- Git website: <https://git-scm.com/>
- Pro Git book: <https://git-scm.com/book>
- GitHub Guides: <https://guides.github.com/>
- GitHub Desktop: <https://desktop.github.com/>

Git is commonly used from a command-line terminal, but graphical applications such as **GitHub Desktop** provide an easier visual workflow.

## 2. GitHub Account and Privacy

GitHub hosts Git repositories online. Choose your username carefully because it is visible on your profile and can become part of your public professional presence.

**Important:** A repository's visibility depends on its settings. Check whether a repository is public or private before publishing code. Do not upload passwords, access tokens, private keys, or other sensitive information.

## 3. Install Git and GitHub Desktop

### Windows

1. Install Git for Windows from <https://git-scm.com/download/win>.
2. Optionally install GitHub Desktop from <https://desktop.github.com/>.
3. Open **Git Bash**, PowerShell, Windows Terminal, or GitHub Desktop to work with Git.
4. Check that Git is installed:

   ```bash
   git --version
   ```

### macOS

1. Install Git from <https://git-scm.com/download/mac>. Git may also be available through Apple's command-line developer tools or a package manager.
2. Optionally install GitHub Desktop from <https://desktop.github.com/>.
3. Open **Terminal** or GitHub Desktop.
4. Check that Git is installed:

   ```bash
   git --version
   ```

If the command is not found, install Git using one of the installation methods above and run the version check again.

## 4. Configure Your Git Identity

Git records a name and email address with commits. Set these to the identity you want associated with your work.

Run the following commands in a terminal on either Windows or macOS:

```bash
git config --global user.name "Your Name"
git config --global user.email "you@example.com"
```

Check the saved settings:

```bash
git config --global --list
```

### Configure the identity in GitHub Desktop

1. Open GitHub Desktop.
2. Open **Options** on Windows or **Settings** on macOS. The exact menu wording can vary by version.
3. Find the Git configuration section.
4. Set the name and email address used for commits.

If you use a shared computer, sign out of GitHub Desktop when you finish. On a shared lab computer, make sure the configured identity is yours.

## 5. Create a Local Repository with GitHub Desktop

A **repository** (or *repo*) is a project directory whose changes are tracked by Git.

1. Open GitHub Desktop.
2. Choose **File → New Repository** (menu wording may vary).
3. Enter a repository name, such as `hello-git-name`.
4. Choose the local folder where the project should be created.
5. Choose an appropriate `.gitignore` template for the language or tools used by the project, if available.
6. Create the repository.

Avoid spaces and unusual characters in repository names when possible. Use a clear, consistent name.

### The `.git` directory

After initializing a repository, Git creates a hidden `.git` directory. It stores repository metadata, configuration, references, and the history needed for version control. Do not manually edit or delete it unless you intentionally want to remove the repository's Git history.

### Publish the local repository to GitHub

A newly created repository may exist only on your computer. To publish it:

1. In GitHub Desktop, select **Publish repository**.
2. Sign in to GitHub if prompted.
3. Choose whether the repository should be public or private.
4. Confirm publication and wait for the upload to finish.
5. Open the repository on GitHub in a browser to verify that it exists.

## 6. The Basic Git Workflow

Git work generally follows this sequence:

1. **Edit** files in your project.
2. **Stage** the changes you want to include in the next snapshot.
3. **Commit** the staged changes to the local repository history.
4. **Push** commits to the remote repository, such as GitHub.

A **commit** is a recorded snapshot of staged changes. A **push** sends local commits to a remote repository.

### Using GitHub Desktop

1. Edit or create files in the project folder.
2. Return to GitHub Desktop. It detects changed files and shows a diff of the changes.
3. Review the changes.
4. Enter a short, descriptive summary in the commit message field.
5. Select **Commit to ...** to create the local commit.
6. Select **Push origin** to upload the commit to GitHub.
7. Check the repository page in your browser to confirm the changes were uploaded.

Commit messages should describe the change, for example:

- `Add README file`
- `Fix input validation`
- `Update project documentation`

A commit is local until it is pushed. Creating a commit alone does not upload it to GitHub.

## 7. Create and Edit a README File

A `README.md` file introduces the project and is commonly displayed on the repository's GitHub page. The `.md` extension means the file uses **Markdown**, a lightweight text-formatting syntax.

A useful README can include:

- Project name and purpose
- Author or contributors
- Tools, libraries, or environment used
- Setup or usage instructions
- Other relevant project information

You can create or edit `README.md` in a code editor, a plain-text editor, or directly on GitHub.com.

After editing it locally, stage and commit the change, then push it to GitHub.

## 8. Download and Synchronize Remote Changes

Changes made on GitHub or by collaborators must be brought into your local copy.

### In GitHub Desktop

1. Select **Fetch origin** to check for remote updates.
2. If updates are available, use the available pull option to download and integrate them. The exact labels depend on the current state of the repository.

### In the command line

```bash
git fetch
git pull
```

- `git fetch` downloads information about remote changes without automatically integrating them into your current branch.
- `git pull` fetches and integrates remote changes into the current branch.

Before starting work, synchronize your local branch when appropriate so that you are working with the latest shared changes.

## 9. Useful Git Commands

The following commands work in Git Bash, PowerShell, Windows Terminal, and macOS Terminal, provided Git is installed.

### Check repository status

```bash
git status
```

Shows the current branch and which files are modified, staged, or untracked.

### Stage changes

```bash
git add filename
```

Stages one file.

```bash
git add .
```

Stages changes under the current directory. Review `git status` before committing to ensure you are not including unwanted files.

### Commit staged changes

```bash
git commit -m "Describe the change"
```

Records staged changes in the local history.

### View commit history

```bash
git log
```

Shows previous commits and their details.

### Push commits to the remote repository

```bash
git push
```

Uploads local commits to the configured remote branch, when the upstream is already set.

### View remote repository settings

```bash
git remote -v
```

Shows the configured remote names and URLs.

## 10. Create a Repository from the Command Line

These steps can be used on Windows or macOS. On Windows, run them in **Git Bash** or another terminal where Git is available. The commands below use a shell that supports standard Unix-style commands such as `mkdir` and `cd`; Git Bash is a straightforward choice on Windows.

### Step 1: Create a project directory

```bash
mkdir my_project
cd my_project
```

### Step 2: Create or add project files

You can create files in your code editor and save them in the project directory.

To create a simple text file from a compatible shell:

```bash
echo "Some project notes" > notes.txt
```

To create an empty file in Git Bash or macOS Terminal:

```bash
touch README.md
```

**Windows note:** `touch` is not a standard PowerShell command. In PowerShell, an empty file can be created with:

```powershell
New-Item README.md -ItemType File
```

You can also create files through File Explorer (Windows) or Finder (macOS), or directly in your editor.

### Step 3: Initialize Git

Make sure the terminal is in the project directory, then run:

```bash
git init
```

This initializes a local Git repository.

### Step 4: Stage and commit the files

```bash
git add .
git commit -m "Initial commit"
```

If Git reports that your identity is not configured, complete the identity configuration described earlier and retry the commit.

### Step 5: Create a remote repository

1. Open GitHub in your browser and create a new repository.
2. Use the same project name, such as `my_project`.
3. If you already committed files locally, avoid initializing the remote with a separate README or other files unless you know how you want to combine the histories.
4. Copy the repository URL from GitHub.

### Step 6: Connect the local repository to GitHub

Replace the example URL with your own repository URL:

```bash
git remote add origin https://github.com/your-username/my_project.git
```

Check the connection:

```bash
git remote -v
```

### Step 7: Check or set the branch name

Display the current branch:

```bash
git branch --show-current
```

Rename the current branch to `main` if needed:

```bash
git branch -M main
```

### Step 8: Push the first commit

```bash
git push -u origin main
```

The `-u` option sets the upstream relationship so that later pushes and pulls can usually use the shorter commands `git push` and `git pull`.

Open the repository on GitHub and verify that the files are present.

## 11. Branches

A **branch** is an independent line of development. Branches let developers work on features or fixes without making every change directly on the main line of development.

### Common branch commands

Create a branch and switch to it:

```bash
git checkout -b new-feature
```

Switch to an existing branch:

```bash
git checkout main
```

Merge another branch into the branch currently checked out:

```bash
git merge new-feature
```

Delete a local branch after it has been merged:

```bash
git branch -d new-feature
```

Newer Git versions also support the `git switch` commands:

```bash
git switch -c new-feature
git switch main
```

**Important:** A merge combines changes from another branch into the current branch. Make sure you have checked out the branch that should receive the changes before running `git merge`.

## 12. Working with Collaborators

GitHub supports collaboration by allowing people to access a shared repository.

### Give a collaborator access

1. Open the repository on GitHub.com.
2. Open **Settings** and find the repository's access or collaborators section.
3. Invite the collaborator by their GitHub username or the method offered by GitHub.
4. The collaborator must accept the invitation if prompted.

Only grant access to people who should be able to work with the repository.

### Clone a collaborator's repository

**Cloning** creates a local copy of a remote repository, including its Git history.

In GitHub Desktop:

1. Choose **File → Clone Repository**.
2. Select the repository or provide its URL.
3. Choose a local path.
4. Clone the repository and open the local copy in your editor.

Or use the command line:

```bash
git clone https://github.com/username/repository.git
```

Replace the example URL with the actual repository URL.

### Share changes

A typical collaboration cycle is:

1. Pull or fetch the latest changes.
2. Edit files locally.
3. Stage and commit your changes.
4. Push your commits to the remote repository, if you have permission.
5. Pull the changes made by collaborators when needed.

If multiple people edit the same parts of a file, Git may report a **merge conflict**. Git cannot automatically decide which version should be kept in every conflict. Open the conflicted file, review the alternatives, edit it into the intended final version, then stage and commit the resolution.

## 13. `.gitignore`

A `.gitignore` file tells Git which untracked files or paths to ignore. It is useful for excluding generated files, local settings, build outputs, and other files that should not be version-controlled.

For example, a project may need to ignore editor-specific user settings or generated build files. The correct entries depend on the language, IDE, and operating system.

Example:

```gitignore
# Local Qt Creator user settings
*.pro.user

# Common generated directories
build/
```

A `.gitignore` rule does **not** automatically stop tracking a file that Git already tracks. If a file was committed earlier, remove it from the Git index while keeping the local copy:

```bash
git rm --cached filename
git commit -m "Stop tracking local configuration file"
```

Use the actual file path in place of `filename`. Check the resulting changes before pushing.

## 14. What Belongs in a Repository?

A repository should contain the files needed to understand, build, or maintain the project, such as:

- Source code
- README and other documentation
- Project or build configuration files needed by collaborators
- Small, appropriate assets required by the project
- Dependency or environment definitions when applicable

Files that are often inappropriate to commit include:

- Passwords, tokens, private keys, and other secrets
- Machine-specific editor settings
- Temporary files and generated build output
- Large compiled binaries when they are reproducible from source or better distributed separately

Whether to include `.exe`, `.bin`, archive files, or other generated artifacts depends on the project's purpose and distribution needs. Do not assume every binary or ZIP file is always forbidden; choose deliberately and follow the project's conventions. Use `.gitignore` to exclude files that should not be tracked.

## 15. Sign Out and Remove a Local Repository

On a shared computer, sign out of GitHub Desktop when finished. The location of the sign-out option varies by version; look in the account settings.

GitHub Desktop can also remove a repository from its local list. This usually removes the repository from the application list, not necessarily from your hard drive. Read the confirmation carefully.

Deleting a repository on GitHub is a separate and potentially irreversible action. Confirm that you no longer need it and that you have any required backup before deleting a remote repository.

## 16. Quick Reference

| Goal | Command |
|---|---|
| Check Git installation | `git --version` |
| Initialize a repository | `git init` |
| Check current changes | `git status` |
| Stage one file | `git add filename` |
| Stage changes in the current directory | `git add .` |
| Create a commit | `git commit -m "Message"` |
| View commit history | `git log` |
| List remote URLs | `git remote -v` |
| Download remote information | `git fetch` |
| Download and integrate remote changes | `git pull` |
| Upload commits | `git push` |
| Clone a repository | `git clone URL` |
| Show current branch | `git branch --show-current` |
| Create and switch to a branch | `git checkout -b branch-name` |
| Switch to a branch | `git checkout main` |
| Merge a branch into the current branch | `git merge branch-name` |
| Delete a merged local branch | `git branch -d branch-name` |

---

**Authors of the original lab material:** Michał Fularz, Tomasz Mańkowski, and Jakub Tomczyński.

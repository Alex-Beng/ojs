param (
    [string]$filePath,
    [string]$message
)

git add $filePath
$commitMessage = "leetcode $($filePath -replace '\..*$', '') $message"
git commit -m $commitMessage

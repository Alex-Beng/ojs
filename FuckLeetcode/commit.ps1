param (
    [string]$filePath,
    [string]$message
)

git add $filePath
$baseName = [System.IO.Path]::GetFileNameWithoutExtension($filePath)
$commitMessage = "leetcode $baseName $message"
git commit -m "$commitMessage"
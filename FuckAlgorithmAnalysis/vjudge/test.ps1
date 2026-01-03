function test {
    # 如果 $args 长度为0，那么就默认显示最近10条记录
    if ($args.Length -eq 0) {
        Write-Host "-----need file as args------"
        return
    }
    Write-Host "-----1. build------"
    g++ $args -o a.exe
    Write-Host "-----2. test------"
    Get-Content in.txt | ./a.exe
}
test $args

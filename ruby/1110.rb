n = gets.chomp.to_i
chk = []
ans = 0
while chk[n] == nil
    chk[n] = 1
    m = (n/10 + n%10) % 10
    n = (n%10)*10 + m
    ans += 1
end
puts ans

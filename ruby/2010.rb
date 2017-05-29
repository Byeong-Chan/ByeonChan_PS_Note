n = gets.chomp.to_i
ans = 1
while n > 0
    n -= 1
    tmp = gets.chomp.to_i
    ans += tmp - 1;
end
puts ans

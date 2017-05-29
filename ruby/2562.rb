n = 9
i = 0
ans = 0
while i < n
    i += 1
    tmp = gets.chomp.to_i
    if ans < tmp
        x = i
        ans = tmp
    end
end
puts ans
puts x

n = 8
ans = 0
while n > 0
    n -= 1
    sw = 0
    sw = 1 if n & 1 == 0
    k = 0
    x = gets.chomp
    x.scan(/\S/) do |letter|
        ans += 1 if (k&1) == sw && letter == 'F'
        k += 1
    end
end
puts ans

x = gets.chomp
ans = 0
x.scan(/\S+/) do |num|
    ans += (num.to_i) * (num.to_i)
end
ans %= 10
puts ans

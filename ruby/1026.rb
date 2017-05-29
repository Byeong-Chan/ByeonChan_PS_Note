x = []
y = []
n = gets.chomp.to_i
_in1 = gets.chomp
_in1.scan(/\d+/) do |num|
    x << num.to_i
end
_in2 = gets.chomp
_in2.scan(/\d+/) do |num|
    y << num.to_i
end
ans = 0
i = 0
x = x.sort.reverse
y = y.sort
while i < n
    ans += x[i] * y[i]
    i += 1
end
puts ans

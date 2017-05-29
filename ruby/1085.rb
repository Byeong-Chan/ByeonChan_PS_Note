k = []
_in = gets.chomp
_in.scan(/\S+/) do |num|
    k << num.to_i
end
y2 = k.pop
x2 = k.pop
y1 = k.pop
x1 = k.pop
min1 = 100000000
min1 = x1 if min1 > x1
min1 = y1 if min1 > y1
min1 = x2 - x1 if min1 > x2 - x1
min1 = y2 - y1 if min1 > y2 - y1
puts min1

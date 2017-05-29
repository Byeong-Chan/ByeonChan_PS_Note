x = gets.chomp
k = []
x.scan(/\S+/) do |num|
    k << num.to_i
end
c = k.pop
b = k.pop
a = k.pop
puts (a+b)%c
puts (a+b)%c
puts (a*b)%c
puts (a*b)%c

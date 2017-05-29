_in = gets.chomp
k = []
_in.scan(/\S+/) do |num|
    k << num.to_i
end
y = k.pop
x = k.pop
puts x+y
puts x-y
puts x*y
puts x/y
puts x%y

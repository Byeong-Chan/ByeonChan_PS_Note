ans = 1
_in = gets.chomp
_in.scan(/\S+/) do |num|
    ans *= num.to_i
end
puts ans

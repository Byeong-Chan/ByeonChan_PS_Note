n = gets.chomp.to_i
if n >= 90 && n <= 100
    puts "A"
    elsif n >= 80 && n <= 89
    puts "B"
    elsif n >= 70 && n <= 79
    puts "C"
    elsif n >= 60 && n <= 69
    puts "D"
    else
    puts "F"
end

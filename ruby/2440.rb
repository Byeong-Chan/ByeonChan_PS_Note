n = gets.chomp.to_i
while n > 0
    i = n;
    n -= 1;
    while i > 0
        print "*"
        i -= 1
    end
    print "\n"
end

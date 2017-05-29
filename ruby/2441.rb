n = gets.chomp.to_i
k = 0
while n > 0
    i = k
    k += 1
    while i > 0
        print " "
        i -= 1
    end
    i = n
    while i > 0
        print "*"
        i -= 1
    end
    n -= 1
    print "\n"
end

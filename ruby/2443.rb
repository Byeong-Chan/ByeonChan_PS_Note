n = gets.chomp.to_i
k = 0
while n > 0
    i = k
    while i > 0
        i -= 1
        print " "
    end
    k += 1
    i = n
    while i > 0
        i -= 1
        print "*"
    end
    n -= 1
    i = n
    while i > 0
        i -= 1
        print "*"
    end
    print "\n"
end

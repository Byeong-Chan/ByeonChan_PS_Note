n = gets.chomp.to_i
dt = Array.new(1010) {Hash.new}
for i in 0..n-1
    k = []
    x = gets.chomp
    x.scan(/\S+/) do |num|
        k << num.to_i
    end
    b = k.pop
    g = k.pop
    r = k.pop
    dt[i][0] = r
    dt[i][1] = g
    dt[i][2] = b
    if i > 0
        dt[i][0] += dt[i-1][1] > dt[i-1][2] ? dt[i-1][2] : dt[i-1][1]
        dt[i][1] += dt[i-1][0] > dt[i-1][2] ? dt[i-1][2] : dt[i-1][0]
        dt[i][2] += dt[i-1][0] > dt[i-1][1] ? dt[i-1][1] : dt[i-1][0]
    end
end
ans = dt[n-1][0]
ans = ans > dt[n-1][1] ? dt[n-1][1] : ans;
ans = ans > dt[n-1][2] ? dt[n-1][2] : ans;
puts ans

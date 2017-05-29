ans = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]
mtoday = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334]
x = gets.chomp
k = []
x.scan(/\S+/) do |num|
    k << num.to_i
end
day = k.pop
month = k.pop
allday = mtoday[month-1]
allday += (day-1)
print ans[allday%7]

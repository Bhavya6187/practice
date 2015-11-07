
maxim = 0;
ones = ["zero","one","two","three","four","five","six","seven","eight","nine","ten"]
tens = ["twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]
teens = ["eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]

summation = 0
for i in range(1,1000):
    string = ""
    if i <= 10:
        string = ones[i]
    if i > 10 and i < 20:
        string = teens[i-11]
    if i >=20 and i < 100:
        string  = tens[i/10 - 2]
        if(i%10 != 0):
            string = string + "" + ones[i%10]
    if i >= 100:
        string = ones[i/100] + "" + "hundred"
        j = i%100;
        if(j != 0):
            string = string + "" + "and" + ""
            if j <= 10:
                string  = string + "" + ones[j]
            if j > 10 and j < 20:
                string  = string + "" + teens[j-11]
            if j >=20:
                string  = string + "" + tens[j/10 - 2]
                if(j%10 != 0):
                    string = string + "" + ones[j%10]
    summation += len(string)

print summation + 11 #for thousand
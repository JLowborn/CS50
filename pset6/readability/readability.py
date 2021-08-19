# Index = 0.0588 * L - 0.296 * S - 15.8
# L = Letters ÷ Words × 100 = 639 ÷ 119 × 100 ≈ 537
# S = Sentences ÷ Words × 100 = 5 ÷ 119 × 100 ≈ 4.20

from cs50 import get_string


phrase = get_string("Text: ")
letters = 0
words = 0
sentences = 0

for i in range(len(phrase)):

    if phrase[i].isalpha():
        letters += 1

    if phrase[i].isalpha() and phrase[i - 1].isspace() or phrase[i - 1].isalpha == False:
        words += 1

    if phrase[i] in ['!','?','.']:
        sentences += 1

print(f"{letters} letters\n{words} words\n{sentences} sentences\n")

lAverage = float((letters / words) * 100)
sAverage = float((sentences / words) * 100)
index = (0.0588 * lAverage) - (0.296 * sAverage) - 15.8

if index < 1:
    print("Before Grade 1\n")
elif index > 16:
    print("Grade 16+\n")
else:
    print(f"Grade {index}")

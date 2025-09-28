scores = []
for i in range(3):
    scores.append(int(input(f"Score {i+1}: ")))

avarage = sum(scores) / len(scores);
print(f"Avarage: {avarage}")

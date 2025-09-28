from PIL import Image, ImageFilter

before = Image.open("courtyard.bmp")
after = before.filter(ImageFilter.BoxBlur(5))
after.save("new.bmp")

import csv

from cs50 import SQL

open("shows.db", "w").close()

db = SQL("sqlite:///shows.db")

db.execute("CREATE TABLE shows (id INTEGER, title TEXT, PRIMARY KEY(id))")
db.execute("CREATE TABLE genres (shows_id INTEGER, genres TEXT, FOREIGN KEY(shows_id) REFERENCES shows(id))")

with open("Favorite TV Shows - Form Responses 1.csv", "r") as file:
   reader = csv.DictReader(file)
   for row in reader:
      title = row["title"].strip().upper()
      id = db.execute("INSERT INTO shows (title) VALUES(?)", title)
      for genre in row["genres"].split(", "):
         db.execute("INSERT INTO genres (shows_id, genres) VALUES(?,?)", id, genre)



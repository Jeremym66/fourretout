import redis
from flask import Flask, render_template, request

from student import Student

app = Flask(__name__)

conn = redis.Redis(host="redis", port=6379, db=0)
try:
    conn.ping()
except redis.exceptions.ConnectionError as err:
    raise err


@app.route("/", methods=["GET"])
def index():
    return render_template("index.html")


@app.route("/handle_data", methods=["POST"])
def handle_data():
    stud = Student(request, conn)
    stud.get_values()
    err = stud.record_student()
    if err:
        return render_template("error.html")
    results = stud.get_all_students()
    return render_template("result.html", results=results)


if __name__ == "__main__":
    app.run("0.0.0.0", 5000)

app.run()

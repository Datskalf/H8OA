from flask import Flask, request, render_template

import Lib.H8OA as H8OA

controller = H8OA.H8OA()
app = Flask(__name__)

@app.route("/control")
def control() -> str:
    return render_template("control.html")

@app.route("/instruction", methods=["POST"])
def handle_instruction() -> str:
    if request.is_json:
        data = request.json
        controller.handle_command(data)
        return "Accepted"
    return "Incorrect Content-Type"


if __name__ == "__main__":
    app.run(debug=True)
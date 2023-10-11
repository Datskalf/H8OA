#!/usr/bin/python3

from flask import Flask, request, render_template, Response

import Lib.H8OA as H8OA

controller = H8OA.H8OA()
app = Flask(__name__)


@app.route("/control")
def control() -> Flask:
    return render_template("control.html")


@app.route("/instruction", methods=["POST"])
def handle_instruction() -> Response:
    if request.is_json:
        data = request.json
        controller.handle_command(data)
        return Response("Accepted", status=200)
    return Response("Incorrect Content-Type", status=406)


if __name__ == "__main__":
    app.run(debug=True)

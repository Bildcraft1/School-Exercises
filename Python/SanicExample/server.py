from sanic import Sanic
from sanic.response import text
from sanic.response import file
# seed the pseudorandom number generator
from random import seed
from random import random
seed(55461)

app = Sanic("Carta-Canta")


@app.get("/")
async def handler(request):
    return await file("public_html/index.html")


@app.get("/<path:path>")
async def path_handler(request, path):
    return await file("public_html/" + path)


@app.get("/api/time")
async def time_handler(request):
    return text("CasaOS " + str(random()))

@app.get("/api/las")
async def las_handler(request):
    return text("LAS-PC8")
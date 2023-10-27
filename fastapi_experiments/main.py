from fastapi import FastAPI

app = FastAPI()

@app.get('/')
async def root():
  return {'message', 'hello from fastapi :)'}


# This works for both ints and floats!!!
@app.get('/items/4')
async def read_my_item():
  print(f'I got exact item id')
  # without explicitly converting it, this will actually return int!!!
  # is this expected?
  return {'my_item_id': 4}

# This works for both ints and floats!!!
@app.get('/items/{item_id}')
async def read_my_item(item_id: float):
  print(f'I got item id {item_id}')
  # without explicitly converting it, this will actually return int!!!
  # is this expected?
  return {'my_item_id': float(item_id)}

# we cannot do this
# @app.get('/items/{item_id}')
# async def read_my_float_item(item_id: float):
#   return {'my_float_item_id': item_id}
from enum import Enum
class ModelName(str, Enum):
  alexnet = 'alexnet'
  resnet = 'resnet'
  lenet = 'lenet'

@app.get('/models/{model_name}')
async def get_model(model_name: ModelName):
  if model_name is ModelName.alexnet:
    return {'model': model_name, 'message': 'deep learning ftw'}
  elif model_name == ModelName.lenet:
    return {'model': model_name, 'blah': 'blah blah'}
  else:
    return {'boo' : 'yeah'}

# This shows how query parameters can be used
fake_items_db = [{"item_name": "Foo"}, {"item_name": "Bar"}, {"item_name": "Baz"}]

# INFO:     127.0.0.1:45024 - "GET /get_items/?skip=1 HTTP/1.1" 200 OK
# INFO:     127.0.0.1:45026 - "GET /get_items/?skip=1&limit=1 HTTP/1.1" 200 OK
@app.get('/get_items/')
async def read_items(skip: int = 0, limit: int = 10):
  return fake_items_db[skip: skip + limit]

# we can have an optional query param along with path param
from typing import Union
@app.get('/echo/{id}')
async def echo(id: str, q: Union[str, None] = None):
  if q:
    return {'item': id, 'q': q}
  return {'item': id}

# boolean query param works with many variations
# short=True, short=true
# short=1, short=yes, short=on and all case variations of these...same for
# negative i.e. no, false, 0 etc
@app.get('/describe')
async def describe(short: bool = False):
  if short:
    return {'description': 'a short message'}
  return {'description': 'this is a much more detailed message'}

# use pydantic for posting
from pydantic import BaseModel
import logging as L

L.basicConfig(level=L.DEBUG)

class Item(BaseModel):
  name: str
  description: Union[str, None] = None
  price: float
  tax: Union[float, None] = None

@app.post('/items/')
async def create_item(item: Item):
  L.debug(f'posting for {item}')
  return item
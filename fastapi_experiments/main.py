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
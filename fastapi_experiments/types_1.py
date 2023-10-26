from datetime import datetime
from typing import Union

from pydantic import BaseModel

class User(BaseModel):
  id: int
  name: str = 'alice bob'
  signup_ts: Union[datetime, None] = None
  friends: list[int] = []

external_data = {
  "id": "123",
  "signup_ts": '2017-06-01 12:22',
  'friends': [1, '2', b'3'], 
}

user = User(**external_data)
print(user)

print(user.id)

from typing import Annotated
def say_hello(name: Annotated[str, 'this is some metadata']) -> str:
  return f'Hello there {name}'

print(say_hello('timmy'))

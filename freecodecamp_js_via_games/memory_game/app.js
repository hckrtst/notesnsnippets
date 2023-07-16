const cardArray = [
  {
    name: 'fries',
    img: 'https://raw.githubusercontent.com/kubowania/memory-game/bc1f74499a7777797c4df2d4f943ca1ca2d346fb/images/fries.png'
  },
  {
    name: 'cheeseburger',
    img: 'https://github.com/kubowania/memory-game/blob/bc1f74499a7777797c4df2d4f943ca1ca2d346fb/images/cheeseburger.png?raw=true'
  },
  {
    name: 'hotdog',
    img: 'https://github.com/kubowania/memory-game/blob/bc1f74499a7777797c4df2d4f943ca1ca2d346fb/images/hotdog.png?raw=true'
  },
  {
    name: 'icecream',
    img: 'https://github.com/kubowania/memory-game/blob/bc1f74499a7777797c4df2d4f943ca1ca2d346fb/images/ice-cream.png?raw=true'
  },
  {
    name: 'milkshake',
    img: 'https://github.com/kubowania/memory-game/blob/bc1f74499a7777797c4df2d4f943ca1ca2d346fb/images/milkshake.png?raw=true'
  },
  {
    name: 'pizza',
    img: 'https://github.com/kubowania/memory-game/blob/bc1f74499a7777797c4df2d4f943ca1ca2d346fb/images/pizza.png?raw=true'
  }
]
cardArray.sort(() => 0.5 - Math.random())

const gridDisplay = document.querySelector('#grid')

function createBoard() {
  for (let i = 0; i < 10; ++i) {
    const card = document.createElement('img')
    card.setAttribute('src', cardArray[i]['img'])
    gridDisplay.appendChild(card)
  }
}

createBoard()
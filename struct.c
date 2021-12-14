
typedef struct Pokemons {
    char name[50];
    int hp;
    int dificulty;
    int rarity;
    int ketangkep;
}Pokemon;


 const Pokemon Bulbasaur={
	"Bulbasaur",10,1,100,0	
};

const  Pokemon Charmander={
	"Charmander",10,10,150,0
};
const  Pokemon Squirtle={
	"Squirtle",10,10,170,0
};
const  Pokemon Caterpie={
	"Caterpie",10,10,200,0
};

const Pokemon Rattata={
	"Rattata",10,10,300,0
};
 const  Pokemon Pidgey={
	"Pidgey",10,20,150,0
};
const Pokemon Kyogre={
	"Kyogre",10,1,40,0
};
const Pokemon Pikachu={
	"Pikachu",10,2,80,0
};
const Pokemon Rayquaza={
	"Rayquaza",10,1,30,0
};
const  Pokemon Mewtwo={
	"Mewtwo",10,1,20,0
};

struct ball{
	char nama[20];
	int harga;
	int power;
	int inventory;
};


struct ball pokeball[4] = {
		{.nama = "Pokeball", .harga = 500, .power=2, .inventory=30},
		{.nama = "Greatball", .harga = 600, .power=5, .inventory=20},
		{.nama = "Ultraball", .harga = 800, .power=10, .inventory=10},
		{.nama = "Masterball", .harga = 90000,.power=50, .inventory=5}
	};

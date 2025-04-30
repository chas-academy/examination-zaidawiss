// Elevdata – du kan ändra här om du vill testa andra värden
const elever = [
    { namn: "alice", prov: [8, 9, 7, 6, 10, 9, 8, 7, 10, 10, 9, 10, 8] },
    { namn: "bob", prov: [10, 10, 6, 4, 5, 6, 5, 5, 4, 6, 5, 5, 4] },
    { namn: "charlie", prov: [3, 9, 9, 1, 10, 9, 9, 10, 9, 10, 10, 9, 10] },
    { namn: "david", prov: [10, 10, 5, 4, 4, 5, 4, 5, 4, 3, 5, 4, 4] },
    { namn: "eve", prov: [9, 6, 7, 8, 7, 6, 7, 7, 6, 7, 8, 7, 6] }
];

const NUM_PROV = 13;
const NUM_ELEVER = elever.length;

// Räkna ut medelpoäng för varje elev
elever.forEach(elev => {
    let summa = elev.prov.reduce((a, b) => a + b, 0);
    elev.medel = summa / NUM_PROV;
});

// Funktion som gör första bokstaven stor
function tillVersal(namn) {
    return namn.charAt(0).toUpperCase() + namn.slice(1).toLowerCase();
}

// Hitta eleven med högst medel
let maxElev = elever.reduce((bäst, nuvarande) =>
    nuvarande.medel > bäst.medel ? nuvarande : bäst
);
if (elever.length === 0) {
    console.log("No students available.");
    return;
}

// Skriv ut den med högst medel
console.log(tillVersal(maxElev.namn));

// Räkna ut totalmedel
let totalMedel = elever.reduce((summa, e) => summa + e.medel, 0) / NUM_ELEVER;

// Skriv ut elever med lägre än gruppmedel
elever.forEach(elev => {
    if (elev.medel < totalMedel) {
        console.log(tillVersal(elev.namn));
    }
});

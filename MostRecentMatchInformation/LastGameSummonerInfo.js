const riotKey = '##########################################';
const sp = '%20';
const fetch = require('node-fetch');
const prompt = require('prompt-sync')();

main();

async function main() {
    const summoner = prompt("What is your summoner name? ");
    const summInfo = await fetchSummByName(summoner);
    const matches = await getMatchList(summInfo.puuid);

    for (let i = 0; i < 1; i++) {
        const match = await getMatchInfo(matches[i]);
        timestamp = match.info.gameCreation;
        const date = new Date(timestamp).toLocaleDateString('en-US');
        console.log("This game played was on: " + date);
        let summoners = match.info.participants;
        
        r = summoners.map(r => {
            return {
                //"Team": r.teamId,
                "Summoner Name": r.summonerName,
                "Champion Name": r.championName,
                "Kills": r.kills,
                "Deaths": r.deaths,
                "Assists": r.assists,
                "Dmg Dealt to Champs": r.totalDamageDealtToChampions
            }
        })

        const teamBlue = r.slice(0, 5);
        const teamRed = r.slice(5);
        
        console.log("--------------------------------------------Blue Team-------------------------------------------")
        console.table(teamBlue);
        console.log("-----------------------------------------------VS-----------------------------------------------")
        console.table(teamRed);
        console.log("--------------------------------------------Red Team--------------------------------------------")
                
    }
}

async function getMatchInfo(matchId) {
    const link = `https://americas.api.riotgames.com/lol/match/v5/matches/${matchId}?api_key=${riotKey}`;
    let response = await fetch(link);
    response = await response.json();
    return response;
}

async function getMatchList(puuid, startTime, endTime, queue, type, start=0, count=5) {
    let link = 'https://americas.api.riotgames.com/lol/match/v5/matches/by-puuid/' + await puuid + '/ids?';
    if (startTime != null)
        link += 'startTime=' + startTime + '&';
    if (endTime != null)
        link += 'endTime=' + endTime + '&';
    if (queue != null)
        link += 'queue=' + queue + '&';
    if (type != null)
        link += 'type=' + type + '&';
    if (start != null)
        link += 'start=' + start + '&';
    if (count != null)
        link += 'count=' + count + '&';
    link += "api_key=" + riotKey;

    let response = await fetch(link);
    response = await response.json();
    return response;
}

async function fetchSummByName(name) {
    while (name.includes(" ")) {
        let spaceSpot = name.indexOf(" ");
        name = name.substring(0, spaceSpot) + sp + name.substring(spaceSpot + 1);
    }

    const link = `https://na1.api.riotgames.com/lol/summoner/v4/summoners/by-name/${name}?api_key=${riotKey}`
    const response = await fetch(link);

    let data = await response.json();
    return data;
}
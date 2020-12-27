/*
 Georgs Toliašvili, gt20010
 */
var tbl = document.createElement('table');

window.addEventListener('DOMContentLoaded', (event) => { // execute the code when the initial HTML document has been completely loaded, we need the continent select to be loaded 

	var lookup = {};

	for (let i in data) { // for every item in the data - every piece of statistic info
		let continent = data[i].continentExp; // read continent from data
		let country = data[i].countriesAndTerritories; // read country from data
		if (continent && !(continent in lookup)) { // if the continet hasn't been previously processed
			lookup[continent] = {}; // add a new continent to the lookup
		}
		lookup[continent][country] = 1; // add a country to the lookup. lookup is a two-dimensional associative array/object
	}

	//console.log(lookup); // uncomment this line if you want to see the result in the console


	// now let's get continents for the first select element
	var continents = Object.keys(lookup).sort(); // get the list of keys in the lookup and sort it

	//console.log(continents); // uncomment this line if you want to see the result in the console

	let continent_s = document.getElementById("continent-select"); // get continent select element
	
	for (let i in continents) { // for every continent
		let opt = document.createElement('option'); // create a new option		
		opt.innerHTML = continents[i]; // fill the text with the continent name
		opt.value = continents[i]; // fill the value with the continent name
		continent_s.appendChild(opt); // add newly created option to the continent select
	}
	
	// to get countries for the first continent and sort it
	var countries = [];

	for (let x in continents) {
		let countryInCont = Object(lookup[continents[x]]);
		let keysFromArr = Object.keys(countryInCont);

		for (let y in keysFromArr)
		{
			countries.push(keysFromArr[y]);
		}
	}

	countries.sort();

	// if you need to process countries in the loop, use loop counter instead of index 0

	//console.log(countries); // uncomment this line if you want to see the result in the console
	
	// write your code to fill the countries select element

	let country_s = document.getElementById("country-select"); // get continent select element

	let firstOpt = document.createElement('option'); // create a new option		
	firstOpt.innerHTML = "All"; // fill the text with the continent name
	firstOpt.value = "All";
	country_s.appendChild(firstOpt);

	for (let i in countries) { // for every continent
		let opt = document.createElement('option'); // create a new option		
		opt.innerHTML = countries[i]; // fill the text with the continent name
		opt.value = countries[i]; // fill the value with the continent name
		country_s.appendChild(opt); // add newly created option to the continent select
	}

	let showListButton =  document.getElementById("show-list");
	showListButton.setAttribute("onclick", "getInputValues();");

	document.addEventListener('input', function (event) {
        if (event.target.id == "continent-select")
        {
			let newCountry_S = document.getElementById("country-select");

			for (let z = newCountry_S.options.length; z > 0; z--)
			{
				newCountry_S.remove(z);
			}

			if (event.target.value)
			{
				let countryInCont;
				let keysFromArr;

				for (let x = 0; x < Object.keys(lookup).length; x++)
				{
					if(event.target.value == continents[x])
					{
						countryInCont = Object(lookup[continents[x]]);
						keysFromArr = Object.keys(countryInCont);
	
						for (let y = 0; y < keysFromArr.length; y++) 
						{
							let opt = document.createElement('option');	
							opt.innerHTML = keysFromArr[y];
							opt.value = keysFromArr[y];
							newCountry_S.appendChild(opt); 
						}					
					}
				}
			}else
			{
				for (let y = 0; y < countries.length; y++) 
				{
					let opt = document.createElement('option');	
					opt.innerHTML = countries[y];
					opt.value = countries[y];
					newCountry_S.appendChild(opt); 
				}	
			}
        }
    
    }, false);

});

function getInputValues () 
{
	let contSelect = document.getElementById("continent-select").value;
	let countrySelect = document.getElementById("country-select").value;
	let dateFromInput = document.getElementById("date-from").value;
	let dateUntilInput = document.getElementById("date-until").value;

	let newDate = [];
	let newCountry = [];
	let newCases = [];
	let newDeaths = [];
	let newCumulative = [];

	let startDate = new Date("2020", "9", "1"); // month 0-11
	let currentDate = new Date();

	let dateFI = new Date(dateFromInput.split("-"));
	let dateUI = new Date(dateUntilInput.split("-"));
	let dateFromData;

	let button = document.getElementById("show-list");

	if (((dateFI.getTime() >= startDate.getTime() && dateFI.getTime() <= currentDate.getTime() && (dateFI.getTime() <= dateUI.getTime() || !dateUntilInput)) || !dateFromInput)
		&& ((dateUI.getTime() >= startDate.getTime() && dateUI.getTime() <= currentDate.getTime()) || !dateUntilInput))
	{
		button.innerHTML = "Show list";

		for (let x in data) {
			dateFromData = new Date(data[x].year, data[x].month - 1, data[x].day);
	
			if((contSelect == data[x].continentExp || !contSelect)
				&& (countrySelect == data[x].countriesAndTerritories || (!countrySelect || countrySelect == "All"))
				&& (dateFI.getTime() <= dateFromData.getTime() || !dateFromInput)
				&& (dateUI.getTime() >= dateFromData.getTime() || !dateUntilInput)) 
			{
				newDate.push(data[x].dateRep);
				newCountry.push(data[x].countriesAndTerritories);
				newCases.push(data[x].cases);
				newDeaths.push(data[x].deaths);
				newCumulative.push(data[x]['Cumulative_number_for_14_days_of_COVID-19_cases_per_100000']);
			}
		}

		tableCreate(newDate, newCountry, newCases, newDeaths, newCumulative);
	}else 
	{
		button.innerHTML = "Incorrect dates entered";
	}
}

function tableCreate(date, country, cases, deaths, cumulative) {
	tbl.remove();
	tbl = document.createElement('table');
	let body = document.getElementsByTagName('body')[0];
	tbl.style.width = '100%';
	tbl.setAttribute('border', '1');
	let tbdy = document.createElement('tbody');
	
	let headerNames = ["Date", "Country", "Cases", "Deaths", "Cumulative number for 14 days of COVID-19 cases per 100000"];

	for (let i = 0; i < date.length + 1; i++) {
		let tr = document.createElement('tr');
		  
		if (i == 0)
		{
			for (let x = 0; x < headerNames.length; x++)
			{
				let th = document.createElement('th');
				th.innerHTML = headerNames[x];
				tr.appendChild(th);
			}		
		}else {
			let index = i - 1;

			for (let j = 0; j < headerNames.length; j++) {
				let td = document.createElement('td');

				switch(j) {
					case 0:
						td.innerHTML = date[index];
						break;
					case 1:
						td.innerHTML = country[index];
						break;
					case 2:
						td.innerHTML = cases[index];
						break;
					case 3:
						td.innerHTML = deaths[index];
						break;
					case 4:
						td.innerHTML = cumulative[index];
						break;
				}
				
				tr.appendChild(td);
			}	
		}
		  
	  	tbdy.appendChild(tr);
	}
	
	tbl.appendChild(tbdy);
	body.appendChild(tbl)
}

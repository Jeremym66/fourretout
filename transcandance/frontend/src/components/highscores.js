export function get_highscores() {
	// remove the previous table or error message
	let leaderboardContent = document.getElementById('leaderboard-content');
	while (leaderboardContent.firstChild) {
		leaderboardContent.firstChild.remove();
	}

	fetch('api/highscores/')
		.then(response => {
			if (!response.ok) {
				throw new Error(`HTTP error! status: ${response.status}`);
			}
			return response.json();
		})
		.then(data => {
			let nb_row = 0;
			let table = document.createElement('table');
			let header = document.createElement('tr');
			['', 'Score', 'Player', 'Total games', 'Won / Lost'].forEach(key => {
				let cell = document.createElement('th');
				cell.textContent = key;
				header.appendChild(cell);
			});
			table.appendChild(header);

			data.forEach(item => {
				let row = document.createElement('tr');


				let imgCell = document.createElement('td');
				let img = document.createElement('img');
				imgCell.appendChild(img);
				row.appendChild(imgCell);

				if (item['image_link'])
					img.src = item['image_link'];
				else
					img.src = "assets/anonymous-icon.png";

				['score', 'login', 'total_games'].forEach(key => {
					let cell = document.createElement('td');
					cell.textContent = item[key];
					row.appendChild(cell);
				});

				// put the ratio bar in the last cell
				let ratioCell = document.createElement('td');
				let progressBarContainer = document.createElement('div');
				progressBarContainer.id = 'progress-bar'; // Utilisez le style CSS pour #progress-bar
				let progressBar = document.createElement('div');
				progressBar.id = 'win-games'; // Utilisez le style CSS pour #win-games
				let winGame = item['win_games'];
				let totalGame = item['total_games'];
				if (winGame > totalGame) {
					totalGame = winGame;
				}
				let winRatio = winGame / totalGame * 100;
				progressBar.style.width = winRatio + '%'; // Mettez à jour la largeur en fonction du pourcentage de jeux gagnés
				progressBarContainer.appendChild(progressBar);
				ratioCell.appendChild(progressBarContainer);
				row.appendChild(ratioCell);

				table.appendChild(row);
			});

			leaderboardContent.appendChild(table);
		})
		.catch(error => {
			console.error('Error:', error);
			let errorMessage = document.createElement('p');
			errorMessage.textContent = "Une erreur est survenue lors de la récupération des scores élevés.";
			leaderboardContent.appendChild(errorMessage);
		});
}

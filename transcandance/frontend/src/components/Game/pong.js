import { draw_game_menu, draw_ingame_menu, draw_endgame_menu } from './pong_menu.js';

document.addEventListener("DOMContentLoaded", function () {

	// RECUP DES INFOS JOUEUR

	

	function get_player_infos() {
		$.ajax({
			url: '/api/get-session/',  // URL of your Django view
			type: 'GET',
			success: function(data) {
				if (data.error){
					console.log("Error: ", data.error);
					return;
				}
	
				canvas.dataset.playerOne = data.user;
	
			},
			error: function(error) {
				console.error('Error retrieving session data:', error);
			}
		});
	}

	// get_player_infos();

	//CONSTANTES

    const canvas = document.getElementById("pongCanvas");
    const ctx = canvas.getContext("2d");
	let playerOneName = canvas.dataset.playerOne || "Player One";
	let playerTwoName = canvas.dataset.playerTwo || "Player Two";

	get_player_infos();
    const winnerImage = document.getElementById("winnerImage");
    const looserImage = document.getElementById("looserImage");
    const pongImage = document.getElementById("pongImage");
	const vsbutton = document.getElementById("vs-btn");
	const aibutton = document.getElementById("ai-btn");
	const modbutton = document.getElementById("mod-btn");
	const tourbutton = document.getElementById("tour-btn");
	const startbutton = document.getElementById("start-btn");
	const pausebutton = document.getElementById("pause-btn");
	const quitbutton = document.getElementById("quit-btn");
	const quit2button = document.getElementById("quit2-btn");
	const newgamebutton = document.getElementById("ng-btn");

	const paddleWidth = canvas.width / 40, paddleHeight = canvas.height / 6;
    const paddleSpeed = 4;
	const ballspeedmax = 4;
	const keyState = {};
	const brickRows = 10; // Nombre de lignes de briques
    const brickCols = 8; // Nombre de colonnes de briques
    const brickWidth = canvas.width / 60; // Largeur des briques
    const brickHeight = canvas.height / 20; // Hauteur des briques
    const brickPadding = canvas.height / 60; // Espace entre les briques
    const brickOffsetTop = canvas.height * 1 / 5; // Marge supérieure des briques
    const brickOffsetLeft = (canvas.width - (brickCols * (brickWidth + brickPadding))) / 2; // Marge gauche des briques
    const brickColors = ["#D35400", "#E67E22", "#F39C12", "#E74C3C", "#F4D03F"];

    let animationFrameId = 0;
    let gamePaused = false;
    let predict = 0;
    let selectedMode = null;
    let quarterfinal = 0;
    let semifinal = 0;
    let final = 0;
    let endtournament = false;
	let matchesquarter = [];
    let matchessemi = [];
    let matchesfinal = [];

    let push_start = 0;
    let scoreLimit = 3;
    let endgame = 0;
    let lastwinner = null;

    let paddle1 = (canvas.height - paddleHeight) / 2
    let paddle2 = (canvas.height - paddleHeight) / 2
    let lastpaddlespeed = 1;

    let score1 = 0;
    let score2 = 0;
    let lastscore = {score1: 0, score2: 0};

    let ballX = canvas.width / 3;
    let ballY = canvas.height / 3;
    let ballSpeedX = 2;
    let ballSpeedY = 2;
    
    let bricks = []; // Tableau pour stocker les briques
    
    
	// INITIALISATION DES ELEMENTS

		//BRICKS

		// Fonction d'initialisation des briques
		function initBricks() {
			for (let c = 0; c < brickCols; c++) {
				bricks[c] = [];
				for (let r = 0; r < brickRows; r++) {
					const brickX = c * (brickWidth + brickPadding) + brickOffsetLeft;
					const brickY = r * (brickHeight + brickPadding) + brickOffsetTop;
					bricks[c][r] = { x: brickX, y: brickY, status: 1, color: brickColors[Math.floor(Math.random() * brickColors.length)] };
				}
			}
		}
    
		// Fonction pour dessiner les briques
		function drawBricks() {
			for (let c = 0; c < brickCols; c++) {
				for (let r = 0; r < brickRows; r++) {
					if (bricks[c][r].status === 1) {
						ctx.beginPath();
						ctx.rect(bricks[c][r].x, bricks[c][r].y, brickWidth, brickHeight);
						ctx.fillStyle = bricks[c][r].color;
						ctx.fill();
						ctx.closePath();
					}
				}
			}
		}

		// RAQUETTES

		// Dessine une raquette
		function drawPaddle(x, y) {
			ctx.fillStyle = "#F1C40F";
			ctx.fillRect(x, y, paddleWidth, paddleHeight);
		}

		// BALLE

		// Dessine la balle
		function drawBall(x, y) {
			ctx.beginPath();
			ctx.arc(x, y, 10, 0, Math.PI * 2);
			ctx.fillStyle = "#CB4335";
			ctx.fill();
			ctx.closePath();
		}

		// TERRAIN

		function draw_pong() {
			if (!gamePaused) {
				if (first_time == 0)
				{
					get_player_infos();
					playerOneName = canvas.dataset.playerOne;
					first_time = 1;
				}
				// Efface le canvas
				ctx.clearRect(0, 0, canvas.width, canvas.height);
	
				// Dessine les lignes de but
				ctx.beginPath();
				ctx.moveTo(5, 0);
				ctx.lineTo(5, canvas.height);
				// Définir le motif de pointillé
				ctx.setLineDash([20, 10]); // [longueur du trait, longueur de l'espace]
				ctx.lineWidth = 5;
				ctx.strokeStyle = "#F7DC6F";
				ctx.stroke();
				ctx.closePath();
				ctx.beginPath();
				ctx.moveTo(canvas.width - 5, 0);
				ctx.lineTo(canvas.width - 5, canvas.height);
				ctx.stroke();
				ctx.closePath();
				ctx.setLineDash([]);
	
				// Dessine la ligne au milieu du terrain
				ctx.beginPath();
				ctx.moveTo(canvas.width / 2, 0);
				ctx.lineTo(canvas.width / 2, canvas.height);
				ctx.strokeStyle = "#F7DC6F";
				ctx.stroke();
				ctx.closePath();
	
				// Affiche le score en haut de l'écran
				ctx.font = "900 100px Noto Sans";
				ctx.fillStyle = "#ffe6b3";
				const score1Metrics = ctx.measureText(score1);
				ctx.fillText(score1, canvas.width / 2 - 25 - score1Metrics.width, 80);
				ctx.fillText(score2, canvas.width / 2 + 25, 80);
				ctx.font = "900 20px Noto Sans";
				ctx.fillStyle = "#ffe6b3";
				const playerOneMetrics = ctx.measureText(playerOneName);
				const playerTwoMetrics = ctx.measureText(playerTwoName);
				ctx.fillText(playerOneName, canvas.width / 4 - playerOneMetrics.width / 2, 20);
				ctx.fillText(playerTwoName, canvas.width * 3 / 4 - playerTwoMetrics.width / 2, 20);
				drawPaddle(10, paddle1);
				drawPaddle(canvas.width - paddleWidth - 10, paddle2);
				if (selectedMode === "mod") {
					drawBricks();
					checkBrickCollision();
					updateBricks();
				}
				endgame = 0;
				startGame();
				if (push_start == 1)
				{
					drawBall(ballX, ballY);
					ballX += ballSpeedX;
					ballY += ballSpeedY;
					if (ballY + 10 > canvas.height || ballY - 10 < 0) {
						ballSpeedY = -ballSpeedY;
					}
					// Gestion de la collision avec la raquette droite (paddle1)
					if (isCollision(ballX, ballY, 10, paddle1, paddleWidth, paddleHeight)) {
						ballSpeedX = -ballSpeedX;
						const paddleCenter = paddle1 + paddleHeight / 2;
						const ballRelativeY = ballY - paddleCenter;
						ballSpeedY = ballRelativeY * 0.05;
						ballSpeedX = Math.abs(ballSpeedX) + Math.abs(ballRelativeY * 0.05);
						if (ballSpeedY > ballspeedmax)
							ballSpeedY = ballspeedmax;
						if (ballSpeedX > ballspeedmax)
							ballSpeedX = ballspeedmax;
					}
	
					// Gestion de la collision avec la raquette droite (paddle2)
					if (isCollision(ballX, ballY, canvas.width - 30, paddle2, paddleWidth, paddleHeight)) {
						ballSpeedX = -ballSpeedX;
						const paddleCenter = paddle2 + paddleHeight / 2;
						const ballRelativeY = ballY - paddleCenter;
						ballSpeedY = ballRelativeY * 0.05;
						ballSpeedX = -Math.abs(ballSpeedX) - Math.abs(ballRelativeY * 0.05);
						if (ballSpeedY > ballspeedmax)
							ballSpeedY = ballspeedmax;
						if (ballSpeedX > ballspeedmax)
							ballSpeedX = ballspeedmax;
					}
	
					// Vérifie si la balle a traversé les raquettes (marque un point)
					if (ballX <= 0 || ballX > canvas.width) {
						if (ballX <= 0)
							score2++;
						else
							score1++;
						// Réinitialise la position de la balle au centre
						ballX = canvas.width / 2;
						ballY = canvas.height / 2;
						if (ballSpeedY < 0)
							ballSpeedY = 2;
						else
							ballSpeedY = -2;
						if (ballSpeedX < 0)
							ballSpeedX = -2;
						else
							ballSpeedX = 2;
					}
				}
				else
				{
					const text = "Press ENTER to start game";
					ctx.font = "900 50px Noto Sans";
					const textMetrics = ctx.measureText(text);
					const textWidth = textMetrics.width;
					const ascent = textMetrics.actualBoundingBoxAscent;
					const descent = textMetrics.actualBoundingBoxDescent;
					const textHeight = ascent + descent;
					ctx.fillStyle = "#ffe6b3";
					const padding = 10;
					ctx.fillRect((canvas.width - textWidth) / 2 - padding, (canvas.height - textHeight) / 2 - padding, textWidth + 2 * padding, textHeight + 2 * padding);
					ctx.fillStyle = "#000"; 
					ctx.fillText(text, (canvas.width - textWidth) / 2, (canvas.height + ascent - descent) / 2);
				}
				updateManualPlayer();
				updateScore()
				if (endgame == 0)
					animationFrameId = requestAnimationFrame(draw_pong);
			}
		}

		// IMAGE DRAGON

		function drawDragonBackground() {
			ctx.clearRect(0, 0, canvas.width, canvas.height);
			ctx.drawImage(pongImage, 0, 0, canvas.width, canvas.height);
		}

	// FONCTIONS QUI PEUVENT ETRE APPELEES EN COURS DE JEU

		// Fonction de reset de la partie

		function resetGame() {
			score1 = 0;
			score2 = 0;
			ballX = canvas.width / 2;
			ballY = canvas.height / 2;
			ballSpeedX = 2;
			ballSpeedY = 2;
			if (selectedMode !== "tournament")
				selectedMode = null;
			gamePaused = false;
			predict = 0;
			paddle1 = (canvas.height - paddleHeight) / 2
			paddle2 = (canvas.height - paddleHeight) / 2
			bricks = [];
			pausebutton.innerText = "Pause";
			initBricks();
		}

	// TOUCHES

		// mise à jour de l'état des touches
		function handleKeydown(event) {
			keyState[event.key] = true;
		}
		
		function handleKeyup(event) {
			keyState[event.key] = false;
		}
		
		
		
		// Mise à jour de la position du joueur manuel
		function updateManualPlayer() 
		{
			if (keyState["p"] && push_start == 1)
				togglePause();
			if (keyState["e"] && paddle1 > 0)
				paddle1 -= paddleSpeed;
			if (keyState["d"] && paddle1 < canvas.height - paddleHeight)
				paddle1 += paddleSpeed;
			if (keyState["ArrowUp"] && paddle2 > 0)
				paddle2 -= paddleSpeed;
			if (keyState["ArrowDown"] && paddle2 < canvas.height - paddleHeight)
				paddle2 += paddleSpeed;
		}

	// EVENEMENTS

		// Fonction pour détecter les collisions entre la balle et les briques
		function checkBrickCollision() {
			for (let c = 0; c < brickCols; c++) {
				for (let r = 0; r < brickRows; r++) {
					const brick = bricks[c][r];
					if (brick.status === 1) {
						// Coordonnées du centre de la balle
						let centerX = ballX;
						let centerY = ballY;
		
						// Trouver la distance entre le centre de la balle et le centre de la brique
						let dx = Math.abs(centerX - brick.x - brickWidth / 2);
						let dy = Math.abs(centerY - brick.y - brickHeight / 2);
		
						// Calculer la distance entre le centre de la balle et le centre de la brique
						let distX = dx - brickWidth / 2;
						let distY = dy - brickHeight / 2;
		
						if (distX < 0 && distY < 0) {
							// La balle touche la brique
							if (Math.abs(distX) < Math.abs(distY)) {
								// Collision verticale
								ballSpeedX = -ballSpeedX; // Inversion de la direction horizontale
							} else {
								// Collision horizontale
								ballSpeedY = -ballSpeedY; // Inversion de la direction verticale
							}
							brick.status = 0; // La brique est détruite
						}
					}
				}
			}
		}
    
		// Fonction pour mettre à jour les briques après une collision
		function updateBricks() {
			let brickCount = 0;
			for (let c = 0; c < brickCols; c++) {
				for (let r = 0; r < brickRows; r++) {
					brickCount += bricks[c][r].status;
				}
			}
			if (brickCount === 0) {
				// Toutes les briques sont détruites, vous pouvez mettre en place une action spéciale ici
			}
		}
    

		function togglePause() {
			gamePaused = !gamePaused;
			if (gamePaused) {
				pausebutton.innerText = "Resume";
				cancelAnimationFrame(animationFrameId);
				// Affiche un message de pause sur l'écran
				ctx.font = "900 50px Noto Sans";
				const pauseText = "Paused";
				const textMetrics = ctx.measureText(pauseText);
				const textWidth = textMetrics.width;
				ctx.fillStyle = "#ffe6b3";
				ctx.fillRect((canvas.width - textWidth) / 2 - 10, canvas.height / 2 - 40, textWidth + 20, 80);
				ctx.fillStyle = "#000";
				ctx.fillText(pauseText, (canvas.width - textWidth) / 2, canvas.height / 2);
			} else {
				pausebutton.innerText = "Pause";
				if (selectedMode === "1vs1" || selectedMode === "tournament" || selectedMode === "mod")
					draw_pong();
				if (selectedMode === "1vsAI")
					draw_pongAI();
			}
		}
    
		function startGame()
		{
			if (keyState["Enter"] && endgame == 0) {
				push_start = 1;
			}
		}

		function isCollision(ballX, ballY, paddleX, paddleY, paddleWidth, paddleHeight)
		{
			return (
				ballX - 10 < paddleX + paddleWidth &&
				ballX + 10 > paddleX &&
				ballY - 10 < paddleY + paddleHeight &&
				ballY + 10 > paddleY
			);
		}
	
		function updateScore() {
			if (score1 >= scoreLimit || score2 >= scoreLimit) {
				cancelAnimationFrame(animationFrameId);
				endgame = 1;
				push_start = 0;
				// Supprime tout du canvas
				ctx.clearRect(0, 0, canvas.width, canvas.height);
	
				ctx.fillStyle = "#a791e7";
				ctx.fillRect(0, 0, canvas.width, canvas.height);
				// Affiche l'image du gagnant dans le canvas
				if (score2 > score1 && selectedMode === "1vsAI")
					ctx.drawImage(looserImage, 0, 100, canvas.width, canvas.height - 100);
				else
					ctx.drawImage(winnerImage, 0, 100, canvas.width, canvas.height - 100);
				if (score1 > score2) {
					// affiche un rectangle bleu en haut de lecran
					ctx.fillStyle = "#000"; // Couleur bleu
					ctx.fillRect(0, 0, canvas.width, 100);
				}
				else {
					// affiche un rectangle rouge en haut de lecran
					ctx.fillStyle = "#000"; // Couleur rouge
					ctx.fillRect(0, 0, canvas.width, 100);
				}
	
				// Affiche le score en haut de l'écran
				ctx.font = "900 80px Noto Sans";
				ctx.fillStyle = "#ffe6b3";
				const score1Metrics = ctx.measureText(score1);
				ctx.fillText(score1, canvas.width / 2 - 25 - score1Metrics.width, 80);
				ctx.fillText(score2, canvas.width / 2 + 25, 80);
				ctx.font = "900 40px Noto Sans";
				ctx.fillStyle = "#ffe6b3";
	
				const playerOneMetrics = ctx.measureText(playerOneName);
				const playerTwoMetrics = ctx.measureText(playerTwoName);
				const AIMetrics = ctx.measureText("AI");
				ctx.fillText(playerOneName, canvas.width / 4 - playerOneMetrics.width / 2, 60);
				if (selectedMode === "1vsAI")
					ctx.fillText("AI", canvas.width * 3 / 4 - AIMetrics.width / 2, 60);
				else
					ctx.fillText(playerTwoName, canvas.width * 3 / 4 - playerTwoMetrics.width / 2, 60);
	
	
				// Dessiner les boutons du menu
				ctx.fillStyle = "#f00"; // Couleur rouge pour les boutons
				ctx.fillRect(canvas.width * 6 / 8, canvas.height * 7 / 8 - 20, 180, 50); // Bouton 1vs1
	
				// Dessiner le texte des boutons
				ctx.font = "900 30px Noto Sans";
				ctx.fillStyle = "#ffe6b3";
				if (selectedMode === "tournament")
					ctx.fillText("Next", canvas.width * 6 / 8 + 10, canvas.height * 7 / 8 + 15);
				else
					ctx.fillText("Newgame", canvas.width * 6 / 8 + 10, canvas.height * 7 / 8 + 15);
				draw_endgame_menu();
				canvas.addEventListener("click", handleMouseClick2);  
			}
		}

		// CLICK SUR LES BOUTONS

		vsbutton.addEventListener("click", (event) => {
			console.log("Bouton 1vs1 cliqué");
			selectedMode = "1vs1";
			draw_ingame_menu();
			draw_pong();
		});
	
		aibutton.addEventListener("click", (event) => {
			console.log("Bouton 1vsAI cliqué");
			selectedMode = "1vsAI";
			draw_ingame_menu();
			draw_pongAI();
		});
	
		modbutton.addEventListener("click", (event) => {
			console.log("Bouton mod cliqué");
			selectedMode = "mod";
			draw_ingame_menu();
			draw_pong();
		});
	
		tourbutton.addEventListener("click", (event) => {
			console.log("Bouton Tournament cliqué");
				selectedMode = "tournament";
	
				// Ajoutez le code pour récupérer le nombre de participants et leurs alias respectifs
				let numParticipants = parseInt(prompt("Enter the number of participants (3 - 8):"));
				// Vérifies si le nombre est dans la plage spécifiée
				while (numParticipants < 3 || numParticipants > 8 || isNaN(numParticipants)) {
					numParticipants = parseInt(prompt("Please enter a number between 3 and 8:"));
				}
				
				const participants = [];
				for (let i = 0; i < numParticipants; i++) {
					let alias = prompt("Enter alias for participant " + (i + 1) + ":");
				
					// Vérifications sur l'alias
					while (!(/^[a-zA-Z]{2,}\d*$/.test(alias)) || alias.length < 2 || alias.length > 10 || alias.toLowerCase() === "exempt" || !alias.trim() || participants.includes(alias.trim())) {
						alias = prompt("Alias must be between 2 and 10 characters, contain at least 2 letters, cannot be 'exempt', and must be unique. Please enter again:");
				
						// Vérifie si l'alias est déjà dans la liste des participants
						if (participants.includes(alias.trim())) {
							alias = prompt("This alias is already taken. Please enter a different alias:");
						}
					}
				
					participants.push(alias.trim()); // Ajoute l'alias à la liste des participants
				}
	
				if (numParticipants > 4) {
					for (let i = 0; i < 8 - numParticipants; i++)
						participants.push("exempt");
					quarterfinal = 1;
					semifinal = 0;
					final = 0;
				}
				else {
					for (let i = 0; i < 4 - numParticipants; i++)
						participants.push("exempt");
					quarterfinal = 0;
					semifinal = 1;
					final = 0;
				}
				console.log("Participants: ", participants);
				draw_ingame_menu();
				startTournament(participants);
		});
	
		startbutton.addEventListener("click", (event) => {
			console.log("Bouton start cliqué");
			push_start = 1;
		});
	
		pausebutton.addEventListener("click", (event) => {
			console.log("Bouton pause cliqué");
			togglePause();
		});
	
		quitbutton.addEventListener("click", (event) => {
			console.log("Bouton quit cliqué");
			endgame = 1;
			push_start = 0;
			if (selectedMode === "tournament")
				cleartournament();
			resetGame();
			draw_game_menu();
		});
	
		quit2button.addEventListener("click", (event) => {
			console.log("Bouton quit2 cliqué");
			resetGame();
			draw_game_menu();
		});
	
		newgamebutton.addEventListener("click", (event) => {
			if (endgame == 1 && selectedMode !== "tournament")
			{
				console.log("Bouton newgame cliqué");
				resetGame();
				draw_game_menu();
				drawDragonBackground();
			}
			else if (endgame == 1 && selectedMode === "tournament")
			{
				console.log("Bouton nextgame cliqué(fin de game)");
				if (score1 > score2)
					lastwinner = playerOneName;
				else
					lastwinner = playerTwoName;
				updatetournament();
				lastscore[score1] = score1;
				lastscore[score2] = score2;
				resetGame();
				if (endtournament == true)
				{
					draw_endgame_menu();
					matchesfinalended();
				}
				else
					drawtournament();
			}
			else if(endgame == 0 && selectedMode === "tournament")
			{
				console.log("Bouton nextgame cliqué(debut de game)");
				draw_endgame_menu();
				draw_pong();
			}
		})

	// AI

		function AIEverySecond() {
			setInterval(function() {
				if (selectedMode === "1vsAI" && push_start == 1) {
					console.log("Une seconde s'est écoulée.");
					console.log("ou pas");
					updateAI();
				}
			}, 1000); // 1000 millisecondes équivalent à 1 seconde
		}

		function AIEverymilliSecond() {
			setInterval(function() {
				if (selectedMode === "1vsAI") {
					if (lastpaddlespeed == 1 && paddle2 < canvas.height - paddleHeight && paddle2 < predict)
						paddle2 += paddleSpeed;
					if (lastpaddlespeed == -1 && paddle2 > 0 && paddle2 > predict)
						paddle2 -= paddleSpeed;
				}
			}, 3); // 1000 millisecondes équivalent à 1 seconde
		}
	
	

		function updateAI() {
			// Logique de mouvement de base

			// Anticipation de la trajectoire de la balle
			if (ballSpeedX > 0) {
				// Prédiction du point d'intersection de la balle avec la ligne de l'IA
				const predictedIntersectionY = calculatePredictedIntersection();

				// Ajustement de la position en fonction de la prédiction
				if (predictedIntersectionY > paddle2 + paddleHeight / 2 && paddle2 < canvas.height - paddleHeight) {
					predict = predictedIntersectionY - paddleHeight / 2;
					lastpaddlespeed = 1;
				}
				if (predictedIntersectionY < paddle2 + paddleHeight / 2 && paddle2 > 0) {
					predict = predictedIntersectionY - paddleHeight / 2;;
					lastpaddlespeed = -1;
				}
			}
		}

		function calculatePredictedIntersection() {
			// Calcule le temps estimé avant que la balle n'atteigne la position de l'IA
			const estimatedTime = (canvas.width - ballX) / ballSpeedX;

			// Calcule la position Y de la balle à ce moment-là
			const predictedY = ballY + ballSpeedY * estimatedTime;

			return predictedY;
		}

		function draw_pongAI() {
			if (!gamePaused) {
				// Efface le canvas
				ctx.clearRect(0, 0, canvas.width, canvas.height);

				// Dessine les lignes de but
				ctx.beginPath();
				ctx.moveTo(5, 0);
				ctx.lineTo(5, canvas.height);
				// Définir le motif de pointillé
				ctx.setLineDash([20, 10]); // [longueur du trait, longueur de l'espace]
				ctx.lineWidth = 5;
				ctx.strokeStyle = "#ffe6b3";
				ctx.stroke();
				ctx.closePath();
				ctx.beginPath();
				ctx.moveTo(canvas.width - 5, 0);
				ctx.lineTo(canvas.width - 5, canvas.height);
				ctx.stroke();
				ctx.closePath();
				ctx.setLineDash([]);

				// Dessine la ligne au milieu du terrain
				ctx.beginPath();
				ctx.moveTo(canvas.width / 2, 0);
				ctx.lineTo(canvas.width / 2, canvas.height);
				ctx.strokeStyle = "#ffe6b3";
				ctx.stroke();
				ctx.closePath();

				// Affiche le score en haut de l'écran
				ctx.font = "900 100px Noto Sans";
				ctx.fillStyle = "#ffe6b3";
				const score1Metrics = ctx.measureText(score1);
				ctx.fillText(score1, canvas.width / 2 - 25 - score1Metrics.width, 80);
				ctx.fillText(score2, canvas.width / 2 + 25, 80);
				ctx.font = "900 20px Noto Sans";
				ctx.fillStyle = "#ffe6b3";
				const playerOneMetrics = ctx.measureText(playerOneName);
				const AIMetrics = ctx.measureText("AI");
				ctx.fillText(playerOneName, canvas.width / 4 - playerOneMetrics.width / 2, 20);
				ctx.fillText("AI", canvas.width * 3 / 4 - AIMetrics.width / 2, 20);

				// Dessine les raquettes
				drawPaddle(10, paddle1);
				drawPaddle(canvas.width - paddleWidth - 10, paddle2);
				endgame = 0;
				startGame();
				// Met à jour la position de la balle
				if (push_start == 1) {
					// Dessine la balle
					drawBall(ballX, ballY);
					ballX += ballSpeedX;
					ballY += ballSpeedY;

					// Rebondissement sur les parois verticales
					if (ballY + 10 > canvas.height || ballY - 10 < 0) {
						ballSpeedY = -ballSpeedY;
					}
					// Rebondissement sur les raquettes
					// Gestion de la collision avec la raquette gauche (paddle1)
					if (isCollision(ballX, ballY, 10, paddle1, paddleWidth, paddleHeight)) {
						ballSpeedX = -ballSpeedX; // Inversion de la direction horizontale

						// Ajuste la direction verticale en fonction de la position de la balle sur la raquette
						const paddleCenter = paddle1 + paddleHeight / 2;
						const ballRelativeY = ballY - paddleCenter;

						// Ajuste la vitesse verticale en fonction de la position sur le paddle
						ballSpeedY = ballRelativeY * 0.05;
						// Ajuste la vitesse horizontale en fonction de la position sur le paddle (plus rapide au centre)
						ballSpeedX = Math.abs(ballSpeedX) + Math.abs(ballRelativeY * 0.05);
						if (ballSpeedY > ballspeedmax)
							ballSpeedY = ballspeedmax;
						if (ballSpeedX > ballspeedmax)
							ballSpeedX = ballspeedmax;
					}

					// Gestion de la collision avec la raquette droite (paddle2)
					if (isCollision(ballX, ballY, canvas.width - 30, paddle2, paddleWidth, paddleHeight)) {
						ballSpeedX = -ballSpeedX; // Inversion de la direction horizontale
						
						// Ajuste la direction verticale en fonction de la position de la balle sur la raquette
						const paddleCenter = paddle2 + paddleHeight / 2;
						const ballRelativeY = ballY - paddleCenter;
						// Ajuste la vitesse verticale en fonction de la position sur le paddle
						ballSpeedY = ballRelativeY * 0.05;
						// Ajuste la vitesse horizontale en fonction de la position sur le paddle (plus rapide au centre)
						ballSpeedX = -Math.abs(ballSpeedX) - Math.abs(ballRelativeY * 0.05);
						if (ballSpeedY > ballspeedmax)
							ballSpeedY = ballspeedmax;
						if (ballSpeedX > ballspeedmax)
							ballSpeedX = ballspeedmax;
					}

					// Vérifie si la balle a traversé les raquettes (marque un point)
					if (ballX <= 0 || ballX > canvas.width) {
						
						if (ballX <= 0)
							score2++;
						else
							score1++;
						// Réinitialise la position de la balle au centre
						ballX = canvas.width / 2;
						ballY = canvas.height / 2;
						if (ballSpeedY < 0)
							ballSpeedY = 2;
						else
							ballSpeedY = -2;
						if (ballSpeedX < 0)
							ballSpeedX = -2;
						else
							ballSpeedX = 2;
					}
				}
				else { // affiche un message a lecran pour demarrer la partie
					// Mesure la largeur et la hauteur du texte
					const text = "Press ENTER to start game";
					ctx.font = "900 50px Noto Sans";
					const textMetrics = ctx.measureText(text);
					const textWidth = textMetrics.width;
				
					// Ajuste la hauteur du texte en utilisant l'ascender et le descender
					const fontHeight = ctx.measureText('M').width; // Hauteur totale de la police
					const ascent = textMetrics.actualBoundingBoxAscent; // Ascender
					const descent = textMetrics.actualBoundingBoxDescent; // Descender
					const textHeight = ascent + descent;
				
					// Dessine le fond blanc autour du texte
					ctx.fillStyle = "#ffe6b3"; // Couleur blanche
					const padding = 10; // Marge autour du texte
					ctx.fillRect((canvas.width - textWidth) / 2 - padding, (canvas.height - textHeight) / 2 - padding, textWidth + 2 * padding, textHeight + 2 * padding);
				
					// Dessine le texte sur le fond blanc
					ctx.fillStyle = "#000"; 
					ctx.fillText(text, (canvas.width - textWidth) / 2, (canvas.height + ascent - descent) / 2);
				}

				updateManualPlayer();

				// Vérifie si l'un des joueurs a gagné
				updateScore();
			
				// Demande une nouvelle frame d'animation
				if (endgame == 0)
					animationFrameId = requestAnimationFrame(draw_pongAI);
			}

		}


	// TOURNOI

    // Fonction pour dessiner la liste des matchs
    function drawMatches(matches) {
        // Définir les paramètres de dessin
        const startX = 20; // Position X de départ des cadres
        const startY = canvas.height * 3 / 8; // Position Y de départ des cadres
        const frameWidth = canvas.width / 3; // Largeur des cadres
        const frameHeight = canvas.height / 12; // Hauteur des cadres
        const verticalGap = canvas.height / 30; // Espacement vertical entre les cadres

        ctx.fillStyle = "#ffe6b3"; // Couleur du texte en blanc
        ctx.font = "900 14px Noto Sans";
        
        // Dessiner chaque match dans un cadre différent
        matches.forEach((match, index) => {
            // Calculer les coordonnées du cadre pour ce match
            const frameX = startX;
            const frameY = startY + (frameHeight + verticalGap) * index;
            const textplayeroneMetrics = ctx.measureText(match.player1);
            const textplayertwoMetrics = ctx.measureText(match.player2);
            const textvsMetrics = ctx.measureText("vs");
            const textplayeroneWidth = textplayeroneMetrics.width;
            const textplayertwoWidth = textplayertwoMetrics.width;
            const textvsWidth = textvsMetrics.width;

            // Dessiner le cadre
            ctx.fillStyle = index % 2 === 0 ? "#0404ce" : "#f00"; // Alternance de couleurs
            ctx.fillRect(frameX, frameY, frameWidth, frameHeight);
            ctx.fillStyle = "#000"; 

            // Dessiner le texte du match
            ctx.fillText("Match " + (index + 1), frameX + 5, frameY + canvas.height / 30);
            if (match.winner != null) {
                if (match.player1 === match.winner )
                    ctx.fillText("winner : " + match.player1, frameX + frameWidth / 2, frameY + canvas.height / 30);
                else
                    ctx.fillText("winner : " + match.player2, frameX + frameWidth / 2, frameY + canvas.height / 30);
            }
            ctx.fillStyle = "#ffe6b3"; // Couleur du texte en blanc
            ctx.font = "900 14px Noto Sans";
            ctx.fillText("vs", (canvas.width / 3 - textvsWidth / 2) / 2 + frameX, frameY + 40);
            ctx.fillText(match.player1, canvas.width / 3 / 4 - textplayeroneWidth / 2 + frameX, frameY + 40);
            ctx.fillText(match.player2, (canvas.width / 3 - textplayertwoWidth / 2) * 3 / 4 + frameX, frameY + 40);
        });
    }

    function startTournament(participants) {
        endtournament = false;
        // Mélanger les participants
        console.log("melange des participants");

        shuffleArray(participants);

        console.log("Participants mélangés: ", participants);
        // Créer les matchs
        createMatches(participants);
        console.log("Matchesquarter: ", matchesquarter);
        console.log("Matchessemi: ", matchessemi);
        console.log("Matchesfinal: ", matchesfinal);
        drawtournament();
    }

    function matchesquarterended() {
        for (let i = 0; i < matchesquarter.length; i += 2) {
            let match = {player1: matchesquarter[i].winner, player2: matchesquarter[i + 1].winner, winner: null};
            matchessemi.push(match);
        }
        quarterfinal = 0;
        semifinal = 1;
        drawtournament();
    }

    function matchessemiended() {
        let match = {player1: matchessemi[0].winner, player2: matchessemi[1].winner, winner: null};
        matchesfinal.push(match);
        semifinal = 0;
        final = 1;
        drawtournament();
    }

    function matchesfinalended() {
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        ctx.fillStyle = "#000";
        ctx.fillRect(0, 0, canvas.width, canvas.height); 
        ctx.drawImage(pongImage, canvas.width * 1 / 6, canvas.height * 1 / 3, canvas.width * 2 / 3, canvas.height * 2 / 3);  
   
        const text = "Winner is...";
        ctx.font = "900 40px Noto Sans";
        const textMetrics = ctx.measureText(text);
        const textWidth = textMetrics.width;
    
        // Ajuste la hauteur du texte en utilisant l'ascender et le descender
        const ascent = textMetrics.actualBoundingBoxAscent; // Ascender
        const descent = textMetrics.actualBoundingBoxDescent; // Descender

        // Dessiner le texte du menu
        ctx.fillStyle = "#ffe6b3"; 
        ctx.fillText(text, (canvas.width - textWidth) / 2, (canvas.height + ascent - descent) / 6);
        ctx.fillText(lastwinner + " !", canvas.width / 2, canvas.height * 1 / 4);

        //lastwinner et lastscore[0 et 1]
        
        ctx.fillStyle = "#0404ce"; // Couleur rouge pour les boutons
        ctx.fillRect(canvas.width * 6 / 8, canvas.height * 7 / 8 - 20, 180, 50); // Bouton 1vs1


        // Dessiner le texte des boutons
        ctx.font = "900 30px Noto Sans";
        ctx.fillStyle = "#ffe6b3";
        ctx.fillText("Menu", canvas.width * 6 / 8 + 10, canvas.height * 7 / 8 + 15);
        cleartournament();

        canvas.addEventListener("click", handleMouseClick4);
    }

    function cleartournament() {
        selectedMode = null;  // Variable pour suivre le mode de jeu sélectionné
        quarterfinal = 0;
        semifinal = 0;
        final = 0;
		first_time = 0;
    
		get_player_infos();
        playerOneName = canvas.dataset.playerOne || "Player One"; // Utilisation d'une valeur par défaut si le nom n'est pas défini
        playerTwoName = canvas.dataset.playerTwo || "Player Two";
        lastwinner = null;
    
        score1 = 0;
        score2 = 0;
        lastscore = {score1: 0, score2: 0};
        predict = 0;
        
        matchesquarter = [];
        matchessemi = [];
        matchesfinal = [];
    }

    function drawtournament() {
        // Efface le canvas
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        ctx.fillStyle = "#a791e7";
        ctx.fillRect(0, 0, canvas.width, canvas.height);
        ctx.drawImage(pongImage, 0, 0, canvas.width, canvas.height);  

        const text = "Tournament";
        ctx.font = "900 80px Noto Sans";
        const textMetrics = ctx.measureText(text);
        const textWidth = textMetrics.width;
    
        // Ajuste la hauteur du texte en utilisant l'ascender et le descender
        const fontHeight = ctx.measureText('M').width; // Hauteur totale de la police
        const ascent = textMetrics.actualBoundingBoxAscent; // Ascender
        const descent = textMetrics.actualBoundingBoxDescent; // Descender
        const textHeight = ascent + descent;

        // Dessiner le texte du menu
        ctx.fillStyle = "#ffe6b3"; 
        ctx.fillText(text, (canvas.width - textWidth) / 2, (canvas.height + ascent - descent) / 6);
        
        // Dessiner les matchs
        if (quarterfinal == 1) {
            ctx.fillStyle = "#0404ce"; // Couleur bleue pour les boutons
            ctx.fillRect(20, canvas.height * 7 / 8 - 20, 260, 50);
            ctx.font = "900 30px Noto Sans";
            ctx.fillStyle = "#ffe6b3";
            ctx.fillText("Quarter-finals", 40, canvas.height * 7 / 8 + 15);
            drawMatches(matchesquarter);
            for (let i = 0; i <= matchesquarter.length; i++) {
                if (i == matchesquarter.length) {
                    matchesquarterended();
                    return;
                }
                if (matchesquarter[i].winner === null) {
                    if (matchesquarter[i].player1 === "exempt" || matchesquarter[i].player2 === "exempt") {
                        if (matchesquarter[i].player1 === "exempt")
                            matchesquarter[i].winner = matchesquarter[i].player2;
                        else
                            matchesquarter[i].winner = matchesquarter[i].player1;
                    }
                    else {
                        playerOneName = matchesquarter[i].player1;
                        playerTwoName = matchesquarter[i].player2;
                        break;
                    }
                }
            }
        }
        else if (semifinal == 1) {
            ctx.fillStyle = "#0404ce"; // Couleur bleue pour les boutons
            ctx.fillRect(20, canvas.height * 7 / 8 - 20, 210, 50);
            ctx.font = "900 30px Noto Sans";
            ctx.fillStyle = "#ffe6b3";
            ctx.fillText("Semi-finals", 40, canvas.height * 7 / 8 + 15);
            drawMatches(matchessemi);
            for (let i = 0; i <= matchessemi.length; i++) {
                if (i == matchessemi.length) {
                    matchessemiended();
                    return;
                }
                if (matchessemi[i].winner === null) {
                    if (matchessemi[i].player1 === "exempt" || matchessemi[i].player2 === "exempt") {
                        if (matchessemi[i].player1 === "exempt")
                            matchessemi[i].winner = matchessemi[i].player2;
                        else
                            matchessemi[i].winner = matchessemi[i].player1;
                    }
                    else {
                        playerOneName = matchessemi[i].player1;
                        playerTwoName = matchessemi[i].player2;
                        break;
                    }
                }
                
            }
        }
        else if (final == 1) {
            ctx.fillStyle = "#0404ce"; // Couleur bleue pour les boutons
            ctx.fillRect(20, canvas.height * 7 / 8 - 20, 210, 50);
            ctx.font = "900 30px Noto Sans";
            ctx.fillStyle = "#ffe6b3";
            ctx.fillText("Final", 80, canvas.height * 7 / 8 + 15);
            drawMatches(matchesfinal);
            playerOneName = matchesfinal[0].player1;
            playerTwoName = matchesfinal[0].player2;
        }
        
         // Dessiner les boutons du menu
         ctx.fillStyle = "#0404ce"; // Couleur rouge pour les boutons
         ctx.fillRect(canvas.width * 6 / 8, canvas.height * 7 / 8 - 20, 180, 50); // Bouton 1vs1


         // Dessiner le texte des boutons
         ctx.font = "900 30px Noto Sans";
         ctx.fillStyle = "#ffe6b3";
         ctx.fillText("nextgame", canvas.width * 6 / 8 + 10, canvas.height * 7 / 8 + 15);
        
         console.log("Matchesquarter: ", matchesquarter);
         console.log("Matchessemi: ", matchessemi);
         console.log("Matchesfinal: ", matchesfinal);

         endgame = 0;

        canvas.addEventListener("click", handleMouseClick2);
    }
    
    function updatetournament() {
        if (quarterfinal == 1) {
            for (let i = 0; i < matchesquarter.length; i++) {
                if (matchesquarter[i].winner === null) {
                    matchesquarter[i].winner = lastwinner;
                    break;
                }
            }
        }            
        else if (semifinal == 1) {
            for (let i = 0; i < matchessemi.length; i++) {
                if (matchessemi[i].winner === null) {
                    matchessemi[i].winner = lastwinner;
                    break;
                }
            }
        }
        else if (final == 1) {
            if (matchesfinal[0].winner === null) {
                matchesfinal[0].winner === lastwinner; 
                endtournament = true;
            }               
        }
    }

    // Fonction pour mélanger un tableau
    function shuffleArray(array) {
        for (let i = array.length - 1; i > 0; i--) {
            const j = Math.floor(Math.random() * (i + 1));
            [array[i], array[j]] = [array[j], array[i]];
        }
        return array;
    }

    // Fonction pour créer les matchs
    function createMatches(participants) {
        
        const numParticipants = participants.length;
        if (numParticipants > 4) {
            // Créer les paires de matchs en associant chaque participant à un autre
            for (let i = 0; i < numParticipants; i += 2) {
                let match = {player1: participants[i], player2: participants[i + 1], winner: null};
                matchesquarter.push(match);
            }
        }
        else {
            // Créer les paires de matchs en associant chaque participant à un autre
            for (let i = 0; i < numParticipants; i += 2) {
                let match = {player1: participants[i], player2: participants[i + 1], winner: null};
                matchessemi.push(match);
            }
        }
    }
    
    function handleMouseClick(event) {
        const mouseX = event.clientX - canvas.getBoundingClientRect().left;
        const mouseY = event.clientY - canvas.getBoundingClientRect().top;
    
        // Bouton 1vs1
        if (
            mouseX >= canvas.width / 8 && mouseX <= canvas.width / 8 + 200 &&
            mouseY >= canvas.height / 2 - 30 && mouseY <= canvas.height / 2 + 20) {
            console.log("Bouton 1vs1 cliqué");
            selectedMode = "1vs1";
            draw_pong();
        }
    
        // Bouton 1vsAI
        else if (
            mouseX >= canvas.width / 8 &&
            mouseX <= canvas.width / 8 + 200 &&
            mouseY >= canvas.height / 2 + 30 &&
            mouseY <= canvas.height / 2 + 80
        ) {
            console.log("Bouton 1vsAI cliqué");
            selectedMode = "1vsAI";
            draw_pongAI();
        }
    
        // Bouton mod
        else if (
            mouseX >= canvas.width / 8 &&
            mouseX <= canvas.width / 8 + 200 &&
            mouseY >= canvas.height / 2 + 90 &&
            mouseY <= canvas.height / 2 + 140
        ) {
            console.log("Bouton mod cliqué");
            selectedMode = "mod";
            draw_pong();
        }

        // Bouton Tournament
        else if (
            mouseX >= canvas.width / 8 &&
            mouseX <= canvas.width / 8 + 200 &&
            mouseY >= canvas.height / 2 + 150 &&
            mouseY <= canvas.height / 2 + 200
        ) {
            console.log("Bouton Tournament cliqué");
            selectedMode = "tournament";

            // Ajoutez le code pour récupérer le nombre de participants et leurs alias respectifs
            let numParticipants = parseInt(prompt("Enter the number of participants (3 - 8):"));
            // Vérifies si le nombre est dans la plage spécifiée
            while (numParticipants < 3 || numParticipants > 8 || isNaN(numParticipants)) {
                numParticipants = parseInt(prompt("Please enter a number between 3 and 8:"));
            }
            
            const participants = [];
            for (let i = 0; i < numParticipants; i++) {
                let alias = prompt("Enter alias for participant " + (i + 1) + ":");
            
                // Vérifications sur l'alias
                while (!(/^[a-zA-Z]{2,}\d*$/.test(alias)) || alias.length < 2 || alias.length > 10 || alias.toLowerCase() === "exempt" || !alias.trim() || participants.includes(alias.trim())) {
                    alias = prompt("Alias must be between 2 and 10 characters, contain at least 2 letters, cannot be 'exempt', and must be unique. Please enter again:");
            
                    // Vérifie si l'alias est déjà dans la liste des participants
                    if (participants.includes(alias.trim())) {
                        alias = prompt("This alias is already taken. Please enter a different alias:");
                    }
                }
            
                participants.push(alias.trim()); // Ajoute l'alias à la liste des participants
            }

            if (numParticipants > 4) {
                for (let i = 0; i < 8 - numParticipants; i++)
                    participants.push("exempt");
                quarterfinal = 1;
                semifinal = 0;
                final = 0;
            }
            else {
                for (let i = 0; i < 4 - numParticipants; i++)
                    participants.push("exempt");
                quarterfinal = 0;
                semifinal = 1;
                final = 0;
            }
            console.log("Participants: ", participants);
            // Ajoutez le code pour démarrer le tournoi avec les participants saisis
            startTournament(participants);
        }
        canvas.removeEventListener("click", handleMouseClick);
    }

    function handleMouseClick2(event) {
        const mouseX = event.clientX - canvas.getBoundingClientRect().left;
        const mouseY = event.clientY - canvas.getBoundingClientRect().top;
    
        // Bouton newgame
        if (
            mouseX >= canvas.width * 6 / 8 && mouseX <= canvas.width * 6 / 8 + 200 &&
            mouseY >= canvas.height * 7 / 8 - 30 && mouseY <= canvas.height * 7 / 8 + 20 &&
            endgame == 1 && selectedMode !== "tournament") {
            console.log("Bouton newgame cliqué");
            resetGame();
            drawDragonBackground();
            canvas.removeEventListener("click", handleMouseClick2);
        }
        else if (
            mouseX >= canvas.width * 6 / 8 && mouseX <= canvas.width * 6 / 8 + 200 &&
            mouseY >= canvas.height * 7 / 8 - 30 && mouseY <= canvas.height * 7 / 8 + 20 &&
            endgame == 1 && selectedMode === "tournament") {
            console.log("Bouton nextgame cliqué(fin de game)");
            if (score1 > score2)
                lastwinner = playerOneName;
            else
                lastwinner = playerTwoName;
            updatetournament();
            lastscore[score1] = score1;
            lastscore[score2] = score2;
            resetGame();
            if (endtournament == true)
                matchesfinalended();
            else
                drawtournament();

        }
        else if (
            mouseX >= canvas.width * 6 / 8 && mouseX <= canvas.width * 6 / 8 + 200 &&
            mouseY >= canvas.height * 7 / 8 - 30 && mouseY <= canvas.height * 7 / 8 + 20 &&
            endgame == 0 && selectedMode === "tournament") {
            console.log("Bouton nextgame cliqué(debut de game)");
            
            draw_pong();
            canvas.removeEventListener("click", handleMouseClick2);
        }

    }

    function handleMouseClick3(event) {
        const mouseX = event.clientX - canvas.getBoundingClientRect().left;
        const mouseY = event.clientY - canvas.getBoundingClientRect().top;
    
        // Bouton newgame
        if (
            mouseX >= canvas.width * 6 / 8 && mouseX <= canvas.width * 6 / 8 + 200 &&
            mouseY >= canvas.height * 6 / 8 - 30 && mouseY <= canvas.height * 6 / 8 + 20) {
            console.log("Bouton pause cliqué");
            togglePause()
        }
        if (
            mouseX >= canvas.width * 6 / 8 && mouseX <= canvas.width * 6 / 8 + 200 &&
            mouseY >= canvas.height * 7 / 8 - 30 && mouseY <= canvas.height * 7 / 8 + 20) {
            console.log("Bouton quit cliqué");
            endgame = 1;
            push_start = 0;
            if (selectedMode === "tournament")
                cleartournament();
            drawDragonBackground();
        }
        canvas.removeEventListener("click", handleMouseClick3);
    }

    function handleMouseClick4(event) {
        const mouseX = event.clientX - canvas.getBoundingClientRect().left;
        const mouseY = event.clientY - canvas.getBoundingClientRect().top;
    
        // Bouton newgame
        if (
            mouseX >= canvas.width * 6 / 8 && mouseX <= canvas.width * 6 / 8 + 200 &&
            mouseY >= canvas.height * 7 / 8 - 30 && mouseY <= canvas.height * 7 / 8 + 20 &&
            endtournament == true) {
            console.log("Bouton menu cliqué(fin de tournoi)");
            resetGame();
            drawDragonBackground();
        }
        canvas.removeEventListener("click", handleMouseClick4);

    }
	let first_time = 0;
	draw_game_menu();
	resetGame();
	drawDragonBackground();
	initBricks();
    AIEverySecond();
    AIEverymilliSecond();
	document.addEventListener("keydown", handleKeydown);
	document.addEventListener("keyup", handleKeyup);
});

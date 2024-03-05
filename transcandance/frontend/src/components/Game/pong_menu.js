export function draw_game_menu() {
	document.getElementById("game_menu").style.display = 'block';
	document.getElementById("in_game").style.display = 'none';
	document.getElementById("end_game").style.display = 'none';
}

export function draw_ingame_menu() {
	document.getElementById("game_menu").style.display = 'none';
	document.getElementById("in_game").style.display = 'block';
	document.getElementById("end_game").style.display = 'none';
}

export function draw_endgame_menu() {
	document.getElementById("game_menu").style.display = 'none';
	document.getElementById("in_game").style.display = 'none';
	document.getElementById("end_game").style.display = 'block';
}
export function get_player_infos() {
	$.ajax({
		url: '/api/get-session/',  // URL of your Django view
		type: 'GET',
		success: function(data) {
			if (data.error){
				console.log("Error: ", data.error);
				return;
			}

			// Update HTML content with session data
			console.log('Session data loaded:', data);

			document.getElementById('profile-login').innerHTML = "<b>" + data.user + "</b>";
			// document.getElementById('profile-firstname').innerHTML = "<b>Prenom :</b> " + data.first_name;
			document.getElementById('profile-email').innerHTML = data.email;
			document.getElementById('profile-score').innerHTML = data.score;
			document.getElementById('profile-wons').innerHTML = data.win_games;
			document.getElementById('profile-games').innerHTML = data.total_games;
			if (data.img)
				document.getElementById('player-image').src = data.img;
			else
				document.getElementById('player-image').src = "assets/anonymous-icon.png";

		},
		error: function(xhr, status, error) {
			console.error('Error retrieving session data:', error);
		}
	});
}

import { createQRcode, display_qrcode } from './identificator.js';

export function get_player_infos_settings() {
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

			document.getElementById('change-firstname').value = data.first_name;
			document.getElementById('change-email').value = data.email;
			if (data.img)
			{
				document.getElementById('player-image').src = data.img;
				document.getElementById('change-image').src = data.img;
			}
			else
				document.getElementById('player-image').src = "assets/anonymous-icon.png";
			createQRcode();
		},
		error: function(xhr, status, error) {
			console.error('Error retrieving session data:', error);
		}
	});
}

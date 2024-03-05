export function update_score(score_to_add, won_or_lost){
	// score_to_add: int (score won on the current game, can be negative)
	// won_or_lost: boolean

    $.ajax({
        url: '/api/update_score/',  // URL of your Django view
        type: 'POST',
        data: {'score': score_to_add,
			   'won': won_or_lost},
        beforeSend: function(xhr) {
            xhr.setRequestHeader("X-CSRFToken", getCookie("csrftoken"));
        },
        success: function(data) {
            if (data.error)
                console.log("Error: ", data.error);
            else
                console.log("prev score:" + data.old_score + " new score:" + data.new_score);
        },
        error: function(xhr, status, error) {
        }
    });
}

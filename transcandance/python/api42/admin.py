from django.contrib import admin

# from .models import User, Game, PlayerScore, PlayerStats
from .models import User


@admin.register(User)
class UserAdmin(admin.ModelAdmin):
    list_display = ('login', 'first_name', 'is_active')
    search_fields = ('login', 'first_name')


# @admin.register(Game)
# class GameAdmin(admin.ModelAdmin):
#     list_display = ('id', 'start_date', 'player_1', 'player_2', 'status')
#     fields = ('start_date', 'player_1', 'player_2', 'status')


# @admin.register(PlayerScore)
# class PlayerScoreAdmin(admin.ModelAdmin):
#     list_display = ('id', 'game', 'player', 'score')
#     fields = ('game', 'player', 'score')


# @admin.register(PlayerStats)
# class PlayerStatsAdmin(admin.ModelAdmin):
#     list_display = ('id', 'player', 'games_played', 'wins', 'losses', 'win_rate')
#     fields = ('player', 'games_played', 'wins', 'losses', 'win_rate')

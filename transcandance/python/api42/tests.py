# from django.test import TestCase
# from api42.models import User
# from api42.models import Game
# from api42.models import PlayerScore
# from django.core.exceptions import ValidationError
# from django.utils import timezone


# class UserTestCase(TestCase):

#     def test_create_user(self):
#         user = User.objects.create(username='test_user', email='test@example.com')
#         self.assertEqual(user.username, 'test_user')
#         self.assertEqual(user.email, 'test@example.com')

#     def test_unique_username(self):
#         user1 = User.objects.create(username='unique_user')
#         user2 = User.objects.create(username='unique_user')
#         self.assertNotEqual(user1.id, user2.id)

#     def test_required_fields(self):
#         with self.assertRaises(ValidationError):
#             User.objects.create(email='test@example.com')
#         with self.assertRaises(ValidationError):
#             User.objects.create(username='test_user')

#     def test_email_validation(self):
#         with self.assertRaises(ValidationError):
#             User.objects.create(username='test_user', email='invalid_email')

#     def test_username_validation(self):
#         with self.assertRaises(ValidationError):
#             User.objects.create(username='')
#         with self.assertRaises(ValidationError):
#             User.objects.create(username='_test_user')


# class GameTestCase(TestCase):

#     def test_create_game(self):
#         game = Game.objects.create(start_date=timezone.now())
#         self.assertEqual(game.start_date, timezone.now())

#     def test_required_fields(self):
#         with self.assertRaises(ValidationError):
#             Game.objects.create()

#     def test_start_date_validation(self):
#         with self.assertRaises(ValidationError):
#             Game.objects.create(start_date='invalid_date')



# class PlayerScoreTestCase(TestCase):

#     def test_create_player_score(self):
#         game = Game.objects.create(start_date=timezone.now())
#         player = User.objects.create(username='test_user')
#         player_score = PlayerScore.objects.create(game=game, player=player, score=100)
#         self.assertEqual(player_score.game, game)
#         self.assertEqual(player_score.player, player)
#         self.assertEqual(player_score.score, 100)

#     def test_required_fields(self):
#         with self.assertRaises(ValidationError):
#             PlayerScore.objects.create()

#     def test_game_and_player_validation(self):
#         with self.assertRaises(ValidationError):
#             PlayerScore.objects.create(game=None)
#         with self.assertRaises(ValidationError):
#             PlayerScore.objects.create(player=None)
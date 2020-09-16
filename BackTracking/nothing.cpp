"About Spotify is an online music streaming service with over 140 million active users and
 over 30 million tracks. One of its popular features is the ability to create playlists, and 
 the service currently hosts over 2 billion playlists. You are posed with the age old 
 recommender problem - given a single song, how do you recommend the next best song from 
 a database of millions of songs, and how do you do this immediately?

Problem Statement The goal is to develop a system for the task of automatic playlist
 continuation. Given a set of playlist features, your systems shall generate a list 
  recommended tracks that can be added to that playlist, thereby ‘continuing’ the playlist.

Resources for the Problem This problem was posed as a challenge in the 12th ACM Conference 
on Recommender Systems, in 2018. A large dataset of playlists and tracks will be provided 
(and the team is free to build on it with additional public datasets), and the team must
 cross reference song IDs with the Spotify Developer API to get detailed metrics about
  tracks like the genre, tempo, acousticness etc. The team must identify and use models
   to learn how playlists are structured and categorised by learning the categorisation
    of songs with each other. The team must also come up with metrics to gauge how well
     a song fits into a playlist - by modifying popular similarity metrics for this task. 

Main Deliverable A model that will take in a single track from the user, and be able to gen
erate a whole playlist from this track that fits the mood and theme of the original song.

Further Work 1. Compare your model objectively on several metrics to the model used by Spot
ify themselves. 2. Explore ways of expanding your model - asking more than one song as an 
input, or starting from a user's personal library. 3. Instead of taking a song as an input,
 take in a sentence or paragraph about how the user is feeling, and generate a playlist for
  it. 

Links https://engineering.atspotify.com/2018/05/30/introducing-the-million-playlist-dataset


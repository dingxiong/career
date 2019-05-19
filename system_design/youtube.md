## Design youtube
- Requirement
    Youtube is website for user to share videos
    - Users can register, post videos
    - Users has favorite list
- Data schema
    - `users` model. `(id, username, email, password_hash, ...)`.
    - `videos` model. `(id, title, description, url, publisher_id, uploaded_at, flags)`. 
- follow up 
    - video storage: Amazon S3 + CDN
    -         
## design chat system
websocket, bosh, long poll http
- Requirement
    1. user A send message to user B. 
        - If B is online, message is delivered to B, and A get acknowledged.
        - If B is offline, notification is send to B and A get acknowledged only after A reads the message.
    2. message app displays whether a friend is online or offline. 
- Schemas
    - `users` (id, email, ...)
    - `messages` (id, sender, receiver, content, media_url, send_at, is_read, read_at, sender_notified, notified_at)
    - `collections` (uer_id, machine_id); stored in distributed cache like Redis
- follow up
    - http persistent connection: websocket
    - encrypt: use a token to encrypt message. store this token in redis `user_a, user_b, token`.
    - so many messages between two users: message compression.
    - support group chat: add a `groups` table (group_id, user_id, join_at) and each message has group_id as foreign key.
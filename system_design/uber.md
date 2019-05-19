Uber is a ride sharing platform
- use case:
    - rider request a driver: (rider_id, rider_loc, destination, car type)
    - driver can accept/deny request
    - rider can cancel ride    
- how uber works: 
    1. driver send location every 4 seconds to Uber.
    2. A rider send a request to Uber in location xxx.
    3. Dispatcher service sends request to location service to get nearby drivers.
- schemas
    - `locations` (user_id, is_driver_or_rider, geo, status(busy, available..))
    - `trips` (id, rider, driver, status, destination)
- problems
    - dispatcher: how to match a demand to supply? 
        - represent each (lng, lat) by an s2 cell
            - reference: http://s2geometry.io/devguide/s2cell_hierarchy.html
        - route optimization
    - pickup point: ML learn from previous data
    - routing & ETA (estimated time of arrival)
        - https://eng.uber.com/engineering-an-efficient-route/
        - open source routing machine (OSRM)
        - Contraction Hierarchies (preprocessing) + Dijkstra
            - reference: https://www.fmi.uni-stuttgart.de/files/alg/teaching/s15/alg/CH.pdf
        -  
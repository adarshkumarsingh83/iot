# Springboot rest api for esp 

----

### To Build the code 
* $ mvn clean package 

### To Run the application 
* $ mvn spring-boot:run 


### To Test the application hit the get api 
``` 
curl -X GET \
http://localhost:8080/api/espark \
-H 'cache-control: no-cache' \
```


### To Test the application hit the post api
``` 
curl -X POST \
http://localhost:8080/api/espark \
-H 'cache-control: no-cache' \
-H 'content-type: application/json' \
-d '{"message":"welcome to the epsark adarsh "}'
```
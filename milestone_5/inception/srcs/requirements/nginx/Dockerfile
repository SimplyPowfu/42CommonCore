FROM	alpine:3.22.1
RUN	apk update && apk upgrade && apk add --no-cache nginx
EXPOSE	443
CMD	["nginx", "-g", "daemon off;"]

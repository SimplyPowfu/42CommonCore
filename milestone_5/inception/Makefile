all:
	@printf "Launch configuration inception...\n"
	@bash srcs/requirements/wordpress/tools/make_dir.sh
	@docker compose -f ./srcs/docker-compose.yml --env-file srcs/.env up -d

build:
	@printf "Building configuration inception...\n"
	@bash srcs/requirements/wordpress/tools/make_dir.sh
	@docker compose -f ./srcs/docker-compose.yml --env-file srcs/.env up -d --build

down:
	@printf "Stopping configuration inception...\n"
	@docker compose -f ./srcs/docker-compose.yml --env-file srcs/.env down

re: down
	@printf "Rebuild configuration inception...\n"
	@docker compose -f ./srcs/docker-compose.yml --env-file srcs/.env up -d --build

.PHONY	: all build down re clean fclean

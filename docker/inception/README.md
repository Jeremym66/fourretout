# Inception Project
This project aims to facilitate setting up a Docker environment for development.

# Required Configuration
Make sure you have Docker installed on your machine before running this project.

# Installation
Clone the GitHub repository to your local machine:

bash
Copy code
git clone https://github.com/jsoulet42/inception.git
Usage
Project Build
# To build the necessary Docker images and start the Docker containers:

bash
Copy code
make
The application will then be accessible at the address: https://jsoulet.42.fr || https://127.0.0.1 || https://127.0.0.1/index.html || https://127.0.0.1/wp-admin

Project Shutdown
# To stop the running Docker containers:

bash
Copy code
make stop
Cleanup
# To remove the Docker containers and built images:

bash
Copy code
make fclean
Notes
Ensure that the ports required by the project are not already in use.
For more details on commands and project structure, refer to the Makefile and configuration files.

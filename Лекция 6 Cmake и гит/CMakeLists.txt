cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME test)				 # задать константу с именем проекта		 
project("${PROJECT_NAME}")			 # имя проекта	


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("inc/")			 # указываем, где искать файлы заголовков

add_executable("${PROJECT_NAME}" main.cpp
								 inc/Func.hpp
								 src/Func.cpp)	# добавить исполняемый файл
								 
file(COPY text.txt DESTINATION "/")	# скопировать файл text.txt в корневую папку проекта
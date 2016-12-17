/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/src/Main.cpp
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */



#include "Main.hpp"



namespace fs = boost::filesystem;

void printBasicUsage(const std::string& appName)
{
	std::cout << "usage: " << appName << " init|build|clean <parameters>" << std::endl;
	std::exit(EXIT_SUCCESS);
}

void processParameters(int argc, char** argv)
{
	std::string			appName = argv[0], action, projectName;
	sc::ProjectManager	projMgr;
	
	if(argc == 1)
		printBasicUsage(appName);
	action = argv[1];
	
	try
	{
		if(action == "init")
		{
			if(argc == 2)
			{
				std::cout << "usage: " << argv[0] << " init <project_name>" << std::endl;
				std::exit(EXIT_SUCCESS);
			}
			projMgr.setPathPrefix(fs::current_path().string());
			projMgr.setProjectName(argv[2]);
			projMgr.initialize();
		}
		else if(action == "addobject"  ||  action == "build"  ||  action == "clean")
		{
			projMgr.setProjectPath(fs::current_path().string());
			if(action == "addobject")
			{
				if(argc == 2)
				{
					std::cout << "usage: " << argv[0] << " addobject <object_name>" << std::endl;
					std::exit(EXIT_SUCCESS);
				}
				projMgr.addObject(argv[2]);
			}
			else if(action == "build")
				projMgr.build();
			else if(action == "clean")
				projMgr.clean();
		}
		else
			printBasicUsage(appName);
	}
	catch(const sc::GeneralException& e)
	{
		std::cerr << action << " error: " << e.what() << std::endl;
	}
}

int main(int argc, char** argv)
{
	processParameters(argc, argv);
	


	/*if(argv[i] == std::string("-l"))
		driver.setTraceLexing(true);
	else if(argv[i] == std::string("-p"))
		driver.setTraceParsing(true);
	else if((result = driver.parse(argv[i])) != 0)
	{
		std::cerr << "compilation terminated due to parsing error " << driver.getResult() << std::endl;
		std::exit(EXIT_FAILURE);
	}

	if(result == 0)
		std::cout << "\n" << ast::stringify(syntaxTree) << "\n";													//output the parsed abstract syntax tree
	sc::Translator::translate(syntaxTree, outputFile);*/
	
	return 0;
}

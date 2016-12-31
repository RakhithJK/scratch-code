/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/ProjectManager.hpp
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



#pragma once



#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <type_traits>

#include <boost/filesystem.hpp>
#include <rapidjson/document.h>
#include <ZipLib/ZipFile.h>

#include "Translator.hpp"
#include "GeneralException.hpp"
#include "Object.hpp"
#include "ObjectParams.hpp"
#include "Resource.hpp"
#include "Costume.hpp"
#include "Sound.hpp"
#include "ManifestEntry.hpp"
#include "ManifestEntryValue.hpp"
#include "ManifestEntryParams.hpp"
#include "ManifestUser.hpp"
#include "ManifestDefinitions.hpp"
#include "Utilities.hpp"



namespace sc
{
	class Object;
	
	class ProjectManager : public ManifestUser<ProjectManager>
	{
		private:
			boost::filesystem::path									projectPath;
			std::shared_ptr<Object>									stageObject;
			std::vector<std::shared_ptr<Object>>					objects;
		
			void													loadAllObjects();
			std::shared_ptr<Object>									getObject(const std::string& objName);
			void													buildProjectJSON(std::shared_ptr<Costume> penLayer, rapidjson::Document& docDest);
			
		public:
			ProjectManager(const boost::filesystem::path& newProjectPath);
		
			void													initialize();
			void													addObject(const std::string& objName, const boost::filesystem::path& objPath, ObjectParams::Type objType=ObjectParams::Type::Generic);
			void													addObject(const std::string& objName, ObjectParams::Type objType=ObjectParams::Type::Generic);
			void													validate();
			void													build();
			void													clean();
			
			const boost::filesystem::path&							getProjectPath();
			std::string												getTitle();
			std::string												getUsername();
			boost::filesystem::path									getBinariesDirectoryPath();
			boost::filesystem::path									getGeneratedFilesDirectoryPath();
			boost::filesystem::path									getObjectsDirectoryPath();
			void													setTitle(const std::string& newTitle);
			void													setUsername(const std::string& newUsername);
			void													setBinariesDirectoryPath(const std::string& newBinariesDirectoryPath);
			void													setGeneratedFilesDirectoryPath(const std::string& newGeneratedFilesDirectoryPath);
			void													setObjectsDirectoryPath(const std::string& newObjectsDirectoryPath);
		
		private:
			template<typename T>
			typename std::enable_if_t<std::is_base_of<Resource, T>::value>
			buildObjectResourceList(const std::vector<std::shared_ptr<T>>& resourceList)
			{
				for(auto it = resourceList.begin(); it != resourceList.end(); ++it)
				{
					auto i = std::distance(resourceList.begin(), it);
					auto p = (*it)->getResourcePath();
					boost::filesystem::copy(p, getGeneratedFilesDirectoryPath() / (std::to_string(i) + p.extension().string()));
				}
			}
	};
}

/*
 *   Copyright 2016 sigalor
 *
 *   File: scratch-code/include/Resource.hpp
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
#include <memory>

#include <boost/filesystem.hpp>
#include <rapidjson/document.h>

#include "Utilities.hpp"



namespace sc
{
	class Resource
	{
		private:
			std::string											md5Sum;
		
		protected:
			std::string											name;
			int													resourceID, resourceIndex;
			boost::filesystem::path								resourcePath;
	
		public:
			Resource();
			
			virtual void										loadFromPath(const boost::filesystem::path& newResourcePath);
			virtual void										buildJSON(rapidjson::Value& valDest, rapidjson::Document::AllocatorType& alloc);
			const std::string&									getName();
			int													getResourceID();									//ID is global (e.g. all costumes have an unique ID)
			int													getResourceIndex();									//index is object-local (e.g. the costume number within an object)
			const boost::filesystem::path&						getResourcePath();
			const std::string&									getMD5Sum();
			void												setName(const std::string& newName);
			void												setResourceID(int newResourceID);
			void												setResourceIndex(int newResourceIndex);
	};
}

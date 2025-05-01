#pragma once  
#include <string>  
#include <vector>
#include <filesystem>
#include <iostream>

class NewProject  
{  
private:  
   std::string _name = "NewProject";
   std::string _path = std::filesystem::current_path().string();
   std::string _templatePath = std::filesystem::current_path().string() + "/ProjectTemplates";

public:
   const std::string& GetName() const  
   {  
       return _name;  
   }  

   void SetName(const std::string& value)  
   {  
       _name = value;  
   }

   const std::string& GetPath() const
   {
       return _path;
   }
   void SetPath(const std::string& value)
   {
       _path = value;
   }

   Newproject()
   {
       try
       {
           std::filesystem::directory_iterator dir(_templatePath);
       }
       catch (const std::filesystem::filesystem_error& e)
       {
           // Handle the error (e.g., log it, display a message, etc.)
           std::cerr << "Error: " << e.what() << std::endl;
   }
};

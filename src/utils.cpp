#include "../include/Utils.hpp"

void install(std::string package)
{
    // Initializing curl
    CURL *installer = curl_easy_init();
    long err_code;
    std::string URL = "https://raw.githubusercontent.com/Llawliet0872/scripts/master/";
    URL += package + ".sh";
    const char *url = URL.c_str();
    // Fetching the installation script from the specified URL
    curl_easy_setopt(installer, CURLOPT_URL, url);
    // Writing the fetched data to a file
    FILE *file = fopen("install.sh", "w");
    curl_easy_setopt(installer, CURLOPT_WRITEDATA, file);
    CURLcode res = curl_easy_perform(installer);
    // Checking if an error occured
    curl_easy_getinfo(installer, CURLINFO_RESPONSE_CODE, &err_code);
    if (err_code == 404)
    {
        std::cout << "Package doesn't exist!" << std::endl;
        remove("install.sh");
    }
    else
    {
        // Closing the file
        fclose(file);
        // Running the script
        system("chmod +x install.sh");
        system("./install.sh");
        // Cleaning up
        curl_easy_cleanup(installer);
        remove("install.sh");
    }
}

void search(std::string keyword)
{
   // Initlializing curl
    CURL *fetcher = curl_easy_init();
    // Writing fetched data to a file
    FILE *temp = fopen("temp", "w");
    curl_easy_setopt(fetcher, CURLOPT_URL, "https://raw.githubusercontent.com/Llawliet0872/scripts/master/packages.txt");
    curl_easy_setopt(fetcher, CURLOPT_WRITEDATA, temp);
    curl_easy_perform(fetcher);
    fclose(temp);
    curl_easy_cleanup(fetcher);
    // Searching the name of the package
    std::string command = "grep -h " + keyword + " temp";
    const char *c = command.c_str();
    system(c);
    // Cleaning up
    system("rm temp");
}

void list()
{
    // Initializing curl
    CURL *curl = curl_easy_init();
    // Fetching data 
    curl_easy_setopt(curl, CURLOPT_URL, "https://raw.githubusercontent.com/Llawliet0872/scripts/master/packages.txt");
    curl_easy_perform(curl);
    // Cleanup
    curl_easy_cleanup(curl);
}

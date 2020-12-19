#include "../include/Utils.hpp"

void install(std::string package)
{
    CURL *installer = curl_easy_init();
    long err_code;
    std::string URL = "https://raw.githubusercontent.com/Llawliet0872/scripts/master/";
    URL += package + ".sh";
    const char *url = URL.c_str();
    curl_easy_setopt(installer, CURLOPT_URL, url);
    FILE *file = fopen("install.sh", "w");
    curl_easy_setopt(installer, CURLOPT_WRITEDATA, file);
    CURLcode res = curl_easy_perform(installer);
    curl_easy_getinfo(installer, CURLINFO_RESPONSE_CODE, &err_code);
    if (err_code == 404)
    {
        std::cout << "Package doesn't exist!" << std::endl;
        remove("install.sh");
    }
    else
    {
        fclose(file);
        system("chmod +x install.sh");
        system("./install.sh");
        curl_easy_cleanup(installer);
        remove("install.sh");
    }
}

void search(std::string keyword)
{
    CURL *fetcher = curl_easy_init();
    FILE *temp = fopen("temp", "w");
    curl_easy_setopt(fetcher, CURLOPT_URL, "https://raw.githubusercontent.com/Llawliet0872/scripts/master/packages.txt");
    curl_easy_setopt(fetcher, CURLOPT_WRITEDATA, temp);
    curl_easy_perform(fetcher);
    fclose(temp);
    curl_easy_cleanup(fetcher);
    std::string command = "grep -h " + keyword + " temp";
    const char *c = command.c_str();
    system(c);
    system("rm temp");
}

void list()
{
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://raw.githubusercontent.com/Llawliet0872/scripts/master/packages.txt");
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
}
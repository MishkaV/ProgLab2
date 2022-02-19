/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:06:47 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/19 11:49:12 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lab.hpp"

std::vector<std::string> input_str()
{   
	std::vector<std::string> def_vec;
	std::string answer;
	int N;
	
	
	std::cout << "Use default params?(Y/n) ";
	std::cin >> answer;

	if (answer == "y" || answer == "Y")
	{
		// Можно через {} указать начальные значения, если компилятор >= 11 
		def_vec.push_back("Helloo");
		def_vec.push_back("World");
		def_vec.push_back("How");
		def_vec.push_back("Aree");
		def_vec.push_back("You");
		def_vec.push_back("apapas");

		return (def_vec);
	}
	
	std:: cout << "Input number of strings: ";
	std:: cin >> N;
	
	std:: cout << "Input strings:\n";
	for (int i = 0; i < N; i++)
	{
		std:: cin >> answer;
		def_vec.push_back(answer);
	}
	return (def_vec);
}

std::string input_substr(std::string def)
{
	std::string answer;
	
	std::cout << "Use default substr?(Y/n) ";
	std::cin >> answer;
	
	if (answer == "y" || answer == "Y")
		return (def);
	
	std:: cout << "Input substr: ";
	std:: cin >> answer;
	return (answer);
}

bool cmp (std::string s1, std::string s2)
{
    return s1.size() < s2.size();
}

std::vector<std::string> delete_odd(std::vector<std::string> vec_str)
{
	std::vector<std::string>::iterator it = vec_str.begin();
	
	while (it != vec_str.end())
		if ((*it).size() % 2)
			it = vec_str.erase(it);
		else 
			it++;
	return (vec_str);
}

std::vector<std::string> sort_str(std::vector<std::string> vec_str)
{
	for (std::vector<std::string>::iterator it = vec_str.begin(); it != vec_str.end(); it++)
		for (std::string::iterator it_str = (*it).begin(); it_str != (*it).end(); it_str += 2)
		{
			char c = *it_str;
			*it_str = *(it_str + 1);
			*(it_str + 1) = c;
		}
	return (vec_str);
}

std::string create_sentence(std::vector<std::string> vec_str, std::string substr)
{
	int count;
	std::string result;
	
	for (std::vector<std::string>::iterator it = vec_str.begin(); it != vec_str.end(); it++)
	{
		count = 0;
		int i = 0;
		for ( i = (*it).find(substr, i++); i != (int)std::string::npos; i = (*it).find(substr, i + 1))
			count++;
		if (count < 3)
			result += *it + " ";
	}

	result.erase(result.size() - 1, 1);
	return (result);
}

int main ()
{
	std::vector<std::string> vec_str = input_str();    
	std::string substr = input_substr("pa");
	std::string result;

	vec_str = delete_odd(vec_str);
	std::sort(vec_str.begin(), vec_str.end(), cmp);
	vec_str = sort_str(vec_str);
	
	result = create_sentence(vec_str, substr);
	std::cout << "Result sentense = " << result;
	return (0);
}
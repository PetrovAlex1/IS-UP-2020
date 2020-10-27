#include <iostream>

int main()
{
	int usbPorts, ram, price, ssd;
	bool hasSSD = false;
	std::cout << "Enter price: ";
	std::cin >> price;
	std::cout << "Enter ram: ";
	std::cin >> ram;
	std::cout << "Enter usb ports: ";
	std::cin >> usbPorts;
	std::cout << "Enter whether it has SSD or not. 0 if it does not have and 1 if it has: ";
	std::cin >> ssd;
	hasSSD = ssd == 1 ? true : false;
	bool priceIsInRange = price > 1000 & price < 1500;
	bool hasExpensiveLaptop = ((usbPorts >= 3) && (ram >= 8) && (hasSSD = true) && priceIsInRange);
	bool hasCheaperLaptop = ((hasSSD = false) && (ram < 8) && (price < 800));
	bool willBuyIt = hasCheaperLaptop || hasExpensiveLaptop;

	if (willBuyIt)
	{
		std::cout << "He will buy the laptop.";
	}
	else
	{
		std::cout << "He will not buy a laptop.";
	}
}
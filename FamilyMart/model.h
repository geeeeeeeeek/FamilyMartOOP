#include <iostream>
#include <vector>

namespace model
{
	class item
	{
	public:
		item(std::string name,double price,int life, std::string product_date)
		{
			this->name=name;
			this->price=price;
			this->life=life;
			this->product_date=product_date;
		}

		std::string get_name()
		{
			return name;
		};
		
		float get_price()
		{
			return price;
		};

	private:
		std::string name;
		double price;
		int life;
		std::string product_date;
	};

	class warehouse
	{
	public:
		int space;
		std::string shop_name;
		warehouse(std::string shop_name,int space,std::vector<item> items)
		{
			this->space=space;
			this->shop_name=shop_name;
			this->items=items;

			std::cout<<shop_name<<" "<<space<<" constructor is invoked."<< std::endl;
		}

		~warehouse()
		{
			close();
		}

		
		warehouse upgrade()
		{
			if (space<100)
			{
				close();
				return warehouse(shop_name,space*2,items);
			}

			return *this;
		}

		void add_items(std::vector<item> its)
		{
			this->items.insert(this->items.end(),items.begin(),items.end());
		}

		void add_item(item it)
		{
			items.push_back(it);
		}

		double remove_item(std::string itname)
		{
			for (std::vector<item>::iterator it = items.begin() ; it != items.end(); ++it)
			{
				if (it->get_name()==itname)
				{
					int price = it->get_price();
					items.erase(it);
					return price;
				}
			}
			return 0;
		}

		std::vector<item> get_items()
		{
			return this->items;
		}

		int get_items_count()
		{
			return items.size();
		}
	private:
		std::vector<item> items;

		void close()
		{
			if (items.size()==space)
			{
std::cout<<shop_name<<" "<<space<<" destructor is invoked."<< std::endl;
			}
		}
	};

	class shop
	{
	public:
		double sales;
		std::string shop_name;
		warehouse *wh;
		shop(std::string name)
		{
			shop_name=name;
			sales=0;
			inited=false;
		}

		void purchase_item(item it)
		{
			if (!inited)
			{
				wh= new warehouse(shop_name,25, std::vector<item>());
				inited=true;
			}
			
			if (wh->get_items_count()==wh->space)
			{
				*wh = wh->upgrade();
			}
			wh->add_item(it);
		}
	
		void sell_item(std::string name,double discount)
		{
			sales+=discount*wh->remove_item(name);
		}
	private:
		bool inited;
	};
}
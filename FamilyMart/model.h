#include <iostream>
#include <vector>

namespace model
{
	class item
	{
		
	public:
		item(std::string name,int id,double price,int life)
		{
			this->name=name;
			this->price=price;
			this->life=life;
			this->id=id;
		}

		std::string get_name()
		{
			return name;
		};
		
		double get_price()
		{
			return price;
		};

		void incr_remains(std::string product_date)
		{
			pieces.push_back(product_date);
		}

		void decr_remains()
		{
			pieces.pop_back();
		}

		int get_remains()
		{
			return this->pieces.size();
		}
	private:
		std::string name;
		double price;
		int id;
		int life;
		std::vector<std::string> pieces;
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

		void add_item(std::string name, std::string product_date)
		{
			for (std::vector<item>::iterator i = items.begin() ; i != items.end(); ++i)
			{
				if (i->get_name()==name)
				{
					//increase remains
					i->incr_remains(product_date);
					return;
				}
			}
		}

		void add_item(item it)
		{
			//if there was no that item before
			items.push_back(it);
		}

		double remove_item(std::string itname)
		{
			for (std::vector<item>::iterator it = items.begin() ; it != items.end(); ++it)
			{
				if (it->get_name()==itname)
				{
					if (it->get_remains()>0)
					{
						it->decr_remains();
						return it->get_price();
					}
						//if sold out
						return 0;
				}
			}
			//if not found
			return -1;
		}

		int get_items_count()
		{
			int count=0;
			for (std::vector<item>::iterator it = items.begin() ; it != items.end(); ++it)
			{
				count+=it->get_remains();
			}
			return count;
		}
	private:
		std::vector<item> items;

		void close()
		{
			if (get_items_count()==space)
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
			records=shop_name+"\n";
		}

		void prepare_item(item it)
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

		void purchase_item(std::string name, std::string product_date)
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
			wh->add_item(name,product_date);
		}
	
		void sell_item(std::string name,double discount)
		{
			double sale=wh->remove_item(name);
			if (sale==-1)
			{
				std::cout << "We do not have "<<name<<"."<< std::endl;
				return;
			}
			if (sale==0)
			{
				std::cout << name<<" is sold out!"<< std::endl;
				return;
			}
			sales+=discount*sale;
			records+=" "+name;
		}

		void add_sell_record_head(std::string head)
		{
			records+=head;
		}

		std::string get_sell_record()
		{
			return records;
		}
	private:
		bool inited;
		std::string records;
	};
}
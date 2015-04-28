####OOP Lab3 (Family Mart)
A lab belonging to the OOP course.

###PART 1. Implementation
####1. Business objects
![enter image description here](https://lh3.googleusercontent.com/-y2HnIuRzvGU/VTttbvzeFfI/AAAAAAAABss/-FChq36_jw4/s0/1.png "1.png")


####2. Business logics
 
 ![enter image description here](https://lh3.googleusercontent.com/-EjkuD65quIc/VTtuFpdOfNI/AAAAAAAABtE/DuXoScHzKB0/s0/2.png "2.png")
 
The event manager controls the whole process. Event manager listens to every user input and publishes it into recognizable event like init/ purchase/ sell/ show_sale_amount/ show_all_shop_name. Then the event manager looks up the subscriber (SHOP1, etc.) of the event and corresponding service (purchase, etc.) that subscriber provides. Finally the event is processed privately by the subscriber.

Take command “purchase purchase.txt” for example. The event manager determines event (PURCHASE), params of the event (20) and subscriber (SHOP1) from the first line. As each line processed into an item, event manager publishes an event to SHOP1. purchase_item (item). Inside purchase_item, warehouse.add_item (item) is invoked.

#### 3. Implemented commands


 - purchase < file > 
 - sell < file > 
 - show_sale_amount
 - show_all_shop_name
 - close

Note that it is a Visual Studio 2012 solution. Use console to input and output.




###PART 2. Overload and default argument
####1. Differences
Both function overloading and default arguments provide a convenience for calling function names.

 - When you overload functions the compiler generates code for each function, probably resulting in larger code size.

 - 	If an overload just acts as a thin wrapper, then the optimizer may eliminate the extra work.

 - 	Default arguments get set at the caller's location, rather than inside the function, so default arguments must be publicly visible, and changing them requires recompiling all callers. With an overload like the pseudo-default argument becomes a hidden detail. 
And guideline from Thinking in C++:

 - 	You shouldn’t use a default argument as a flag upon which to conditionally execute code. You should instead break the function into two or more overloaded functions if you can. A default argument should be a value you would ordinarily put in that position. It’s a value that is more likely to occur than all the rest, so client programmers can generally ignore it or use it only if they want to change it from the default value.

 - 	The default argument is included to make function calls easier, especially when those functions have many arguments with typical values. Not only is it much easier to write the calls, it’s easier to read them, especially if the class creator can order the arguments so the least-modified defaults appear latest in the list. 

 - 	An especially important use of default arguments is when you start out with a function with a set of arguments, and after it’s been used for a while you discover you need to add arguments. By defaulting all the new arguments, you ensure that all client code using the previous interface is not disturbed.  

####2. Usage in my code
 

    void publish(string command, string file="")

Here I use default argument for two reasons. First, this function has over 100 lines of code thus overloading will result in much larger code size. Second, to maintain the flexibility of the command. Also, the second parameter file is frequently used.

Case for overloading? Nope, I didn’t implement one cause no need.

###PART 3. Examples
 ![enter image description here](https://lh3.googleusercontent.com/-kCAMVKVoqgs/VT9AseiCcwI/AAAAAAAABuE/XrwzzvTNd1Y/w657-h430-no/QQ%E6%88%AA%E5%9B%BE20150428155128.png "3.png")

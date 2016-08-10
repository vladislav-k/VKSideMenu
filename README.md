# VKSideMenu
## Description
**VKSideMenu** is a `UITableView`-like menu with blur effect and gestures.<br>
**Note:** blur effect is availabe for iOS 8.0 and later only. You will get a simple UIView with half-transperent background for iOS 7.

![VKSideMenu Demo](https://github.com/vladislav-k/VKSideMenu/blob/master/Demo.gif?raw=true)

## Installation
For now you can install **VKSideMenu** manually only. Just add VKSideMenu folder into your project and `#import VKSideMenu.h` in your parent class.

## Example project
Example project shows how you can create both left-side and right-side **VKSideMenu** in one controller.
To test it it, clone the repo and run it from the Example directory. 

## Usage
Work of **VKSideMenu** is similliar to `UITableView`. Here is an example of menu initialization:
```
// Add VKSideMenuDelegate and VKSideMenuDataSource in your parent class interface

@property (nonatomic, strong) VKSideMenu *menu;

self.menu = [[VKSideMenu alloc] initWithWidth:220 andDirection:VKSideMenuDirectionLeftToRight];
self.menu.dataSource = self;
self.menu.delegate   = self;

// And show it from somewhere in your code
[self.menu show];
```
After initialization you should assign data source and delegate to menu object and declare according methods. It's really easy to use:

```
-(NSInteger)numberOfSectionsInSideMenu:(VKSideMenu *)sideMenu
{
    return 1;
}

-(NSInteger)sideMenu:(VKSideMenu *)sideMenu numberOfRowsInSection:(NSInteger)section
{
	return 3;
}

-(VKSideMenuItem *)sideMenu:(VKSideMenu *)sideMenu itemForRowAtIndexPath:(NSIndexPath *)indexPath
{
	VKSideMenuItem *item = [VKSideMenuItem new];

	switch (indexPath.row)
	{
	case 0:
		item.title = @"Profile";
		item.icon  = [UIImage imageNamed:@"ic_option_1"];
		break;
                
	case 1:
		item.title = @"Messages";
		item.icon  = [UIImage imageNamed:@"ic_option_2"];
		break;
                
	case 2:
		item.title = @"Cart";
		item.icon  = [UIImage imageNamed:@"ic_option_3"];	
		break;
                
	case 3:
		item.title = @"Settings";
		item.icon  = [UIImage imageNamed:@"ic_option_4"];
        break;
                
	default:
		break;
	}
    
    return item;
}

```

This class is very flexible for customization. You can set text colors, text fonts, background etc. See more info in `VKSideMenu.h` file.

## Gestures
You can add Swipe gesture recognition for a specific view. Just use method `addSwipeGestureRecognition:` to enable it.

## Author
Vladislav Kovalyov, http://woopss.com/

## License
**VKSideMenu** is available under the MIT License. See the LICENSE file for more info.
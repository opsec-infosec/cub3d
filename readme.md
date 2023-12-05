![](cub3d.gif)

# 42 Cube 3d Project

## Skills Learned

### Core Skills

- Ray Casting
- Texture mapping
- Memory Management
- Parsing

### Soft Skills

- Teamwork
- Project Management
- Time Management

## Team

Dale Furneaux - https://github.com/opsec-infosec

Alka Santhosh - https://github.com/alka0203

```
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:11:44 by dfurneau          #+#    #+#             */
/*   Updated: 2022/08/31 16:11:44 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:36:07 by asanthos          #+#    #+#             */
/*   Updated: 2022/10/26 13:37:16 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

## Key Features

- Mini map - mini map triggered by ```<space bar>``` shows partial map
- Full size map - full size map triggered by ```'M'``` key.  Shows position of detection points and raycasting
- Debug console - displays useful debugging realtime information
- Parsing - uses allocated memory 'on the fly' to parse the map files
- Sprites - Gun sprite animation

## OS
 - Macos - No known issues
 - Linux - Issue with linux with minilibx with transparent images

## Libft Modifications
Modified Libft:
- ft_realloc - Memory re-allocation function, used in parsing
- ft_strnjoin - String join with variadic function acceptin 1 to n strings
- ft_ato.. - Added ascii to long, int, double, float, long long
- ft_dtoa - Double to ascii
- ft_splitn - splits on delimiter up to n positions


## Maps
### Mandatory
- 1 - Walls
- 0 - Floors
- N,E,W,S - Player Starting Direction
### Bonus
- D - Doors

## Compiling

make all
- makes the mandatory project

make bonus
- makes the bonus

Bonus includes lighting effects, sprite animation, and other features

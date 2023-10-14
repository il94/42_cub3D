<p align="center">
	<img src="https://i.goopics.net/bp0krn.gif">
</p>

<h1 align="center">
	Description
</h1>
<p align="center">
	This is a 42 School group project. The project consists in creating a small 3D environnement using raycasting with the MiniLibX, the school's graphic library. Some walls are a bit special. If so, a little fairy will let you know ;)
</p>

<p align="center">
	This project has been completed in collaboration with <a href="https://github.com/AntoineDouay" target="_blank">@AntoineDouay</a>.
</p>

<h2 align="center">
	Commands
</h2>
<table>
	<tr>
		<td align="center"><code>W</code><br>Move forward</td>
		<td align="center"><code>S</code><br>Move backward</td>
		<td align="center"><code>A</code><br>Move left</td>
		<td align="center"><code>D</code><br>Move right</td>
		<td align="center"><code>🡰</code><br>Look left</td>
		<td align="center"><code>🡲</code><br>Look right</td>
		<td align="center"><code>SPACE</code><br>Open door</td>
		<td align="center"><code>TAB</code><br>Enable mouse</td>
		<td align="center"><code>ESC</code><br>Close game</td>
	</tr>
</table>

<h2 align="center">
	Installation
</h2>

```bash
sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev libxcomposite-dev
sudo apt-get install vlc
git clone https://github.com/il94/42_cub3D cub3D
cd cub3D && make -j
```

<h2 align="center">
	Run
</h2>

```bash
./cub3D [MAP.cub]
```

<p align="center">
	A default map is provided in the "maps" folder, but you can customize it as you want, so enjoy !
</p>

<h2 align="center">
	File map composition
</h2>

<table align="center">
	<tr>
		<td>
			<p align="center">
				First of all, you can choose the images and colors of the rendering
			</p>
		</td>
		<td>
			<table align="center">
				<tr align="center">
					<td>Index</td><td>Format</td>
				</tr>
				<tr align="center">
					<td><code>NO</code></td><td>Image in xpm format of 128x128 (north direction)</td>
				</tr>
				<tr align="center">
					<td><code>SO</code></td><td>Image in xpm format of 128x128 (south direction)</td>
				</tr>
				<tr align="center">
					<td><code>EA</code></td><td>Image in xpm format of 128x128 (east direction)</td>
				</tr>
				<tr align="center">
					<td><code>WE</code></td><td>Image in xpm format of 128x128 (west direction)</td>
				</tr>
				<tr align="center">
					<td><code>F</code></td><td>Image in xpm format of 512x512 /</br>RGB value (sky) </td>
				</tr>
				<tr align="center">
					<td><code>C</code></td><td>RGB value (floor)</td>
				</tr>
			</table>
		</td>
	</tr>
	<tr>
		<td>
			<p align="center">
				Then the map itself, composed of the following characters
			</p>
		</td>
		<td>
			<table align="center">
				<tr align="center">
					<td>Character</td><td align="center">Element</td>
				</tr>
				<tr align="center">
					<td><code>0</code></td><td align="center">Floor</td>
				</tr>
				<tr align="center">
					<td><code>1</code></td><td align="center">Wall</td>
				</tr>
				<tr align="center">
					<td><code>2</code></td><td align="center">Door (closed)</td>
				</tr>
				<tr align="center">
					<td><code>3</code></td><td align="center">Door (opened)</td>
				</tr>
				<tr align="center">
					<td><code>Space</code></td><td align="center">Void</td>
				</tr>
				<tr align="center">
					<td><code>N</code></td><td align="center">Player (looking north)</td>
				</tr>
				<tr align="center">
					<td><code>S</code></td><td align="center">Player (looking south)</td>
				</tr>
				<tr align="center">
					<td><code>E</code></td><td align="center">Player (looking east)</td>
				</tr>
				<tr align="center">
					<td><code>W</code></td><td align="center">Player (looking west)</td>
				</tr>
			</table>
		</td>
	</tr>
	<tr>
		<td>
			<p align="center">
				Example
				<pre>
NO sprites/wall_clouds_2.xpm
SO sprites/wall_clouds_2.xpm
EA sprites/wall_clouds.xpm
WE sprites/wall_clouds.xpm
F 31,163,224
C sprites/wall_stars.xpm</br>

   11
  10011
  1000011
  100000011
  10000000011
111000000000011
10E0000000000001
111000000000011
  10000000011
  100000011
  1000011
  10011
   11</pre></p>
		</td>
		<td>
			<img src="https://i.goopics.net/7nsmqk.png">
		</td>
	</tr>
</table>	

<p>
	To be valid, a map must meet the following conditions :
	<ul>
		<li>being surrounded by walls</li>
		<li>containing only one player</li>
		<li>being composed by only valid characters</li>
		<li>the file containing map must be .cub</li>
	</ul>
</p>
<p>
	By respecting the conditions above, you can create your own maps !
</p>

<h2 align="center">
	Informations
</h2>
<p align="center">
	All sound effects, scores and sprites come from different Nintendo games. True fans will know ;)
</p>

#ifndef DUNE_SCREENPLAYFIELD_H
#define DUNE_SCREENPLAYFIELD_H

class cMapCell;

class cScreenPlayfield {
private:
	cVideoSurface		*_surfaceTileHighlight;
	cVideoSurface		*_surfaceLandscape;							// Current playfield surface
	cVideoSurface		*_surfaceUnits;								// Current unit playfield overlay
	
	size_t				 _width, _height;
	word				 _mapX,		 _mapY;							// New Map X-Y		(Top-Left of the playfield)
	word				 _landscapeX,_landscapeY;					// Currently drawn '_surfaceLandscape' Map X-Y (Top-Left of the playfield)
	word				 _mouseX, _mouseY;

	bool				 _redraw;

	cMapCell		   **_mapCell;									// Current selected map cell									
	word				*_scale;									// Current map scale

			
	void				 drawLandscape();							// Draw landscape to '_surfaceLandscape'
	void				 drawObjects();								// Draw units to '_surfaceUnits'
	void				 drawTileSquares(cVideoSurface *pSurface);							// 
	void				 drawTileSquare( word pMapX, word pMapY );	//
	void				 drawTileSquares( cVideoSurface *pSurface, word pMapIndex, cStructure *pStructure );

	bool				 scrollCheck(size_t X, size_t Y);

public:

						 cScreenPlayfield();
	//					~cScreenPlayfield();
	virtual				~cScreenPlayfield();

			void		 screenPrep();
	virtual void		 draw( cVideoSurface *pSurface );

	void				 mapCellSet( word pX, word pY );

	virtual bool		 mouseMove( size_t pX, size_t pY );

			void		 buttonClear();
	virtual void		 buttonPressLeft( size_t pX, size_t pY );
	virtual void		 buttonPressRight(size_t pX, size_t pY );
	virtual void		 buttonReleaseLeft( size_t pX, size_t pY );
	virtual void		 buttonReleaseRight(size_t pX, size_t pY );

	bool				 mapInScreen( word mapIndex );
	bool				 mapInScreen( size_t pX, size_t pY);

	void				 mapTacticalSet( short int pX, short int pY );

	inline word			 mapXGet()							{ return _mapX; }
	inline word			 mapYGet()							{ return _mapY; }

	inline void			 widthSet( size_t pVal ) {_redraw = true;
													_width = pVal; }

	inline void			 heightSet( size_t pVal ) { _redraw = true;
													_height = pVal; }

	void				 scaleSet();
	inline word			 *scaleGet() { return _scale; }

	inline void			 redrawSet() { _redraw = true; }

};

#endif // DUNE_SCREENPLAYFIELD_H

#ifndef DUNE_MAP_H
#define DUNE_MAP_H

class cMapCell;

class cMap {
private:
	cMapCell					*_mapCells[0x1000];

public:
								 cMap( );
								~cMap();

	void						 mapLoad();												// Load the map from the generator
	
	void						 mapRetile( word pMapIndex, short int pArg_2 );

	word				 sub_1D7E0( word pMapIndex1, word pMapIndex2 );
	size_t				 mapColorGet( word pMapIndex );
	size_t				 mapTileColorGet( word pMapIndex );
	word				 mapTileTypeGet( word pMapIndex );

	word				 sub_57146( word pMapIndex );
	word				 sub_5700A( word pMapIndex, short int pArg_2 );

	inline cMapCell		**mapCellGet( word pMapIndex ) {
		return  &_mapCells[ pMapIndex ];
	}

	inline cMapCell		**mapCellGet( word pX, word pY ) {
		pY &= 0x3F;
		pX &= 0x3F;

		return mapCellGet(posXYtoIndex( pX, pY ));
	}

	sMapPoint		 mapIndexToXY( word mapPos );

	inline word			 mapIndexFromXY( sMapPoint pPoint ) {
		pPoint._X >>= 8;
		pPoint._Y &= 0xFF00;
		pPoint._Y >>= 2;

		return (pPoint._Y | pPoint._X);
	}

	inline sMapPoint		 posAdjust( sMapPoint pPoint ) {
		pPoint._X &= 0xFF00;
		pPoint._X += 0x80;
		pPoint._Y &= 0xFF00;
		pPoint._Y += 0x80;

		return pPoint;
	}

	inline word			 posXFromIndex( word pIndex ) {
		return (pIndex & 0x3F);
	}

	inline word			 posYFromIndex( word pIndex ) {
		return ((pIndex >> 6) & 0x3F);
	}

	// seg012:034C
	inline word			 posXYtoIndex( word pX, word pY ) {				// Convert X/Y into MapArray Index
		return (pX | (pY << 6));
	}

	inline word			 posXMaxYtoIndex( word pX, word pY ) {				// Convert X/Y into MapArray Index
		return posXYtoIndex( pX & 0x3F, pY );
	}
};

#endif // DUNE_MAP_H

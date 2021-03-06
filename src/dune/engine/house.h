#ifndef ENGINE_HOUSE_H
#define ENGINE_HOUSE_H

class cUnit;
class cStructure;
class cTeam;

class cHouse  {
private:
	eHouse							 _houseID;
	sHouseData						*_houseData;
	size_t							 _buildingsHave;						// Each bit indicates one of the building types

	multimap< size_t, cUnit* >	  	 _units;								// Unit Type and Unit Pointer
	multimap< size_t, cStructure*>	 _structures;							// Struct Type and Struct Pointer
	SDL_Palette						*_palette;
	
	dword							 _credits,	_creditQuota, _maxUnits;

	string							_brain;

public:
					 cHouse(  eHouse pHouse );
					~cHouse();
	
	void			 palletePrep();

	cUnit			*unitCreate( word pType, word pHealthPercent, word pMapIndex, byte pAngle, byte pAction );
	cStructure		*structureCreate( word pType, word pHealthPercent, word pMapIndex );
	cTeam			*teamCreate( size_t pAiMode, size_t pMovementType, word arg_6, word pUnitsMax );

	void			 reset();												// Reset the house 
	void			 mapPrepare();											// Prepare units and structures at start of map
	
	void					 buildingsHave( word pTypeIndex, bool pOn );
	inline size_t			 buildingsHaveGet()		{ return _buildingsHave; }		// Get flag of building types that are built
	
	void					 brainSet( string pVal ) { _brain = pVal; }
	inline string			 brainGet() { return _brain; }
	inline eHouse			 houseIDGet()			{ return _houseID; }
	inline SDL_Palette		*paletteGet()			{ return _palette; }
	inline size_t			 colorGet()				{ return _houseData->color; }	// House color palette index
	

	inline dword			 creditGet() { return _credits; }
	inline void				 creditSet( word pVal)			 { _credits = pVal; }

	inline dword			 creditQuotaGet() { return _creditQuota; }
	inline void				 creditQuotaSet( word pVal )	 { _creditQuota = pVal; }

	inline dword			 maxUnitGet() { return _maxUnits; }
	inline void				 maxUnitSet( word pVal)			 { _maxUnits = pVal; }

	sHouseData				*houseDataGet() { return _houseData; }

	multimap< size_t, cUnit* >		*unitsGet()		{ return &_units; }
	multimap< size_t, cStructure*>	*structsGet()	{ return &_structures; }

	void					 unitRemove( cUnit *pUnit );
	void					 structureRemove( cStructure *pStructure );

};

#endif // ENGINE_HOUSE_H

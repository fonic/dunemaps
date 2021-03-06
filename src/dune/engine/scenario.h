#ifndef ENGINE_SCENARIO_H
#define ENGINE_SCENARIO_H

class cMap;
class cMapGenerator;
class cUnit;
class cHouse;
class cTeam;

struct sReinforcement {
	eHouse			 mHouse;
	size_t			 mUnitType;
	size_t			 mDirection;
	word			 mTime;

	bool			 mRepeat;

	sReinforcement() {
		mHouse = eHouse_Harkonnen;
		mUnitType = mDirection = 0;
		mTime = 0;

		mRepeat = false;
	}
};

struct sChoam {
	string			mUnitType;
	int				mCount;
};

class cScenario {
protected:
	cMap						*_map;
	cMapGenerator				*_mapGenerator;
	
	size_t						 _mapSeed, _mapScale, _mapTactical, _mapTimeOut,  _mapCursor, _mapLoseFlags, _mapWinFlags;
	string						 _mapField, _mapBloom, _mapSpecial;
	string						 _pictureLose, _pictureBrief, _pictureWin;

	void						 scenarioMapPrepare();

	void						 unitsLoad();
	void						 structuresLoad();

	vector<sReinforcement>		 mReinforcements;
	vector< cTeam* >			 mTeams;
	vector< sChoam >			 mChoam;
			
public:
								 cScenario( );												// Constructor
	//							~cScenario();				// Destructor
	virtual						~cScenario();				// Destructor

	void						 clear();

	void						 mapSeedSet( string pSeed );

	virtual void				 iniLoad( string pFile, bool pLocalFile );
	virtual void				 iniSave( string pFile );

	void						 reinforcementLoad( string pHouse, string pUnitType, string pDirection, string pTimer, bool pRepeat );

	void						 teamCreate(string pHouseName, string pAiMode, string pMovementType, string pUnitsMin, string pUnitsMax );

	void						 mapLoad();
	void						 teamsLoad();
	void						 teamsClear();

	void						 houseLoad();
	void						 choamLoad();
	void						 reinforcementsLoad();
	void						 reinforcementsClear();

	inline cMap					*mapGet()			{ return _map; }
	inline cMapGenerator		*mapGeneratorGet()	{ return _mapGenerator; }

	inline size_t				 mapScaleLevelGet()				{ return _mapScale; }	
	inline void					 mapScaleLevelSet( size_t pVal ){ _mapScale = pVal; }

	inline size_t				 mapSeedGet()					{ return _mapSeed; }
	inline void					 mapSeedSet( size_t pVal )		{ _mapSeed = pVal; }
	
	inline size_t				 mapTacticalGet()				{ return _mapTactical; }
	inline void					 mapTacticalSet( size_t pVal )	{ _mapTactical = pVal; }

	inline size_t				 mapCursorGet()					{ return _mapCursor; }
	inline void					 mapCursorSet( size_t pVal )	{ _mapCursor = pVal; }

	inline string				 mapFieldGet()					{ return _mapField; }
	inline void					 mapFieldSet( string pVal )		{ _mapField = pVal; }

	inline string				 mapBloomGet()					{ return _mapBloom; }
	inline void					 mapBloomSet( string pVal )		{ _mapBloom = pVal; }

	inline string				 mapSpecialGet()					{ return _mapSpecial; }
	inline void					 mapSpecialSet( string pVal )		{ _mapSpecial = pVal; }
	
	inline size_t				 mapTimeoutGet()					{ return _mapTimeOut; }
	inline void					 mapTimeoutSet( size_t pVal )	{ _mapTimeOut = pVal; }
	
	inline size_t				 mapLoseFlagsGet()					{ return _mapLoseFlags; }
	inline void					 mapLoseFlagsSet( size_t pVal )	{ _mapLoseFlags = pVal; }

	inline size_t				 mapWinFlagsGet()					{ return _mapWinFlags; }
	inline void					 mapWinFlagsSet( size_t pVal )	{ _mapWinFlags = pVal; }

	inline string				 pictureLoseGet()					{ return _pictureLose; }
	inline void					 pictureLoseSet( string pVal )		{ _pictureLose = pVal; }

	inline string				 pictureBriefGet()					{ return _pictureBrief; }
	inline void					 pictureBriefSet( string pVal )		{ _pictureBrief = pVal; }

	inline string				 pictureWinGet()					{ return _pictureWin; }
	inline void					 pictureWinSet( string pVal )		{ _pictureWin = pVal; }

	inline vector<sReinforcement>	*reinforcementsGet() { return &mReinforcements; }
	inline vector< cTeam* >			*teamsGet()			 { return &mTeams; }
	inline vector< sChoam >			*choamGet()			 { return &mChoam; }
};

#endif // ENGINE_SCENARIO_H

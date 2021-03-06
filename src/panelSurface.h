///-----------------------------------------------------------------
///
/// @file      panelSurface.h
/// @author    Robert
/// Created:   13/11/2010 16:50:28
/// @section   DESCRIPTION
///            cPanelSurface class declaration
///
///------------------------------------------------------------------

#ifndef MAIN_PANELSURFACE_H
#define MAIN_PANELSURFACE_H

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/menu.h>
////Header Include End

#include <wx/dcbuffer.h>

////Dialog Style Start
#undef cPanelSurface_STYLE
#define cPanelSurface_STYLE wxSYSTEM_MENU
////Dialog Style End

class cMapCell;

class cPanelSurface : public wxPanel
{
	private:
		DECLARE_EVENT_TABLE();
				
		size_t						 mScale;
		wxCoord						 mMouseX, mMouseY;
		wxTimer						*mTimer;
		bool						 mMouseIgnore;
		cMapCell					**mMapCell;
		
		void						 menuOrdersBuild();

	public:
		cPanelSurface(wxWindow *parent, wxWindowID id = 1, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
		virtual ~cPanelSurface();
		
		void menuOrdersReset();

	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxMenu *mPopupStructure;
		wxMenu *mPopupUnit;
		wxMenu *mPopupUnitOrders;
		wxMenu *mPopupTerrain;
		////GUI Control Declaration End

	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_MNU_DELETE_1009 = 1009,
			
			ID_MNU_UNITROTATE_1003 = 1003,
			ID_MNU_STARTINGORDERS_1004 = 1004,
			ID_MNU_ORDER_2000 = 2000,
			ID_MNU_DELETE_1005 = 1005,
			
			ID_MNU_ADDBLOOM_1001 = 1001,
			ID_MNU_ADDSPICEFIELD_1002 = 1002,
			ID_MNU_ADDSPECIAL = 1003,
			ID_MNU_DELETE = 1008,
			
			////GUI Enum Control ID End
			inputTimer,
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void OnPaint(wxPaintEvent& event);
		void OnSize(wxSizeEvent& event);
		void OnMouse(wxMouseEvent& event);
		void OnInputTimer(wxTimerEvent& event);

		void CreateGUIControls();

public:

		void cPanelSurfaceRightDown(wxMouseEvent& event);
		void playfieldSizeUpdate( size_t pScale = 0, size_t pWidth = 0, size_t pHeight = 0  );
		void Mnuaddbloom1001Click(wxCommandEvent& event);
		void Mnuaddspicefield1002Click(wxCommandEvent& event);
		void Mnuunitrotate1003Click(wxCommandEvent& event);
		void menuActionSet(wxCommandEvent& event);
		void Mnudelete2001Click(wxCommandEvent& event);

		unsigned short	MapIndexGet();
		cMapCell	**MapCellGet() { return mMapCell; }
		void MnuaddspecialClick(wxCommandEvent& event);

};

#endif // MAIN_PANELSURFACE_H

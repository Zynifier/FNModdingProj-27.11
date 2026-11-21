// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUIExtensionSlot.generated.h"

UENUM(BlueprintType)
enum class EUIExtensionSlot : uint8
{
	/** Not used */
	Invalid = 0,
	/**
	 * Allows the UI extension to provide a custom widget that's inserted in the primary slot of the HUD overlaying all
	 * standard (persistent) HUD content, things like the compass, health bar, team view, minimap are in this layer.
	 */
	Primary = 1,
	/** Slot for the same as Primary, but nested higher in the widget hierarchy to allow for other widgets to draw on top */
	Secondary = 2,
	/** Slot for anchoring UI to the top right corner under the minimap */
	TopRightCorner = 3,
	/** Slot for appending UI elements to the HUD game counters (timer, killcount, etc) */
	GameInfoBox = 4,
	/** Slot for appending UI elements to the quickbar. */
	Quickbar = 5,
	/** Slot for appending UI elements underneath/behind the quickbar. */
	QuickbarUnderlay = 6,
	/** Slot for anchoring UI within the prioritized switcher where storm messages are @see IFortPrioritizedWidget */
	UpperCenter = 7,
	/** Slot for anchoring UI near the crosshair, on the right */
	CrosshairRight = 8,
	/** Slot that appears under the squad info */
	UnderSquadInfo = 9,
	/** In the full screen map widget, to the right of the widget */
	FullScreenMap = 10,
	/** Show below the respawn counter when respawning */
	BelowRespawnWidget = 11,
	/** Sits right below the compass */
	BelowCompass = 12,
	/** under each team mate status widget */
	UnderTeammateStatus = 13,
	/** Where controller binding callouts are for vehicles and alternate modes. */
	ControllerBindingCallout = 14,
	/** Just above where the storm messages are. */
	AboveStormMessageSlot = 15,
	/** A Space to put custom minigame Callouts */
	CustomMinigameCallouts = 16,
	/** Below Local Player Health/Shields */
	UnderLocalPlayerInfo = 17,
	/** Overlay behind the Player's Health Bar */
	PlayerHealthbarOverlay = 18,
	/** Overlay on top of the Player's Health Bar */
	PlayerOverHealthbarOverlay = 19,
	/** Container for messages under the minimap */
	UnderMinimapMessageContainer = 20,
	/** Vehicle actions horizontal box spacer */
	VehicleActionsSpacer = 21,
	/** Replacement for standard inventory menu */
	InventoryScreenReplacement = 22,
	/** Centered around the reticle */
	Reticle = 23,
	/** Inserted into prioritized switcher where the killfeed is. @see IFortPrioritizedWidget  */
	KillfeedSlot = 24,
	/** Inserted into the Context tutorial priority switcher, which is on the left of the screen. */
	PrioritizedContextualSlot = 25,
	/** Added to the right of each team mate status widget in the top left of the screen */
	RightOfTeammateStatus = 26,
	/** Added to the right of each team mate status bars widget in the top left of the screen */
	RightOfTeammateStatusBars = 27,
	/** Added as an overlay on the portrait of each teammate status widget in the top left of the screen */
	TeammateStatusPortraitOverlay = 28,
	/** Added as an underlay on the portrait of each teammate status widget in the top left of the screen */
	TeammateStatusPortraitUnderlay = 29,
	/** Added as an overlay on the portrait of each teammate status widget in the in-game-menus (match recap, ready up, etc) */
	TeammateStatusPortraitOverlay_IGM = 30,
	/** Added as an overlay on the top of the team mate healthbar*/
	TeammateOverHealthbarOverlay = 31,
	/** Added as an overlay on the top of the team mate shieldbar*/
	TeammateOverShieldbarOverlay = 32,
	/** The bottom right corner of the Mobile HUD */
	MobileHUDBottomRight = 33,
	/** Added as an additional major tab on the inventory screen */
	InventoryScreenTab = 34,
	/** Added as an additional sub tab on the inventory panel */
	InventoryPanelSubTab = 35,
	/** Overlay that includes the Minimap, MapKey, and SkydivingInfoWidget */
	MiniMapOverlay = 36,
	/** Overlay that Sits above the resources, ingredients, and backpack icon */
	AboveResourcesOverlay = 37,
	/** Overlay that Sits under the resources, ingredients, and backpack icon, used for the no build icon*/
	UnderResourcesOverlay = 38,
	/** Added to quickbar equip slot on the inventory panel */
	InventoryEquipSlot = 39,
	/** Added to the item info panel on the inventory screen below the item type */
	InventoryItemInfoBelowItemType = 40,
	/** Added to the equipped item info shown on the HUD next to the quick bars */
	HUDEquippedItemInfo = 41,
	/** Added to the equipped item info AMMO section shown on the HUD next to the quick bars */
	HUDEquippedItemInfo_Ammo = 42,
	/** Appends widgets to the vertical box list in AthenaSquadInfo, starting underneath the teammate status entry list */
	UnderneathTeammateStatusList = 43,
	/** Overlay for the SquadEliminations widget in BP_AthenaMapGameInfo  */
	FullScreenMapSquadEliminationsOverlay = 44,
	/** Overlay for the Athena Map Storm Info widget in BP_AthenaMapStormInfo */
	FullScreenMapStormInfo = 45,
	/** Added to primary quick bar slots on the HUD */
	PrimaryQuickBarSlot = 46,
	/** Added to Main Menu button list in zone */
	MainMenuButtonListInZone = 47,
	/** Added to Main Menu button list in the Front End */
	MainMenuButtonListFrontEnd = 48,
	/** Added to the Dynamic Overlay in the Front End Lobby */
	DynamicOverlayLobby = 49,
	/** Added to the overlay on the Post match xp recap screen */
	PostMatchXPRecap = 50,
	/** Added to the right side on the Post match xp recap screen */
	PostMatchXPRecap_RightSide = 51,
	/** Added to the top left side on the Post match xp recap screen */
	PostMatchXPRecap_TopLeft = 52,
	/** Added under the Mobile Minimap in-game container */
	MobileHUDUnderMinimap = 53,
	/** Added under the Sidebar panel list */
	SidebarPanels = 54,
	/** Spectator player status info */
	SpectatorRightOfPlayerStatus = 55,
	/** Eliminated screen status overlay */
	LastKillerInfoStatus = 56,
	/** Behind mobile Local Player Health/Shields */
	BehindMobileLocalPlayerInfo = 57,
	/** Under Mobile Local Player Health/Shields */
	UnderMobileLocalPlayerInfo = 58,
	/** Above Mobile Local Player Health/Shields */
	AboveMobileLocalPlayerInfo = 59,
	/** Added to the Dynamic Overlay on entire FrontEnd */
	DynamicOverlayFrontEnd = 60,
	/** Added to the NPC status widget 'bars prefix' slot */
	NPCStatusWidgetBarsPrefix = 61,
	/** Added to the NPC status widget 'above bars' section */
	NPCStatusWidgetAboveBars = 62,
	/** Added to the Player Indicator widget 'above' section */
	AbovePlayerIndicatorWidget = 63,
	/** Athena Dashboard Widget general overlay  */
	AthenaDashboardWidgetOverlay = 64,
	/** For adding tabs to the fullscreen map */
	FullScreenMapTab = 65,
	/** For adding tabs to the post match screen*/
	PostMatchScreenTab = 66,
	/** Above Mobile Reload Weapon widget */
	AboveBacchusEquippedItemReloadWidget = 67,
	/** For adding additional rows to Inventory Panels */
	InventoryExtensionRow = 68,
	/** For adding additional widgets underneath all elements of LobbyDetails in the frontend */
	UnderDefaultLobbyDetails = 69,
	/** For underlay elements on the 'visited' or 'landmark' display */
	VisitedAreaDisplayUnderlay = 70,
	/** For text underlay elements on the 'discovered' display*/
	DiscoveredAreaTextUnderlay = 71,
	/** For adding a widget that fills the stamina bar */
	StaminaOverlay = 72,
	//For the level up widget at the left-side of the screen

	LevelUpMobile = 73,
	// Exp stacking in the middle of the screen

	ExpMobile = 74,
	/** Used to replace the current resources panel in the inventory */
	InventoryGroupPanel = 75,
	/** Slot for Replacing the quickbar editor in the inventory. */
	InventoryQuickbarEditor = 76,
	/** Slot for replacing the POI visited MainBox layout. Still uses the same animations. */
	VisitedAreaDisplayMainBoxOverride = 77,
	/** Added to the item info panel on the inventory screen below the item name */
	InventoryItemInfoContents = 78,
	/** Slot for adding Discover into the Lobby. */
	DiscoverInLobby = 79,
	/** Currently, the same as the killfeed slot for mobile, but this is mobile only. */
	PlaylistUIExtensionMobile = 80,
	/** Added to the item info panel on the inventory screen while in preview [unexpanded] mode */
	InventoryItemInfoInspectPreview = 81,
	//Used to iterate the enum

	Count = 82 UMETA(Hidden),
};


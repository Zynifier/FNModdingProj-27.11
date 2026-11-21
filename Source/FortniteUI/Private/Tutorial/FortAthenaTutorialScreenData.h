// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Layout/Margin.h"
#include "Math/MathFwd.h"
#include "Widgets/Layout/Anchors.h"
#include "Athena/Tutorial/FortAthenaTutorialBase.h"
#include "FortAthenaTutorialScreenData.generated.h"

class UUserWidget;

UENUM()
enum class EFortAthenaTutorialScreenExtraWidget : uint8
{
	None = 0,
	DragToTurn = 1,
	Completed = 2,
	Count = 3,
};

UENUM()
enum class EFortAthenaTutorialStep : uint8
{
	Look = 0,
	Move = 1,
	Harvest = 2,
	Clamber = 3,
	Pickup = 4,
	Shoot = 5,
	Ambush = 6,
	Heal = 7,
	Build = 8,
	Chest = 9,
	Scoping = 10,
	Completed = 11,
	Count = 12,
};

UENUM()
enum class EFortAthenaTutorialSubstep : uint8
{
	//Look

	ScreenSwipeToLook = 0,
	ScreenFindMarker = 1,
	//Move

	ScreenUseLeftStick = 2,
	ScreenMoveToBuilding = 3,
	ScreenJump = 4,
	ScreenCrouch = 5,
	//Harvest

	ScreenReachMarker = 6,
	ScreenUsePickaxe = 7,
	//Clamber

	ScreenReachClamber = 8,
	ScreenClamber = 9,
	//Pickup

	ScreenReachPickUp = 10,
	ScreenPickUpItems = 11,
	ScreenEquipItem = 12,
	//Shoot

	ScreenShootTargets = 13,
	ScreenReload = 14,
	//Ambush

	ScreenReachLocation = 15,
	ScreenDefendYourself = 16,
	ScreenHealthAlert = 17,
	ScreenDestroyEnemies = 18,
	//Heal

	ScreenCollectLoot = 19,
	ScreenUseMedkit = 20,
	ScreenUseShield = 21,
	ScreenShieldInfo = 22,
	//Build

	ScreenLookForChest = 23,
	ScreenChestFound = 24,
	ScreenSelectBuildMode = 25,
	ScreenShowMaterials = 26,
	ScreenShowBuildPieces = 27,
	ScreenSelectStairs = 28,
	ScreenPlaceStairs = 29,
	ScreenReachChest = 30,
	ScreenExitBuildMode = 31,
	//Chest

	ScreenLootChest = 32,
	ScreenCollectLootChest = 33,
	//Scoping

	ScreenEquipRifle = 34,
	ScreenUseScope = 35,
	ScreenShootTargetsScoping = 36,
	//Completed

	ScreenCompleted = 37,
	//Standalone

	HealingInterrupted = 38,
	Count = 39,
};

USTRUCT(BlueprintType)
struct FFortAthenaTutorialHighlightInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialHighlightInfo")
	FGameplayTag WidgetToHighlight;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialHighlightInfo")
	FGameplayTag ItemHighlightTag;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialHighlightInfo")
	FMargin HighlightMargin;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialHighlightInfo")
	TSoftClassPtr<UUserWidget> HighlightWidgetOverride;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialHighlightInfo")
	bool bIsLegacyHighlight;

};

USTRUCT(BlueprintType)
struct FFortAthenaTutorialScreenInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialScreenInfo")
	EFortAthenaTutorialSubstep Substep;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialScreenInfo")
	FVector2D TextPromptPosition;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialScreenInfo")
	FVector2D TextPromptPosition_AthenaHUD;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialScreenInfo")
	FAnchors TextPromptAnchors;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialScreenInfo")
	FAnchors TextPromptAnchors_AthenaHUD;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialScreenInfo", meta=(MultiLine="TRUE"))
	FText TextPromptText_Touch;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialScreenInfo", meta=(MultiLine="TRUE"))
	FText TextPromptText_Gamepad;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialScreenInfo", meta=(MultiLine="TRUE"))
	FText TextPromptText_TouchLegacy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAthenaTutorialScreenInfo", meta=(AllowPrivateAccess="TRUE"))
	FDataTableRowHandle ActionWidget_DataTableRow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAthenaTutorialScreenInfo")
	TArray<FName> KeybindWidget_NameArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAthenaTutorialScreenInfo")
	TArray<FName> KeybindWidget_GamepadNameArray;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialScreenInfo")
	bool ForceSingleInputKeybind;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialScreenInfo")
	TArray<FFortAthenaTutorialHighlightInfo> HighlightInfo;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialScreenInfo")
	bool DisplayNextButton;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialScreenInfo")
	bool DisplayTextPromptTarget;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialScreenInfo")
	EFortAthenaTutorialScreenExtraWidget ExtraWidget;

};

USTRUCT(BlueprintType)
struct FFortAthenaStandaloneTutorialStepInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAthenaStandaloneTutorialStepInfo")
	TArray<FFortAthenaTutorialScreenInfo> StepScreenInfo;

};

USTRUCT(BlueprintType)
struct FFortAthenaTutorialStandaloneStepInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialStandaloneStepInfo")
	EFortAthenaTutorial_StandaloneStep StandaloneStep;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialStandaloneStepInfo")
	FFortAthenaTutorialScreenInfo StepScreenInfo;

};

USTRUCT(BlueprintType)
struct FFortAthenaTutorialStepInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialStepInfo")
	EFortAthenaTutorialStep TutorialStep;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialStepInfo")
	TArray<FFortAthenaTutorialScreenInfo> StepScreenInfo;

};

UCLASS()
class UFortAthenaTutorialScreenData : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialScreenData")
	TArray<FFortAthenaTutorialStepInfo> TutorialSteps;

	UPROPERTY(EditAnywhere, Category="FortAthenaTutorialScreenData")
	TArray<FFortAthenaTutorialStandaloneStepInfo> StandaloneTutorialSteps;

};


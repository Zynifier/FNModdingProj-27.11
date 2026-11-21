// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/RichTextBlock.h"
#include "Layout/Margin.h"
#include "Styling/SlateColor.h"
#include "Types/SlateEnums.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "FortHUDMessageData.h"
#include "AthenaWinConditionMsgBase.generated.h"

class AFortGameState;
class AFortVolume;
class APlayerState;
enum class ESpatialLoadingState : uint8;

UENUM(BlueprintType)
enum class EWinConditionParentType : uint8
{
	None = 0,
	// Default

	Desktop = 1,
	// For desktop and console HUDs

	Mobile = 2,
};

USTRUCT(BlueprintType)
struct FWinConditionPlacementData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WinConditionPlacementData")
	FMargin Padding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WinConditionPlacementData")
	TEnumAsByte<EHorizontalAlignment> HorizontalAlignment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WinConditionPlacementData")
	TEnumAsByte<EVerticalAlignment> VerticalAlignment;

};

USTRUCT(BlueprintType)
struct FWinConditionPlacementDataMapWrapper
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WinConditionPlacementDataMapWrapper")
	TMap<EHUDMessagePlacement, FWinConditionPlacementData> Data;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaWinConditionMsgBase : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void BindVolumeManagerEvents();

	UFUNCTION(BlueprintImplementableEvent, Category="Game State", meta=(DisplayName="On GameState Initialized"))
	void BP_OnGameStateInitialized(AFortGameState* GameState);

	UFUNCTION(BlueprintImplementableEvent, Category="Minigame", meta=(DisplayName="On Minigame Ended"))
	void BP_OnMinigameEnded();

	UFUNCTION(BlueprintImplementableEvent, Category="HUD Message", meta=(DisplayName="On Show HUD Message"))
	void BP_OnShowHUDMessage(FHUDMessageData MessageData);

	UFUNCTION(BlueprintPure)
	FSlateColor GetTextFillColor(const FRichTextStyleRow& Row) const;

	UFUNCTION()
	void HandleEnteredVolume(APlayerState* ClientState, AFortVolume* Volume);

	UFUNCTION()
	void HandleExitVolume(APlayerState* ClientState, AFortVolume* Volume);

	UFUNCTION()
	void HandleGameStateInitialized(AFortGameState* GameState);

	UFUNCTION()
	void HandleMinigameEnded();

	UFUNCTION()
	void HandlePlaylistInitialized();

	UFUNCTION()
	void HandleSpatialLoadingStateChanged(ESpatialLoadingState NewState, AFortVolume* Volume);

	UFUNCTION()
	void OnShowHUDMessage(FHUDMessageData MessageData);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaWinConditionMsgBase")
	FFortPrioritizedWidgetData PrioritizedWidgetData;

};


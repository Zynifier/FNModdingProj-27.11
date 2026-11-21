// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Fonts/SlateFontInfo.h"
#include "Math/Color.h"
#include "Styling/SlateBrush.h"
#include "UI/HUDIndicator/FortMiniMapIndicator.h"
#include "FortMiniMapTeamIndicators.generated.h"

class AFortPlayerController;
class AFortPlayerControllerSpectating;
class UAthenaIndicatorPlayersCache;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortMiniMapTeamIndicators : public UFortMiniMapIndicator
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> PlayerController;

	UPROPERTY(Transient)
	bool bSpectating;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerControllerSpectating> SpectatorPC;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaIndicatorPlayersCache> IndicatedPlayersCache;

	UPROPERTY(Transient)
	float PlatformScale;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush SquadPlayerBrush;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush TeamPlayerBrush;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush EnemyPlayerBrush;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush SpectatedPlayerBrush;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush SpectatedPlayerVehicleBrush;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush MiniMapIconBrushDBNO;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FLinearColor MinimapIconColorSelf;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FLinearColor MinimapIconColorTeammate;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FLinearColor MinimapIconColorEnemy;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	TArray<FLinearColor> MinimapIconColorEnemy_MultiTeam;

	UPROPERTY(EditDefaultsOnly, Category="Spectating")
	FSlateBrush PlayerNameBackgroundBrush;

	UPROPERTY(EditDefaultsOnly, Category="Spectating")
	FSlateFontInfo PlayerNameFontInfo;

};


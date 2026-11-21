// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Fonts/SlateFontInfo.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Layout/Margin.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "FortMiniMapInterface.h"
#include "FortWorldSettings.h"
#include "Quests/FortQuestIndicatorData.h"
#include "FortFrontEndMiniMapManager.generated.h"

class UFortQuestItemDefinition;
class UMaterialInstanceDynamic;
class UMaterialInterface;

UCLASS(Abstract, Config=Game, DefaultConfig, MinimalAPI)
class AFortFrontEndMiniMapManager : public AActor, public IFortMiniMapInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FFortChallengeMapPoiData> PoiDataConfigOverrides;

	UPROPERTY(Config)
	TArray<FString> ExcludedFromMapNameDisplayPOIs;

	UPROPERTY(Config)
	int32 MapLocationFontSizeOverride;

	UPROPERTY(EditAnywhere, Category="Map Locations", meta=(ArraySizeEnum="/Script/FortniteGame.EMapLocationStateType"))
	FLinearColor DefaultMapLocationFontColor[3];

	UPROPERTY(EditAnywhere, Category="Map Locations")
	FSlateFontInfo DefaultMapLocationFont;

	UPROPERTY(EditAnywhere, Category="Map Locations")
	uint32 MobileMapLocationFontSizeOverride;

	UPROPERTY(EditAnywhere, Category="FortFrontEndMiniMapManager")
	FGameplayTag SpybaseTag;

	UPROPERTY(EditAnywhere, Category="FortFrontEndMiniMapManager")
	TObjectPtr<UFortQuestItemDefinition> NamedLocationQuestItemDefinition;

	UPROPERTY(EditAnywhere, Category="FortFrontEndMiniMapManager")
	TObjectPtr<UFortQuestItemDefinition> POIQuestItemDefinition;

	UPROPERTY(EditAnywhere, Category="Camera")
	int32 MapLayerSize;

	UPROPERTY(EditAnywhere, Category="Camera")
	FMargin MapMargin;

	UPROPERTY(EditAnywhere, Category="Camera")
	TObjectPtr<UMaterialInterface> MapMaterial;

	UPROPERTY(EditAnywhere, Category="Camera")
	TObjectPtr<UMaterialInterface> MapMaskMaterial;

	UPROPERTY(EditAnywhere, Category="FortFrontEndMiniMapManager")
	float MapWorldScale;

	UPROPERTY(EditAnywhere, Category="FortFrontEndMiniMapManager")
	FVector2D CaptureResolution;

	UPROPERTY(Transient)
	TMap<FGameplayTag, FMapLocationRenderData> MinimapLocationRenderData_Player1;

	UPROPERTY(Transient)
	TMap<FGameplayTag, FMapLocationRenderData> MinimapLocationRenderData_Player2;

	UPROPERTY(Transient)
	FSlateFontInfo MapLocationFont;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> MapMaterialMID;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> MapMaskMaterialMID;

};


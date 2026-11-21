// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/LayoutProfile/FortMobileHUDLayoutProfile.h"
#include "DynamicUI/DynamicUIDirectorBase.h"
#include "DynamicUI/DynamicUIWidgetTarget.h"
#include "DynamicBacchusHUDDirector.generated.h"

class UDynamicUIMobileScene;
class UDynamicUIScene;
class UFortMobileHUDWidgetRegistry;

UCLASS(HideCategories=("Actor", "ActorTick", "Collision", "Cooking", "DataLayers", "Events", "HLOD", "Input", "LOD", "Physics", "Rendering", "Replication", "WorldPartition"))
class DYNAMICBACCHUSHUD_API ADynamicBacchusHUDDirector : public ADynamicUIDirectorBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FGameplayTagContainer CurrentContextTags;

	UPROPERTY(Transient)
	FFortMobileHUDLayoutProfile LayoutProfile;

private:
	UPROPERTY(EditDefaultsOnly, Category="Touch Control Region")
	FDynamicUIWidgetTarget TouchControlRegionWidget;

	UPROPERTY(EditAnywhere, Category="Customizable HUD", meta=(DisplayName="Base HUD Widget Registry"))
	TObjectPtr<UFortMobileHUDWidgetRegistry> BaseHUDWidgetRegistry;

	UPROPERTY(EditAnywhere, Category="Development Testing", meta=(DisplayName="Watermark Scene"))
	TObjectPtr<UDynamicUIScene> WatermarkScene;

	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<UDynamicUIMobileScene>> ScenesPool;

	UPROPERTY(Transient)
	TObjectPtr<UFortMobileHUDWidgetRegistry> HUDWidgetRegistry;

};


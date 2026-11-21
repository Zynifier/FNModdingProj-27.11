// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "GameplayTagContainer.h"
#include "FortPoiVolume.generated.h"

class UDataLayerAsset;
class UFortPoiCollisionComponent;
class UShapeComponent;

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Collision", "Brush", "Physics", "Object", "Blueprint", "Display", "Rendering", "Physics", "Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortPoiVolume : public AVolume
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool ContainsLocationTag(const FGameplayTag& Tag) const;

	UFUNCTION(BlueprintCallable)
	bool DoesShapeComponentOverlap(UShapeComponent* Shape);

#if WITH_EDITOR
	UFUNCTION(Category="BrushSettings", meta=(CallInEditor="true"))
	void FixBoxScaling();
#endif

	UFUNCTION(BlueprintPure)
	UDataLayerAsset* GetPoiDataLayer() const;

	UPROPERTY(VisibleAnywhere, Category="DesignHelp")
	bool bIsLargeGameVolume;

	UPROPERTY(VisibleAnywhere, Category="DesignHelp")
	float CurrentFortPoiVolumeSize;

	UPROPERTY(VisibleAnywhere, Category="DesignHelp")
	float VolumeThresholdForLargeGameVolume;

protected:
	UPROPERTY(Config)
	float LargeGameVolume;

	UPROPERTY(EditAnywhere, Category="GameplayTag")
	TArray<FString> EventsEnabledDuring;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayTag")
	FGameplayTagContainer LocationTags;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortPoiCollisionComponent> PoiCollisionComp;

	UPROPERTY(EditAnywhere, Category="FortPoiVolume")
	TObjectPtr<UDataLayerAsset> PoiDataLayer;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortPoiVolume")
	bool bExcludeFromQuestMapMarkers;
#endif

private:
	UFUNCTION()
	void CalendarEventsShouldBeReady(const TArray<FString>& NewEvents);

};


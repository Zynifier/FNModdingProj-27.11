// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Cosmetics/Items/AthenaEmojiItemDefinition.h"
#include "AthenaShoutItemDefinition.generated.h"

class UAudioComponent;
class UObject;
class USceneComponent;
class USoundBase;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("FrontendPreview", "ParticleSystem", "Variants", "Visual", "Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition", "Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaShoutItemDefinition : public UAthenaEmojiItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Audio")
	void ConfigureSoundComponent(TSoftObjectPtr<USoundBase> OverrideSound, UAudioComponent* ComponentToConfigure) const;

protected:
	UFUNCTION(BlueprintCallable, Category="Audio", meta=(WorldContext="WorldContext"))
	void SpawnSoundComponent(TSoftObjectPtr<USoundBase> OverrideSound, USceneComponent* Component, FVector LocationAt, UAudioComponent*& SpawnedComponent, UObject* WorldContext);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	TSoftObjectPtr<USoundBase> ShoutSound;

	UPROPERTY(Export, meta=(EditInline="true"))
	TSet<TObjectPtr<UAudioComponent>> TemporarilyHeldAudioComponents;

};


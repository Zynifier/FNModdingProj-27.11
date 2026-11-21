// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Cosmetics/Items/AthenaDanceItemDefinition.h"
#include "AthenaEmojiItemDefinition.generated.h"

class UAnimMontage;
class UMaterialInstance;
class UMaterialInterface;
class UParticleSystemComponent;
class UTexture2D;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition", "Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaEmojiItemDefinition : public UAthenaDanceItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="ParticleSystem")
	void ConfigureParticleSystem(UParticleSystemComponent* ParticleSystem, TSoftObjectPtr<UTexture2D> OverrideImage) const;

protected:
	UPROPERTY(EditAnywhere, Category="GameplayTags")
	FGameplayTag EmojiGameplayCueTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	TSoftObjectPtr<UAnimMontage> PreviewAnimation;

	UPROPERTY(EditAnywhere, Category="Texture")
	TSoftObjectPtr<UTexture2D> SpriteSheet;

	UPROPERTY(EditAnywhere, Category="Texture")
	FIntPoint SheetDimensions;

	UPROPERTY(EditAnywhere, Category="Texture")
	int32 FrameIndex;

	UPROPERTY(EditAnywhere, Category="Texture")
	int32 FrameCount;

	UPROPERTY(EditAnywhere, Category="Material")
	TObjectPtr<UMaterialInterface> BaseMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ParticleSystem")
	FVector IconSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ParticleSystem")
	FLinearColor InitialColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ParticleSystem")
	FVector InitialLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ParticleSystem")
	FVector InitialVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ParticleSystem")
	float LifetimeIntroSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ParticleSystem")
	float LifetimeMidSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ParticleSystem")
	float LifetimeOutroSeconds;

private:
	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstance> GeneratedMaterial;

};


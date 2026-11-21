// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Items/FortAccoladeTypes.h"
#include "Items/FortPersistableItemDefinition.h"
#include "FortAccoladeItemDefinition.generated.h"

class UFortAccoladeItemDefinition;
class USoundCue;
class UTexture2D;
enum class EFortAccoladeSubtype : uint8;
enum class EFortAccoladeType : uint8;
enum class EXPEventPriorityType : uint8;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("AccountItem", "Sacrifice", "Conversion", "Level", "FortItemDefinition", "InventoryLimit", "Rating", "Functionality", "Frontend"))
class UFortAccoladeItemDefinition : public UFortPersistableItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetAccoladeLevel() const;

	UFUNCTION()
	EFortAccoladeSubtype GetAccoladeSubtype() const;

	UFUNCTION(BlueprintPure)
	EFortAccoladeType GetAccoladeType() const;

	UFUNCTION(BlueprintPure)
	int32 GetAccoladeXpValue() const;

	UFUNCTION(BlueprintPure)
	int32 GetAccoladeXpValueWithCountScalar(const int32 Count) const;

	UFUNCTION(BlueprintPure)
	USoundCue* GetAwardedSound() const;

	UFUNCTION(BlueprintPure)
	TSoftObjectPtr<UTexture2D> GetPreviousAccoladeLargePreviewImage() const;

	UFUNCTION(BlueprintPure)
	TSoftObjectPtr<UTexture2D> GetPreviousAccoladeSmallPreviewImage() const;

	UFUNCTION(BlueprintPure)
	EXPEventPriorityType GetPriority() const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAccoladeItemDefinition")
	EFortAccoladeType AccoladeType;

	UPROPERTY(EditDefaultsOnly, Category="FortAccoladeItemDefinition")
	EFortAccoladeSubtype AccoladeSubtype;

	UPROPERTY(EditDefaultsOnly, Category="FortAccoladeItemDefinition")
	TArray<TSoftObjectPtr<UFortAccoladeItemDefinition>> AccoladeToReplace;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TSoftObjectPtr<UTexture2D> PreviouseAccoladeSmallPreviewImage;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TSoftObjectPtr<UTexture2D> PreviouseAccoladeLargePreviewImage;

	UPROPERTY(EditAnywhere, Category="FortAccoladeItemDefinition")
	EXPEventPriorityType Priority;

	UPROPERTY(EditDefaultsOnly, Category="FortAccoladeItemDefinition")
	FScalableFloat XpRewardAmount;

	UPROPERTY(EditDefaultsOnly, Category="FortAccoladeItemDefinition")
	float AccoladeLevel;

	UPROPERTY(EditDefaultsOnly, Category="FortAccoladeItemDefinition")
	bool bOnlyAllowOncePerDay;

	UPROPERTY(EditDefaultsOnly, Category="FortAccoladeItemDefinition")
	bool bIgnoreInAntiAddictionReducedStates;

	UPROPERTY(EditDefaultsOnly, Category="FortAccoladeItemDefinition")
	TObjectPtr<USoundCue> AwardedSoundCue;

	UPROPERTY(EditDefaultsOnly, Category="FortAccoladeItemDefinition")
	FScalableFloat XpRewardScalarByCount;

	UPROPERTY(EditDefaultsOnly, Category="FortAccoladeItemDefinition", meta=(TitleProperty="Type"))
	TArray<FAccoladeSecondaryXpType> SecondaryXpValues;

};


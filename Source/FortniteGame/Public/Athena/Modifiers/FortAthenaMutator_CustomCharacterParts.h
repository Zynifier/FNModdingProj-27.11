// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortGender.h"
#include "FortAthenaMutator_CustomCharacterParts.generated.h"

class AFortPlayerController;
class UCustomCharacterPart;

USTRUCT(BlueprintType)
struct FPartOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display Data")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display Data")
	TArray<TObjectPtr<UCustomCharacterPart>> PartsToSwapIn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display Data")
	TArray<TObjectPtr<UCustomCharacterPart>> DefaultParts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display Data", meta=(Categories="Cosmetics.MetaTags.Theme"))
	FGameplayTag CosmeticSwapTag;

};

UCLASS(Abstract, HideDropdown, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CustomCharacterParts : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Skins")
	bool GetPartOverridesForPlayer(TArray<FPartOverrideData>& OutOverrideParts, const AFortPlayerController* FortPlayerController) const;

	UPROPERTY(EditDefaultsOnly, Category="Base Override Customizations")
	TArray<FPartOverrideData> PartOverrideCustomizations;

	UPROPERTY(EditAnywhere, Category="Skins")
	FScalableFloat ShouldSwapSkins;

	UPROPERTY(EditAnywhere, Category="Skins")
	FGameplayTagContainer SkinMetaTagsToSkip;

};


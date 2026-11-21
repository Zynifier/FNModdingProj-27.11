// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerGliderAnimAsset.h"
#include "FortPlayerGliderAnimSet.generated.h"

USTRUCT(BlueprintType)
struct FFortTagToGliderAnimSetPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	FGameplayTag MatchingTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	FFortAnimInput_PlayerGliderAnimAsset OverrideAnimAsset;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortPlayerGliderAnimSet : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="AnimSet")
	FFortAnimInput_PlayerGliderAnimAsset AnimAsset;

	UPROPERTY(EditAnywhere, Category="AnimSet")
	TArray<FFortTagToGliderAnimSetPair> OverrideAnimAssets;

};


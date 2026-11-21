// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PrototypeRecipeBookDataAsset.generated.h"

class UPrototypeRecipeDataAsset;

UCLASS(BlueprintType, Blueprintable)
class FORTNITEGAME_API UPrototypeRecipeBookDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PrototypeRecipeBookDataAsset")
	TArray<TObjectPtr<UPrototypeRecipeDataAsset>> RecipeList;

};


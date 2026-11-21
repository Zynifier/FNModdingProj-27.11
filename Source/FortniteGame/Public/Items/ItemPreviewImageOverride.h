// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "ItemPreviewImageOverride.generated.h"

class UTexture2D;

UCLASS(EditInlineNew)
class UItemPreviewImageOverride : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="ItemPreviewImageOverride")
	TSoftObjectPtr<UTexture2D> OverrideTexture;

	UPROPERTY(EditDefaultsOnly, Category="ItemPreviewImageOverride")
	FGameplayTag TagToCheck;

};


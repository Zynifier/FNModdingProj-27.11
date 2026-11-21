// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterAccessoryData.h"
#include "CustomCharacterBackpackData.generated.h"

UCLASS()
class UCustomCharacterBackpackData : public UCustomCharacterAccessoryData
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Backpack")
	FName LootSocketName;

};


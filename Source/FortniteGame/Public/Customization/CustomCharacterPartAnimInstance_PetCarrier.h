// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_PetCarrier.generated.h"

class AFortPlayerPawn;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_PetCarrier : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Carrier")
	TObjectPtr<AFortPlayerPawn> PlayerPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Jump")
	uint8 bIsZiplining : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Jump")
	uint8 bIsBallooning : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Jump")
	uint8 bIsFlying : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Jump")
	uint8 bIsInAirNotJumping : 1;

};


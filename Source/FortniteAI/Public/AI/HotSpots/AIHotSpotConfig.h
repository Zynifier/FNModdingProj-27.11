// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "AI/FortAITypes.h"
#include "AIHotSpotConfig.generated.h"

class UAIHotSpotSlotGenerator;

USTRUCT()
struct FAIHotSpotSlotConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AIHotSpot")
	FVector Offset;

	UPROPERTY(EditDefaultsOnly, Category="AIHotSpot")
	FVector Direction;

	UPROPERTY(EditDefaultsOnly, Category="AIHotSpot")
	EFortHotSpotSlot SlotType;

};

UCLASS()
class UAIHotSpotConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AIHotSpot")
	TArray<FAIHotSpotSlotConfig> Slots;

	UPROPERTY(EditDefaultsOnly, Category="AIHotSpot")
	uint8 bDetectUnreachableSlots : 1;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="AIHotSpot")
	TObjectPtr<UAIHotSpotSlotGenerator> SlotGenerator;

};


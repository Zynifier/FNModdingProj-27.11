// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "AIHotSpotSlotGenerator.generated.h"

class AAIHotSpot;
class UAIHotSpotSlot;

UCLASS(Abstract, EditInlineNew, BlueprintType, Blueprintable)
class UAIHotSpotSlotGenerator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AI|Hotspot", meta=(AdvancedDisplay="2"))
	UAIHotSpotSlot* AddSlot(const FVector& RelativeLocation, const FRotator& RelativeRotation, TSubclassOf<UAIHotSpotSlot> CustomSlotClass = nullptr, bool bEnabled = true) const;

	UFUNCTION(BlueprintNativeEvent, Category="AI|Hotspot")
	void GenerateSlots();

	UFUNCTION(BlueprintPure, Category="AI|Hotspot")
	AAIHotSpot* GetHotSpot() const;

};


// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Mobile/BacchusHUDElement.h"
#include "BacchusSignalQualityWidget.generated.h"

enum class EBacchusSignalQuality : uint8;

UENUM(BlueprintType)
enum class EBacchusSignalQuality : uint8
{
	None = 0,
	Low = 1,
	Medium = 2,
	High = 3,
};

UCLASS()
class UBacchusSignalQualityWidget : public UBacchusHUDElement
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnNewSignalQuality(float NewRawQuality);

	UFUNCTION(BlueprintImplementableEvent)
	void SetNewSignalQuality(EBacchusSignalQuality NewSignalQuality);

};


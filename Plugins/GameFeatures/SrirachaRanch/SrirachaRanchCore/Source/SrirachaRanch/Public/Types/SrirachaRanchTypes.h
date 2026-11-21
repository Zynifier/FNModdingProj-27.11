// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SrirachaRanchTypes.generated.h"

UENUM(BlueprintType)
enum class ERadioSource : uint8
{
	Invalid = 0,
	Vehicle = 1,
};

USTRUCT()
struct FSrirachaInputMappingData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SrirachaInputMappingData")
	FName MainActionName;

	UPROPERTY(EditAnywhere, Category="SrirachaInputMappingData")
	FName GamepadActionName;

	UPROPERTY(EditAnywhere, Category="SrirachaInputMappingData")
	FText DisplayName;

};


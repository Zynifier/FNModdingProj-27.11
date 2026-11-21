// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FabricMetasoundUserOption.generated.h"

UENUM(BlueprintType)
enum class EFabricUserOptionConversionType : uint8
{
	Linear = 0 UMETA(Tooltip="Lerp linearly between the minimum and maximum value."),
	Exponential = 1 UMETA(Tooltip="Lerp exponentially between the minimum and maximum value."),
	Lookup = 2 UMETA(Tooltip="Use the incoming value as an index into a provided array of inputs"),
};

USTRUCT(BlueprintType)
struct FABRICMETASOUNDDATATYPES_API FFabricUserOption
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricUserOption")
	EFabricUserOptionConversionType ConversionType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricUserOption")
	float Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricUserOption")
	float Max;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricUserOption")
	TArray<float> LookupTable;

};

UCLASS(BlueprintType, Blueprintable)
class FABRICMETASOUNDDATATYPES_API UFabricMetaSoundUserOption : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MidiStepSequence")
	FFabricUserOption FabricUserOption;

};


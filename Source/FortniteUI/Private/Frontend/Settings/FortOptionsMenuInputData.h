// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Input/FortActionKeyMapping.h"
#include "FortOptionsMenuInputData.generated.h"

class UCommonTextBlock;
enum class EFortInputActionGroup : uint8;

UCLASS(BlueprintType)
class UFortOptionsMenuInputData : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	EFortInputActionGroup GetInputActionGroup() const;

	UFUNCTION(BlueprintPure)
	float GetInputScale() const;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuInputData")
	FName ActionName;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuInputData")
	FText DisplayText;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuInputData")
	FText PrimaryText;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuInputData")
	FText SecondaryText;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenuInputData")
	int32 ElementNumber;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortOptionsMenuInputData", meta=(EditInline="true"))
	TObjectPtr<UCommonTextBlock> TabText;

	UPROPERTY()
	FFortActionKeyMapping ActionKeyMapping;

};


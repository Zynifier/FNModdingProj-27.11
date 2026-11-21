// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonNumericTextBlock.h"
#include "FortItemCountTextBlock.generated.h"

class UFortItemDefinition;
enum class EFortItemCountStyle : uint8;

UENUM(BlueprintType)
enum class EFortItemCountStyle : uint8
{
	// Displays the number of instances of the specified item definition in inventory.

	StackCount = 0,
	// Displays the specified number.

	OverrideCount = 1,
	// Displays, as a fraction, the number of instances of the specified item definition in inventory over the specified number.

	StackCountOverOverride = 2,
};

UCLASS(PrioritizeCategories=("Content"), meta=(Category="Fortnite UI"))
class UFortItemCountTextBlock : public UCommonNumericTextBlock
{
	GENERATED_BODY()

public:
	UFortItemCountTextBlock(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, Category="Numeric Interpolation")
	void InterpolateOverrideToValue(const int32 TargetValue, float MaximumInterpolationDuration = 3.000000f, float MinimumChangeRate = 1.000000f, float OutroOffset = 0.000000f);

	UFUNCTION(BlueprintCallable, Category="FortItemCountTextBlock")
	void SetCountStyle(EFortItemCountStyle InCountStyle);

	UFUNCTION(BlueprintCallable, Category="FortItemCountTextBlock")
	void SetItemDefinition(UFortItemDefinition* InItemDefinition);

	UFUNCTION(BlueprintCallable, Category="FortItemCountTextBlock")
	void SetOverrideValue(int32 InOverrideValue);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCountTextBlock", meta=(ExposeOnSpawn="TRUE"))
	TObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCountTextBlock", meta=(ExposeOnSpawn="TRUE"))
	EFortItemCountStyle CountStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCountTextBlock", meta=(ExposeOnSpawn="TRUE"))
	float ItemCountMaxInterpolateDuration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemCountTextBlock", meta=(ExposeOnSpawn="TRUE"))
	float ItemCountMinInterpolateRate;

private:
	UFUNCTION()
	void HandleItemCountChanged(UFortItemDefinition* Definition, int32 Delta);

};

